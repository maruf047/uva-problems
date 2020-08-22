#include <stdio.h>

char maze[100][100];

void explore(int u, int v) {
    if (maze[u][v] == 32 || maze[u][v] == 42) {
        maze[u][v] = 35;
        explore(u - 1, v);
        explore(u, v + 1);
        explore(u, v - 1);
        explore(u + 1, v);
    } else return;
}

int main() {
    int testcase, si, sj, maxi;
    register int i, j, uc;
    char x;
    scanf("%d", &testcase);
    x = getchar();
    while (testcase--) {
        int bj[100];
        uc = 0;
        i = 0, j = 0;
        while ((x = getchar()) != 95) {
            if (x != 42 && x != 10) {
                maze[i][j] = x;
                ++j;
            } else if (x == 42) {
                si = i;
                sj = j;
                maze[i][j] = x;
                ++j;
            } else {
                bj[i] = j;
                ++i;
                j = 0;
            }
        }
        maxi = i;
        while ((x = getchar()) != 10)++uc;

        explore(si, sj);
        for (i = 0; i < maxi; ++i) {
            for (j = 0; j < bj[i]; ++j) {
                printf("%c", maze[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i <= uc; ++i) {
            printf("_");
        }
        printf("\n");
    }
    return 0;
}
