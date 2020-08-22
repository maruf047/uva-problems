#include <stdio.h>

#define RANGE 105
#define PLAIN 46
#define STICKER 42
#define PILLAR 35
#define NORTH 78
#define EAST 76
#define SOUTH 83
#define WEST 79
#define D 68
#define E 69
#define F 70

int grid[RANGE][RANGE];

int main() {
    int bx, by, move, direction = NORTH;
    scanf("%d %d %d", &by, &bx, &move);
    while (bx != 0 && by != 0 && move != 0) {
        getchar();
        int sticker = 0;
        register int i, j, x = 0, y = 0;
        for (i = 0; i < by; ++i) {
            for (j = 0; j < bx; ++j) {
                int ch = getchar();;
                if (ch != PLAIN && ch != PILLAR && ch != STICKER) {
                    direction = ch;
                    x = j;
                    y = i;
                    ch = PLAIN;
                }
                grid[i][j] = ch;
            }
            getchar();
        }
        int instruction;
        for (i = 0; i < move; ++i) {
            instruction = getchar();
            if (direction == NORTH) {
                if (instruction == D) {
                    direction = EAST;
                } else if (instruction == E) {
                    direction = WEST;
                } else if ((y != 0) && (grid[y - 1][x] != PILLAR)) {
                    --y;
                    if (grid[y][x] == STICKER) {
                        ++sticker;
                        grid[y][x] = PLAIN;
                    }
                }
            } else if (direction == EAST) {
                if (instruction == D) {
                    direction = SOUTH;
                } else if (instruction == E) {
                    direction = NORTH;
                } else if (((x + 1) != bx) && (grid[y][x + 1] != PILLAR)) {
                    ++x;
                    if (grid[y][x] == STICKER) {
                        ++sticker;
                        grid[y][x] = PLAIN;
                    }
                }
            } else if (direction == SOUTH) {
                if (instruction == D) {
                    direction = WEST;
                } else if (instruction == E) {
                    direction = EAST;
                } else if (((y + 1) != by) && (grid[y + 1][x] != PILLAR)) {
                    ++y;
                    if (grid[y][x] == STICKER) {
                        ++sticker;
                        grid[y][x] = PLAIN;
                    }
                }
            } else {
                if (instruction == D) {
                    direction = NORTH;
                } else if (instruction == E) {
                    direction = SOUTH;
                } else if ((x != 0) && (grid[y][x - 1] != PILLAR)) {
                    --x;
                    if (grid[y][x] == STICKER) {
                        ++sticker;
                        grid[y][x] = PLAIN;
                    }
                }
            }
        }
        getchar();
        printf("%d", sticker);
        putchar(10);
        scanf("%d %d %d", &by, &bx, &move);
    }
    return 0;
}
