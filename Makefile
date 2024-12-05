CC = clang
CFLAGS=-Wall -ggdb -std=c11 -pedantic

cell: main.c 
	$(CC) $(CFLAGS) -o cell main.c
