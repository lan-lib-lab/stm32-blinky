#include "F446RE/delay.h"
#include "F446RE/io_memory_map/stk.h"

/*
 * Delays a given number of microseconds.
 * From Dr. Livingston.
 */
void delay_us(int t_us)
{
	//Ensure Counter is off
	*(STK_CTRL) &= ~(1<<STK_ENABLE_F);

	//t_ms time
	for (uint32_t i=0; i<t_us; i++)
	{
		//Load 16 int STK_LOAD
		*(STK_LOAD) = 16; //1us

		//Turn on counter
		*(STK_CTRL) |= ((1<<STK_ENABLE_F) | (1<<STK_CLKSOURCE_F));

		//Wait for flag go to 1
		while ( !(*(STK_CTRL) & (1<<STK_CNTFLAG_F) ) ) {}

		//Turn off counter
		*(STK_CTRL) &= ~(1<<STK_ENABLE_F);
	}
}

/*
 * Delays a given number of milliseconds.
 * From Dr. Livingston.
 */
void delay_ms(int t_ms)
{
	//Ensure Counter is off
	*(STK_CTRL) &= ~(1<<STK_ENABLE_F);

	//t_ms time
	for (uint32_t i=0; i<t_ms; i++)
	{
		//Load 16 int STK_LOAD
		*(STK_LOAD) = 16000; //1ms

		//Turn on counter
		*(STK_CTRL) |= ((1<<STK_ENABLE_F) | (1<<STK_CLKSOURCE_F));

		//Wait for flag go to 1
		while ( !(*(STK_CTRL) & (1<<STK_CNTFLAG_F) ) ) {}

		//Turn off counter
		*(STK_CTRL) &= ~(1<<STK_ENABLE_F);
	}
}
