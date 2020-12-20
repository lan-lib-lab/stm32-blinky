# toolchain
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
AR = arm-none-eabi-ar
OBJDUMP = arm-none-eabi-objdump
OBJCOPY = arm-none-eabi-objcopy

src = $(wildcard src/*.c) $(wildcard src/*/*.c)

obj = $(patsubst src/%, build/obj/%, $(src:.c=.o))
dep = $(obj:.o=.d)

libs = $(patsubst lib%, -l%, $(notdir $(basename $(wildcard libs/*.a) $(wildcard libs/*/*.a))))
exec = $(notdir $(CURDIR))

version = 0.1.0
PROG = $(exec)-$(version)

CFLAGS_INCLUDE_LIB_HEADERS = -Iinc $(patsubst %, -I%, $(dir $(wildcard libs/*/)))
LDFLAGS_INCLUDE_LIB_DIRS = -Llibs $(patsubst %, -L%, $(dir $(wildcard libs/*/)))

CFLAGS = $(strip -Wall -Wno-main -mthumb $(CFLAGS_INCLUDE_LIB_HEADERS))
LDFLAGS = $(strip $(LDFLAGS_INCLUDE_LIB_DIRS) $(libs))

# for testing, enable conditional compilation macro
ifeq ($(MAKECMDGOALS), test)
	CFLAGS += -D TEST_MODE_ENABLED
endif

# add debug flags for debug target
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -ggdb -D DEBUG
else
	CFLAGS += -O2
endif

all: build

.PHONY: build
build: build_vectors $(obj)
	@mkdir -p build/
	$(LD) -T flash.ld $(LDFLAGS) build/obj/vectors.o $(obj) -o build/$(PROG).elf
	$(OBJDUMP) -D build/$(PROG).elf > build/$(PROG).lst
	$(OBJCOPY) build/$(PROG).elf -O binary build/$(PROG).bin

.PHONY: test
test: build

.PHONY: debug
debug: build

.PHONY: build_vectors
build_vectors:
	$(AS) vectors.s -o build/obj/vectors.o

.PHONY: clean
clean:
	rm -f $(obj)
	rm -f guile/obj/vectors.o
	rm -f $(dep)
	rm -f build/$(exec)-$(version).elf
	rm -f build/$(exec)-$(version).bin
	rm -f build/$(exec)-$(version).lst

.PHONY: program
program:
	sudo STM32_Programmer_CLI --connect port=SWD --download build/$(PROG).elf --start

# rule for creating a library in case this is a library project
# an assumption is made that intead of main, a library requires a "lib.c"
# this is used so that this rule isn't accidentally ran on projects that aren't meant to be library projects
lib: $(obj)
ifeq (,$(wildcard src/lib.c))
	$(error "making a static library in a project that doesn't contain a lib.c!")
endif
	mkdir -p build/
	rm -rf build/lib$(exec)-$(version)/
	mkdir -p build/lib$(exec)-$(version)/
	mkdir -p build/lib$(exec)-$(version)/$(exec)/
	$(AR) rcs build/lib$(exec)-$(version)/lib$(exec)-$(version).a $^
	cp inc/* build/lib$(exec)-$(version)/$(exec)/



# include dep files in the makefile
ifneq (,$(wildcard build/obj/*))
-include $(dep)
endif

build/obj/%.o: src/%.c
	@mkdir -p $(dir  $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
build/obj/%.d: src/%.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@
