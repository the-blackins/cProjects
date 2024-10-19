# Compiler
CC = gcc

# Compiler flags with include paths for cURL and OpenSSL
CFLAGS = -Wall -g -IC:/curl/curl-8.10.1_6-win64-mingw/include -IC:/curl/curl-8.10.1_6-win64-mingw/include/openssl




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
	$(CC) $(OBJS) -o $(TARGET) -LC:/curl/curl-8.10.1_6-win64-mingw/lib -lcurl -lssl -lcrypto

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
