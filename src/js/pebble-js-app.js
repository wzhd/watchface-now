// Listen for when the watchface is opened
Pebble.addEventListener('ready',
  function(e) {
    console.log('PebbleKit JS ready!');

    // Get the initial weather
    getWeather();
  }
);

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    console.log('AppMessage received!');
  }
);

var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};

function locationSuccess(pos) {
  // We will request the weather here
  var url = 'http://api.openweathermap.org/data/2.5/weather?lat=' +
      pos.coords.latitude + '&lon=' + pos.coords.longitude;
  xhrRequest(url,
             "GET",
             function(responseText){
               // responseText contains a JSON object with weather info
               var json = JSON.parse(responseText);

               // Temperature in Kelvin requires adjustment
               var temperature = json.main.temp;
               console.log('Temperature is ' + temperature);

               // Conditions
               var conditions = json.weather[0].main;
               console.log('Conditions are ' + conditions);
             }
            );
}

function locationError(err) {
  console.log('Error requesting location!');
}

function getWeather() {
  navigator.geolocation.getCurrentPosition(
    locationSuccess,
    locationError,
    {timeout: 15000, maximumAge: 60000}
  );
}
