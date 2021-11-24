var title;
const socket = io();

var getSocket = function() {
  return socket;
};

var say = function(data) {
  socket.emit('say', data);
  return;
};


var hidden, visibilityChange; 
if (typeof document.hidden !== "undefined") { // Opera 12.10 and Firefox 18 and later support 
  hidden = "hidden";
  visibilityChange = "visibilitychange";
} else if (typeof document.msHidden !== "undefined") {
  hidden = "msHidden";
  visibilityChange = "msvisibilitychange";
} else if (typeof document.webkitHidden !== "undefined") {
  hidden = "webkitHidden";
  visibilityChange = "webkitvisibilitychange";
}




function handleVisibilityChange() {
  if (document[hidden]) {
    socket.emit('blur');
  } else {
    socket.emit('focus');
  }
}
document.addEventListener(visibilityChange, handleVisibilityChange, false);


$(function() {

    title = document.title;

    //
    //    SOCKET.IO
    //

    socket.on('say', function(message) {
      // console.log(`Console: ${message}`);
    });


    //initialize swiper when document ready
    var mySwiper = new Swiper ('.swiper-container', {
      // Optional parameters
      direction: 'horizontal',
      loop: true,
      navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
      },
      grabCursor: true,
      setWrapperSize: true,
      keyboard: true,
    })

    mySwiper.on('slideChange', function () {
        var active = this.activeIndex;
        var bg = $('.swiper-slide')[active].children[0].currentSrc;

        var banner = $('.background-image-blur');

        banner.css('background-image', `url(${bg})`);
    });

    

      
    // NAVBAR ACTIVE
    var $navbarBurgers = Array.prototype.slice.call(document.querySelectorAll('.navbar-burger'), 0);
    if ($navbarBurgers.length > 0) {
      $navbarBurgers.forEach(function ($el) {
        $el.addEventListener('click', function () {
          var target = $el.dataset.target;
          var $target = document.getElementById(target);
          $el.classList.toggle('is-active');
          $target.classList.toggle('is-active');
        });
      });
    }

    $('#notification').click(function() {
      $('#notification-drop').toggleClass("is-hidden");
    });

    $('.modal-close').click(function(){
      $('.modal').removeClass('is-active');
    });

    $('.modal-background').click(function(){
      $('.modal').removeClass('is-active');
    });

    socket.on('match', function(data) {
      $('.modal').addClass('is-active');
      $('.modal-content').html("it's a match");
    });

});