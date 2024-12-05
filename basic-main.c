#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 70
#define ITERS 30
// https://www.youtube.com/watch?v=z9y1SDjl0YQ&t=7061s

typedef enum {
    O = 0,
    I = 1,
} Cell;

// Bit shift '1 << 3' = '2**3' = 8  num-of-cellular patterns
// Also C doesnt have binary-litterals like [0b000] = 0, C++ has
/*
    #define: Introduces the macro.
    PATTERN(A, B, C): Defines the macro name PATTERN and its parameters
    (A, B, C). These parameters act like function arguments.
    ((A << 2) | (B << 1) | C): The macro's body. It specifies how the arguments
    A, B, and C are combined into an expression. When PATTERN(A, B, C) is
    encountered in code, it is replaced with ((A << 2) | (B << 1) | C).
*/
#define PATTERN(A, B, C) ((A << 2) | (B << 1) | C)

// https://en.wikipedia.org/wiki/Rule_110
// pattern 	111 	110 	101 	100 	011 	010 	001 	000
// NSFC 	0 	1 	1 	0 	1 	1 	1 	0
// NewStateForCell
Cell patterns[1 << 3] = {
    [PATTERN(O, O, O)] = O, [PATTERN(O, O, I)] = I, [PATTERN(O, I, O)] = I,
    [PATTERN(O, I, I)] = I, [PATTERN(I, O, O)] = O, [PATTERN(I, O, I)] = I,
    [PATTERN(I, I, O)] = I, [PATTERN(I, I, I)] = O,
};

char cell_image[2] = {
    [O] = ' ',
    [I] = '*',
};

typedef struct {
    Cell cells[ROW_SIZE];
} Row;

Row next_row(Row prev) {
    // assert(0 && "Not yet implemented");
    Row next = {0};
    // N =5
    // 01234
    // ***** // sliding window [***]
    //  ^ ^
    for (int i = 1; i < ROW_SIZE - 1; i++) {
        const int index =
            PATTERN(prev.cells[i - 1], prev.cells[i], prev.cells[i + 1]);
        next.cells[i] = patterns[index];
    }
    return next;
}

void print_row(Row row) {
    putc('|', stdout);
    for (int i = 0; i < ROW_SIZE; i++) {
        putc(cell_image[row.cells[i]], stdout);
    }
    putc('|', stdout);
    putc('\n', stdout);
}

Row random_row(void) {
    // The = {0} syntax is a memset-like initializer for the structure.
    Row result = {0};

    for (int i = 0; i < ROW_SIZE; i++) {
        result.cells[i] = rand() % 2;
    }
    return result;
}

int main(void) {
    // printf("Cellular Automaton 110\n");
    srand(time(NULL));  // using pseudo-random seed every time program runs
    Row row = random_row();
    for (int i = 0; i < ITERS; i++) {
        print_row(row);
        row = next_row(row);
    }
    return 0;
}
