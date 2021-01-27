#include <stdio.h>
#include <string.h>
#include "version.h"
#include "error_handling_macros.h"
#include "F446RE/delay.h"
#include "F446RE/stk.h"
#include "F446RE/uart_driver.h"
#include "msoe_rev1/board_leds.h"
#include "trap_error.h"

#ifdef TEST_MODE
void run_unit_tests(void);
#endif

void main(void) {
#ifdef TEST_MODE
 run_unit_tests(); 
 while(1) {}
#endif
  ASSERT_OK(board_leds_init(0x3FF));
  init_usart2(115200, STK_SYS_CLOCK);
  delay_ms(100);

  /* printf("hello world!\n"); */
  /* trap_error(TRAP_ERROR_MAIN | 0x1); */

  int t_ms = 100;
  int x = 0;
  
  const char s[] = "Hello World!\r\n";
  char debug_str[200] = {0};

  while(1) {
    /* sprintf(debug_str, "Iteration %d\r\n", x); */
    /* sprintf(debug_str, "BEEEP\r\n"); */
    /* _write(1, debug_str, strlen(debug_str)); */
    /* _write(1, s, sizeof(s)/sizeof(s[0])); */
    /* fprintf(1, "Does this work?\n\r"); */
    /* printf("Starting Iteration %d!\n", x++); */
    printf("Beep! x: %d\r\n", x);

    usart2_putch('H');
    ASSERT_OK(board_leds_clear(0x3FF));
    ASSERT_OK(board_leds_set(0));
    delay_ms(t_ms);

    ASSERT_OK(board_leds_clear(0x3FF));
    ASSERT_OK(board_leds_set(x & 0x3FF));
    delay_ms(t_ms);
    x++;
  }
}


#ifdef TEST_MODE
#include "unit_test.h"
void run_unit_tests(void) {
  init_usart2(115200, STK_SYS_CLOCK);
  stk_init(false);

#ifdef UTEST_STK_ENABLED
    utest_stk();
#endif
}
#endif
