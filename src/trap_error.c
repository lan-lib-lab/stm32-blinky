#include "trap_error.h"
#include "mini_inttypes.h"
#include "msoe_rev1/board_leds.h"
#include "F446RE/delay.h"

void trap_error(unsigned char code) {
  if (code == 0)
    return;
  
  const u8 module_code = (code & 0xF0) >> 4;
  const u8 error_code = code & 0x0F;
  u16 leds_code = (module_code << 5) | error_code;
  leds_code = leds_code & 0x2FF;

  board_leds_init(0x3FF);
  board_leds_set(0x200);    // set last bit to clearly indicate error state

  int t1_ms = 10;
  int t2_ms = 3*t1_ms;

  int i = 0;
  while (1) {
    board_leds_clear(0x1FF);
    /* if (i % 10 == 0) */
      /* board_leds_set(0x1EF); */
    board_leds_set(leds_code);
    delay_ms(t2_ms);

    board_leds_clear(0x1FF);
    delay_ms(t2_ms);

    board_leds_clear(0x1FF);
    board_leds_set(leds_code);
    delay_ms(t1_ms);

    i++;
  }
}
