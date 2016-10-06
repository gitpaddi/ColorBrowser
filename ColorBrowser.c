#include "pebble.h"

#define NUM_FONTS 62
#define NUM_MESSAGES 3

typedef struct {
 char *name;
 char *variant;
 char *res;
 int color;
} PebbleFont;

static PebbleFont pebble_fonts[] = {
    { .name = "Black", .variant = "#000000", .color = 0x000000, .res = FONT_KEY_GOTHIC_14 },
    { .name = "White", .variant = "#FFFFFF", .color = 0xFFFFFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Light Gray", .variant = "#AAAAAA", .color = 0xAAAAAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Dark Gray", .variant = "#555555", .color = 0x555555, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Pastell Yellow", .variant = "#FFFFAA", .color = 0xFFFFAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Icterine", .variant = "#FFFF55", .color = 0xFFFF55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Yellow", .variant = "#FFFF00", .color = 0xFFFF00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Chrome Yellow", .variant = "#FFAA00", .color = 0xFFAA00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Rajah", .variant = "#FFAA55", .color = 0xFFAA55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Orange", .variant = "#FF5500", .color = 0xFF5500, .res = FONT_KEY_GOTHIC_14 },

    { .name = "Sunset Orange", .variant = "#FF5555", .color = 0xFF5555, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Windsor Tan", .variant = "#FFAA00", .color = 0xFFAA00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Red", .variant = "#FF0000", .color = 0xFF0000, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Melon", .variant = "#FFAAAA", .color = 0xFFAAAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Folly", .variant = "#FF0055", .color = 0xFF0055, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Rose Vale", .variant = "#AA5555", .color = 0xAA5555, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Bulgarian Rose", .variant = "#550000", .color = 0x550000, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Dark Candy Apple Red", .variant = "#AA0000", .color = 0xAA0000, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Jazzberry Jam", .variant = "#AA0055", .color = 0xAA0055, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Fashion Magenta", .variant = "#FF00AA", .color = 0xFF00AA, .res = FONT_KEY_GOTHIC_14 },
    
    { .name = "Magenta", .variant = "#FF00FF", .color = 0xFF00FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Brilliant Rose", .variant = "#FF55AA", .color = 0xFF55AA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Brilliant Lavender", .variant = "#FFAAFF", .color = 0xFFAAFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Shocking Pink", .variant = "#FF55FF", .color = 0xFF55FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Purple", .variant = "#AA00AA", .color = 0xAA00AA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Purpureus", .variant = "#AA55AA", .color = 0xAA55AA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Lavender Indigo", .variant = "#AA55FF", .color = 0xAA55FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Vivid Violet", .variant = "#AA00FF", .color = 0xAA00FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Indigo", .variant = "#5500AA", .color = 0x5500AA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Oxford Blue", .variant = "#000055", .color = 0x000055, .res = FONT_KEY_GOTHIC_14 },
    
    { .name = "Electric Ultramarine", .variant = "#5500FF", .color = 0x5500FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Liberty", .variant = "#5555AA", .color = 0x5555AA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Baby Blue Eyes", .variant = "#AAAAFF", .color = 0xAAAAFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Very Light Blue", .variant = "#5555FF", .color = 0x5555FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Blue", .variant = "#0000FF", .color = 0x0000FF, .res = FONT_KEY_GOTHIC_14 },    
    { .name = "Blue Moon", .variant = "#0055FF", .color = 0x0055FF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Duke Blue", .variant = "#0000AA", .color = 0x0000AA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Piction Blue", .variant = "#55AAFF", .color = 0x55AAFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Vivid Cerulean", .variant = "#00AAFF", .color = 0x00AAFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Cobalt Blue", .variant = "#0055AA", .color = 0x0055AA, .res = FONT_KEY_GOTHIC_14 },
    
    { .name = "Cadet Blue", .variant = "#55AAAA", .color = 0x55AAAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Tiffany Blue", .variant = "#00AAAA", .color = 0x00AAAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Cyan", .variant = "#00FFFF", .color = 0x00FFFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Electric Blue", .variant = "#55FFFF", .color = 0x55FFFF, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Celeste", .variant = "#AAFFFF", .color = 0xAAFFFF, .res = FONT_KEY_GOTHIC_14 },  
    { .name = "Medium Spring Green", .variant = "#00FFAA", .color = 0x00FFAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Jaeger Green", .variant = "#00AA55", .color = 0x00AA55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "May Green", .variant = "#55AA55", .color = 0x55AA55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Dark Green", .variant = "#005500", .color = 0x005500, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Army Green", .variant = "#555500", .color = 0x555500, .res = FONT_KEY_GOTHIC_14 },
    
    { .name = "Medium Aquamarine", .variant = "#55FFAA", .color = 0x55FFAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Malachite", .variant = "#00FF55", .color = 0x00FF55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Screaming Green", .variant = "#55FF55", .color = 0x55FF55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Mint Green", .variant = "#AAFFAA", .color = 0xAAFFAA, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Green", .variant = "#00FF00", .color = 0x00FF00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Bright Green", .variant = "#55FF00", .color = 0x55FF00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Spring Bud", .variant = "#AAFF00", .color = 0xAAFF00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Inchworm", .variant = "#AAFF55", .color = 0xAAFF55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Islamic Green", .variant = "#00AA00", .color = 0x00AA00, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Kelly Green", .variant = "#55AA00", .color = 0x55AA00, .res = FONT_KEY_GOTHIC_14 },
    
    { .name = "Brass", .variant = "#AAAA55", .color = 0xAAAA55, .res = FONT_KEY_GOTHIC_14 },
    { .name = "Limerick", .variant = "#AAAA00", .color = 0xAAAA00, .res = FONT_KEY_GOTHIC_14 },
};


static Window *s_main_window, *s_font_window;
static MenuLayer *s_menu_layer;
static TextLayer *s_text_layer, *s_font_name_layer, *s_font_variant_layer, *s_font_size_layer;

/* Store the index of the currently selected font and text message. */
static int s_current_font;
static int s_current_message;

/* Text buffer for the size required to display font and message */
static char s_size_text[256] = "GColor";

static uint16_t get_num_rows(struct MenuLayer* menu_layer, uint16_t section_index, void *callback_context) {
  return NUM_FONTS;
}

static void draw_row(GContext *ctx, const Layer *cell_layer, MenuIndex *cell_index, void *callback_context) {
  PebbleFont *font_array = (PebbleFont*) callback_context;
  PebbleFont *this_font = &font_array[cell_index->row];

  menu_cell_basic_draw(ctx, cell_layer, this_font->name, this_font->variant, NULL);
}

static void select_click(struct MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context) {
  s_current_font = cell_index->row;

  window_stack_push(s_font_window, true);
}

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);

  s_menu_layer = menu_layer_create(layer_get_bounds(window_layer));
  menu_layer_set_callbacks(s_menu_layer, pebble_fonts, (MenuLayerCallbacks) {
    .get_num_rows = get_num_rows,
    .draw_row = draw_row,
    .select_click = select_click
  });
  menu_layer_set_click_config_onto_window(s_menu_layer, window);

  layer_add_child(window_layer, menu_layer_get_layer(s_menu_layer));
}

static void main_window_unload(Window *window) {
  menu_layer_destroy(s_menu_layer);
}

static void show_selected_font_and_message() {
  PebbleFont *font = &pebble_fonts[s_current_font];

  // Update the font and text for the demo message
  text_layer_set_font(s_text_layer, fonts_get_system_font(font->res));
  
  text_layer_set_background_color(s_text_layer, GColorFromHEX(font->color));

  // Update the font name and font variant at the bottom of the screen
  text_layer_set_text(s_font_name_layer, font->name);
  text_layer_set_text(s_font_variant_layer, font->variant);

  text_layer_set_text(s_font_size_layer, s_size_text);
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  s_current_message++;
  if ((unsigned)s_current_message >= NUM_MESSAGES) {
    s_current_message = 0;
  }

  show_selected_font_and_message();
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  s_current_font--;
  if (s_current_font < 0) {
    s_current_font = NUM_FONTS - 1;
  }

  MenuIndex idx = menu_layer_get_selected_index(s_menu_layer);
  idx.row = s_current_font;
  menu_layer_set_selected_index(s_menu_layer, idx, MenuRowAlignCenter, false);

  show_selected_font_and_message();
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  s_current_font++;
  if ((unsigned)s_current_font >= NUM_FONTS) {
    s_current_font = 0;
  }

  MenuIndex idx = menu_layer_get_selected_index(s_menu_layer);
  idx.row = s_current_font;
  menu_layer_set_selected_index(s_menu_layer, idx, MenuRowAlignCenter, false);

  show_selected_font_and_message();
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler)select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler)up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler)down_click_handler);
}

static void font_window_load(Window *window) {
  // Define some event handlers for clicks
  window_set_click_config_provider(window, (ClickConfigProvider) click_config_provider);

  Layer *window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);

  // Arrange the three text layers on top of each other
  window_bounds.size.h -= PBL_IF_RECT_ELSE(60, 70);
  s_text_layer = text_layer_create(window_bounds);

  window_bounds.origin.x = 2;
  window_bounds.size.w -= 4;

  window_bounds.origin.y += window_bounds.size.h;
  window_bounds.size.h = PBL_IF_RECT_ELSE(20, 16);

  GFont text_alignment = fonts_get_system_font(PBL_IF_RECT_ELSE(FONT_KEY_GOTHIC_18_BOLD, FONT_KEY_GOTHIC_18_BOLD));
  GFont text_alignment_size = fonts_get_system_font(PBL_IF_RECT_ELSE(FONT_KEY_GOTHIC_14, FONT_KEY_GOTHIC_14));

  const uint8_t text_separation = 2;

  s_font_size_layer = text_layer_create(window_bounds);
  text_layer_set_font(s_font_size_layer, text_alignment_size);

  window_bounds.origin.y += window_bounds.size.h - text_separation;

  s_font_name_layer = text_layer_create(window_bounds);
  text_layer_set_font(s_font_name_layer, text_alignment_size);

  window_bounds.origin.y += window_bounds.size.h - text_separation;

  s_font_variant_layer = text_layer_create(window_bounds);
  text_layer_set_font(s_font_variant_layer, text_alignment);

  // Add the child layer to the current window (s_font_window)
  layer_add_child(window_layer, text_layer_get_layer(s_text_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_font_name_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_font_variant_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_font_size_layer));
#ifdef PBL_ROUND
  text_layer_enable_screen_text_flow_and_paging(s_text_layer, 5);
  text_layer_enable_screen_text_flow_and_paging(s_font_size_layer, 5);
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  text_layer_set_text_alignment(s_font_name_layer, GTextAlignmentCenter);
  text_layer_set_text_alignment(s_font_variant_layer, GTextAlignmentCenter);
  text_layer_set_text_alignment(s_font_size_layer, GTextAlignmentCenter);
#endif
  // Finally, update the text and font in the layers
  show_selected_font_and_message();
}

static void font_window_unload(Window *window) {
  layer_remove_child_layers(window_get_root_layer(window));

  text_layer_destroy(s_text_layer);
  text_layer_destroy(s_font_name_layer);
  text_layer_destroy(s_font_variant_layer);
}

static void init() {
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  s_font_window = window_create();
  window_set_window_handlers(s_font_window, (WindowHandlers) {
    .load = font_window_load,
    .unload = font_window_unload
  });

  window_stack_push(s_main_window, true);
}

static void deinit() {
  window_destroy(s_font_window);
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
