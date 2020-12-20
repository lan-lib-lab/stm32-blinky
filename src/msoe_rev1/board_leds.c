#include "msoe_rev1/board_leds.h"
#include "mini_inttypes.h"

// GPIO pins routed for LEDs
static GPIO_Pin board_leds_pins[] = {
  PIN_A7, PIN_A8, PIN_A9, PIN_A10, PIN_A11,
  PIN_B8, PIN_B9, PIN_B10, PIN_B12, PIN_B13,
};

BoardLEDs_Error board_leds_init(led_bitset_t leds) {
    GPIO_Error gpio_status;

    // ensure that the flags describe no more than 10 bits corresponding to 10 LEDs
    if (leds > 0x3FF) 
      return BOARD_LEDS_ERROR_OUT_OF_BOUNDS;

    // init each selected LED
    for (int bit=0; bit<10; bit++) {
        if (leds & (1<<bit)) {
            gpio_status = gpio_clock_enable(board_leds_pins[bit].port, /*en*/ true);
            if (gpio_status != GPIO_OK) 
              return BOARD_LEDS_ERROR_INTERNAL_GPIO;

            gpio_status = gpio_set_mode(&board_leds_pins[bit], IO_GPIO_MODE_OUTPUT);
            if (gpio_status != GPIO_OK) 
              return BOARD_LEDS_ERROR_INTERNAL_GPIO;

            volatile IO_GPIO_t *led_gpio;
            if (gpio_from_port(&led_gpio, board_leds_pins[bit].port) != GPIO_OK) 
              return BOARD_LEDS_ERROR_INTERNAL_GPIO;
        }
    }
    
    return BOARD_LEDS_OK;
}


BoardLEDs_Error board_leds_set(led_bitset_t leds) {
    GPIO_Error gpio_status;

    // ensure that the flags describe no more than 10 bits corresponding to 10 LEDs
    if (leds > 0x3FF) 
      return BOARD_LEDS_ERROR_OUT_OF_BOUNDS;

    // init each selected LED
    for (int bit=0; bit<10; bit++) {
        if (leds & (1<<bit)) {
            volatile IO_GPIO_t *led_gpio;
            gpio_status = gpio_from_port(&led_gpio, board_leds_pins[bit].port);
            if (gpio_status != GPIO_OK) 
              return BOARD_LEDS_ERROR_INTERNAL_GPIO;

            led_gpio->ODR |= (1<<board_leds_pins[bit].pin);
        }
    }
    
    return BOARD_LEDS_OK;
}


BoardLEDs_Error board_leds_clear(led_bitset_t leds) {
    GPIO_Error gpio_status;

    // ensure that the flags describe no more than 10 bits corresponding to 10 LEDs
    if (leds > 0x3FF) 
      return BOARD_LEDS_ERROR_OUT_OF_BOUNDS;

    // init each selected LED
    for (int bit=0; bit<10; bit++) {
        if (leds & (1<<bit)) {
            volatile IO_GPIO_t *led_gpio;
            gpio_status = gpio_from_port(&led_gpio, board_leds_pins[bit].port);
            if (gpio_status != GPIO_OK) 
              return BOARD_LEDS_ERROR_INTERNAL_GPIO;

            led_gpio->ODR &= ~(1<<board_leds_pins[bit].pin);
        }
    }
    
    return BOARD_LEDS_OK;
}
