# Makefile for codestat

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/main.c \
      src/scanner.c \
      src/UsrCommands.c \
      src/analyzer/analyzer.c \
      src/analyzer/loc.c

TARGET = codestat

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
