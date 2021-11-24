const promisify = require('es6-promisify');
const express = require('express');
const router = express.Router();


const profileController = require('../controllers/profileController');
const userController = require('../controllers/userController');
const authController = require('../controllers/authController');
const matchingController = require('../controllers/matchingController');
const apiController = require('../controllers/apiController');
const { catchErrors } = require('../handlers/errorHandlers');

router.get('/',
  authController.isLog,
  matchingController.browse
  );

router.get('/login', userController.loginForm);
router.post('/login', authController.login);

router.get('/register', userController.registerForm);
router.post('/register',
  userController.checkFormValidity,
  catchErrors(userController.checkUnicity),
  catchErrors(userController.addUser)
);

router.get('/edit', 
  authController.isLog,
  userController.editUser);
router.get('/edit/photos', 
  authController.isLog,
  profileController.getAddPhoto);
router.post('/edit',
  userController.checkEditFormValidity,
  catchErrors(userController.uploadUserAndEdit),
  userController.renderProfile
);
router.post('/edit/photos',
  profileController.upload,
  catchErrors(profileController.resize)
);

router.get('/askfornew',
  authController.askfornew);
router.post('/askfornew', catchErrors(authController.resetPw));
router.get('/askfornew/reset/:token',
  catchErrors(authController.resetPwForm));
router.post('/askfornew/reset/:token',
  authController.confirmedPasswords,
  catchErrors(authController.update));

router.get('/search',
  authController.isLog,
  matchingController.chooseYourParam);
router.post('/search', 
  matchingController.controlSearch, 
  catchErrors(matchingController.getPreview));
router.get('/search/:currentUser/:user',
  authController.isLog,
  matchingController.visitProfile);
router.get('/profile',
  authController.isLog,
  profileController.getProfile);
router.get('/profile/:user([a-z-A-Z0-9_-]{2,15})',
  authController.isLog,
  profileController.addVisited,
  // profileController.measurePopularity,
  profileController.getProfile);

router.get('/chat',
  authController.isLog,
  catchErrors(matchingController.chatWith)
);

router.get('/chat/:matches',
  authController.isLog,
  matchingController.chat
);

router.get('/logout', authController.logout);

// API
router.get('/api/user/:username([a-zA-Z0-9_-]{2,15})', apiController.getUser);
router.get('/api/relations/:user1([a-zA-Z0-9_-]{2,15})/:user2([a-zA-Z0-9_-]{2,15})', apiController.getRelations);


router.post('/api/like/', apiController.like);
router.post('/api/unlike/', apiController.unlike);
router.post('/api/report/', apiController.report);
router.post('/api/block/', apiController.block);
router.post('/api/unblock/', apiController.unblock);
router.post('/api/notification/delete', apiController.notification.delete);
router.post('/api/notification/delete/all', apiController.notification.deleteAll);
router.post('/api/chat', apiController.chat);

module.exports = router;
