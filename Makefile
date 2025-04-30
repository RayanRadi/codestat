# Makefile
# Builds the codestat executable from all .c files

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/main.c src/scanner.c src/analyzer/analyzer.c

codestat: $(SRC)
	$(CC) $(CFLAGS) -o codestat $(SRC)

clean:
	rm -f codestat
