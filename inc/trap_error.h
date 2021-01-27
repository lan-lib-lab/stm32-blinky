#ifndef TRAP_ERROR_H
#define TRAP_ERROR_H

typedef enum {
  TRAP_ERROR_VAL_UNK,
  TRAP_ERROR_VAL_MAIN,
  TRAP_ERROR_VAL_GPIO,
  TRAP_ERROR_VAL_UART,
  TRAP_ERROR_VAL_BOARD_LEDS,
  TRAP_ERROR_VAL_STK,
  TRAP_ERROR_VAL_OTHER = 16     // last
}TRAP_ERROR_VAL;

#define TRAP_ERROR_UNK        (0b0000 << 4)
#define TRAP_ERROR_MAIN       (TRAP_ERROR_VAL_MAIN << 4)
#define TRAP_ERROR_GPIO       (TRAP_ERROR_VAL_GPIO << 4)
#define TRAP_ERROR_UART       (TRAP_ERROR_VAL_UART << 4)
#define TRAP_ERROR_BOARD_LEDS (TRAP_ERROR_VAL_BOARD_LEDS << 4)
#define TRAP_ERROR_STK        (TRAP_ERROR_VAL_STK << 4)
#define TRAP_ERROR_OTHER      (TRAP_ERROR_VAL_OTHER << 4)

/// handler that can be called when things go wrong. Takes advantage of
/// the board LEDs to show the error code.
/// LED[9] is always HIGH to indicate error,
/// LED[8:6] indicate which module, refer to TRAP_ERROR_... defines
/// LED[4:0] indicate the error code. Refer to the module in question.
void trap_error(unsigned char);

#endif // TRAP_ERROR_H
