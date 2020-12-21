#ifndef F446RE_IO_MEMORY_MAP_GPIO_H
#define F446RE_IO_MEMORY_MAP_GPIO_H

#include "mini_inttypes.h"

typedef struct {
   u32 MODER;
   u32 OTYPER;
   u32 OSPEEDER;
   u32 PUPDR;
   u32 IDR;
   u32 ODR;
   u32 BSRR;
   u32 LCKR;
   u32 AFRL;
   u32 AFRH;
}IO_GPIO_t;

typedef enum {
    IO_GPIO_MODE_INPUT,
    IO_GPIO_MODE_OUTPUT,
    IO_GPIO_MODE_ALTERNATE_FUNCTION,
    IO_GPIO_MODE_ANALOG,
}IO_GPIO_MODE;


#endif // F446RE_IO_MEMORY_MAP_GPIO_H
