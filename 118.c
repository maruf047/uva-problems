#include <stdio.h>

#define RANGE 55
#define NORTH 78
#define EAST 69
#define SOUTH 83
#define WEST 87
#define R 82
#define L 76
#define F 70

int grid[RANGE][RANGE];
int bx, by;

int main() {
    scanf("%d %d", &bx, &by);
    register int i, j;
    for (i = 0; i <= by; ++i) {
        for (j = 0; j <= bx; ++j) {
            grid[i][j] = 0;
        }
    }
    int x, y, direction;
    while (scanf("%d %d", &x, &y) == 2) {
        getchar();
        direction = getchar();
        getchar();
        int instruction, lost = 0;
        while (instruction = getchar()) {
            if (instruction == 10 || instruction == EOF) break;
            if (lost == 0) {
                if (direction == NORTH) {
                    if (instruction == R) {
                        direction = EAST;
                    } else if (instruction == L) {
                        direction = WEST;
                    } else if (y == by) {
                        if (grid[y][x] == 0) { lost = 1, grid[y][x] = 1; }
                    } else ++y;
                } else if (direction == EAST) {
                    if (instruction == R) {
                        direction = SOUTH;
                    } else if (instruction == L) {
                        direction = NORTH;
                    } else if (x == bx) {
                        if (grid[y][x] == 0) { lost = 1, grid[y][x] = 1; }
                    } else ++x;
                } else if (direction == SOUTH) {
                    if (instruction == R) {
                        direction = WEST;
                    } else if (instruction == L) {
                        direction = EAST;
                    } else if (y == 0) {
                        if (grid[y][x] == 0) { lost = 1, grid[y][x] = 1; }
                    } else --y;
                } else {
                    if (instruction == R) {
                        direction = NORTH;
                    } else if (instruction == L) {
                        direction = SOUTH;
                    } else if (x == 0) {
                        if (grid[y][x] == 0) { lost = 1, grid[y][x] = 1; }
                    } else --x;
                }
            }
        }
        printf("%d %d %c", x, y, direction);
        if (lost == 1) printf(" LOST");
        putchar(10);
    }
    return 0;
}