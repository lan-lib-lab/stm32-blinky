#ifndef STK_H
#define STK_H

#include <stdbool.h>
#include "F446RE/io_memory_map.h"

inline void stk_enable_clock(bool en);

/// load must be no greater than IO_STK_LOAD_RELOAD
inline void stk_set_load(u32 val);

/// sets load to `t_ms` in milliseconds according to clock source
bool stk_set_load_ms(u32 t_ms);

/// sets load to `t_us` in microseconds accoridng to clock source
bool stk_set_load_us(u32 t_us);

inline void stk_counter_start(bool prescale);

/// disables the counter
inline void stk_counter_stop();

/// checks if the timer reached zero and that it is
/// enabled
inline bool stk_counter_zero();


/// sets the STK timer to tick `t_ms` milliseconds,
/// polling until the counter reaches zero
/// originally written by Dr. Livingston
void stk_delay_ms(int t_ms);

/// sets the STK timer to tick `t_us` microseconds,
/// polling until the counter reaches zero
/// originally written by Dr. Livingston
void stk_delay_us(int t_us);

#endif // STK_H

