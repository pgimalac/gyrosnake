CROSSCOMPILE = arm-none-eabi-

CC = $(CROSSCOMPILE)gcc
LD = $(CROSSCOMPILE)ld
AS = $(CROSSCOMPILE)as
OBJCOPY = $(CROSSCOMPILE)objcopy

SRC = src

DEVICE = STM32L475VG

GDB = $(CROSSCOMPILE)gdb
GDB_SERVER = JLinkGDBServer
ENDIAN = little

ARCH = -mcpu=cortex-m4 -mthumb
# for floating op
# -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS = -Wall -Wextra -Werror -g -O0 $(ARCH)
LDFLAGS = -T ld_ram.lds -nostartfiles

SRCS = $(wildcard $(SRC)/*.c) $(wildcard *.c)
DEPS = $(SRCS:%.c=%.d)
OBJS = $(SRCS:%.c=%.o) crt0.o

EXE = main
ELF = $(EXE).elf
IMG = $(EXE).bin

$(IMG): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): $(OBJS) ld_ram.lds
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

-include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -M -MF $@ -MP $<

gdb_server:
	$(GDB_SERVER) -device $(DEVICE) -endian $(ENDIAN) -if SWD -speed auto -ir -LocalhostOnly

gdb:
	$(GDB) $(ELF)

clean:
	$(RM) $(OBJS) $(DEPS) $(ELF)

clean-all: clean
	$(RM) $(IMG)

re: clean-all $(IMG)

.PHONY: gdb gdb_server clean re
