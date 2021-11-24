const promisify = require('es6-promisify');
const db = require('./dbController');
const crypto = require('crypto');
const ObjectId = require('mongodb').ObjectID;
const querystring = require('querystring');
const ageCalculator = require('age-calculator');
const axios = require('axios');
const profileController = require('./profileController');

// geocoder.selectProvider("google", {'key':'AIzaSyAWJj2wY0DVY7TdtUNEM3r91L4suYhK8jc'})


exports.loginForm = (req, res) => {
  res.render('login', {title: 'login'});
};

exports.registerForm = (req, res) => {
  res.render('register', {title: 'register'});
};

exports.editUser = async (req, res) => {
  var currentUser = await db.getUser(ObjectId(req.session.user._id));
  var tags = await db.getTags();
  var userTags = [];
  req.session.user = currentUser;
  if (currentUser.tags) {
    for(i = 0; i < currentUser.tags.length; i++) {
      var tag = await db.getTag(ObjectId(currentUser.tags[i]));
      if (tag) {
        userTags.push(tag.name);
      }
    }
  }

  res.render('edit', {
    title: 'edit',
    tags,
    userTags,
    currentUser: req.session.user,
  });
};

getEmail = async (email) => {
  const db = await connection();
  const col = await db.collection('elem');
  return res;
};

exports.validateRegister = (req, res, next) => {
};

const passwordValidity = (password) => {
  let strongRegex = new RegExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.{8,})");
  if (password.match(strongRegex)) {
    return true;
  }
  return false;
}

const findAddress = async (ip, address = null) => {
  let error = false;
  let location = {};
  let result;

  if (address) {
    let query = querystring.stringify({address});
    await axios.get(`https://maps.googleapis.com/maps/api/geocode/json?address=${query}&key=${process.env.GOOGLE_KEY}`)
    .then(function(response) {
      if (response.data.status === 'OK') {
        result = response.data.results[0];
      } else {
        error = true;
      }
    }).catch(function(err) {
      error = true;
    });
  }

  if (error || !address) {
    if (ip == '127.0.0.1') {
      await axios.get(`https://freegeoip.net/json/`)
      .then(function(response) {
        location.lat = response.data.latitude;
        location.lng = response.data.longitude;
      }).catch(function(err) {
        error = true;
      });
    } else {
      await axios.get(`https://freegeoip.net/json/${ip}`)
      .then(function(response) {
        location.lat = response.data.latitude;
        location.lng = response.data.longitude;
      }).catch(function(err) {
        error = true;
      });
    }
    await axios.get(`https://maps.googleapis.com/maps/api/geocode/json?latlng=${location.lat},${location.lng}&key=${process.env.GOOGLE_KEY}`)
    .then(function(response) {
      if (response.data.status === 'OK') {
        result = response.data.results[0];
      }
    }).catch(function(err) {
      error = true;
    });
  }

  return result;
}

exports.checkFormValidity = (req, res, next) => {
  var form = req.body;
  const errs = [];
  const regex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
  const regex_name = /^[a-zA-Z0-9_-]+$/;
  const hash = crypto.createHash('whirlpool');

  if (!form.username || !form.firstname || !form.lastname || !form.email || !form.password || !form.repeatPassword)
    errs.push('Please fill all fields');
  else {
    if (!form.username.match(regex_name) || !form.firstname.match(regex_name) || !form.lastname.match(regex_name))
      errs.push('Names must only contain alphanumeric characters.');
    else {
      if (!(form.username.length >= 3 && form.username.length <= 15) || !(form.firstname.length >= 3 && form.firstname.length <= 15) || !(form.lastname.length >= 3 && form.lastname.length <= 15))
        errs.push('Your name must contain between 3 and 15 characters');
      else {
        if (!form.birthday)
          errs.push('No birthday...');
        else {
          if (!form.email.match(regex))
            errs.push('Your email address is not valid');
          else {
            if (form.password !== form.repeatPassword)
              errs.push('Your passwords didn\'t match');
            else {
              if (!passwordValidity(form.password)) {
                errs.push('Your password must contain at least 8 characters, and at least one elem in each categories : [a-z][A-Z][0-9]');
              } else {
                hash.update(form.password);
                form.password = hash.digest('hex');
              }
            }
          }
        }
      }
    }
  }
  if (errs.length) {
    for (err in errs) {
      req.flash('is-danger', `${errs[err]}`);
    }
    res.redirect('/register');
  }
  else
    next();
};

exports.checkUnicity = async (req, res, next) => {
  const datab = await db.getConnection();
  const col = await datab.collection('users');
  var find_email = await col.findOne({ email: req.body.email});
  var find_username = await col.findOne({ username: req.body.username});
  if (find_email) {
    req.flash('is-danger', 'Your mail already exist');
    res.redirect('/renderProfile');
  }
  if (find_username) {
    req.flash('is-danger', 'Username not available');
    res.redirect('/register');
  }
  if (!find_email && !find_username)
    next();
};

exports.addUser = async (req, res, next) => {
  // const col = db.getCol('users');
	const datab = await db.getConnection();
	const col = await datab.collection('users');
  var form = req.body;
  var geo = await findAddress(req.ip, form.location.address);

  let basicUser = {
    username: form.username,
    firstname: form.firstname,
    lastname: form.lastname,
    birthday: form.birthday,
    email: form.email,
    sex: "man",
    sexWanted: "both",
    location: {
      address: geo.formatted_address,
      lat: geo.geometry.location.lat,
      lng: geo.geometry.location.lng
    },
    search: {
      ageMin: "18",
      ageMax: "100",
      popularityMin: "1",
      popularityMax: "10",
      lengthMax: "500",
      sort: "-",
      tags: []
    },
    password: form.password,
    bio: null,
    tags: [],
    photos: [],
    block: [],
    notifications: [],
    number: 1
  };
	await col.insertOne(basicUser);
	// const ret = await col.find({email : req.body.email})
	req.flash('is-success', `Successfully created ${req.body.email} account. Now login`);
	res.redirect('/login');
};

exports.checkEditFormValidity = async (req, res, next) => {
  var form = req.body;
  const errs = [];
  const regex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
  const regexLongWord = /^.*?\S{28,}.*?$/;

  const exist = await db.getUser({ email: form.email});
  if (!form.firstname || !form.lastname || !form.email || !form.birthday || !form.sexWanted)
    errs.push('Please fill all fields');
  else {
    if (!(form.firstname.length >= 3 && form.firstname.length <= 15) || !(form.lastname.length >= 3 && form.lastname.length <= 15))
      errs.push('Your name must contain between 3 and 15 characters');
    else {
      if (!form.email.match(regex))
        errs.push('Your email address is not valid');
        else {
        if (!form.birthday)
          errs.push('No birthday...');
          else {
          if (exist && exist._id != req.session.user._id)
            errs.push('Your email address is not valid');
          else {
            if (form.sex != "woman" && form.sex != "man")
              errs.push('You didn\'t put your sex');
            else {
              if (form.sexWanted != "women" && form.sexWanted != "men" && form.sexWanted != "both")
                errs.push('You didn\'t put your sexual orientation');
              else {
                if (form.bio.match(regexLongWord))
                  errs.push('Your word must be below 28 characters');
              }
            }
          }
        }
      }
    }
  }
  if (errs.length) {
    for (err in errs) {
      req.flash('is-danger', `${errs[err]}`);
    }
    res.redirect('/edit');
  }
  else
    next();
};

exports.uploadUserAndEdit = async (req, res, next) => {
  req.body.location.type = 'Point';
  var editThisUser = await db.getUser(ObjectId(req.session.user._id));
  var form = req.body;
  var geo = await findAddress(req.ip, form.location.address);
  var tags = [];

  if (form.tags) {
    if (!Array.isArray(form.tags)) {
      form.tags = new Array(form.tags);
    }
    for(i = 0; i < form.tags.length; i++) {
      var tag = await db.getTag({name : form.tags[i].substring(1)});
      if (tag) {
        tags.push(tag._id);
      }
    }
  }

  var setnew = {
    firstname: form.firstname,
    lastname: form.lastname,
    birthday: form.birthday,
    email: form.email,
    sex: form.sex,
    sexWanted: form.sexWanted,
    location: {
      address: geo.formatted_address,
      lat: geo.geometry.location.lat,
      lng: geo.geometry.location.lng
    },
    bio: form.bio,
    tags: tags
  };
  if (editThisUser.email) {
    await db.addInfoUser(editThisUser, {$set: setnew}, {$new: setnew});
  }
  req.flash('is-success', `Successfully updated your profile!`);
  res.redirect('/edit');
};

exports.renderProfile = async (req, res, next) => {
  req.flash('is-success', 'You successfully edited your profile.');
  var user = await db.getUser(ObjectId(req.session.user._id));
  var age = new AgeFromDateString(user.birthday).age;
  var tags = await db.getTags();
  var userTags = [];

  for(i = 0; i < user.tags.length; i++) {
    var tag = await db.getTag(ObjectId(user.tags[i]));
    if (tag) {
      userTags.push(tag);
    }
  }

  res.render('profile', {
    currentUser: req.session.user,
    user,
    tags,
    userTags,
    age,
    title: 'Profile'
  });
};
