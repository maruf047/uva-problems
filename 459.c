#include <stdio.h>

int letters[30], grid[30][30];

void visit(int c, int l) {
    if (letters[c] == 0)return;
    letters[c] = 0;
    int i = 0;
    for (i = 0; i <= l; ++i) {
        if (grid[c][i] == 1) {
            grid[c][i] = 0;
            grid[i][c] = 0;
            visit(i, l);
        }
    }
    return;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    getchar();
    getchar();
    while (testcase--) {
        int limit;
        register int i, j, s = 0;
        char c = getchar();
        limit = c - 65;
        for (i = 0; i <= limit; ++i) {
            letters[i] = 1;
        }
        while ((c = getchar())) {
            if (c > 64 && c < 91) {
                s = 0;
                int x = c - 65;
                c = getchar();
                int y = c - 65;
                grid[x][y] = 1;
                grid[y][x] = 1;
            } else if (c == 10 || c == EOF) {

                if (s == 0)s = 1;
                else {
                    j = 0;
                    for (i = 0; i <= limit; ++i) {
                        if (letters[i] == 1) {
                            visit(i, limit);
                            ++j;
                        }
                    }
                    printf("%d", j);
                    putchar(10);
                    if (testcase != 0)putchar(10);
                    break;
                }
            }
        }
    }
    return 0;
}
