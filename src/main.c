#include "version.h"
#include "msoe_rev1/board_leds.h"
#include "F446RE/delay.h"
#include "error_handling_macros.h"

void trap_error(int code) {
  if (code == 0)
    return;
  
  board_leds_init(0x3FF);

  int t1_ms = 200;
  int t2_ms = 3*t1_ms;

  while (1) {
    board_leds_clear(0x3FF);
    board_leds_set(code);
    delay_ms(t2_ms);

    board_leds_clear(0x3FF);
    delay_ms(t2_ms);

    board_leds_clear(0x3FF);
    board_leds_set(code);
    delay_ms(t1_ms);
  }
}

void main(void) {
  ASSERT_EXPECT_PASS(board_leds_init(0x3FF));

  int t_ms = 100;
  while(1) {
    ASSERT_EXPECT_PASS(board_leds_clear(0x3FF));
    ASSERT_EXPECT_PASS(board_leds_set(0x0));
    delay_ms(t_ms);

    ASSERT_EXPECT_PASS(board_leds_clear(0x3FF));
    ASSERT_EXPECT_PASS(board_leds_set(0x3FF));
    delay_ms(t_ms);
  }
}

