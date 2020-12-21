#ifndef IO_MEMORY_MAP_H
#define IO_MEMORY_MAP_H

#include "mini_inttypes.h"
#include "io_memory_map/rcc.h"
#include "io_memory_map/gpio.h"
#include "io_memory_map/stk.h"

#define IO_GPIO_A ((volatile IO_GPIO_t* const)     0x40020000)
#define IO_GPIO_B ((volatile IO_GPIO_t* const)     0x40020400)
#define IO_GPIO_C ((volatile IO_GPIO_t* const)     0x40020800)
#define IO_GPIO_D ((volatile IO_GPIO_t* const)     0x40020C00)
#define IO_GPIO_E ((volatile IO_GPIO_t* const)     0x40021000)
#define IO_GPIO_F ((volatile IO_GPIO_t* const)     0x40021400)
#define IO_GPIO_G ((volatile IO_GPIO_t* const)     0x40021800)
#define IO_GPIO_H ((volatile IO_GPIO_t* const)     0x40021C00)
#define IO_RCC    ((volatile IO_RCC_t* const)      0x40023800)
#define IO_STK    ((volatile IO_STK_t* const)      0xE000E010)

#endif // IO_MEMORY_MAP_H
