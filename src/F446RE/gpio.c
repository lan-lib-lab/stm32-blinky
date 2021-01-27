#include <stdlib.h>
#include <stdbool.h>
#include "F446RE/gpio.h"
#include "F446RE/io_memory_map.h"
#include "F446RE/io_memory_map/gpio.h"

// forward define
GPIO_Error _validate_and_get_gpio(const GPIO_Pin *pin, volatile IO_GPIO_t **gpiox);

GPIO_Error gpio_clock_enable(GPIO_Port port, bool en) {
    #define SET_GPIO_CLOCK(bitfield, en) do{\
        IO_RCC->AHB1ENR &= ~(bitfield);\
        IO_RCC->AHB1ENR |= (en) ? (bitfield) : 0;\
    }while(0)

    switch (port) {
        case GPIO_PORT_A:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOAEN, en);
            break;
        case GPIO_PORT_B:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOBEN, en);
            break;
        case GPIO_PORT_C:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOCEN, en);
            break;
        case GPIO_PORT_D:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIODEN, en);
            break;
        case GPIO_PORT_E:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOEEN, en);
            break;
        case GPIO_PORT_F:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOFEN, en);
            break;
        case GPIO_PORT_G:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOGEN, en);
            break;
        case GPIO_PORT_H:
            SET_GPIO_CLOCK(IO_RCC_AHB1ENR_GPIOHEN, en);
            break;
        default:
            return GPIO_ERROR_INVALID_PORT;
    }

    return GPIO_OK;
}

GPIO_Error gpio_from_port(volatile IO_GPIO_t **out, GPIO_Port port) {
    switch (port) {
        case GPIO_PORT_A:
            *out = IO_GPIO_A;
            break;
        case GPIO_PORT_B:
            *out = IO_GPIO_B;
            break;
        case GPIO_PORT_C:
            *out = IO_GPIO_C;
            break;
        case GPIO_PORT_D:
            *out = IO_GPIO_D;
            break;
        case GPIO_PORT_E:
            *out = IO_GPIO_E;
            break;
        case GPIO_PORT_F:
            *out = IO_GPIO_F;
            break;
        case GPIO_PORT_G:
            *out = IO_GPIO_G;
            break;
        case GPIO_PORT_H:
            *out = IO_GPIO_H;
            break;
        default:
            return GPIO_ERROR_INVALID_PORT;
    }

    return GPIO_OK;
}

GPIO_Error gpio_set_mode(const GPIO_Pin *pin, IO_GPIO_MODE mode) {
    if (mode > IO_GPIO_MODE_ANALOG) 
      return GPIO_ERROR_INVALID_MODE;
    if (pin->pin > PINS_PER_GPIO-1) 
      return GPIO_ERROR_INVALID_PIN;

    volatile IO_GPIO_t * gpiox = NULL;
    GPIO_Error status;

    if ((status = gpio_from_port(&gpiox, pin->port)) != GPIO_OK) 
      return status;

    gpiox->MODER &= ~(0b11 << (2*(pin->pin)));
    gpiox->MODER |= (mode) << (2*(pin->pin));

    return GPIO_OK;
}

GPIO_Error gpio_output_high(const GPIO_Pin *pin) {
    volatile IO_GPIO_t *gpiox = NULL;
    GPIO_Error status;
    if ((status = _validate_and_get_gpio(pin, &gpiox)) != GPIO_OK)
      return status;

    gpiox->ODR |= (1 << pin->pin);
    return GPIO_OK;
}

GPIO_Error gpio_output_low(const GPIO_Pin *pin) {
    volatile IO_GPIO_t *gpiox = NULL;
    GPIO_Error status;
    if ((status = _validate_and_get_gpio(pin, &gpiox)) != GPIO_OK)
      return status;

    gpiox->ODR &= ~(1 << pin->pin);
    return GPIO_OK;
}

GPIO_Error gpio_input(const GPIO_Pin *pin, int *val) {
    volatile IO_GPIO_t *gpiox = NULL;
    GPIO_Error status;
    if ((status = _validate_and_get_gpio(pin, &gpiox)) != GPIO_OK)
      return status;

    *val = (gpiox->IDR & (1 << pin->pin)) != 0;

    return GPIO_OK;
}

/// validates that the pin is within range and that
/// the port is valid. 
/// Writes to `gpiox` if GPIO_OK
GPIO_Error _validate_and_get_gpio(const GPIO_Pin *pin, volatile IO_GPIO_t **gpiox) {
    if (pin->pin > PINS_PER_GPIO-1) 
      return GPIO_ERROR_INVALID_PIN;

    GPIO_Error status;

    if ((status = gpio_from_port(gpiox, pin->port)) != GPIO_OK) 
      return status;

    return GPIO_OK;
}
