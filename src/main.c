#include <pebble.h>
#include "main.h"

static Window *s_main_window;
static TextLayer *s_time_layer;

static Layer *s_layer;
static GPath *s_map_paths[NUM_MAP_PATHS];

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

static void image_layer_update_callback(Layer *layer, GContext *ctx) {
  graphics_context_set_fill_color(ctx, GColorBlack);
  for (int i = 0; i < NUM_MAP_PATHS; ++i) {
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

  for (int i = 0; i < NUM_MAP_PATHS; ++i) {
    s_map_paths[i] = gpath_create(&MAP_PATHS[i]);
  }

  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
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
