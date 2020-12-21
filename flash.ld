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

  .text : { *(.text*) } >rom
  .rodata : { *(.rodata*) } >rom
  /* .bss : { *(.bss*) } >ram */
  
  .data : { 
    . = ALIGN(4);
    _sdata = .;     /*create a global symbol at data start*/
    *(.data*) 
    . = ALIGN(4);
    _edata = .;     /*create a global symbol at data end*/
  } >ram AT>rom

  . = ALIGN(4);
  .bss : {
    _sbss = .;
    *(.bss*)
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
