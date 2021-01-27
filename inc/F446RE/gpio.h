#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>
#include "mini_inttypes.h"
#include "io_memory_map.h"
#include "trap_error.h"

#define PINS_PER_GPIO 16

typedef enum {
    GPIO_OK,
    GPIO_ERROR_INVALID_PORT
#ifdef TRAP_ERROR_GPIO
        = TRAP_ERROR_GPIO
#endif
    ,
    GPIO_ERROR_INVALID_PIN,
    GPIO_ERROR_INVALID_MODE,
}GPIO_Error;

typedef enum {
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
}GPIO_Port;

/// a pin is defined by a port and a pin value 0-{PINS_PER_GPIO-1}.
/// @error GPIO_ERROR_INVALID_PIN if pin is not within 0-{PINS_PER_GPIO-1}
typedef struct {
    GPIO_Port port;
    u8 pin;
}GPIO_Pin;

/// sets the clock for GPIO{`port`} to `en`
/// @param[in]  port   which GPIO to enable the block for
/// @param[in]  en     set the GPIO clock to `en`
/// @return GPIO_OK
///      || GPIO_ERROR_INVALID_PORT
GPIO_Error gpio_clock_enable(GPIO_Port port, bool en);

/// selects a GPIO by `port` and returns that in `out`
/// @param[out] out     selected GPIO{`port`}.
///                     Not modified if GPIO_ERROR_INVALID_PORT
/// @param[in]  port    the port to select by
/// @return GPIO_OK
///      || GPIO_ERROR_INVALID_PORT
GPIO_Error gpio_from_port(volatile IO_GPIO_t **out, GPIO_Port port);

/// sets the GPIO `mode` for the specified `pin`
/// @param[in]  pin     the GPIO pin to configure. 
///                     Use the pin definitions like PIN_A0
/// @param[in]  mode    the GPIO mode to set the pin to
/// @return GPIO_OK
///      || GPIO_ERROR_INVALID_PORT
///      || GPIO_ERROR_INVALID_PIN
///      || GPIO_ERROR_INVALID_MODE
GPIO_Error gpio_set_mode(const GPIO_Pin *pin, IO_GPIO_MODE mode);

/// Sets `pin` to 1
/// Expects mode to already be set
/// @param[in]  pin     The pin to output. Ex. PIN_A5
/// @return GPIO_OK
///      || GPIO_ERROR_INVALID_PORT
///      || GPIO_ERROR_INVALID_PIN
GPIO_Error gpio_output_high(const GPIO_Pin *pin);

/// Sets `pin` to 0
/// Expects mode to already be set
/// @param[in]  pin     The pin to output. Ex. PIN_A5
/// @return GPIO_OK
///      || GPIO_ERROR_INVALID_PORT
///      || GPIO_ERROR_INVALID_PIN
GPIO_Error gpio_output_low(const GPIO_Pin *pin);

/// Gets value of `pin` and outputs it to `val`
/// Expects mode to already be set
/// @param[in]  pin     The pin to input. Ex. PIN_B2
/// @param[out] val     Read value is stored in val
/// @return GPIO_OK
///      || GPIO_ERROR_INVALID_PORT
///      || GPIO_ERROR_INVALID_PIN
GPIO_Error gpio_input(const GPIO_Pin *pin, int *val);

// all valid pins
#define PIN_A0 ((GPIO_Pin) {GPIO_PORT_A, 0})
#define PIN_A1 ((GPIO_Pin) {GPIO_PORT_A, 1})
#define PIN_A2 ((GPIO_Pin) {GPIO_PORT_A, 2})
#define PIN_A3 ((GPIO_Pin) {GPIO_PORT_A, 3})
#define PIN_A4 ((GPIO_Pin) {GPIO_PORT_A, 4})
#define PIN_A5 ((GPIO_Pin) {GPIO_PORT_A, 5})
#define PIN_A6 ((GPIO_Pin) {GPIO_PORT_A, 6})
#define PIN_A7 ((GPIO_Pin) {GPIO_PORT_A, 7})
#define PIN_A8 ((GPIO_Pin) {GPIO_PORT_A, 8})
#define PIN_A9 ((GPIO_Pin) {GPIO_PORT_A, 9})
#define PIN_A10 ((GPIO_Pin) {GPIO_PORT_A, 10})
#define PIN_A11 ((GPIO_Pin) {GPIO_PORT_A, 11})
#define PIN_A12 ((GPIO_Pin) {GPIO_PORT_A, 12})
#define PIN_A13 ((GPIO_Pin) {GPIO_PORT_A, 13})
#define PIN_A14 ((GPIO_Pin) {GPIO_PORT_A, 14})
#define PIN_A15 ((GPIO_Pin) {GPIO_PORT_A, 15})
#define PIN_B0 ((GPIO_Pin) {GPIO_PORT_B, 0})
#define PIN_B1 ((GPIO_Pin) {GPIO_PORT_B, 1})
#define PIN_B2 ((GPIO_Pin) {GPIO_PORT_B, 2})
#define PIN_B3 ((GPIO_Pin) {GPIO_PORT_B, 3})
#define PIN_B4 ((GPIO_Pin) {GPIO_PORT_B, 4})
#define PIN_B5 ((GPIO_Pin) {GPIO_PORT_B, 5})
#define PIN_B6 ((GPIO_Pin) {GPIO_PORT_B, 6})
#define PIN_B7 ((GPIO_Pin) {GPIO_PORT_B, 7})
#define PIN_B8 ((GPIO_Pin) {GPIO_PORT_B, 8})
#define PIN_B9 ((GPIO_Pin) {GPIO_PORT_B, 9})
#define PIN_B10 ((GPIO_Pin) {GPIO_PORT_B, 10})
#define PIN_B11 ((GPIO_Pin) {GPIO_PORT_B, 11})
#define PIN_B12 ((GPIO_Pin) {GPIO_PORT_B, 12})
#define PIN_B13 ((GPIO_Pin) {GPIO_PORT_B, 13})
#define PIN_B14 ((GPIO_Pin) {GPIO_PORT_B, 14})
#define PIN_B15 ((GPIO_Pin) {GPIO_PORT_B, 15})
#define PIN_C0 ((GPIO_Pin) {GPIO_PORT_C, 0})
#define PIN_C1 ((GPIO_Pin) {GPIO_PORT_C, 1})
#define PIN_C2 ((GPIO_Pin) {GPIO_PORT_C, 2})
#define PIN_C3 ((GPIO_Pin) {GPIO_PORT_C, 3})
#define PIN_C4 ((GPIO_Pin) {GPIO_PORT_C, 4})
#define PIN_C5 ((GPIO_Pin) {GPIO_PORT_C, 5})
#define PIN_C6 ((GPIO_Pin) {GPIO_PORT_C, 6})
#define PIN_C7 ((GPIO_Pin) {GPIO_PORT_C, 7})
#define PIN_C8 ((GPIO_Pin) {GPIO_PORT_C, 8})
#define PIN_C9 ((GPIO_Pin) {GPIO_PORT_C, 9})
#define PIN_C10 ((GPIO_Pin) {GPIO_PORT_C, 10})
#define PIN_C11 ((GPIO_Pin) {GPIO_PORT_C, 11})
#define PIN_C12 ((GPIO_Pin) {GPIO_PORT_C, 12})
#define PIN_C13 ((GPIO_Pin) {GPIO_PORT_C, 13})
#define PIN_C14 ((GPIO_Pin) {GPIO_PORT_C, 14})
#define PIN_C15 ((GPIO_Pin) {GPIO_PORT_C, 15})
#define PIN_D0 ((GPIO_Pin) {GPIO_PORT_D, 0})
#define PIN_D1 ((GPIO_Pin) {GPIO_PORT_D, 1})
#define PIN_D2 ((GPIO_Pin) {GPIO_PORT_D, 2})
#define PIN_D3 ((GPIO_Pin) {GPIO_PORT_D, 3})
#define PIN_D4 ((GPIO_Pin) {GPIO_PORT_D, 4})
#define PIN_D5 ((GPIO_Pin) {GPIO_PORT_D, 5})
#define PIN_D6 ((GPIO_Pin) {GPIO_PORT_D, 6})
#define PIN_D7 ((GPIO_Pin) {GPIO_PORT_D, 7})
#define PIN_D8 ((GPIO_Pin) {GPIO_PORT_D, 8})
#define PIN_D9 ((GPIO_Pin) {GPIO_PORT_D, 9})
#define PIN_D10 ((GPIO_Pin) {GPIO_PORT_D, 10})
#define PIN_D11 ((GPIO_Pin) {GPIO_PORT_D, 11})
#define PIN_D12 ((GPIO_Pin) {GPIO_PORT_D, 12})
#define PIN_D13 ((GPIO_Pin) {GPIO_PORT_D, 13})
#define PIN_D14 ((GPIO_Pin) {GPIO_PORT_D, 14})
#define PIN_D15 ((GPIO_Pin) {GPIO_PORT_D, 15})
#define PIN_E0 ((GPIO_Pin) {GPIO_PORT_E, 0})
#define PIN_E1 ((GPIO_Pin) {GPIO_PORT_E, 1})
#define PIN_E2 ((GPIO_Pin) {GPIO_PORT_E, 2})
#define PIN_E3 ((GPIO_Pin) {GPIO_PORT_E, 3})
#define PIN_E4 ((GPIO_Pin) {GPIO_PORT_E, 4})
#define PIN_E5 ((GPIO_Pin) {GPIO_PORT_E, 5})
#define PIN_E6 ((GPIO_Pin) {GPIO_PORT_E, 6})
#define PIN_E7 ((GPIO_Pin) {GPIO_PORT_E, 7})
#define PIN_E8 ((GPIO_Pin) {GPIO_PORT_E, 8})
#define PIN_E9 ((GPIO_Pin) {GPIO_PORT_E, 9})
#define PIN_E10 ((GPIO_Pin) {GPIO_PORT_E, 10})
#define PIN_E11 ((GPIO_Pin) {GPIO_PORT_E, 11})
#define PIN_E12 ((GPIO_Pin) {GPIO_PORT_E, 12})
#define PIN_E13 ((GPIO_Pin) {GPIO_PORT_E, 13})
#define PIN_E14 ((GPIO_Pin) {GPIO_PORT_E, 14})
#define PIN_E15 ((GPIO_Pin) {GPIO_PORT_E, 15})
#define PIN_F0 ((GPIO_Pin) {GPIO_PORT_F, 0})
#define PIN_F1 ((GPIO_Pin) {GPIO_PORT_F, 1})
#define PIN_F2 ((GPIO_Pin) {GPIO_PORT_F, 2})
#define PIN_F3 ((GPIO_Pin) {GPIO_PORT_F, 3})
#define PIN_F4 ((GPIO_Pin) {GPIO_PORT_F, 4})
#define PIN_F5 ((GPIO_Pin) {GPIO_PORT_F, 5})
#define PIN_F6 ((GPIO_Pin) {GPIO_PORT_F, 6})
#define PIN_F7 ((GPIO_Pin) {GPIO_PORT_F, 7})
#define PIN_F8 ((GPIO_Pin) {GPIO_PORT_F, 8})
#define PIN_F9 ((GPIO_Pin) {GPIO_PORT_F, 9})
#define PIN_F10 ((GPIO_Pin) {GPIO_PORT_F, 10})
#define PIN_F11 ((GPIO_Pin) {GPIO_PORT_F, 11})
#define PIN_F12 ((GPIO_Pin) {GPIO_PORT_F, 12})
#define PIN_F13 ((GPIO_Pin) {GPIO_PORT_F, 13})
#define PIN_F14 ((GPIO_Pin) {GPIO_PORT_F, 14})
#define PIN_F15 ((GPIO_Pin) {GPIO_PORT_F, 15})
#define PIN_G0 ((GPIO_Pin) {GPIO_PORT_G, 0})
#define PIN_G1 ((GPIO_Pin) {GPIO_PORT_G, 1})
#define PIN_G2 ((GPIO_Pin) {GPIO_PORT_G, 2})
#define PIN_G3 ((GPIO_Pin) {GPIO_PORT_G, 3})
#define PIN_G4 ((GPIO_Pin) {GPIO_PORT_G, 4})
#define PIN_G5 ((GPIO_Pin) {GPIO_PORT_G, 5})
#define PIN_G6 ((GPIO_Pin) {GPIO_PORT_G, 6})
#define PIN_G7 ((GPIO_Pin) {GPIO_PORT_G, 7})
#define PIN_G8 ((GPIO_Pin) {GPIO_PORT_G, 8})
#define PIN_G9 ((GPIO_Pin) {GPIO_PORT_G, 9})
#define PIN_G10 ((GPIO_Pin) {GPIO_PORT_G, 10})
#define PIN_G11 ((GPIO_Pin) {GPIO_PORT_G, 11})
#define PIN_G12 ((GPIO_Pin) {GPIO_PORT_G, 12})
#define PIN_G13 ((GPIO_Pin) {GPIO_PORT_G, 13})
#define PIN_G14 ((GPIO_Pin) {GPIO_PORT_G, 14})
#define PIN_G15 ((GPIO_Pin) {GPIO_PORT_G, 15})
#define PIN_H0 ((GPIO_Pin) {GPIO_PORT_H, 0})
#define PIN_H1 ((GPIO_Pin) {GPIO_PORT_H, 1})
#define PIN_H2 ((GPIO_Pin) {GPIO_PORT_H, 2})
#define PIN_H3 ((GPIO_Pin) {GPIO_PORT_H, 3})
#define PIN_H4 ((GPIO_Pin) {GPIO_PORT_H, 4})
#define PIN_H5 ((GPIO_Pin) {GPIO_PORT_H, 5})
#define PIN_H6 ((GPIO_Pin) {GPIO_PORT_H, 6})
#define PIN_H7 ((GPIO_Pin) {GPIO_PORT_H, 7})
#define PIN_H8 ((GPIO_Pin) {GPIO_PORT_H, 8})
#define PIN_H9 ((GPIO_Pin) {GPIO_PORT_H, 9})
#define PIN_H10 ((GPIO_Pin) {GPIO_PORT_H, 10})
#define PIN_H11 ((GPIO_Pin) {GPIO_PORT_H, 11})
#define PIN_H12 ((GPIO_Pin) {GPIO_PORT_H, 12})
#define PIN_H13 ((GPIO_Pin) {GPIO_PORT_H, 13})
#define PIN_H14 ((GPIO_Pin) {GPIO_PORT_H, 14})
#define PIN_H15 ((GPIO_Pin) {GPIO_PORT_H, 15})

#endif // GPIO_H
