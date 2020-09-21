# Sources:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html#Implicit-Variables
# https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html#Catalogue-of-Rules
# https://www.gnu.org/software/make/manual/html_node/Functions.html
# https://sen.enst.fr/system/files/588bc0bf3e380f220510914f9331bcd4/makefiles.pdf

# the compilation toolchain we use
CROSSCOMPILE=arm-none-eabi-

CC = $(CROSSCOMPILE)gcc
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
# lib compiler flags (distinct from CFLAGS)
LIBCFLAGS = -g -O2 $(CMODE)

# libraries
LDLIBS = -lm

# library source files
LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)
# library objects files
LIB_OBJS = $(notdir $(LIB_SRCS:%.c=%.o))
# source files
SRCS = $(wildcard *.c) $(LIB_SRCS)
# dependency files
DEPS = $(SRCS:%.c=%.d)
# objects files
OBJS = $(notdir $(SRCS:%.c=%.o))
# executable name
EXE = hello

all: $(EXE)

-include $(DEPS)

# special compiler command for lib files
$(LIB_OBJS): %.o: $(LIB_DIR)/%.c
	$(CC) $(LIBCFLAGS) -c -o $@ $<

# generates dependency rule file ; must not be displayed
%.d: %.c
	@$(CC) $(CFLAGS) -M -MF $@ -MP $<

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) -f $(OBJS) $(DEPS) $(EXE)

.PHONY: clean
