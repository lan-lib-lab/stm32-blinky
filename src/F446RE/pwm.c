#if 0
/* #if 1 */
#include <inttypes.h>
#include "F446RE/pwm.h"
#include "F446RE/stk.h"
#include "trap_error.h"
#include "mini_inttypes.h"

typedef enum {
  PWM_OK,
  PWM_ERROR_DUTY_CYCLE
#ifdef TRAP_ERROR_PWM
    = TRAP_ERROR_PWM
#endif
  ,
  PWM_ERROR_INTERNAL
}PWMError;

typedef struct {
  u8 duty_cycle;      // 0-100, else PWM_ERROR_DUTY_CYCLE
  u32 period_ticks;   // period of waveform, based on STK_TICKS_PER_SECOND
  u32 _cur_tick;      // current tick, based on STK_TICKS_PER_SECOND
}PWMState;

PWMError pwm_create(PWMState *self, u8 duty_cycle, u32 period) {
  if (duty_cycle < 0 || duty_cycle > 100)
    return PWM_ERROR_DUTY_CYCLE;

  self->duty_cycle = duty_cycle;
  self->period_ticks = period;
  self->_cur_tick = 0;
}

PWMError pwm_task_generate(PWMState *self, bool out) {

}


#endif
