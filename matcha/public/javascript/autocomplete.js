function autocomplete(input) {
	if (!input) return;
	const dropdown = new google.maps.places.Autocomplete(input[0]);
	dropdown.addListener('place_changed', () => {
		const place = dropdown.getPlace();
	});
	input.keydown((e) => {
		if (e.keyCode === 13)
			e.preventDefault();
	});
}

$(document).ready(function(){
	navigator.geolocation.getCurrentPosition(function(pos) {
		const geo = new google.maps.Geocoder;
		const latlng = {
			lat: pos.coords.latitude,
			lng: pos.coords.longitude
		}
		geo.geocode({ location: latlng }, function(results, status) {
			if (status == 'OK') {
				$('#addr')[0].value = results[0].formatted_address
			}
		});
	});
	autocomplete($('#addr'));
});
