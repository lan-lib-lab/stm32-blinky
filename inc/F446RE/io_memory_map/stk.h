/**
 * Flags and registers for the SysTick timer
 * See PM0214 programming manual section 4.5
 */

#ifndef IO_MEMORY_MAP_STK_H
#define IO_MEMORY_MAP_STK_H

#include "mini_inttypes.h"

typedef struct {
  u32 CTRL;
  u32 LOAD;
  u32 VAL;
  u32 CALIB;
} IO_STK_t;

#define IO_STK_CTRL_ENABLE          (0x1<<0)  
#define IO_STK_CTRL_TICKINT         (0x1<<1)  
#define IO_STK_CTRL_CLKSOURCE       (0x1<<2)  
#define IO_STK_CTRL_RESERVED03      (0x1FFF<<3)
#define IO_STK_CTRL_COUNTFLAG       (0x1<<16) 
#define IO_STK_CTRL_RESERVED017     (0x7FFF<<17)
#define IO_STK_CTRL_ENABLE_F        0
#define IO_STK_CTRL_TICKINT_F       1
#define IO_STK_CTRL_CLKSOURCE_F     2
#define IO_STK_CTRL_COUNTFLAG_F     16

#define IO_STK_LOAD_RELOAD          (0xFFFFFF<<0)
#define IO_STK_LOAD_RESERVED24      (0xFF<<24)
#define IO_STK_LOAD_RELOAD_F        0

#define IO_STK_VAL_CURRENT          (0xFFFFFF<<0)
#define IO_STK_VAL_RESERVED24       (0xFF<<24)
#define IO_STK_VAL_CURRENT_F        0

#define IO_STK_CALIB_TENMS          (0xFFFFFF<<0)
#define IO_STK_CALIB_RESERVED24     (0x3F<<24)
#define IO_STK_CALIB_SKEW           (0x1<<30)
#define IO_STK_CALIB_NOREF          (0x1<<31)
#define IO_STK_CALIB_TENMS_F        0
#define IO_STK_CALIB_SKEW_F         30
#define IO_STK_CALIB_NOREF_F        31

#endif // IO_MEMORY_MAP_STK_H
