const promisify = require('es6-promisify');

const db = require('./dbController');
const matchingController = require('./matchingController');

const multer = require('multer');
const jimp = require('jimp');
const uuid = require('uuid');
const fs = require('fs');
const ObjectId = require('mongodb').ObjectID;
const geolib = require('geo-lib');
var socket = require('socket.io-client')('http://localhost:7777');

const ageCalculator = require('age-calculator');
const {AgeFromDateString, AgeFromDate} = require('age-calculator');


const multerOptions = {
  storage: multer.memoryStorage(),
  limits: { fileSize: 2000000 },
  fileFilter(req, file, next) {
    const isPhoto = file.mimetype.startsWith('image/png');
    const isPhoto2 = file.mimetype.startsWith('image/jpeg');
    if(isPhoto || isPhoto2) {
      next(null, true);
    } else {
      next({ message: 'That file isn\'t allowed' }, false);
    }
  }
};

exports.getHome = (req, res) => {
  res.render('layout', {
    currentUser: req.session.user,
    title: 'Matcha'
  });
};

exports.getAddPhoto = async (req,res) => {
  var currentUser = await db.getUser(ObjectId(req.session.user._id));
  res.render('addPhoto', {
    currentUser: req.session.user,
    title: 'Edit Photo'
  });
};

exports.addVisited = async (req, res, next) => {
  let user1 = req.session.user.username;
  let photo = (req.session.user.photos && req.session.user.photos[0]) ? "//localhost:7777/user/" + req.session.user._id + "/" + req.session.user.photos[0] : null;
  let user2 = await db.getUser({ username: insensitive(req.params.user) });
  if (!user2) {
    res.redirect('/');
    return;
  }
  if (user1.toLowerCase() != user2.username.toLowerCase()) {
    // console.log(`${user1} is visiting ${user2.username}`.red);
    let id = new ObjectId();
    let link = await db.findLink(user1, user2.username);
    let visited = {
      user1: {
        username: user1,
        last_visit: new Date(Date.now()),
        like: false
      },
      user2: {
        username: user2.username,
        last_visit: null,
        like: false
      },
    };
    req.body.link = link ? link : visited
    await db.addVisit(visited, link, user1);
    
    let block = await db.isBlocked(user2.username, user1)
    if (!block) {
      await db.addNotification(user2.username, {
        _id: id,
        type: "visit",
        color: "",
        icon: photo,
        url: `//localhost:7777/profile/${user1.toLowerCase()}`,
        seen: false,
        date: new Date(),
        user: user1
      });

      if (global.clients[user2.username.toLowerCase()]) {
        global.clients[user2.username.toLowerCase()].forEach(function(element) {
          global.io.to(element.id).emit('notification', {
            _id: id,
            user: user1,
            url: `http://localhost:7777/profile/${user1.toLowerCase()}`,
            icon: photo,
            message: "visited your profile!",
            date: global.timeAgo(new Date())
          });
        })
      }
    }
  }
  next();
};

const findNumberOfLike = (links, name) => {
  let like = 0;
  links.map((x) => {
    if (x.user1.username === name) {
      if (x.user2.like) {
        like++;
      }
    }
    if (x.user2.username === name) {
      if (x.user1.like) {
        like++;
      }
    }
  });
  return like;
};

const popularity = async (req, res) => {
  let links = await db.findAllLinks(req.params.user);
  let likes = findNumberOfLike(links, req.params.user);
  let number = likes + 1;
  let HighestNb = await db.findHighestNumber();
  let popularity = (number / HighestNb * 10);

  await db.addInfoUser({username: req.params.user}, {$set: {number}});
  return popularity.toFixed(2);
}

const likeStatus = (link, username) => {
  if (link.user1.username === username) {
    if (link.user1.like) {
      return (link.user1.like);
    } else {
      return (false);
    }
  } else {
    if (link.user2.like) {
      return (link.user2.like);
    } else {
      return (false);
    }
  }
};

// const findLike = (links, username) => {
//   if 
// }

const getViewAndLike = async (links, username, req) => {
  let res = {}
  res.all = []
  res.like = false 
  res.visit = false

  blocked = req.session.user.block
  // console.log(blocked)
  await Promise.all(links.map(async (x) => {
    if (x.user1.username.toLowerCase() === username.toLowerCase()) {
      if ((x.user2.like || x.user2.last_visit) && blocked.indexOf(x.user1.username.toLowerCase()) == -1) {
        let user = await db.getUser({ username: insensitive(x.user2.username) });
        res.all.push({ _id: user._id, username: user.username, photos: user.photos, like: x.user2.like, last_visit: x.user2.last_visit})
        if (x.user2.like) {
          res.like = true
        } if (x.user2.last_visit) {
          res.visit = true
        }
      }
    }
    if (x.user2.username.toLowerCase() === username.toLowerCase()) {
      if ((x.user1.like || x.user1.last_visit) && blocked.indexOf(x.user1.username.toLowerCase()) == -1) {
        let user = await db.getUser({ username: insensitive(x.user1.username) });
        res.all.push({ _id: user._id, username: user.username, photos: user.photos, like: x.user1.like, last_visit: x.user1.last_visit})
        if (x.user1.like) {
          res.like = true
        } if (x.user2.last_visit) {
          res.visit = true
        }
      }
    }
  }));
  return (res);
};

exports.getProfile = async (req, res) => {
  let maxPopularity = await db.highestPopularity();
  if (req.params.user) {
    var user = await db.getUser({
        username: insensitive(req.params.user)
    });
    user.popularity = await db.getPopularity(req.params.user);
  } else if (req.session.user) {
    var user = await db.getUser(ObjectId(req.session.user._id));
    req.session.user = user;
    req.session.user.popularity = await db.getPopularity(req.session.user.username);
  } else {
    res.redirect('/');
  }
  let age = new AgeFromDateString(user.birthday).age;
  let distance = Math.floor(geolib.distance([
    [user.location.lat, user.location.lng],
    [req.session.user.location.lat, req.session.user.location.lng]
  ]).distance);
  user.tags = user.tags || [];
  let tags = [];
  for(i = 0; i < user.tags.length; i++) {
    var tag = await db.getTag(ObjectId(user.tags[i]));
    if (tag) {
      tags.push(tag.name);
    }
  }
  let like;
  let user2_like;
  if (req.body.link) {
    like = likeStatus(req.body.link, req.session.user.username);
    user2_like = likeStatus(req.body.link, req.params.user);
  }
  let link = await db.findLink(req.session.user.username, user.username);
  let links = await db.findAllLinks(req.session.user.username);
  let viewAndLike = await getViewAndLike(links, req.session.user.username, req);
  let block = await db.isBlocked(req.session.user.username, user.username);
  let orientation = ((req.session.user.sexWanted === "men" && req.session.user.sex === "man") || (req.session.user.sexWanted === "women" && req.session.user.sex === "woman")) ? "Homosexual" :
                    ((req.session.user.sexWanted === "women" && req.session.user.sex === "man") || (req.session.user.sexWanted === "men" && req.session.user.sex === "woman")) ? "Heterosexual" : "Bisexual";
  res.render('profile', {
    currentUser: req.session.user,
    user,
    like,
    user2_like,
    age,
    tags,
    block,
    link,
    distance,
    maxPopularity,
    orientation,
    links: viewAndLike,
    title: 'Profile'
  });
};

exports.upload = multer(multerOptions).fields([
  {name: 'photo-1'},
  {name: 'photo-2'},
  {name: 'photo-3'},
  {name: 'photo-4'},
  {name: 'photo-5'},
]);

exports.resize = async (req, res) => {
  const currentUser = await db.getUser(ObjectId(req.session.user._id));
  req.body = currentUser;
  for (var key in req.files) {
    var i = key.split('-').pop() - 1;
    if (req.body.photos && req.body.photos[i] && fs.existsSync(`./public/user/${req.session.user._id}/${req.body.photos[i]}`))
      fs.unlinkSync(`./public/user/${req.session.user._id}/${req.body.photos[i]}`);
    const extension = req.files[key][0].mimetype.split('/')[1];
    const name = `${uuid.v4()}.${extension}`;
    if (!req.body.photos)
      req.body.photos = [];
    if (req.body.photos.length > i) {
      req.body.photos[i] = name;
    }
    else {
      req.body.photos.push(name)
    }
    const photo = await jimp.read(req.files[key][0].buffer);
    await photo.resize(800, jimp.AUTO);
    await photo.write(`./public/user/${req.session.user._id}/${name}`)
  }
  let x = await db.addInfoUser({ _id: ObjectId(req.session.user._id)}, {$set: req.body});
  // const newUser = await db.getUser( {_id: req.session.user} );
  res.redirect('/profile');
};
