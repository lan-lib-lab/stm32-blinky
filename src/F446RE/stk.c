#include "F446RE/stk.h"
#include "mini_inttypes.h"

inline void stk_enable_clock(bool en) {
    IO_STK->CTRL &= ~(IO_STK_CTRL_ENABLE);
    IO_STK->CTRL |= (en << IO_STK_CTRL_ENABLE_F);
}

inline void stk_counter_start(bool prescale) {
  IO_STK->CTRL |= IO_STK_CTRL_ENABLE | (prescale<<IO_STK_CTRL_CLKSOURCE_F);
}

inline void stk_counter_stop() {
  IO_STK->CTRL &= ~IO_STK_CTRL_ENABLE;
}

inline void stk_set_load(u32 val) {
  IO_STK->LOAD = val & IO_STK_LOAD_RELOAD;
}

bool stk_set_load_ms(u32 t_ms) {
  const int clock_ticks = (IO_STK->CTRL & IO_STK_CTRL_CLKSOURCE) ?
      16000 : 2000;

  if (t_ms > IO_STK_LOAD_RELOAD / clock_ticks)
    return false;

  IO_STK->LOAD = clock_ticks * t_ms;
  return true;
}

bool stk_set_load_us(u32 t_us) {
  int clock_ticks = (IO_STK->CTRL & IO_STK_CTRL_CLKSOURCE) ?
      16 : 2;

  if (t_us > IO_STK_LOAD_RELOAD / clock_ticks)
    return false;

  IO_STK->LOAD = clock_ticks * t_us;
  return true;
}

inline bool stk_counter_zero() {
  return ((IO_STK->CTRL & IO_STK_CTRL_COUNTFLAG) == 0)
    && (IO_STK->CTRL & IO_STK_CTRL_ENABLE);
}

void stk_delay_ms(int t_ms) {
  // ensure counter is off
  IO_STK->CTRL &= ~(IO_STK_CTRL_ENABLE);

  for (u32 i=0; i<t_ms; i++) {
    // load 1ms, or 16000 (16E6 clock)
    IO_STK->LOAD = 16000;

    // turn on counter (with no clock source division)
    IO_STK->CTRL |= IO_STK_CTRL_ENABLE | IO_STK_CTRL_CLKSOURCE;

    // poll until timer is done
    while ((IO_STK->CTRL & IO_STK_CTRL_COUNTFLAG) == 0);

    // turn off counter
    IO_STK->CTRL &= ~(IO_STK_CTRL_ENABLE);
  }
}

void stk_delay_us(int t_us) {
  // ensure counter is off
  IO_STK->CTRL &= ~(IO_STK_CTRL_ENABLE);

  for (u32 i=0; i<t_us; i++) {
    // load 1ms, or 16 (16E6 clock)
    IO_STK->LOAD = 16;

    // turn on counter (with no clock source division)
    IO_STK->CTRL |= IO_STK_CTRL_ENABLE | IO_STK_CTRL_CLKSOURCE;

    // poll until timer is done
    while ((IO_STK->CTRL & IO_STK_CTRL_COUNTFLAG) == 0);

    // turn off counter
    IO_STK->CTRL &= ~(IO_STK_CTRL_ENABLE);
  }
}
