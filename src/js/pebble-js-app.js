// Listen for when the watchface is opened
Pebble.addEventListener('ready',
                        function(e) {
                          console.log('PebbleKit JS ready!');
                          sendUtcOffset();
                        });

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
                        function(e) {
                          console.log('AppMessage received!');
                          sendUtcOffset();
                        });


function sendUtcOffset() {
  // offset in minutes
  var tz_offset = (new Date()).getTimezoneOffset();
  var dictionary = {
    'KEY_TIMEOFFSET': tz_offset * 60
  };

  // Send to Pebble
  Pebble.sendAppMessage(dictionary,
                        function(e) {
                          console.log('Time offset sent to Pebble successfully!');
                        },
                        function(e) {
                          console.log('Error sending time offset!');
                        }
                       );

}
