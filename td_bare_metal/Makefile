CROSSCOMPILE = arm-none-eabi-

CC = $(CROSSCOMPILE)gcc
LD = $(CROSSCOMPILE)ld
AS = $(CROSSCOMPILE)as
OBJCOPY = $(CROSSCOMPILE)objcopy

SRC = src

DEVICE = STM32L475VG
DEVICE_GEN = STM32L475xx

GDB = $(CROSSCOMPILE)gdb
GDB_SERVER = JLinkGDBServer
ENDIAN = little

ARCH = -mcpu=cortex-m4 -mthumb
FLOAT = -mfloat-abi=hard -mfpu=fpv4-sp-d16
INCLUDE = -ICMSIS/Include/ -ICMSIS/Device/ST/STM32L4xx/Include
CFLAGS = -Wall -Wextra -Werror -g -O1 -std=gnu99 -pedantic $(ARCH) $(INCLUDE) $(FLOAT) -D$(DEVICE_GEN)
LDFLAGS = -T ld_ram.lds -nostartfiles

SRCS = $(wildcard $(SRC)/*.c) $(wildcard *.c)
DEPS = $(SRCS:%.c=%.d)
# objs_del are the objects we can delete (needed because we don't have clocks.c)
OBJS_DEL = $(SRCS:%.c=%.o) crt0.o
OBJS = $(OBJS_DEL) src/clocks.o

EXE = main
ELF = $(EXE).elf
IMG = $(EXE).bin

$(IMG): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): $(OBJS) ld_ram.lds
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

-include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -M -MF $@ -MP $< -MT $(@:%.d=%.o)

gdb_server:
	$(GDB_SERVER) -device $(DEVICE) -endian $(ENDIAN) -if SWD -speed auto -ir -LocalhostOnly

gdb:
	$(GDB) $(ELF)

clean:
	$(RM) $(OBJS_DEL) $(DEPS) $(ELF)

clean-all: clean
	$(RM) $(IMG)

re: clean-all $(IMG)

.PHONY: gdb gdb_server clean re
