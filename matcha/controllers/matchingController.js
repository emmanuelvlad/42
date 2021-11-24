const promisify = require('es6-promisify');
const db = require('./dbController');
const crypto = require('crypto');
const ObjectId = require('mongodb').ObjectID;
const ageCalculator = require('age-calculator');
const geolib = require('geo-lib');
const {AgeFromDateString, AgeFromDate} = require('age-calculator');

exports.chooseYourParam = async (req, res) => {
  var maxPopularity = await db.highestPopularity();
  var tags = await db.getTags();
  var userTags = [];

  if (req.session.user.search.tags) {
    for(i = 0; i < req.session.user.search.tags.length; i++) {
      var tag = await db.getTag(ObjectId(req.session.user.search.tags[i]));
      if (tag) {
        userTags.push(tag.name);
      }
    }
  }
  res.render('search', {
    currentUser: req.session.user,
    tags,
    userTags,
    maxPopularity,
    title: 'Search'
  });
};

const testAge = (val) => {
  if ( val && typeof(val) === 'string') {
    val = parseInt(val);
    if (val >= 18 && val <= 100) {
      return false;
    }
    else {
      return true;
    }
  }
}

const testLength = (val) => {
  if ( val && typeof(val) === 'string') {
    val = parseInt(val);
    if (val >= 0 && val <= 500) {
      return false;
    }
    else {
      return true;
    }
  }
}

exports.controlSearch = async (req, res, next) => {
  let form = req.body;
  let maxPopularity = await db.highestPopularity();
  if (testAge(form.ageMax) || testAge(form.ageMin)) { 
    req.flash('is-danger', 'Wrong age range');
    res.redirect('/search');
    return ;
  }
  if (parseInt(form.popularityMin) < 0 || parseInt(form.popularityMin) > maxPopularity || parseInt(form.popularityMax) < 0 || parseInt(form.popularityMax) > maxPopularity) {
    req.flash('is-danger', 'Wrong popularity range');
    res.redirect('/search');
    return ;
  }
  if (testLength(form.lengthMax)) {
    req.flash('is-danger', 'Wrong length range');
    res.redirect('/search');
    return ;
  }
  if (!form.sort || (form.sort !== '-' && form.sort !== 'Age' && form.sort !== 'Tags' && form.sort !== 'Popularity' && form.sort !== 'Nearest')) {
    req.flash('is-danger', 'Wrong sort');
    res.redirect('/search');
    return ;
  }
  next();
}

exports.getPreview = async (req, res) => {
  var tags = [];
  
  if (req.body.tags) {
    if (!Array.isArray(req.body.tags)) {
      req.body.tags = new Array(req.body.tags);
    }
    for(i = 0; i < req.body.tags.length; i++) {
      var tag = await db.getTag({name : req.body.tags[i].substring(1)});
      if (tag) {
        tags.push(tag._id);
      }
    }
  }

  let form = { 
    ageMin: req.body.ageMin,
    ageMax: req.body.ageMax,
    popularityMin: req.body.popularityMin,
    popularityMax: req.body.popularityMax,
    lengthMax: req.body.lengthMax,
    sort: req.body.sort,
    tags: tags 
  }
  await db.addInfoUser({ _id: ObjectId(req.session.user._id)}, {$set: { search: form }});
  res.redirect('/');
};

const sortByAge = (users) => {
  users.sort((a, b) => {
    return (new AgeFromDateString(a.birthday).age - new AgeFromDateString(b.birthday).age);
  });
};

const numberOfTagsMatch = (user1, user2) => {
  let i = 0;
  if (user1.tags && user2.tags) {
    user1.tags.map((x) => {
      if (user2.tags.indexOf(x)) {
        i++;
      }
    })
  }
  return (i);
};

const sortByTags = (user, users) => {
  users.sort((a, b) => {
    return (numberOfTagsMatch(b, user) - numberOfTagsMatch(a, user));
  });
};

const sortByPopularity = (users) => {
  users.sort((a, b) => {
    return (b.number - a.number);
  });
};

Math.dist=function(x1,y1,x2,y2){ 
  return Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) * 100; 
}

const sortByDistance = (user, users) => {
  users.sort((a, b) => {
    return (Math.floor(geolib.distance([ [user.location.lat, user.location.lng], [a.location.lat, a.location.lng] ]).distance) - Math.floor(geolib.distance([ [user.location.lat, user.location.lng], [b.location.lat, b.location.lng] ]).distance));
  });
};

const weight = async (user1, user2) => {
  let distance = Math.floor(geolib.distance([
    [user1.location.lat, user1.location.lng],
    [user2.location.lat, user2.location.lng]
  ]).distance) || 0;
  let tagsNumber = numberOfTagsMatch(user1, user2);
  let popularity = await db.getPopularity(user2);
  if (tagsNumber === 0) {
    tagsNumber = 0.1;
  } if (distance === 0) {
    distance = 0.1;
  }
  return (popularity + 1 / distance * 10 + tagsNumber * 5);
};

const sortWeighting = (user, users) => {
  users.sort((a, b) => {
    weight(user, a);
    return (weight(user, b) - weight(user, a));
  })
};

const matchTags = (user, x) => {
  if (user.search.tags.length !== 0) {
    let found = false;
    let strings = [];
    x.tags.forEach((r) => {
      strings.push(r.toString());
    });
    user.search.tags.forEach((r) => {
      if (strings.indexOf(r.toString()) >= 0) {
        found = true;
      }
    })
    return (found)
  } else {
    return true;
  }
}

const deleteUserOutRange = async (user, users) => {
  let ret = [];
  if (user.search.ageMin && user.search.ageMax && user.search.popularityMax && user.search.popularityMin
  && user.search.lengthMax) {
    for (let i=0; users.length > i; i++) {
      let x = users[i];
      let age = new AgeFromDateString(x.birthday).age;
      if (age >= user.search.ageMin && age <= user.search.ageMax
        && matchTags(user, x)
        && Math.floor(geolib.distance([[user.location.lat, user.location.lng], [x.location.lat, x.location.lng]]).distance) < user.search.lengthMax) {
        let popularity = await db.getPopularity(x.username);
        if (popularity >= user.search.popularityMin && popularity <= user.search.popularityMax) {
          ret.push(x);
        }
      }
    }
  };
  return (ret);
};

const findInterstingUser = async (req) => {
  let user = await db.getUser(ObjectId(req.session.user._id));
  req.session.user = user;
  let users = await db.selectMatches(user);
  let filtredUsers = [];
  if (req.session.user.block) {
    users.map((x) => {
      if (req.session.user.block.indexOf(x.username.toLowerCase()) < 0) {
        filtredUsers.push(x);
      }
    });
  }
  else {
    filtredUsers = users;
  }
  return (filtredUsers);

}

exports.findInterstingUser = findInterstingUser;

exports.browse = async (req, res) => {
  let filtredUsers = await findInterstingUser(req);
  if (typeof req.session.user.search.sort === 'undefined') {
    req.session.user.search.sort = '-';
  }
  switch (req.session.user.search.sort) {
    case 'Age':
      sortByAge(filtredUsers);
      break ;
    case 'Tags':
      sortByTags(req.session.user, filtredUsers);
      break ;
    case 'Popularity':
      sortByPopularity(filtredUsers);
      break ;
    case 'Nearest':
      sortByDistance(req.session.user, filtredUsers);
      break ;
    default :
      sortWeighting(req.session.user, filtredUsers);
      break ;
  }
  filtredUsers = await deleteUserOutRange(req.session.user, filtredUsers);
  res.render('found', {
    currentUser: req.session.user,
    users: filtredUsers,
    title: 'Browse'
  });
};

const deletePrivateInfo = (user) => {
  user.password = '';
  user.email = '';
  return (user);
};

exports.visitProfile = async (req, res) => {
  user = deletePrivateInfo(user);
  res.render('publicProfile', {
    currentUser: req.session.user,
    user
  });
};

const parseMatches = async (matches, username) => {
  let parseMatch = [];
  await Promise.all(matches.map( async (x) => {
    if (username === x.user1.username) {
      let user = await db.getUser({ username: insensitive(x.user2.username) });
      parseMatch.push({ _id: user._id, username: user.username, photo: user.photos });
    } else if (username === x.user2.username) {
      let user = await db.getUser({ username: insensitive(x.user1.username) });
      parseMatch.push({ _id: user._id, username: user.username, photo: user.photos });
    }
  }));
  return parseMatch;
};

exports.chatWith = async (req, res) => {
  let matches = await db.findAllMatches(req.session.user.username);
  let users = await parseMatches(matches, req.session.user.username);
  res.render('chatWith', {
    title: 'Chat',
    currentUser: req.session.user,
    users
  });
};

exports.chat = async (req, res) => {
  let link = await db.findLink(req.session.user.username, req.params.matches);
  if (link && link.user1.like && link.user2.like) {
    res.render('chat', {
      currentUser: req.session.user,
      title: req.params.matches,
      link
    });
  } else {
    res.redirect('/');
  }
}