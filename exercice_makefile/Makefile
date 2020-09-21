# Sources:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html#Implicit-Variables
# https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html#Catalogue-of-Rules
# https://www.gnu.org/software/make/manual/html_node/Functions.html
# https://sen.enst.fr/system/files/588bc0bf3e380f220510914f9331bcd4/makefiles.pdf

# the compilation toolchain we use
CROSSCOMPILE=arm-none-eabi-

# linker
LD = $(CROSSCOMPILE)ld
# assembly
AS = $(CROSSCOMPILE)as
# compiler
CC = $(CROSSCOMPILE)gcc
# rm
RM = rm

# project libs
LIB_DIR = libs
# custom libs
MY_LIBS = /opt/mylibs

# compiler mode
CMODE = -mthumb
# linker flags
LDFLAGS = -L$(MY_LIBS) $(CMODE)
# compiler flags
CFLAGS = -Wall -Werror -g -Og $(CMODE)
# lib compiler flags (distinct from CLFLAGS)
LIBCFLAGS = -g -O2 $(CMODE)

# libraries
LDLIBS = -lm

# source files
SRCS = $(wildcard *.c)
# objects files
OBJS = $(SRCS:%.c=%.o)

# lib source files
LIBS_SRCS = $(wildcard $(LIB_DIR)/*.c)
# lib objects
LIBS_OBJS = $(notdir $(LIBS_SRCS:%.c=%.o))

# executable name
EXE = hello

all: $(EXE)

-include $(subst .c,.d,$(SOURCES))

stubs.o: $(LIB_DIR)/stubs.c
	$(CC) $(LIBCFLAGS) -c -o $@ $^

%.d: %.c
	$(CC) $(CFLAGS) -M -MF $@ -MP $<

$(EXE): $(OBJS) $(LIBS_OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) -f $(OBJS) $(LIBS_OBJS) $(EXE)

.PHONY: all clean
