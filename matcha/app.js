require('dotenv').config({ path: 'variables.env' });

// Global functions
insensitive = function (str) {
	return new RegExp(["^", str, "$"].join(""), "i");
}


const express = require('express');
const http = require('http');
var session = require('express-session')({
	secret: process.env.SECRET,
	key: process.env.KEY,
	resave: true,
	saveUninitialized: true,
})
var sharedsession = require("express-socket.io-session");
const path = require('path');
const cookieParser = require('cookie-parser');
const bodyParser = require('body-parser');
const promisify = require('es6-promisify');
const flash = require('connect-flash');
const routes = require('./routes/routes');
const helpers = require('./handlers/helpers');
const errorHandlers = require('./handlers/errorHandlers');
var io = require('socket.io');
var colors = require('colors');
global.clients = [];
global.timeAgo = require('node-time-ago');

var app = express();
var port = process.env.PORT || 7777;

var server = http.createServer(app);

io = io(server);
global.io = io;
// Load *variables.env* into proccess.env


app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

app.use(express.static(path.join(__dirname, 'public')));
// app.use(express.static(path.join(__dirname, 'public')));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.use(cookieParser());

const db = require('./controllers/dbController');

const database = db.getConnection();
app.use(session);

app.use(flash());

app.use((req, res, next) => {
	req.io = io;
	next();
});

// Passing variables to templates + all requests
app.use((req, res, next) => {
	res.locals.h = helpers;
	res.locals.flashes = req.flash();
	res.locals.user = req.session.user || null;
	res.locals.email = req.session.email || null;
	res.locals.currentPath = req.path;
	next();
});

// promisify some callback based APIs
app.use((req, res, next) => {
	req.login = promisify(req.login, req);
	next();
});




//
//   			SOCKET.IO
//


io.use(sharedsession(session, {
    autoSave:true
}));

io.on('connection', function (socket) {

	if (socket.handshake.session.user) {
		// console.log(`[Socket.io] New socket for ${socket.handshake.session.user.username}`.cyan);
		socket.handshake.focus = true;
		global.clients[socket.handshake.session.user.username.toLowerCase()].push(socket);

		if (global.clients[socket.handshake.session.user.username.toLowerCase()].length === 1) {
			db.addInfoUser({ username: insensitive(socket.handshake.session.user.username) }, { $set: { status: "Online" } })
		}

		socket.on('disconnect', function() {
			// console.log(`[Socket.io] Removed old socket for ${socket.handshake.session.user.username}`.red);

			if (global.clients[socket.handshake.session.user.username.toLowerCase()].length == 1) {
				db.addInfoUser({ username: insensitive(socket.handshake.session.user.username) }, { $set: { last_visit: new Date(), status: "Offline" } });
			}
			var i = global.clients[socket.handshake.session.user.username.toLowerCase()].indexOf(socket);
			global.clients[socket.handshake.session.user.username.toLowerCase()].splice(i, 1);
		});
	}	


	socket.on("login", function(userdata) {
		// console.log(`[Socket.io] ${userdata.username} logged in!`.green)
		socket.handshake.session.userdata = userdata;
		global.clients[socket.handshake.session.userdata.username.toLowerCase()] = [];
		socket.handshake.session.save();
	});
	
    socket.on("logout", function(userdata) {
        if (socket.handshake.session.userdata && userdata) {
			// console.log(`[Socket.io] ${userdata.username} logged out!`.red)
            delete socket.handshake.session.userdata;
			socket.handshake.session.save();
			var i = clients.indexOf(socket);
			clients.splice(i, 1);
        }
    });

	socket.on('connect', function(user) {
		console.log(`${user.username} connected!`);
		// socket.username = user.username;
	});

	socket.on('say', function(message) {
		// console.log(message);
	});

	socket.on('focus', function() {
		this.handshake.focus = true;
	});

	socket.on('blur', function() {
		this.handshake.focus = false;
	});

	socket.on('message', function (data) {
		db.addMessageToLink(data);
		if (global.clients[data.to]) {
			let chatSockets = global.clients[data.to];
			chatSockets.forEach((x) => {
				if (x.handshake.headers.referer.split('/')[3] === 'chat' && x.handshake.headers.referer.split('/')[4] === data.from) {
					socket.to(x.id).emit('message', data);
				}
			});
		}
	});
});

app.use('/', routes);

// if that above routes didnt work, we 404 them and forward to error handler
app.use(errorHandlers.notFound);

// One of our error handlers will see if these errors are just validation errors
app.use(errorHandlers.flashValidationErrors);

// Otherwise this was a really bad error we didn't expect! Shoot eh
if (app.get('env') === 'development') {
  /* Development Error Handler - Prints stack trace */
  app.use(errorHandlers.developmentErrors);
}

// production error handler
app.use(errorHandlers.productionErrors);

server.listen(port, '127.0.0.1', () => {
	// console.log(`[Express] Running on port ${port}`.yellow);
});
