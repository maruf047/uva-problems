#include <stdio.h>

int grid[31][81], visited[31][81], col[31], boundary[31][2], bx, by, sx, sy, first_found;

void color(int y, int x) {

    register int i = 0, j = 0;

    if (y < 0 || x < 0 || x > col[y] - 2 || y > by - 2)return;
    if (visited[y][x] == 1)return;
    visited[y][x] = 1;
    if (grid[y][x] != 32)return;
    if (col[y - 1] <= x && ((grid[y][x - 1] != 32 && grid[y][x - 1] != 35) || (grid[y][x + 1] != 32 &&
                                                                               grid[y][x + 1] != 35))) {
        for (i = 0; i < col[y]; ++i)grid[y - 1][i] = 32;
        grid[y - 1][i++] = 10;
        col[y - 1] = i;
        grid[y][x] = 35;

    }

    if (x > 0 && grid[y][x - 1] != 32 && grid[y][x - 1] != 35) {
        grid[y][x] = 35;
    }
    if (x < col[y] && grid[y][x + 1] != 32 && grid[y][x + 1] != 35) {
        grid[y][x] = 35;
    }
    if (y > 0 && grid[y - 1][x] != 32 && grid[y - 1][x] != 35) {
        grid[y][x] = 35;
    }
    if (y < by && grid[y + 1][x] != 32 && grid[y + 1][x] != 35) {
        grid[y][x] = 35;
    }

    color(y - 1, x);
    color(y + 1, x);
    color(y, x + 1);
    color(y, x - 1);
}

int main() {
    int grid_count;
    scanf("%d", &grid_count);
    getchar();
    while (grid_count--) {
        register int i = 0, j = 0;
        char c;

        for (i = 0; i < 31; ++i) {
            boundary[i][0] = -1;
            boundary[i][1] = -1;
            for (j = 0; j < 81; ++j) {
                visited[i][j] = 0;
            }
        }

        i = 0, j = 0;

        first_found = 0;
        while ((c = getchar()) != 95) {
            if (c != 10) {
                grid[i][j] = c;
                if (c != 32 && c != 35 && c != 42) {
                    if (first_found) {
                        boundary[i][1] = j;
                    } else {
                        boundary[i][0] = j;
                        first_found = 1;
                    }
                } else if (c == 42) {
                    grid[i][j] = 32;
                    sx = j;
                    sy = i;
                }
                ++j;
            } else {
                grid[i][j] = c;
                col[i] = ++j;
                j = 0;
                first_found = 0;
                ++i;
            }
        }

        by = ++i;

        if (boundary[sy][0] == -1) {
            for (i = 0; i < by - 1; i++) {
                if (boundary[i][0] != -1) {
                    sx = boundary[i][0] - 1;
                    col[sy] = boundary[sy][1] + 1;
                    grid[sy][col[sy] - 1] = 10;
                    sy = i;
                    break;
                }
            }
        }
        printf("contour: %c (%d,%d)\n", grid[sy][sx], sy, sx);
        color(sy, sx);
        for (i = 0; i < by; ++i) {
            for (j = 0; j < col[i]; ++j) {
                putchar(grid[i][j]);
            }
        }

        for (i = 0; i < 31; ++i) {
            for (j = 0; j < 81; ++j) {
                printf("%d ", visited[i][j]);
            }
            putchar(10);
        }

        putchar(c);
        while ((c = getchar()) != 10 && c != EOF) {
            putchar(c);
        }
        putchar(10);
    }
    return 0;
}
