#include <stdio.h>

#define TP 30
#define MX 105

int primes[TP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
int factors[MX][TP];

int main() {
    register int i, j, fc, num;
    int pc = 0, n;
    for (i = 0; i <= MX; ++i) {
        for (j = 0; j < TP; ++j) {
            factors[i][j] = 0;
        }
    }
    for (i = 2; i <= 100; ++i) {
        num = i;
        for (j = 0; primes[j] <= i; ++j) {
            fc = 0;
            while (num % primes[j] == 0) {
                ++fc;
                num = num / primes[j];
            }
            factors[i][j] = factors[i - 1][j] + fc;
        }
    }
    scanf("%d", &n);
    while (n != 0) {
        i = 0;
        printf("%3d! =", n);
        while (factors[n][i] > 0) {
            if (i == 15)printf("\n      ");
            printf("%3d", factors[n][i]);
            ++i;
        }
        putchar(10);
        scanf("%d", &n);
    }
    return 0;
}