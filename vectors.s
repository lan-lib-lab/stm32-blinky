.thumb

.global _start
_start:
  // See PM0214 section 2.3.4 Vector Table
/*0*/   .word 0x20002000    // initial SP value
/*1*/   .word reset
/*2*/   .word done
/*3*/   .word done
/*256   .word*/

.thumb_func
reset:
  bl main
  b done

.thumb_func
done:
  b done
