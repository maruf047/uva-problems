#include <stdio.h>
#include <math.h>

#define CUBES 57
#define MAX_DIFF 10000

int cubes[65], diff[10005][2];

int main() {
    int num;
    register int i, j;
    for (i = 0; i <= CUBES; ++i) {
        cubes[i] = (int) pow(i, 3);
    }
    for (i = 0; i <= MAX_DIFF; ++i) {
        diff[i][0] = 0;
    }
    for (i = 1; i < CUBES; ++i) {
        for (j = i + 1; j <= CUBES; ++j) {
            if (cubes[j] - cubes[i] > MAX_DIFF)break;
            if (diff[cubes[j] - cubes[i]][0] == 0) {
                diff[cubes[j] - cubes[i]][0] = j;
                diff[cubes[j] - cubes[i]][1] = i;
            }
        }
    }

    scanf("%d", &num);
    while (num != 0) {
        if (diff[num][0] == 0) {
            printf("No solution\n");
        } else {
            printf("%d %d\n", diff[num][0], diff[num][1]);
        }
        scanf("%d", &num);
    }
    return 0;
}