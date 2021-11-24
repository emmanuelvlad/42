const promisify = require('es6-promisify');
const crypto = require('crypto');
const db = require('./dbController');
const mail = require('../handlers/mail');
const socket = require('socket.io-client')('http://localhost:7777');

exports.logout = (req, res) => {
  socket.emit('logout', req.session.user);

  req.session.user = null;
  req.session.email = null;
  req.flash('is-success', 'You are now logged out! 👋');
  res.redirect('/login');
};

exports.login = async (req, res) => {
  const hash = crypto.createHash('whirlpool');
  hash.update(req.body.password);
  req.body.password = hash.digest('hex');
  const user = await db.getUser({username: insensitive(req.body.username), password: req.body.password});
  if (user) {
    req.session.user = user;
    req.session.username = req.body.username;
    socket.emit('login', req.session.user);
    req.flash('is-success', 'You successfully logged in');
    res.redirect('/');
  }
  else {
    req.flash('is-warning', 'Failed to logged you in');
    res.redirect('/login');
  }
};

exports.isLog = async (req, res, next) => {
  if (req.session.user) {
    var update = await db.getUser({ username: insensitive(req.session.user.username) });
    req.session.user = update;
    next();
  }
  else {
    req.flash('is-warning', "You must be connected to visit this page");
    res.redirect('/login');
  }
}

exports.resetPwForm = async (req, res) => {
  var a = new Date(Date.now());
  const user = await db.getUser({
    $and: [
      { resetToken: req.params.token },
      { resetExpire: { $gt: new Date(Date.now()) }}
    ]
  });
  if (!user) {
    req.flash('is-danger', 'Password reset is invalid or has expired');
    return res.redirect('/login');
  }
  // if there is a user, show the rest password form
  res.render('reset', { title: 'Reset your Password' });
};

const passwordValidity = (password) => {
  let strongRegex = new RegExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.{8,})");
  if (password.match(strongRegex)) {
    return true;
  }
  return false;
}

exports.confirmedPasswords = (req, res, next) => {
  if (req.body.password == req.body['password-confirm']) {
    if (!passwordValidity(req.body.password)) {
      req.flash('is-danger', 'Your password must contain at least 8 characters, and at least one elem in each categories : [a-z][A-Z][0-9]');
      res.redirect('back');
      return ;
    }
    next();
    return ;
  }
  req.flash('is-danger', 'Passwords doesn\'t match');
  res.redirect('back');
}

exports.update = async (req, res) => {
  const user = await db.getUser({
    $and: [
      { resetToken: req.params.token },
      { resetExpire: { $gt: new Date(Date.now()) }}
    ]
  });
  if (!user) {
    req.flash('is-danger', 'Password reset is invalid or has expired');
    return res.redirect('/login');
  }
  const hash = crypto.createHash('whirlpool');
  hash.update(req.body.password);
  req.body.password = hash.digest('hex');
  await db.addInfoUser(
    { resetToken: req.params.token },
    { $set:  { password: req.body.password }}
  );
  req.flash('is-success', '💃 Nice! Your password has been reset!');
  res.render('login');
}

exports.askfornew = (req, res) => {
  res.render('newpw');
};

exports.resetPw = async (req, res) => {
  const token = {
    resetToken: crypto.randomBytes(20).toString('hex'),
    resetExpire: new Date(Date.now() + 3600000)
  }
  const user = await db.getUser({ email: req.body.email });
  if (!user) {
    req.flash('is-warning', 'No account with that email');
    return res.redirect('/login');
  }
  const userToken = await db.addInfoUser(
    { email: req.body.email },
    { $set: token }
  );
  const sentURL = `http://${req.headers.host}/askfornew/reset/${userToken.resetToken}`;
  const content = `Click on this URL to reset your password: ${sentURL}`;
  await mail.send({
    email: req.body.email,
    subject: 'Matcha, Reset your password',
    content
  });
  req.flash('is-success', 'We send you an email to reset your password');
  res.redirect('/login');
}
