# Compiler
CC = gcc
CFLAGS = -Wall -g
LIBS = -lcurl -lssl -lcrypto

# Target executable (same name as subdirectory)
TARGET = https

# List of source files in this directory
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Default target: compile the project
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
