const promisify = require('es6-promisify');
const db = require('./dbController');
const ObjectId = require('mongodb').ObjectID;
var socket = require('socket.io-client')('http://localhost:7777');

const error = {
    error : "Bad Request",
    status : 400
};

exports.getUser = async (req, res) => {
    var data = await db.getUser( { username : insensitive(req.params.username) } );
    if (data) {
        delete data._id;
        delete data.password;
        delete data.email;
        res.json(data);
    } else {
        res.json(error);
    }
};

exports.getRelations = async (req, res) => {
	var params = req.params;
	if (params.user1 !== params.user2) {
		var user1 = await db.getUser( { username : insensitive(params.user1) } );
		var user2 = await db.getUser( { username : insensitive(params.user2) } );
		if (user1 && user2) {
			// TODO
			res.json(error);
		}
	} else {
			res.json(error);
	}
};

exports.like = async (req, res) => {
	let success = false;
	let error = null;

	if (req.session.user) {
		if (req.session.user.photos && req.session.user.photos[0]) {
			let id = new ObjectId();
			
			let user1 = req.session.user.username.toLowerCase();
			let photo = (req.session.user.photos && req.session.user.photos[0]) ? "//localhost:7777/user/" + req.session.user._id + "/" + req.session.user.photos[0] : null;

			let user2 = req.body.user.toLowerCase();
			if (user1 !== user2) {
				let block = await db.isBlocked(user1, user2);
				if (!block) {
					// console.log(`${user1} liked ${user2}`);
					let user2_data = await db.getUser({ username: insensitive(user2) });
					let user2_photo = (user2_data.photos && user2_data.photos[0]) ? "//localhost:7777/user/" + user2_data._id + "/" + user2_data.photos[0] : null;
					
					let link = await db.findLink(user1, user2);
					if (link) {
						if (!(link.user1.like && link.user2.like)) {
							await db.handleLike(link, user1, true);

							let match = (link.user2.username.toLowerCase() === user2) ? (link.user2.like) ? true : false : (link.user1.like) ? true : false;
							
							block = await db.isBlocked(user2, user1)
							if (!block) {
								await db.addNotification(user2, {
									_id: id,
									type: "like",
									color: "",
									icon: photo,
									url: `//localhost:7777/profile/${user1}`,
									seen: false,
									date: new Date(),
									user: user1
								});
								if (match) {
									// console.log(`It's a match!`);
									if (global.clients[user2]) {
										global.clients[user2].forEach(function(element) {
											global.io.to(element.id).emit('match', {
												user: req.session.user.username,
												url: `http://localhost:7777/profile/${user1}`,
												icon: photo
											});
										})
									}
									if (global.clients[user1]) {
										global.clients[user1].forEach(function(element) {
											global.io.to(element.id).emit('match', {
												user: user2_data.username,
												url: `http://localhost:7777/profile/${user2}`,
												icon: user2_photo
											});
										})
									}
								}
								if (global.clients[user2]) {
									global.clients[user2].forEach(function(element) {
										global.io.to(element.id).emit('notification', {
											_id: id,
											user: user1,
											url: `http://localhost:7777/chat/${user1}`,
											icon: photo,
											message: "likes you! It's a match!",
											date: global.timeAgo(new Date())
										});
									})
								}
							}
							success = true;
						}
					}
				}
				else {
					error = "You cannot like someone you blocked";
				}
			} else {
				error = "You cannot like yourself!";
			}
		}
		else {
			error = "You need a profile picture first!";
		}
	}
	res.json({ success, error });
};

const unlike_notification = async (user1, user2) => {
	let id = new ObjectId();
	
	let photo = (user1.photos && user1.photos[0]) ? "//localhost:7777/user/" + user1._id + "/" + user1.photos[0] : null;
	let block = await db.isBlocked(user2, user1.username);

	if (!block) {
		await db.addNotification(user2, {
			_id: id,
			type: "unlike",
			color: "",
			icon: photo,
			url: `//localhost:7777/profile/${user1.username.toLowerCase()}`,
			seen: false,
			date: new Date(),
			user: user1.username
		});
		if (global.clients[user2]) {
			global.clients[user2].forEach(function(element) {
				global.io.to(element.id).emit('notification', {
					_id: id,
					user: user1.username,
					url: `http://localhost:7777/profile/${user1.username.toLowerCase()}`,
					icon: photo,
					message: "doesn't like you anymore!",
					date: global.timeAgo(new Date())
				});
			})
		}
	}
};

exports.unlike = async (req, res) => {
	let success = false;
	let error = null;

	if (req.session.user) {
		let user1 = req.session.user.username;
		let user2 = req.body.user.toLowerCase();
		let link = await db.findLink(user1, user2);
		if (link) {
			if ((link.user1.username.toLowerCase() === user1.toLowerCase() && link.user1.like) || (link.user2.username.toLowerCase() === user1.toLowerCase() && link.user2.like)) {
				success = true;
			}
			if (link.user1.like && link.user2.like) {
				unlike_notification(req.session.user, user2);
				await db.handleLike(link, user1, false);
			}
		} else {
			error = "Oops";
		}
	}

	res.json({ success, error });
};

exports.report = async (req, res) => {
	let success = false;

	if (req.session.user) {
		let report = {
			user: req.session.user.username,
			reportedUser: req.body.user,
			date: new Date(Date.now()),
			report: 'fake profile',
		};
		success = await db.report(report);
	}

	res.json({ success });
};

exports.block = async (req, res) => {
	let success = false;
	let animation = true;

	if (req.session.user) {
		let block = req.session.user.block || [];
		let index = block.indexOf(req.body.user.toLowerCase());
		if (index === -1) {
			let link = await db.findLink(req.session.user.username, req.body.user);
			if (link) {
				if ((link.user1.username.toLowerCase() === req.session.user.username.toLowerCase() && link.user1.like) || (link.user2.username.toLowerCase() === req.session.user.username.toLowerCase() && link.user2.like)) {
					unlike_notification(req.session.user, req.body.user);
					await db.handleLike(link, req.session.user.username, false);
				} else {
					animation = false;
				}
			}
			block.push(req.body.user.toLowerCase());
			await db.addInfoUser({ username: req.session.user.username }, { $set: { block } })
			success = true;
		}
	}

	res.json({ success, animation });
};

exports.unblock = async (req, res) => {
	let success = false;

	if (req.session.user) {
		let block = req.session.user.block;
		let index = block.indexOf(req.body.user.toLowerCase());
		if (index > -1) {
			block.splice(index, 1);
		}

		await db.addInfoUser({ username: req.session.user.username }, { $set: { block } })
		success = true;
	}

	res.json({ success });
};

exports.notification = {};

exports.notification.delete = async (req, res) => {
	let success = false;

	if (req.session.user) {
		await db.deleteNotification(req.session.user.username, req.body.id);
		success = true;
	}

	res.json({ success });
}

exports.notification.deleteAll = async (req, res) => {
	let success = false;

	if (req.session.user) {
		await db.addInfoUser({ username: insensitive(req.session.user.username) }, { $set: { notifications: [] } });
		success = true;
	}

	res.json({ success });
};

exports.chat = async (req, res) => {
	let success = false;
	let error = null;

	if (req.session.user) {
		let id = new ObjectId();

		let user1 = req.session.user.username;
		let photo = (req.session.user.photos && req.session.user.photos[0]) ? "//localhost:7777/user/" + req.session.user._id + "/" + req.session.user.photos[0] : null;
		
		let user2 = req.body.user.toLowerCase();
		let link = await db.findLink(user1, user2);
		if (link && link.user1.like && link.user2.like) {
			let data = {
				from: user1,
				to: user2,
				message: req.body.message
			};

			await db.addMessageToLink(data);

			let found = false;
			if (global.clients[user2]) {
				for (var i = 0; i < global.clients[user2].length; i++) {
					let el = global.clients[user2][i];
					if (el.handshake.focus) {
						let url = el.handshake.headers.referer.split('/');
						if (url.length === 5 && url[3] === "chat" && url[4] === user1.toLowerCase()) {
							found = true;
						}
					}
				}
			}

			if (!found) {
				await db.addNotification(user2, {
					_id: id,
					type: "message",
					color: "",
					icon: photo,
					url: `//localhost:7777/profile/${user1.toLowerCase()}`,
					seen: false,
					date: new Date(),
					user: user1
				});

				if (global.clients[user2]) {
					global.clients[user2].forEach(function(element) {
						global.io.to(element.id).emit('notification', {
							_id: id,
							user: user1,
							url: `http://localhost:7777/chat/${user1.toLowerCase()}`,
							icon: photo,
							message: "sent a new message!",
							date: global.timeAgo(new Date())
						});
					});
				}
			} else {
				if (global.clients[user2]) {
					global.clients[user2].forEach(function(element) {
						global.io.to(element.id).emit('message', {
							from: data.from,
							message: data.message
						});
					});
				}
			}
		
			if (global.clients[user1.toLowerCase()]) {
				global.clients[user1.toLowerCase()].forEach(function(element) {
					global.io.to(element.id).emit('message', {
						from: data.from,
						message: data.message
					});
				});
			}
			success = true;
		} else {
			error = "There is no match!";
		}
	}

	res.json({ success, error })
};