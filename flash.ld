_estack = 0x20020000;      /* end of RAM */
_Min_Heap_Size = 0;       
_Min_Stack_Size = 0x400;

MEMORY
{
  rom : ORIGIN = 0x08000000, LENGTH = 512K
  ram : ORIGIN = 0x20000000, LENGTH = 128K 
}

SECTIONS
{

  .isr_vector : {
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    . = ALIGN(4);
  } >rom

  .text : { 
    /* . = ALIGN(4); */
    *(.text*) 
    *(.glue_7)      /*glue arm to thumb code*/
    *(.glue_7t)     /*glue thumb to arm code*/
    *(.eh_frame) 

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;     /*global symbol at end of code*/
  } >rom

  .rodata : { 
    . = ALIGN(4);
    *(.rodata*) 
    . = ALIGN(4);
  } >rom

  .ARM.extab : {
    . = ALIGN(4);
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    . = ALIGN(4);
  } >rom

  .preinit_array : {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(4);
  } >rom

  .init_array : {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(4);
  } >rom

  .fini_array : {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
    . = ALIGN(4);
  } >rom

  /* Used by the startup to initialize data */
  _sidata = LOADADDR(.data);
  
  .data : { 
    . = ALIGN(4);
    _sdata = .;     /*global symbol at data start*/
    *(.data*) 
    . = ALIGN(4);
    _edata = .;     /*global symbol at data end*/
  } >ram

  .bss : {
  . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    _ebss = .;
  . = ALIGN(4);
  } >ram   

  .__user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  }
}
