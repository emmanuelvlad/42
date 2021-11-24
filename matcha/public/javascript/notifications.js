var notification = {};

notification.get = function() {
    return Number($("#notification").attr('data-count')) || 0;
}

notification.add = function(value = 1) {
    var el = $("#notification");
    var count = Number(el.attr('data-count')) || 0;

    document.title = `(${count + value}) ${title}`;
    el.attr('data-count', count + value);
    el.removeClass('notify');
    el[0].offsetWidth = el[0].offsetWidth;
    el.addClass('notify');
    if (count === 0) {
        el.addClass('show-count');
    }
}

notification.set = function(value) {
    var el = $("#notification");
    var count = Number(el.attr('data-count')) || 0;

    el.attr('data-count', value);
    if (value > 0) {
        if (count === 0) {
            el.addClass('show-count');
        }
        document.title = `(${value}) ${title}`;
        el.removeClass('notify');
        el[0].offsetWidth = el[0].offsetWidth;
        el.addClass('notify');
    } else {
        el.removeClass('show-count');
        document.title = `${title}`;
    }
}

notification.remove = function(value = 1) {
    var el = $("#notification");
    var count = Number(el.attr('data-count')) || 0;

    document.title = `(${count - value}) ${title}`;
    el.attr('data-count', count - value);
    if (count - value <= 0) {
        notification.set(0);
    }
}

notification.deleteAll = function() {
    $.post(`/api/notification/delete/all`, (data) => {
        if (data.success) {
            var el = document.querySelectorAll(`[data-notification-id]`);
            el.forEach(function(element) {
                element.remove();
            });
            if ($('.notification-empty').hasClass('is-hidden')) {
                $('.notification-empty').removeClass('is-hidden');
            }
            notification.set(0);
        }
    });
}

notification.delete = function(id) {
    $.post(`/api/notification/delete`, { id }, (data) => {
        if (data.success) {
            if (notification.get() === 1) {
                if ($('.notification-empty').hasClass('is-hidden')) {
                    $('.notification-empty').removeClass('is-hidden');
                }
            }
            var el = document.querySelectorAll(`[data-notification-id="${id}"]`);
            el.forEach(function(element) {
                element.remove();
            });
            notification.remove();
        }
    });
}

$(function() {

socket.on('notification', function(data) {
    if (notification.get() === 0) {
        if (!$('.notification-empty').hasClass('is-hidden')) {
            $('.notification-empty').addClass('is-hidden');
        }
    }
    notification.add();
    $('.notification-content').prepend(`
      <div class="notification-block" data-notification-id="${data._id}">
        <div class="notification-delete">
          <i class="fa fa-times"></i>
        </div>
        <div class="notification-img">
          <figure class="image is-48x48">
            <div class="user-img is-circle" style="background-image: url(${data.icon})"></div>
          </figure>
        </div>
        <div class="notification-info">
          <span class="is-size-7">
            <a class="is-bold" href="${data.url}">${data.user}</a>
            <span> ${data.message}</span>
          <span>
          <div class="notification-age is-size-7">
            <i class="fa fa-clock-o"></i>
            <span>${data.date}</span>
          </div>
        <div>
      </div>
    `);
    // $(`[data-notification-id="${data._id}`).find('i').attr('onclick', `notification.delete("${data._id}")`);
    $(`[data-notification-id="${data._id}`).find('i').click(function() {
        notification.delete(`${data._id}`)
    });
  });
});