# Compiler
CC = gcc
CFLAGS = -lm -lpthread -I.

# Source files directory
HWDIR = hw_interface
SSDIR = scope_stream

# Object files directory
OBJDIR = generated_objects

# Source files in the root directory
SRCS_ROOT = $(wildcard *.c)

# Source files in the src directory
SRCS_HW = $(wildcard $(HWDIR)/*.c)
SRCS_SS = $(wildcard $(SSDIR)/*.c)

# Object files
OBJS_ROOT = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_ROOT))
OBJS_HW = $(patsubst $(HWDIR)/%.c,$(OBJDIR)/%.o,$(SRCS_HW))
OBJS_SS = $(patsubst $(SSDIR)/%.c,$(OBJDIR)/%.o,$(SRCS_SS))
# Target executable
TARGET = executable

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS_ROOT) $(OBJS_HW) $(OBJS_SS)
	$(CC)	-o	$@ $^	$(CFLAGS)

$(OBJDIR)/%.o: $(HWDIR)/%.c | $(OBJDIR)
	$(CC)	-c	$<	-o	$@	$(CFLAGS)

$(OBJDIR)/%.o: $(SSDIR)/%.c | $(OBJDIR)
	$(CC)	-c	$<	-o	$@	$(CFLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC)	-c	$<	-o	$@	$(CFLAGS)

$(OBJDIR):
	mkdir	-p	$(OBJDIR)

clean:
	rm	-rf	$(OBJDIR)	$(TARGET)