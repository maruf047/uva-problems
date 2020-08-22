#include <stdio.h>

#define ZERO 0
#define DEC 10
#define NL 10
#define LAST 3000
#define TOTAL 100

int f[TOTAL + 1][LAST + 1], f_len[TOTAL + 1];
int lx, lr, lb;

int main() {
    register int i, r, n, d, c;
    int m = 1;
    f[ZERO][LAST] = 1;
    f_len[ZERO] = 1;
    while (m <= TOTAL) {
        r = m;
        lx = f_len[m - 1];
        lb = 0;
        while (r != 0) {
            d = r % DEC;
            n = 0;
            lx = LAST - f_len[m - 1];
            lr = LAST - lb;
            c = 0;
            for (i = LAST; i > lx; --i) {
                n = (d * f[m - 1][i]) + f[m][lr] + n;
                f[m][lr] = n % DEC;
                n = n / DEC;
                --lr;
            }
            while (n > 0) {
                f[m][lr] = n % DEC + f[m][lr];
                --lr;
                n = n / DEC;
            }
            ++lb;
            r = r / DEC;
        }
        f_len[m] = LAST - lr;
        lr = LAST - f_len[m] + 1;
        for (i = lr; i <= LAST; ++i) {
            printf("%d", f[m][i]);
        }
        printf(" -> %d!", m);
        putchar(NL);
        ++m;
    }
    while (scanf("%d", &m) == 1) {
        lr = LAST - f_len[m] + 1;
        printf("%d!\n", m);
        for (i = lr; i <= LAST; ++i) {
            printf("%d", f[m][i]);
        }
        putchar(NL);
    }
    return 0;
}
