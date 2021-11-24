$(function() {
	let user = window.location.pathname.split('/')[2];
	let username = $('#username').text();
	var firstLoad = 1;

	$("#content").animate({ scrollTop: $('#content').prop('scrollHeight') }, 0);
	
	$('#messageSend').click(() => {
		sendMessage();
	});

	$('#messageInput').keyup((e) => {
		if (e.keyCode === 13) {
			sendMessage();
		}
	});

	var sendMessage = () => {
		let message = $('#messageInput').val();
		var bottom = $('#content').prop('scrollHeight');
		var heightAfter = $('#content').scrollTop() + $('#content').height();
		if (bottom === heightAfter) {
			$("#content").animate({ scrollTop: $('#content').prop('scrollHeight') }, 0);
		}

		$.post(`/api/chat`, { user, message }, (data) => {
			// console.log(data);
			if (data.success) {
				$('#messageInput').val('').focus();
			} else if (data.error) {
				alert(data.error);
			}
		});
	};

	socket.on('message', (data) => {
		insereMessage(data);
	})

	socket.emit('message', user);

	const insereMessage = (data) => {
		let from = (data.from === user) ? data.from : "You";
		var bottom = $('#content').prop('scrollHeight');
		var heightAfter = $('#content').scrollTop() + $('#content').height();
		$('#zoneChat').append( '<tr><th>' + from + '</th> <td>' + data.message + '</td></tr>')
		// console.log(`bottom: ${bottom} |||| eightafter: ${heightAfter}`);
		if ((bottom === heightAfter || bottom === heightAfter + 1)) {
			$("#content").animate({ scrollTop: $('#content').prop('scrollHeight') }, 0);
		}
	}
})