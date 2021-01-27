#include "F446RE/stk.h"
#include "mini_inttypes.h"

int _msToTicks();
int _usToTicks();

void stk_init(bool prescale) {
  stk_enable_clock(true);
  stk_set_prescale(prescale);
  stk_set_load(0xFFFFFF);
  stk_counter_start(prescale);
}

void stk_enable_clock(bool en) {
    IO_STK->CTRL &= ~(IO_STK_CTRL_ENABLE);
    IO_STK->CTRL |= (en << IO_STK_CTRL_ENABLE_F);
}

void stk_set_prescale(bool prescale) {
  IO_STK->CTRL |= prescale<<IO_STK_CTRL_CLKSOURCE_F;
}

void stk_counter_start(bool prescale) {
  IO_STK->CTRL |= IO_STK_CTRL_ENABLE | (prescale<<IO_STK_CTRL_CLKSOURCE_F);
}

void stk_counter_stop() {
  IO_STK->CTRL &= ~IO_STK_CTRL_ENABLE;
}

void stk_set_load(u32 val) {
  IO_STK->LOAD = val & IO_STK_LOAD_RELOAD;
}

bool stk_set_load_ms(u32 t_ms) {
  const int clock_ticks = _msToTicks();

  if (t_ms > IO_STK_LOAD_RELOAD / clock_ticks)
    return false;

  IO_STK->LOAD = clock_ticks * t_ms;
  return true;
}

bool stk_set_load_us(u32 t_us) {
  int clock_ticks = _usToTicks();

  if (t_us > IO_STK_LOAD_RELOAD / clock_ticks)
    return false;

  IO_STK->LOAD = clock_ticks * t_us;
  return true;
}

bool stk_counter_zero() {
  return ((IO_STK->CTRL & IO_STK_CTRL_COUNTFLAG) == 1)
    && (IO_STK->CTRL & IO_STK_CTRL_ENABLE);
}

u32 stk_tick_current() {
  return IO_STK->VAL;
}

bool stk_tick_expired(u32 tick) {
  return IO_STK->VAL <= tick;
}

u32 stk_tick_add_ms(u32 tick, int t_ms) {
  u32 new_tick;

  if (tick < _msToTicks() * t_ms)
    new_tick = 0xFFFFFF - (_msToTicks() * t_ms - tick);
  else
    new_tick = tick - _msToTicks() * t_ms;

  return new_tick;
}

/*
// not added to header yet
u32 stk_tick_overflow_add_ms(int *iterations, u32 tick, int t_ms) {
  if (0xFFFFFF / _msToTicks() > t_ms) {
    // normal case, no overflow
    *iterations = 0;
    return stk_tick_add_ms(tick, t_ms);
  }

  *iterations = t_ms
}
*/

u32 stk_tick_add_us(u32 tick, int t_us) {
  u32 new_tick;

  if (tick < _usToTicks() * t_us)
    new_tick = 0xFFFFFF - (_usToTicks() * t_us - tick);
  else
    new_tick = tick - _usToTicks() * t_us;

  return new_tick;
}

void stk_delay_ms(int t_ms) {
  u32 tick = stk_tick_current();
  tick = stk_tick_add_ms(tick, t_ms);

  while (!stk_tick_expired(tick));
}

void stk_delay_us(int t_us) {
  u32 tick = stk_tick_current();
  tick = stk_tick_add_us(tick, t_us);

  while (!stk_tick_expired(tick));
}

/// gets ticks per millisecond
int _msToTicks() {
  return (IO_STK->CTRL & IO_STK_CTRL_CLKSOURCE) ?
      16000 : 2000;
}

/// gets ticks per microsecond
int _usToTicks() {
  return (IO_STK->CTRL & IO_STK_CTRL_CLKSOURCE) ?
      16 : 2;
}


#ifdef TEST_MODE
#include <stdio.h>
#include "unit_test.h"
#include "error_handling_macros.h"
#include "msoe_rev1/board_leds.h"
#include "F446RE/gpio.h"
void utest_stk(void) {
  int rc;

  // init test signal PA0
  if ((rc = gpio_clock_enable(PIN_A0.port, true)) != GPIO_OK) 
    trap_error(TRAP_ERROR_STK | rc);
  if ((rc = gpio_set_mode(&PIN_A0, IO_GPIO_MODE_OUTPUT)) != GPIO_OK)
    trap_error(TRAP_ERROR_STK | rc);

  user_button_init();
  stk_init(false);

  int period = 20;

  printf("Testing stk_delay_us() and stk_delay_ms()\r\n");
  printf("+ Testing stk_delay_us()\r\n");
  printf("+ Make sure the period of PA0 is %d us.\r\n", period);
  printf("+ Press User Button to continue\r\n\r\n");

  while (true) {
    if ((rc = gpio_output_low(&PIN_A0)) != GPIO_OK) 
      trap_error(TRAP_ERROR_STK | rc);
    stk_delay_us(period / 2);

    if ((rc = gpio_output_high(&PIN_A0)) != GPIO_OK) 
      trap_error(TRAP_ERROR_STK | rc);
    stk_delay_us(period / 2);

    if (user_button_pushed()) {
      while (user_button_pushed()); // wait for release
      break;
    }
  }

  period = 200;

  printf("+ Testing stk_delay_ms()\r\n");
  printf("+ Make sure the period of PA0 is %d ms.\r\n", period);
  printf("+ Press User Button to continue\r\n\r\n");

  while (true) {
    if ((rc = gpio_output_low(&PIN_A0)) != GPIO_OK) 
      trap_error(TRAP_ERROR_STK | rc);
    stk_delay_ms(period / 2);

    if ((rc = gpio_output_high(&PIN_A0)) != GPIO_OK) 
      trap_error(TRAP_ERROR_STK | rc);
    stk_delay_ms(period / 2);

    if (user_button_pushed()) {
      while (user_button_pushed()); // wait for release
      break;
    }
  }
}
#endif
