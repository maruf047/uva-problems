#include <stdio.h>

char wl[100][100];

int lc, z, li, lj;

void explore(int u, int v) {
    if (u > li - 1 || v > lj - 1)return;
    if (z == 1) {
        if (wl[u][v] != 'W') return;
        ++lc;
        wl[u][v] = 'X';
        explore(u - 1, v + 1);
        explore(u - 1, v);
        explore(u - 1, v - 1);
        explore(u, v + 1);
        explore(u, v - 1);
        explore(u + 1, v);
        explore(u + 1, v + 1);
        explore(u + 1, v - 1);
    } else {
        if (wl[u][v] != 'X') return;
        ++lc;
        wl[u][v] = 'W';
        explore(u - 1, v + 1);
        explore(u - 1, v);
        explore(u - 1, v - 1);
        explore(u, v + 1);
        explore(u, v - 1);
        explore(u + 1, v);
        explore(u + 1, v + 1);
        explore(u + 1, v - 1);
    }
}

int main() {
    unsigned int testcase, pi, pj;
    char c;
    register unsigned int t, i, j, s, r;
    scanf("%u%^c", &testcase);
    t = testcase;
    while (t--) {
        s = 0, r = 0;
        i = 0, j = 0;
        lc = 0;
        while (c = getchar()) {
            if (c > 47 && c < 58)break;
            if (c != 10) {
                wl[i][j] = c;
                ++j;
            } else {
                lj = j;
                j = 0;
                ++i;
            }
        }
        li = i;
        pi = c - 48;
        s = 1;
        while (c = getchar()) {
            if (c != 10) {
                if (s && c != 32) {
                    if (pj == -1) {
                        pi = (pi * 10) + (c - 48);
                        s = 0;
                    } else {
                        pj = (pj * 10) + (c - 48);
                        s = 0;
                    }
                } else {
                    c = getchar();
                    pj = c - 48;
                    s = 1;
                }
            } else {
                if (wl[pi - 1][pj - 1] == 'W')z = 1;
                else z = 0;
                explore(pi - 1, pj - 1);
                printf("%d\n", lc);
                lc = 0;
                pi = -1, pj = -1;
                c = getchar();
                if (c == 10 || c == EOF)break;
                else {
                    pi = c - 48;
                    s = 1;
                }
            }
        }
        if (t)printf("\n");
    }
    return 0;
}
