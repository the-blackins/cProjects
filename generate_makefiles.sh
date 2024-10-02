#!/bin/bash

# Loop through all subdirectories
for dir in */; do
    # Check if Makefile already exists in the subdirectory
    if [ ! -f "${dir}Makefile" ]; then
        echo "Creating Makefile in $dir"
        
        # Create the Makefile in the subdirectory
        cat > "${dir}Makefile" <<EOL
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable (same name as subdirectory)
TARGET = $(basename ${dir})

# List of source files in this directory
SRCS = \$(wildcard *.c)

# Object files
OBJS = \$(SRCS:.c=.o)

# Default target: compile the project
all: \$(TARGET)

# Build the executable
\$(TARGET): \$(OBJS)
	\$(CC) \$(OBJS) -o \$(TARGET)

# Compile .c files into .o files
%.o: %.c
	\$(CC) \$(CFLAGS) -c \$< -o \$@

# Clean up generated files
clean:
	rm -f \$(OBJS) \$(TARGET)
EOL
    else
        echo "Makefile already exists in $dir"
    fi
done
