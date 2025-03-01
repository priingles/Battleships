# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -std=c99

# Output executable
TARGET = final

# Source files
SRCS = Bot.c Main.c Grid.c Game.c Player.c Ship.c

# Object files (for each .c file, there will be a corresponding .o file)
OBJS = $(SRCS:.c=.o)

# Header files (you can add more headers here if needed)
HEADERS = header.h

# Makefile rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile each .c file into .o file
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to recompile everything
rebuild: clean all

.PHONY: all clean rebuild
