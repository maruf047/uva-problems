#include <stdio.h>

int main() {
    int n;
    int c[5] = {1, 5, 10, 25, 50}, w[7490] = {0};
    register int i, j;
    w[0] = 1;

    for (j = 0; j < 5; ++j) {
        for (i = c[j]; i <= 7489; ++i) {
            w[i] += w[i - c[j]];
        }
    }
    while (scanf("%d", &n) == 1) {
        printf("%d\n", w[n]);
    }
    return 0;
}
