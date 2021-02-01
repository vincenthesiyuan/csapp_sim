CC = /usr/bin/gcc
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXE = PROGRAMS

SRC = ./src
CODE = ./src/cpu/mmu.c ./src/disk/code.c ./src/memory/dram.c ./src/memory/instruction.c ./src/main.c

.PHONY: PROGRAMS
main:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)
	./$(EXE)
	