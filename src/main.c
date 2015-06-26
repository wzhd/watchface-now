#include <pebble.h>

#define KEY_TEMPERATURE 0
#define KEY_CONDITIONS 1

static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_weather_layer;
static GFont s_time_font;
static GFont s_weather_font;
static GBitmap *s_bg_bitmap;
static BitmapLayer *s_bitmap_layer;

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  // Create a long-lived buffer that persists across multiple calls
  static char buffer[] = "00:00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00:00"), "%H:%M:%S", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00:00"), "%I:%M:%S", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void main_window_load(Window *window) {
  s_bg_bitmap = gbitmap_create_with_resource(RESOURCE_ID_BG_IMAGE);
  s_bitmap_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bg_bitmap);
  layer_add_child(window_get_root_layer(window),
                  bitmap_layer_get_layer(s_bitmap_layer));


  s_time_layer = text_layer_create(GRect(0, 55, 144, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);

  // Improve the layout to be more like a watchface
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_LOVED_BY_THE_KING_40));
  text_layer_set_font(s_time_layer, s_time_font);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(window),
                  text_layer_get_layer(s_time_layer));

  // Weather Layer
  s_weather_layer = text_layer_create(GRect(0, 120, 144, 48));
  text_layer_set_background_color(s_weather_layer, GColorClear);
  text_layer_set_text_color(s_weather_layer, GColorWhite);
  text_layer_set_text_alignment(s_weather_layer, GTextAlignmentCenter);
  text_layer_set_text(s_weather_layer, "Loading");
  s_weather_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_LOVED_BY_THE_KING_30));
  text_layer_set_font(s_weather_layer, s_weather_font);
  layer_add_child(window_get_root_layer(window),
                  text_layer_get_layer(s_weather_layer));
}

static void main_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_weather_layer);

  // Unload GFont
  fonts_unload_custom_font(s_time_font);
  fonts_unload_custom_font(s_weather_font);

  gbitmap_destroy(s_bg_bitmap);
  bitmap_layer_destroy(s_bitmap_layer);
}

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  // Store incoming information
  char temperature_buffer[8];
  char conditions_buffer[32];
  static char weather_layer_buffer[32];

  Tuple *t = dict_read_first(iterator);
  while(t != NULL) {
    switch(t->key) {
    case KEY_TEMPERATURE:
      snprintf(temperature_buffer, sizeof(temperature_buffer), "%dK", (int)t->value->int32);
      break;
    case KEY_CONDITIONS:
      snprintf(conditions_buffer, sizeof(conditions_buffer), "%s", t->value->cstring);
      break;
    default:
      APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized.", (int)t->key);
    }

    t = dict_read_next(iterator);
  }

  snprintf(weather_layer_buffer, sizeof(weather_layer_buffer), "%s %s", temperature_buffer, conditions_buffer);
  text_layer_set_text(s_weather_layer, weather_layer_buffer);
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
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);

  // Register callbacks
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);

  // Open AppMessage
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
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
