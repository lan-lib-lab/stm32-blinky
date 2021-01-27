#ifndef STK_H
#define STK_H


#include <stdbool.h>
#include "F446RE/io_memory_map.h"

#define STK_SYS_CLOCK 16000000

#define STK_TICKS_PER_SECOND 16000000

/// enables the clock and starts the counter at frequency specified by `prescale`.
/// this sets the counter to MAX so it counts down to 0 from there.
/// if `prescale`, divide the clock by 8
void stk_init(bool prescale);

void stk_enable_clock(bool en);

/// sets whether to prescale the clock or not
void stk_set_prescale(bool prescale);

/// load must be no greater than IO_STK_LOAD_RELOAD
void stk_set_load(u32 val);

/// sets load to `t_ms` in milliseconds according to clock source
bool stk_set_load_ms(u32 t_ms);

/// sets load to `t_us` in microseconds accoridng to clock source
bool stk_set_load_us(u32 t_us);

void stk_counter_start(bool prescale);

/// disables the counter
void stk_counter_stop();

/// checks if the timer reached zero and that it is
/// enabled
bool stk_counter_zero();

/// returns the value of the current tick counter
u32 stk_tick_current();

/// checks if the current tick is past the specified `tick`
bool stk_tick_expired(u32 tick);

/// returns a tick that is `t_ms` milliseconds ahead of `tick`.
/// can be used with `stk_tick_expired()` to tell if the specified time has elapsed
u32 stk_tick_add_ms(u32 tick, int t_ms);

/// returns a tick that is `t_us` microseconds ahead of `tick`
/// can be used with `stk_tick_expired()` to tell if the specified time has elapsed
u32 stk_tick_add_us(u32 tick, int t_us);

/// polls until `t_ms` milliseconds has elapsed
void stk_delay_ms(int t_ms);

/// polls until `t_us` microseconds has elapsed
void stk_delay_us(int t_us);

#endif // STK_H

