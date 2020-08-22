#include <stdio.h>

int main() {
    register int i, d;
    int n, pow, r, t;
    while (scanf("%d", &n) == 1) {
        d = 1;
        r = pow = n / 5;
        if (pow >= 5) {
            d = 6;
        }
        for (i = r * 5 + 1; i <= n; ++i) {
            d = (d * (i % 10)) % 10;
        }
        while (r >= 5) {
            t = r;
            r = r / 5;
            for (i = r * 5 + 1; i <= t; ++i) {
                d = (d * (i % 10)) % 10;
            }
            pow = pow + r;
        }
        for (i = 1; i <= r; ++i) {
            d = (d * (i % 10)) % 10;
        }
        pow = pow % 4;
        for (i = 1; i <= pow; ++i) {
            d = (d * 2) % 10;
        }
        printf("%5d -> %d\n", n, d);
    }

    return 0;
}
