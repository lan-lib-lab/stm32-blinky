#include <stdio.h>
#include "version.h"
#include "msoe_rev1/board_leds.h"
#include "F446RE/delay.h"
#include "F446RE/stk.h"
#include "F446RE/uart_driver.h"
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
  board_leds_init(0x3FF);
  board_leds_set(0x3FF);
  delay_ms(100);
  while(1);

  ASSERT_OK(board_leds_init(0x3FF));
  /* init_usart2(115200, 16000000); */



  int t_ms = 100;
  /* int x = 0; */

  while(1) {
    /* printf("Starting Iteration %d!\n", x++); */
    ASSERT_OK(board_leds_clear(0x3FF));
    ASSERT_OK(board_leds_set(0x3FF));
    delay_ms(t_ms);

    ASSERT_OK(board_leds_clear(0x3FF));
    ASSERT_OK(board_leds_set(0x3FF));
    delay_ms(t_ms);
  }
}

