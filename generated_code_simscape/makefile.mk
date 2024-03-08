# Compiler
CC = gcc
CFLAGS = -lm -I.

# Source files directory
HWDIR = hw_interface

# Object files directory
OBJDIR = generated_objects

# Source files in the root directory
SRCS_ROOT = $(wildcard *.c)

# Source files in the src directory
SRCS_HW = $(wildcard $(HWDIR)/*.c)

# Object files
OBJS_ROOT = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_ROOT))
OBJS = $(patsubst $(HWDIR)/%.c,$(OBJDIR)/%.o,$(SRCS_HW))
# Target executable
TARGET = executable

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS_ROOT) $(OBJS)
	$(CC)	-o	$@ $^	$(CFLAGS)

$(OBJDIR)/%.o: $(HWDIR)/%.c | $(OBJDIR)
	$(CC)	-c	$<	-o	$@	$(CFLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC)	-c	$<	-o	$@	$(CFLAGS)

$(OBJDIR):
	mkdir	-p	$(OBJDIR)

clean:
	rm	-rf	$(OBJDIR)	$(TARGET)