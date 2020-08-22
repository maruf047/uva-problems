#include <stdio.h>

int fib[4790][1001];
int fiblen[4790];

int main() {
    register int i = 0;
    fiblen[0] = 1, fib[0][0] = 0;
    fiblen[1] = fib[1][0] = 1;
    fiblen[2] = fib[2][0] = 1;
    for (i = 3; i < 4787; ++i) {
        register int c = 0, l = 0;
        while (l < fiblen[i - 2]) {
            int x = fib[i - 1][l] + fib[i - 2][l] + c;
            fib[i][l] = x > 9 ? x % 10 : x;
            c = x > 9 ? 1 : 0;
            ++l;
        }
        while (l < fiblen[i - 1]) {
            int x = fib[i - 1][l] + c;
            fib[i][l] = x > 9 ? x % 10 : x;
            c = x > 9 ? 1 : 0;
            ++l;
        }
        if (c) {
            fib[i][l++] = 1;
        }
        fiblen[i] = l;
    }
    int n;
    while (scanf("%d", &n) == 1) {
        for (i = fiblen[n] - 1; i >= 0; --i) {
            putchar(48 + fib[n][i]);
        }
        putchar(10);
    }
    return 0;
}
