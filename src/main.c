#include <pebble.h>
#include "main.h"

#define KEY_TIMEOFFSET 0

static int32_t utc_offset_seconds = 0;
static int request_timezone_tries_left = 10;  // Try this many times before giving up.

static Window *s_main_window;
static TextLayer *s_time_layer;

static Layer *s_layer;
static GPath *s_map_paths[NUM_MAP_PATHS];

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  // Create a long-lived buffer that persists across multiple calls
  static char buffer[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();

  // In fact this is not necessary. update_time causes a draw of everything.
  layer_mark_dirty(s_layer);
}

static void image_layer_update_callback(Layer *layer, GContext *ctx) {
  time_t now = time(NULL);
  now += utc_offset_seconds;
  int32_t angle = (int32_t)((now % 86400) / 86400.0 * TRIG_MAX_ANGLE);
  // https://sslimgs.xkcd.com/comics/now/00h00m.png is 12 hours off 00:00 UTC
  angle += TRIG_MAX_ANGLE * 0.5;

  graphics_context_set_fill_color(ctx, GColorBlack);
  for (int i = 0; i < NUM_MAP_PATHS; ++i) {
    gpath_rotate_to(s_map_paths[i], angle);
    gpath_draw_filled(ctx, s_map_paths[i]);
  }
}

static void main_window_load(Window *window) {
  s_layer = layer_create(GRect(0, 0, 144, 144));
  layer_set_update_proc(s_layer, image_layer_update_callback);
  layer_add_child(window_get_root_layer(window),s_layer);


  s_time_layer = text_layer_create(GRect(0, 136, 144, 32));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);

  // Improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(window),
                  text_layer_get_layer(s_time_layer));
}

static void main_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);

  for (int i = 0; i < NUM_MAP_PATHS; ++i) {
    gpath_destroy(s_map_paths[i]);
  }

  layer_destroy(s_layer);
}

void set_timezone_offset(int offset) {
  if (offset != utc_offset_seconds) {
    utc_offset_seconds = (int32_t)offset;
    layer_mark_dirty(s_layer);
  }
}

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {

  Tuple *t = dict_read_first(iterator);
  while(t != NULL) {
    switch(t->key) {
    case KEY_TIMEOFFSET:
      set_timezone_offset((int)t->value->int32);
      break;
    default:
      APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized.", (int)t->key);
    }

    t = dict_read_next(iterator);
  }

  // Got timezone info. Don't request.
  if (request_timezone_tries_left > 0) {
    request_timezone_tries_left = 0;
  }
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

static void request_timezone(void) {
  if (request_timezone_tries_left > 0) {
    request_timezone_tries_left -= 1;
  } else {
    return;
  }

  // Sending anything is okay
  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);
  dict_write_uint8(iter, 0, 0);

  // Send the message!
  app_message_outbox_send();

  // Run this function again in 1000ms in case there were failures.
  app_timer_register(1000, (AppTimerCallback)request_timezone, NULL);
}

static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  update_time();

  GPoint center = {
    .x = 72,
    .y = 72,
  };
  for (int i = 0; i < NUM_MAP_PATHS; ++i) {
    s_map_paths[i] = gpath_create(&MAP_PATHS[i]);
    gpath_move_to(s_map_paths[i], center);
  }

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  // Register callbacks
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);

  // Open AppMessage
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());

  request_timezone();
}

static void deinit() {
  // Destroy Window
   window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
