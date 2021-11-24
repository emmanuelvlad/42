const promisify = require('es6-promisify');
const mongo = require('mongodb');
const ObjectId = require('mongodb').ObjectID;
const MongoClient = mongo.MongoClient;

var connect;

const connection = () => {
  if (!connect) {
    connect = MongoClient.connect(process.env.DATABASE);
    // console.log('[MongoDB] Connected'.green);
  }
  return connect;
};

exports.getConnection = async () => {
  try {
    let db = await connection();
    return db;
  }
  catch (err) {
  }
};

exports.getCol = async (col) => {
  let db = await connection();
  let data = await db.collection(col);
  return data;
};

exports.getUser = async (user) => {
	let db = await connection();
  let col_user = await db.collection('users');
	let res = await col_user.findOne(user);
	return res;
}

exports.getTag = async (data) => {
  let db = await connection();
  let col = await db.collection('tags');

  let res = await col.findOne(data);
  return res;
}

exports.getTags = async () => {
  let db = await connection();
  let col = await db.collection('tags');

  let res = await col.find().toArray();
  return res;
}

exports.addInfoUser = async (user, newUser) => {
  let db = await connection();
  let col_user = await db.collection('users');
  let res = await col_user.findOneAndUpdate(user, newUser, { returnOriginal: false });
  return res.value;
}

const searchingForYourOrientation = (sexWanted) => {
  switch (sexWanted) {
    case 'women':
      res = { sex: 'woman' };
      break;
    case 'men':
      res = { sex: 'man' };
      break;
    case 'both':
      res = { $or: [{ sex: "man"}, { sex: "woman"}] };
      break;
    case null:
      res = { $or: [{ sex: "man"}, { sex: "woman"}] };
      break;
  }
  return res;
};
const searchingForYourSex = (sex) => {
  switch (sex) {
    case 'woman':
      res = { sexWanted: 'women' };
      return res;
    case 'man':
      res = { sexWanted: 'men' };
      return res;
    case null:
      res = { $or: [{ sexWanted: 'women'}, { sexWanted: 'men'}] };
      return res;
  }
  res = null;
  return res;
};

exports.selectMatches = async (user) => {
  let db = await connection();
  let col = await db.collection('users');
  let res = await col.find({$and: [
    searchingForYourOrientation(user.sexWanted),
    { _id: { $ne: ObjectId(user._id) } },
    { $or: [
      { sexWanted: "both" },
      searchingForYourSex(user.sex)
    ]}
  ]}).sort({ birthday: -1 })
  .toArray();
  return res;
};

exports.findLink = async (u1, u2) => {
	let db = await connection();
  let col = await db.collection('matches');
	let res = await col.findOne({ $or: [
      { $and: [
        { 'user1.username': insensitive(u1) },
        { 'user2.username': insensitive(u2) }
      ]},
      { $and: [
        { 'user1.username': insensitive(u2) },
        { 'user2.username': insensitive(u1)}
      ]},
     ]
  });
	return res;
};

exports.findAllLinks = async (username) => {
	let db = await connection();
  let col = await db.collection('matches');
	let res = await col.find({ $or: [
      { 'user1.username': insensitive(username) },
      { 'user2.username': insensitive(username) }
    ]}
  ).toArray();
	return res;
};

exports.findAllMatches = async (username) => {
	let db = await connection();
  let col = await db.collection('matches');
	let res = await col.find({ $and: [
        { $or: [
          { 'user1.username': insensitive(username) },
          { 'user2.username': insensitive(username) }
        ]},
        { 'user1.like': true},
        { 'user2.like': true}
    ]}
  ).toArray();
	return res;
};

exports.addVisit = async (matches, link, name) => {
  let db = await connection();
  let col = await db.collection('matches');

  if (!link) {
    await col.insertOne(matches);
  }
  else {
    if (name.toLowerCase() === link.user1.username.toLowerCase()) {
      await col.findOneAndUpdate(link, { $set: { 'user1.last_visit': new Date(Date.now()) } }, { returnOriginal: false });
    }
    if (name.toLowerCase() === link.user2.username.toLowerCase()) {
      await col.findOneAndUpdate(link, { $set: { 'user2.last_visit': new Date(Date.now()) } }, { returnOriginal: false });
    }
  }
};

exports.handleLike = async (link, user, value) => {
  let db = await connection();
  let col = await db.collection('matches');
  if (link.user1.username.toLowerCase() === user.toLowerCase()) {
    await col.findOneAndUpdate(link, { $set: { 'user1.like': value } }, { returnOriginal: false });
  }
  else if (link.user2.username.toLowerCase() === user.toLowerCase()) {
    await col.findOneAndUpdate(link, { $set: { 'user2.like': value } }, { returnOriginal: false });
  }
};

exports.report = async (report) => {
  let db = await connection();
  let col = await db.collection('reports');

  let res = await col.findOne( { user: insensitive(report.user), reportedUser: insensitive(report.reportedUser) } );
  if (!res) {
    await col.insertOne(report);
    return true;
  }
  return false;
};

exports.findHighestNumber = async () => {
  let db = await connection();
  let col = await db.collection('users');
  let highest = await col.find().sort({number:-1}).limit(1).toArray();
  return(highest[0].number);
}

exports.addNotification = async (user, data) => {
  let db = await connection();
  let col = await db.collection('users');

  let res = await col.findOneAndUpdate( { username: insensitive(user) }, { $push: { 'notifications': data } }, { returnOriginal: false });
};

exports.deleteNotification = async (user, id) => {
  let db = await connection();
  let col = await db.collection('users');

  let res = await col.findOneAndUpdate( { username: insensitive(user) }, { $pull: { 'notifications': { _id: ObjectId(id) } } }, { returnOriginal: false });
};

exports.addMessageToLink = async (message) => {
	let db = await connection();
  let col = await db.collection('matches');
	let res = await col.findOneAndUpdate({ $or: [
      { $and: [
        { 'user1.username': insensitive(message.from) },
        { 'user2.username': insensitive(message.to) }
      ]},
      { $and: [
        { 'user1.username': insensitive(message.to) },
        { 'user2.username': insensitive(message.from) }
      ]},
     ]
    }, { $push: {
      chat: {
        user: message.from,
        message: message.message,
        date: new Date(Date.now())
      }
    }
  });
};

exports.isBlocked = async (user, target) => {
  let db = await connection();
  let col = await db.collection('users');

  let res = await col.findOne( { username: insensitive(user) } );

  if (res.block && res.block.indexOf(target.toLowerCase()) > -1) {
    return true;
  } else {
    return false;
  }
};

exports.getPopularity = async (user) => {
  let links = await this.findAllLinks(user);
  let popularity = 0;

  links.forEach(element => {
    popularity++;
    if ((element.user1.username.toLowerCase() === user.toLowerCase() && element.user2.like) ||
        (element.user2.username.toLowerCase() === user.toLowerCase() && element.user1.like)) {
      popularity += 5;
    }
    if (element.user1.like && element.user2.like) {
      popularity += 5;
    }
  });

  return popularity;
};

exports.highestPopularity = async () => {
  let db = await connection();
  let col = await db.collection('users');

  let res = await col.count();

  return ((res - 1) * 11);
};