.thumb

.section .isr_vector,"a",%progbits
.global _start
_start:
  // See PM0214 section 2.3.4 Vector Table
/*0*/    .word 0x20002000    // initial SP value
/*1*/    .word	Reset_Handler
/*2*/    .word	NMI_Handler
/*3*/    .word	HardFault_Handler
/*4*/    .word	MemManage_Handler
/*5*/    .word	BusFault_Handler
/*6*/    .word	UsageFault_Handler
/*7*/    .word	0
/*8*/    .word	0
/*9*/    .word	0
/*10*/   .word	0
/*11*/   .word	SVC_Handler
/*12*/   .word	DebugMon_Handler
/*13*/   .word	0
/*14*/   .word	PendSV_Handler
/*15*/   .word	SysTick_Handler
/*16*/   .word	WWDG_IRQHandler                   // Window WatchDog
/*17*/   .word	PVD_IRQHandler                 // PVD through EXTI Line detection
/*18*/   .word	TAMP_STAMP_IRQHandler             // Tamper and TimeStamps through the EXTI line
/*19*/   .word	RTC_WKUP_IRQHandler               // RTC Wakeup through the EXTI line
/*20*/   .word	FLASH_IRQHandler                 // FLASH
/*21*/   .word	RCC_IRQHandler                    // RCC
/*22*/   .word	EXTI0_IRQHandler                 // EXTI Line0
/*23*/   .word	EXTI1_IRQHandler                  // EXTI Line1
/*24*/   .word	EXTI2_IRQHandler                  // EXTI Line2
/*25*/   .word	EXTI3_IRQHandler                  // EXTI Line3
/*26*/   .word	EXTI4_IRQHandler                  // EXTI Line4
/*27*/   .word	DMA1_Stream0_IRQHandler           // DMA1 Stream 0
/*28*/   .word	DMA1_Stream1_IRQHandler           // DMA1 Stream 1
/*29*/   .word	DMA1_Stream2_IRQHandler           // DMA1 Stream 2
/*30*/   .word	DMA1_Stream3_IRQHandler           // DMA1 Stream 3
/*31*/   .word	DMA1_Stream4_IRQHandler           // DMA1 Stream 4
/*32*/   .word	DMA1_Stream5_IRQHandler           // DMA1 Stream 5
/*33*/   .word	DMA1_Stream6_IRQHandler           // DMA1 Stream 6
/*34*/   .word	ADC_IRQHandler                    // ADC1, ADC2 and ADC3s
/*35*/   .word	CAN1_TX_IRQHandler                // CAN1 TX
/*36*/   .word	CAN1_RX0_IRQHandler               // CAN1 RX0
/*37*/   .word	CAN1_RX1_IRQHandler               // CAN1 RX1
/*38*/   .word	CAN1_SCE_IRQHandler               // CAN1 SCE
/*39*/   .word	EXTI9_5_IRQHandler                // External Line[9:5]s
/*40*/   .word	TIM1_BRK_TIM9_IRQHandler          // TIM1 Break and TIM9
/*41*/   .word	TIM1_UP_TIM10_IRQHandler          // TIM1 Update and TIM10
/*42*/   .word	TIM1_TRG_COM_TIM11_IRQHandler     // TIM1 Trigger and Commutation and TIM11
/*43*/   .word	TIM1_CC_IRQHandler                // TIM1 Capture Compare
/*44*/   .word	TIM2_IRQHandler                   // TIM2
/*45*/   .word	TIM3_IRQHandler                   // TIM3
/*46*/   .word	TIM4_IRQHandler                   // TIM4
/*47*/   .word	I2C1_EV_IRQHandler                // I2C1 Event
/*48*/   .word	I2C1_ER_IRQHandler                // I2C1 Error
/*49*/   .word	I2C2_EV_IRQHandler                // I2C2 Event
/*50*/   .word	I2C2_ER_IRQHandler                // I2C2 Error
/*51*/   .word	SPI1_IRQHandler                   // SPI1
/*52*/   .word	SPI2_IRQHandler                   // SPI2
/*53*/   .word	USART1_IRQHandler                 // USART1
/*54*/   .word	USART2_IRQHandler                 // USART2
/*55*/   .word	USART3_IRQHandler                 // USART3
/*56*/   .word	EXTI15_10_IRQHandler              // External Line[15:10]s
/*57*/   .word	RTC_Alarm_IRQHandler              // RTC Alarm (A and B) through EXTI Line
/*58*/   .word	OTG_FS_WKUP_IRQHandler            // USB OTG FS Wakeup through EXTI line
/*59*/   .word	TIM8_BRK_TIM12_IRQHandler         // TIM8 Break and TIM12
/*60*/   .word	TIM8_UP_TIM13_IRQHandler          // TIM8 Update and TIM13
/*61*/   .word	TIM8_TRG_COM_TIM14_IRQHandler     // TIM8 Trigger and Commutation and TIM14
/*62*/   .word	TIM8_CC_IRQHandler                // TIM8 Capture Compare
/*63*/   .word	DMA1_Stream7_IRQHandler           // DMA1 Stream7
/*64*/   .word	FMC_IRQHandler                    // FMC
/*65*/   .word	SDIO_IRQHandler                   // SDIO
/*66*/   .word	TIM5_IRQHandler                   // TIM5
/*67*/   .word	SPI3_IRQHandler                   // SPI3
/*68*/   .word	UART4_IRQHandler                  // UART4
/*69*/   .word	UART5_IRQHandler                  // UART5
/*70*/   .word	TIM6_DAC_IRQHandler               // TIM6 and DAC1&2 underrun errors
/*71*/   .word	TIM7_IRQHandler                   // TIM7
/*72*/   .word	DMA2_Stream0_IRQHandler           // DMA2 Stream 0
/*73*/   .word	DMA2_Stream1_IRQHandler           // DMA2 Stream 1
/*74*/   .word	DMA2_Stream2_IRQHandler           // DMA2 Stream 2
/*75*/   .word	DMA2_Stream3_IRQHandler           // DMA2 Stream 3
/*76*/   .word	DMA2_Stream4_IRQHandler           // DMA2 Stream 4
/*77*/   .word	0                                 // Reserved
/*78*/   .word	0                                 // Reserved
/*79*/   .word	CAN2_TX_IRQHandler                // CAN2 TX
/*80*/   .word	CAN2_RX0_IRQHandler               // CAN2 RX0
/*81*/   .word	CAN2_RX1_IRQHandler               // CAN2 RX1
/*82*/   .word	CAN2_SCE_IRQHandler               // CAN2 SCE
/*83*/   .word	OTG_FS_IRQHandler                 // USB OTG FS
/*84*/   .word	DMA2_Stream5_IRQHandler           // DMA2 Stream 5
/*85*/   .word	DMA2_Stream6_IRQHandler           // DMA2 Stream 6
/*86*/   .word	DMA2_Stream7_IRQHandler           // DMA2 Stream 7
/*87*/   .word	USART6_IRQHandler                 // USART6
/*88*/   .word	I2C3_EV_IRQHandler                // I2C3 event
/*89*/   .word	I2C3_ER_IRQHandler                // I2C3 error
/*90*/   .word	OTG_HS_EP1_OUT_IRQHandler         // USB OTG HS End Point 1 Out
/*91*/   .word	OTG_HS_EP1_IN_IRQHandler          // USB OTG HS End Point 1 In
/*92*/   .word	OTG_HS_WKUP_IRQHandler            // USB OTG HS Wakeup through EXTI
/*93*/   .word	OTG_HS_IRQHandler                 // USB OTG HS
/*94*/   .word	DCMI_IRQHandler                   // DCMI
/*95*/   .word	0                                 // Reserved
/*96*/   .word	0                                 // Reserved
/*97*/   .word	FPU_IRQHandler                    // FPU
/*98*/   .word	0                                 // Reserved
/*99*/   .word	0                                 // Reserved
/*100*/   .word	SPI4_IRQHandler                   // SPI4
/*101*/   .word	0                                 // Reserved
/*102*/   .word	0                                 // Reserved
/*103*/   .word	SAI1_IRQHandler                   // SAI1
/*104*/   .word	0                                 // Reserved
/*105*/   .word	0                                 // Reserved
/*106*/   .word	0                                 // Reserved
/*107*/   .word	SAI2_IRQHandler                   // SAI2
/*108*/   .word	QUADSPI_IRQHandler                // QuadSPI
/*109*/   .word	HDMI_CEC_IRQHandler               // CEC
/*110*/   .word	SPDIF_RX_IRQHandler               // SPDIF RX
/*111*/   .word	FMPI2C1_IRQHandler                // FMPI2C1 Event
/*112*/   .word	FMPI2C1_Error_IRQHandler          // FMPI2C1 Error


/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

  	.weak	NMI_Handler
	.thumb_set NMI_Handler,Default_Handler

  	.weak	HardFault_Handler
	.thumb_set HardFault_Handler,Default_Handler

  	.weak	MemManage_Handler
	.thumb_set MemManage_Handler,Default_Handler

  	.weak	BusFault_Handler
	.thumb_set BusFault_Handler,Default_Handler

	.weak	UsageFault_Handler
	.thumb_set UsageFault_Handler,Default_Handler

	.weak	SVC_Handler
	.thumb_set SVC_Handler,Default_Handler

	.weak	DebugMon_Handler
	.thumb_set DebugMon_Handler,Default_Handler

	.weak	PendSV_Handler
	.thumb_set PendSV_Handler,Default_Handler

	.weak	SysTick_Handler
	.thumb_set SysTick_Handler,Default_Handler

	.weak	WWDG_IRQHandler
    .weak	PVD_IRQHandler
    .weak	TAMP_STAMP_IRQHandler
    .weak	RTC_WKUP_IRQHandler
    .weak	FLASH_IRQHandler
    .weak	RCC_IRQHandler
    .weak	EXTI0_IRQHandler
    .weak	EXTI1_IRQHandler
    .weak	EXTI2_IRQHandler
    .weak	EXTI3_IRQHandler
    .weak	EXTI4_IRQHandler
    .weak	DMA1_Stream0_IRQHandler
    .weak	DMA1_Stream1_IRQHandler
    .weak	DMA1_Stream2_IRQHandler
    .weak	DMA1_Stream3_IRQHandler
    .weak	DMA1_Stream4_IRQHandler
    .weak	DMA1_Stream5_IRQHandler
    .weak	DMA1_Stream6_IRQHandler
    .weak	ADC_IRQHandler
    .weak	CAN1_TX_IRQHandler
    .weak	CAN1_RX0_IRQHandler
    .weak	CAN1_RX1_IRQHandler
    .weak	CAN1_SCE_IRQHandler
    .weak	EXTI9_5_IRQHandler
    .weak	TIM1_BRK_TIM9_IRQHandler
    .weak	TIM1_UP_TIM10_IRQHandler
    .weak	TIM1_TRG_COM_TIM11_IRQHandler
    .weak	TIM1_CC_IRQHandler
    .weak	TIM2_IRQHandler
    .weak	TIM3_IRQHandler
    .weak	TIM4_IRQHandler
    .weak	I2C1_EV_IRQHandler
    .weak	I2C1_ER_IRQHandler
    .weak	I2C2_EV_IRQHandler
    .weak	I2C2_ER_IRQHandler
    .weak	SPI1_IRQHandler
    .weak	SPI2_IRQHandler
    .weak	USART1_IRQHandler
    .weak	USART2_IRQHandler
    .weak	USART3_IRQHandler
    .weak	EXTI15_10_IRQHandler
    .weak	RTC_Alarm_IRQHandler
    .weak	OTG_FS_WKUP_IRQHandler
    .weak	TIM8_BRK_TIM12_IRQHandler
    .weak	TIM8_UP_TIM13_IRQHandler
    .weak	TIM8_TRG_COM_TIM14_IRQHandler
    .weak	TIM8_CC_IRQHandler
    .weak	DMA1_Stream7_IRQHandler
    .weak	FMC_IRQHandler
    .weak	SDIO_IRQHandler
    .weak	TIM5_IRQHandler
    .weak	SPI3_IRQHandler
    .weak	UART4_IRQHandler
    .weak	UART5_IRQHandler
    .weak	TIM6_DAC_IRQHandler
    .weak	TIM7_IRQHandler
    .weak	DMA2_Stream0_IRQHandler
    .weak	DMA2_Stream1_IRQHandler
    .weak	DMA2_Stream2_IRQHandler
    .weak	DMA2_Stream3_IRQHandler
    .weak	DMA2_Stream4_IRQHandler
    .weak	CAN2_TX_IRQHandler
    .weak	CAN2_RX0_IRQHandler
    .weak	CAN2_RX1_IRQHandler
    .weak	CAN2_SCE_IRQHandler
    .weak	OTG_FS_IRQHandler
    .weak	DMA2_Stream5_IRQHandler
    .weak	DMA2_Stream6_IRQHandler
    .weak	DMA2_Stream7_IRQHandler
    .weak	USART6_IRQHandler
    .weak	I2C3_EV_IRQHandler
    .weak	I2C3_ER_IRQHandler
    .weak	OTG_HS_EP1_OUT_IRQHandler
    .weak	OTG_HS_EP1_IN_IRQHandler
    .weak	OTG_HS_WKUP_IRQHandler
    .weak	OTG_HS_IRQHandler
    .weak	DCMI_IRQHandler
    .weak	FPU_IRQHandler
    .weak	SPI4_IRQHandler
    .weak	SAI1_IRQHandler
    .weak	SAI2_IRQHandler
    .weak	QUADSPI_IRQHandler
    .weak	HDMI_CEC_IRQHandler
    .weak	SPDIF_RX_IRQHandler
    .weak	FMPI2C1_IRQHandler
    .weak	FMPI2C1_Error_IRQHandler


	.thumb_set WWDG_IRQHandler,Default_Handler
    .thumb_set PVD_IRQHandler,Default_Handler
    .thumb_set TAMP_STAMP_IRQHandler,Default_Handler
    .thumb_set RTC_WKUP_IRQHandler,Default_Handler
    .thumb_set FLASH_IRQHandler,Default_Handler
    .thumb_set RCC_IRQHandler,Default_Handler
    .thumb_set EXTI0_IRQHandler,Default_Handler
    .thumb_set EXTI1_IRQHandler,Default_Handler
    .thumb_set EXTI2_IRQHandler,Default_Handler
    .thumb_set EXTI3_IRQHandler,Default_Handler
    .thumb_set EXTI4_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream0_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream1_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream2_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream3_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream4_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream5_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream6_IRQHandler,Default_Handler
    .thumb_set ADC_IRQHandler,Default_Handler
    .thumb_set CAN1_TX_IRQHandler,Default_Handler
    .thumb_set CAN1_RX0_IRQHandler,Default_Handler
    .thumb_set CAN1_RX1_IRQHandler,Default_Handler
    .thumb_set CAN1_SCE_IRQHandler,Default_Handler
    .thumb_set EXTI9_5_IRQHandler,Default_Handler
    .thumb_set TIM1_BRK_TIM9_IRQHandler,Default_Handler
    .thumb_set TIM1_UP_TIM10_IRQHandler,Default_Handler
    .thumb_set TIM1_TRG_COM_TIM11_IRQHandler,Default_Handler
    .thumb_set TIM1_CC_IRQHandler,Default_Handler
    .thumb_set TIM2_IRQHandler,Default_Handler
    .thumb_set TIM3_IRQHandler,Default_Handler
    .thumb_set TIM4_IRQHandler,Default_Handler
    .thumb_set I2C1_EV_IRQHandler,Default_Handler
    .thumb_set I2C1_ER_IRQHandler,Default_Handler
    .thumb_set I2C2_EV_IRQHandler,Default_Handler
    .thumb_set I2C2_ER_IRQHandler,Default_Handler
    .thumb_set SPI1_IRQHandler,Default_Handler
    .thumb_set SPI2_IRQHandler,Default_Handler
    .thumb_set USART1_IRQHandler,Default_Handler
    .thumb_set USART2_IRQHandler,Default_Handler
    .thumb_set USART3_IRQHandler,Default_Handler
    .thumb_set EXTI15_10_IRQHandler,Default_Handler
    .thumb_set RTC_Alarm_IRQHandler,Default_Handler
    .thumb_set OTG_FS_WKUP_IRQHandler,Default_Handler
    .thumb_set TIM8_BRK_TIM12_IRQHandler,Default_Handler
    .thumb_set TIM8_UP_TIM13_IRQHandler,Default_Handler
    .thumb_set TIM8_TRG_COM_TIM14_IRQHandler,Default_Handler
    .thumb_set TIM8_CC_IRQHandler,Default_Handler
    .thumb_set DMA1_Stream7_IRQHandler,Default_Handler
    .thumb_set FMC_IRQHandler,Default_Handler
    .thumb_set SDIO_IRQHandler,Default_Handler
    .thumb_set TIM5_IRQHandler,Default_Handler
    .thumb_set SPI3_IRQHandler,Default_Handler
    .thumb_set UART4_IRQHandler,Default_Handler
    .thumb_set UART5_IRQHandler,Default_Handler
    .thumb_set TIM6_DAC_IRQHandler,Default_Handler
    .thumb_set TIM7_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream0_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream1_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream2_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream3_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream4_IRQHandler,Default_Handler
    .thumb_set CAN2_TX_IRQHandler,Default_Handler
    .thumb_set CAN2_RX0_IRQHandler,Default_Handler
    .thumb_set CAN2_RX1_IRQHandler,Default_Handler
    .thumb_set CAN2_SCE_IRQHandler,Default_Handler
    .thumb_set OTG_FS_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream5_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream6_IRQHandler,Default_Handler
    .thumb_set DMA2_Stream7_IRQHandler,Default_Handler
    .thumb_set USART6_IRQHandler,Default_Handler
    .thumb_set I2C3_EV_IRQHandler,Default_Handler
    .thumb_set I2C3_ER_IRQHandler,Default_Handler
    .thumb_set OTG_HS_EP1_OUT_IRQHandler,Default_Handler
    .thumb_set OTG_HS_EP1_IN_IRQHandler,Default_Handler
    .thumb_set OTG_HS_WKUP_IRQHandler,Default_Handler
    .thumb_set OTG_HS_IRQHandler,Default_Handler
    .thumb_set DCMI_IRQHandler,Default_Handler
    .thumb_set FPU_IRQHandler,Default_Handler
    .thumb_set SPI4_IRQHandler,Default_Handler
    .thumb_set SAI1_IRQHandler,Default_Handler
    .thumb_set SAI2_IRQHandler,Default_Handler
    .thumb_set QUADSPI_IRQHandler,Default_Handler
    .thumb_set HDMI_CEC_IRQHandler,Default_Handler
    .thumb_set SPDIF_RX_IRQHandler,Default_Handler
    .thumb_set FMPI2C1_IRQHandler,Default_Handler
    .thumb_set FMPI2C1_Error_IRQHandler,Default_Handler

	.weak	SystemInit

.thumb_func
Reset_Handler:
// enable floating point - added by DER
	# CPACR is located at address 0xE000ED88
	LDR     R0, =0xE000ED88
	# Read CPACR
	LDR R1, [R0]
	# Set bits 20-23 to enable CP10 and CP11 coprocessors
	 #ORR R1, R1, #(0xF << 20)
  LDR     R2, =0x00F00000
  ORR     R1, R1, R2
	# Write back the modified value to the CPACR
	STR R1, [R0] // wait for store to complete
	DSB
	# reset pipeline now the FPU is enabled
	ISB

/* Copy the data segment initializers from flash to SRAM */
  movs	r1, #0
  b	LoopCopyDataInit

CopyDataInit:
	ldr	r3, =_sidata
	ldr	r3, [r3, r1]
	str	r3, [r0, r1]
	add	r1, r1, #4

LoopCopyDataInit:
	ldr	r0, =_sdata
	ldr	r3, =_edata
	add	r2, r0, r1
	cmp	r2, r3
	bcc	CopyDataInit
	ldr	r2, =_sbss
	b	LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
	mov  r3, #0
 	str  r3, [r2]
	add  r2, r2, #4

LoopFillZerobss:
	ldr	r3, = _ebss
	cmp	r2, r3
	bcc	FillZerobss

/* Call the clock system intitialization function.*/
    bl  SystemInit
/* Call static constructors */
    bl __libc_init_array
/* Call the application's entry point.*/
	bl	main

LoopForever:
    b LoopForever

.size	Reset_Handler, .-Reset_Handler


.thumb_func
Default_Handler:
  mov r0, #1
  bl trap_error
  b done

done:
  b done
