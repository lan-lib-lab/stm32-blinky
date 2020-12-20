echo "script deprecated. refer to README#install"
exit 0
PROG_NAME=blinky

function main() {
  local command=$1

  if [ "$command" = "-h" ] || [ "$command" = "--help" ]; then
    display_help
    exit 0
  elif [ "$command" = "" ]; then
    build
  elif [ "$command" == "clean" ]; then
    clean
  elif [ "$command" == "program" ]; then
    program
  else
    display_help
    exit 1
  fi
}

function display_help() {
    echo "Usage: $(basename $0) [-h] [clean|program]"
}

function build() {
  set -x
  arm-none-eabi-as vectors.s -o vectors.o \
  && arm-none-eabi-gcc -O2 -c -mthumb so.c -o so.o \
  && arm-none-eabi-ld -T flash.ld vectors.o so.o -o $PROG_NAME.elf \
  && arm-none-eabi-objdump -D $PROG_NAME.elf > $PROG_NAME.lst \
  && arm-none-eabi-objcopy $PROG_NAME.elf -O binary $PROG_NAME.bin
  { set +x; } 2>/dev/null
}

function clean() {
  set -x
  rm -f *.o $PROG_NAME.elf $PROG_NAME.lst $PROG_NAME.out $PROG_NAME.bin
  { set +x; } 2>/dev/null
}

function program() {
  # requires sudo due to libusb
  set -x
  sudo STM32_Programmer_CLI --connect port=SWD --download $PROG_NAME.elf --start
  { set +x; } 2>/dev/null
}

main $@
