#include <stdio.h>

#define RANGE 15
#define N 78
#define E 69
#define S 83
#define W 87

int grid[RANGE][RANGE], status[RANGE][RANGE];

int main() {
    int by, bx, entry;
    scanf("%d %d %d", &by, &bx, &entry);
    while (by != 0 && bx != 0 && entry != 0) {
        getchar();
        register int i, j, step = 0;
        for (i = 0; i < by; ++i) {
            for (j = 0; j < bx; ++j) {
                grid[i][j] = getchar();
                status[i][j] = 0;
            }
            getchar();
        }
        i = 0, j = entry - 1;
        int loop = 0;
        while (1) {
            if (i < 0 || j < 0 || i == by || j == bx) {
                break;
            } else if (status[i][j] == 1) {
                loop = 1;
                break;
            }
            status[i][j] = 1;
            if (grid[i][j] == N) {
                grid[i][j] = ++step;
                --i;
            } else if (grid[i][j] == E) {
                grid[i][j] = ++step;
                ++j;
            } else if (grid[i][j] == S) {
                grid[i][j] = ++step;
                ++i;
            } else {
                grid[i][j] = ++step;
                --j;
            }
        }
        if (loop == 0) {
            printf("%d step(s) to exit\n", step);
        } else {
            printf("%d step(s) before a loop of %d step(s)\n", grid[i][j] - 1, step - grid[i][j] + 1);
        }
        scanf("%d %d %d", &by, &bx, &entry);
    }
    return 0;
}
