//#include "config.h"

#include "quantum.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
	// Rotate OLED to fit
    if (!is_keyboard_left()) {
       return OLED_ROTATION_180;
	}
		return rotation;
}

void render_logo(void) {
	// QMK Logo
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
	
	// Create OLED content;;
    oled_write_P(PSTR("RefleXion X65"), false);
	oled_write_P(PSTR("\n"), false);

    // Print current layer
    //oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base Layer\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Numeric Layer\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Function Layer\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Settings Layer\n"), false);
            break;
        default:
            oled_write_P(PSTR("Layer Error"), false);
    }
	
	// Display autoshift
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("Capslock"), led_usb_state.caps_lock);
	oled_write_P(PSTR(" - "), false);
	bool autoshift = get_autoshift_state();
	//oled_write_P(PSTR("\n"), false);
	oled_write_P(PSTR("Auto-Shift"), autoshift);
	//oled_write_P(PSTR("\n"), false);

}

bool oled_task_kb(void) {
	// Render the OLED
	if (is_keyboard_master()) {
		print_status_narrow();
    } else {
		print_status_narrow();
        //render_logo();
		//oled_scroll_left();
    }
	return false;
}
#endif

layer_state_t layer_state_set_kb(layer_state_t state) {
	// Allow switching to the 'hidden' layer
   return update_tri_layer_state(state, 1, 2, 3);
}