CROSSCOMPILE = arm-none-eabi-

CC = $(CROSSCOMPILE)gcc
LD = $(CROSSCOMPILE)ld
AS = $(CROSSCOMPILE)as
DB = $(CROSSCOMPILE)gdb
CPP = $(CROSSCOMPILE)cpp
OBJCOPY = $(CROSSCOMPILE)objcopy

DIRS = src .

DEVICE = STM32L475VG
DEVICE_GEN = STM32L475xx

GDB_SERVER = JLinkGDBServer
ENDIAN = little

ARCH = -mcpu=cortex-m4 -mthumb
ASFLAGS = -g
CPPFLAGS = -D$(DEVICE_GEN) -ICMSIS/Include/ -ICMSIS/Device/ST/STM32L4xx/Include
FLOAT = -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS = -Wall -Wextra -Werror -g -O1 -std=gnu99 -pedantic $(ARCH) $(FLOAT)
LDFLAGS = -T ld_ram.lds -nostartfiles

SRCS_c = $(foreach DIR, $(DIRS), $(wildcard $(DIR)/*.c))
SRCS_s = $(foreach DIR, $(DIRS), $(wildcard $(DIR)/*.s))
SRCS_S = $(foreach DIR, $(DIRS), $(wildcard $(DIR)/*.S))
DEPS = $(SRCS_c:%.c=%.d)
# objs_del are the objects we can delete (needed because we don't have clocks.c)
OBJS_GEN = $(SRCS_c:%.c=%.o) $(SRCS_s:%.s=%.o) $(SRCS_S:%.S=%.o)
OBJS = $(OBJS_GEN) src/clocks.o

EXE = main
ELF = $(EXE).elf
IMG = $(EXE).bin

$(IMG): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): $(OBJS) ld_ram.lds
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

-include $(DEPS)

%.d: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -M -MF $@ -MP $< -MT $(@:%.d=%.o)

gdb_server:
	$(GDB_SERVER) -device $(DEVICE) -endian $(ENDIAN) -if SWD -speed auto -ir -LocalhostOnly

gdb: $(ELF)
	$(DB) $(ELF)

clean:
	$(RM) $(OBJS_GEN) $(DEPS) $(ELF)

clean-all: clean
	$(RM) $(IMG)

re: clean-all $(IMG)

.PHONY: gdb gdb_server clean re
