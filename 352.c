#include <stdio.h>

char o[100][100];
int x;

void eagles(int u, int v) {
    if ((u >= x && v >= x) || (u < 0 && v < 0)) return;
    if (o[u][v] != '1')return;
    o[u][v] = '0';
    eagles(u - 1, v + 1);
    eagles(u - 1, v);
    eagles(u - 1, v - 1);
    eagles(u, v + 1);
    eagles(u, v);
    eagles(u, v - 1);
    eagles(u + 1, v);
    eagles(u + 1, v + 1);
    eagles(u + 1, v - 1);
}

int main() {
    register int i, j, c, t = 0;
    while (scanf("%d", &x) != -1) {
        c = 0;
        for (i = 0; i < x; i++) {
            for (j = 0; j < x; j++) {
                scanf(" %c", &o[i][j]);
            }
        }

        for (i = 0; i < x; i++) {
            for (j = 0; j < x; j++) {
                if (o[i][j] == '1') {
                    eagles(i, j);
                    c++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++t, c);
    }
    return 0;
}