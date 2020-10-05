CROSSCOMPILE = arm-none-eabi-

CC = $(CROSSCOMPILE)gcc
LD = $(CROSSCOMPILE)ld
AS = $(CROSSCOMPILE)as

SRC = src

DEVICE = STM32L475VG

GDB = $(CROSSCOMPILE)gdb
GDB_SERVER = JLinkGDBServer
ENDIAN = little

ARCH = -mcpu=cortex-m4 -mthumb
CFLAGS = -Wall -Wextra -Werror -g -O1 $(ARCH)
LDFLAGS = -T ld_ram.lds
# add -nostdlib ?

SRCS = $(wildcard $(SRC)/*.c)
DEPS = $(SRCS:%.c=%.d)
OBJS = $(SRCS:%.c=%.o)

EXE = main

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

-include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -M -MF $@ -MP $<

gdb_server:
	$(GDB_SERVER) -device $(DEVICE) -endian $(ENDIAN) -if SWD -speed auto -ir -LocalhostOnly

gdb:
	$(GDB) $(EXE)

.PHONY: gdb gdb_server
