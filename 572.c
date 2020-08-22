#include <stdio.h>

char o[100][100];
int x, y;

void depo(int u, int v) {
    if ((u >= x && v >= y) || (u < 0 && v < 0)) return;
    if (o[u][v] != '@')return;
    o[u][v] = '*';
    depo(u - 1, v + 1);
    depo(u - 1, v);
    depo(u - 1, v - 1);
    depo(u, v + 1);
    depo(u, v);
    depo(u, v - 1);
    depo(u + 1, v);
    depo(u + 1, v + 1);
    depo(u + 1, v - 1);
}

int main() {
    register int i, j, c;
    scanf("%d %d", &x, &y);
    while (x != 0 && y != 0) {
        c = 0;
        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
                scanf(" %c", &o[i][j]);
            }
        }

        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
                if (o[i][j] == '@') {
                    depo(i, j);
                    c++;
                }
            }
        }
        printf("%d\n", c);
        scanf("%d %d", &x, &y);
    }
    return 0;
}
