CROSSCOMPILE = arm-none-eabi-

CC = $(CROSSCOMPILE)gcc
LD = $(CROSSCOMPILE)ld
AS = $(CROSSCOMPILE)as

DEVICE = STM32L475VG

GDB = $(CROSSCOMPILE)gdb
GDB_SERVER = JLinkGDBServer
ENDIAN = little

gdb_server:
	$(GDB_SERVER) -device $(DEVICE) -endian $(ENDIAN) -if SWD -speed auto -ir -LocalhostOnly

.PHONY: gdb
