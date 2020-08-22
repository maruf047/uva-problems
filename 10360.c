#include <stdio.h>

#define LENGTH 1025
int sewerage[1030][1030];

int main() {
    int testcsae;
    register int i, j, k;
    scanf("%d", &testcsae);
    for (i = 0; i < LENGTH; ++i) {
        for (j = 0; j < LENGTH; ++j) {
            sewerage[i][j] = 0;
        }
    }
    while (testcsae--) {
        int strength, total, x, y, population, max = 0, mx = LENGTH, my = LENGTH;
        scanf("%d\n%d", &strength, &total);
        for (i = 0; i < total; ++i) {
            scanf("%d %d %d", &x, &y, &population);
            for (j = y - strength; j <= y + strength; ++j) {
                if (j < 0)continue;
                if (j == LENGTH)break;
                for (k = x - strength; k <= x + strength; ++k) {
                    if (k < 0)continue;
                    if (k == LENGTH)continue;
                    sewerage[j][k] += population;
                }
            }
        }

        for (j = 0; j < LENGTH; ++j) {
            for (i = 0; i < LENGTH; ++i) {
                if (max < sewerage[i][j]) {
                    max = sewerage[i][j];
                    mx = j;
                    my = i;
                }
                sewerage[i][j] = 0;
            }
        }
        printf("%d %d %d\n", mx, my, max);
    }
    return 0;
}
