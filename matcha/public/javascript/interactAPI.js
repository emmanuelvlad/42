$(function() {

	var socket = getSocket();

	let user = window.location.pathname.split('/')[2];
	// console.log(user);

	function like() {
		$.post(`/api/like`, {user}, (data) => {
			// console.log(data);
			if (data.success) {
				$('#like').addClass('is-success');
				$('#like').find('i').addClass('bounceIn infinite');
				$('#like').blur();
			} else {
				alert(data.error);
			}
		});
	}

	function unlike() {
		$.post(`/api/unlike`, {user}, (data) => {
			// console.log(data);
			if (data.success) {
				unlike_animation();
			}
		});
	}

	function unlike_animation() {
		$('#like').removeClass('is-success');
		$('#like').find('i').removeClass('bounceIn infinite');
		$('#like').find('i').addClass('hinge');
		$('#like').blur();
		setTimeout(function() {
			$('#like').find('i').removeClass('hinge');
		}, 2500);
	}

	function block() {
		$.post('/api/block', {user}, (data) => {
			// console.log(data);
			if (data.success) {
				if (data.animation) {
					unlike_animation();
				}
				$('#block').addClass('is-danger');
				$('#block').blur();
			}
		});
	}

	function unblock() {
		$.post('/api/unblock/', {user}, (data) => {
			// console.log(data);
			if (data.success) {
				$('#block').removeClass('is-danger');
				$('#block').blur();
			}
		});
	}

	function report() {
		$.post('/api/report', {user}, (data) => {
			// console.log(data);
			if (data.success) {
				$.notify('User reported', 'success');
			}
			else {
				$.notify('User already reported', 'error')
			}
			$(this).blur();
		});
	}

	$('#like').click(function() {
		if (!$(this).hasClass('is-success')) {
			like();
		} else {
			unlike();
		}
	});

	$('#report').click(function() {
		report();
	});

	$('#block').click(function() {
		if (!$(this).hasClass('is-danger')) {
			block();
		} else {
			unblock();
		}
	});
});
