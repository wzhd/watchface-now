var platform;
// Listen for when the watchface is opened
Pebble.addEventListener('ready',
                        function(e) {
                          console.log('PebbleKit JS ready!');

                          // Work around Pebble.getActiveWatchInfo() failure on basalt
                          // https://forums.getpebble.com/discussion/comment/142327#Comment_142327
                          if(Pebble.getActiveWatchInfo) {
                            try {
                              // Currently this only works on aplite platforms
                              var current_watch = Pebble.getActiveWatchInfo();
                              platform = current_watch.platform;
                            } catch(err) {
                              platform = 'basalt';
                            }
                          } else {
                            platform = 'aplite';
                          }

                          if (platform == 'aplite') {
                            sendUtcOffset();
                          }
                        });

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
                        function(e) {
                          console.log('AppMessage received!');
                          if (platform == 'aplite') {
                            sendUtcOffset();
                          }
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
