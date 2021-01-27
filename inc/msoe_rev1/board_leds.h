#ifndef BOARD_LEDS_H
#define BOARD_LEDS_H

#include "F446RE/gpio.h"
#include "trap_error.h"

#define USER_BUTTON PIN_C13

typedef enum {
    BOARD_LEDS_OK,
    BOARD_LEDS_ERROR_OUT_OF_BOUNDS,
    BOARD_LEDS_ERROR_INTERNAL_GPIO, 
}BoardLEDs_Error;

typedef u16 led_bitset_t;

/// enables the clock and sets the mode to OUTPUT for each led flag in `leds`. 
/// @param leds   represents a bitset of witdh 10 -- any value used over 0x3FF 
///               (10 enabled bits) results in BOARD_LEDS_ERROR_OUT_OF_BOUNDS
/// @return BOARD_LEDS_OK
///      || BOARD_LEDS_OUT_OF_BOUNDS
///      || BOARD_LEDS_ERROR_INTERNAL_GPIO
BoardLEDs_Error board_leds_init(led_bitset_t leds);

/// sets each specified led in $leds to HIGH.
/// @param leds   represents a bitset of witdh 10 -- any value used over 0x3FF 
//                (10 enabled bits) will result in an error
/// @return BOARD_LEDS_OK
///      || BOARD_LEDS_OUT_OF_BOUNDS
///      || BOARD_LEDS_ERROR_INTERNAL_GPIO
BoardLEDs_Error board_leds_set(led_bitset_t leds);

// sets each specified led in $leds to LOW
/// param leds: represents a bitset of witdh 10 -- any value used over 0x3FF (10 enabled bits) will result in an error
/// @return BOARD_LEDS_OK
///      || BOARD_LEDS_OUT_OF_BOUNDS
///      || BOARD_LEDS_ERROR_INTERNAL_GPIO
BoardLEDs_Error board_leds_clear(led_bitset_t leds);

/// init the user button so that it can be checked
void user_button_init(void);

/// check if the user button is currently active
bool user_button_pushed(void);

/// poll until the user button is pressed
void wait_push_user_button(void);

#endif // BOARD_LEDS_H

