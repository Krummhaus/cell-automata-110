#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 20
// https://www.youtube.com/watch?v=z9y1SDjl0YQ&t=7061s

typedef enum {
    O = 0,
    I = 1,
} Cell;

char cell_image[2] = {
    [O] = ' ',
    [I] = '*',
};

typedef struct {
    Cell cells[20];
} Row;

Row next_row(Row prev) {
    assert(0 && "Not yet implemented");
    return prev;
}

void print_row(Row row) {
    for (int i = 0; i < ROW_SIZE; i++) {
        putc(cell_image[row.cells[i]], stdout);
    }
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

int main(int argc, char **atgv) {
    // printf("Cellular Automaton 110\n");
    srand(time(NULL));
    print_row(random_row());
    return 0;
}
