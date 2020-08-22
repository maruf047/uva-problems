#include <stdio.h>

int n, grid[201][201], p;

void join_b(int x, int y) {
    if (p != 0 || x < 0 || y < 0 || x == n || y == n || grid[x][y] == 119 || grid[x][y] == 46)return;
    grid[x][y] = 46;
    if (x == n - 1) {
        p = 1;
        return;
    }
    join_b(x - 1, y - 1);
    join_b(x - 1, y);
    join_b(x, y - 1);
    join_b(x, y + 1);
    join_b(x + 1, y);
    join_b(x + 1, y + 1);
    return;
}

void join_w(int x, int y) {
    if (p != 0 || x < 0 || y < 0 || x == n || y == n || grid[x][y] == 98 || grid[x][y] == 46)return;
    grid[x][y] = 46;
    if (y == n - 1) {
        p = 2;
        return;
    }
    join_w(x - 1, y - 1);
    join_w(x - 1, y);
    join_w(x, y - 1);
    join_w(x, y + 1);
    join_w(x + 1, y);
    join_w(x + 1, y + 1);
    return;
}

int main() {
    int t = 0;
    scanf("%d", &n);
    while (n != 0) {
        getchar();
        register int i, j;
        p = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                grid[i][j] = getchar();
            }
            getchar();
        }
        for (i = 0; i < n; ++i) {
            join_b(0, i);
            join_w(i, 0);
            if (p != 0)break;
        }
        printf("%d", ++t);
        putchar(32);
        if (p == 1)putchar(66); else putchar(87);
        putchar(10);
        scanf("%d", &n);
    }
    return 0;
}
