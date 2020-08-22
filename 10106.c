#include <stdio.h>

#define LN 255
#define ZERO 48
#define NL 10

int x[300], y[300], r[650];
int lx, ly, lr, lb;
int ch;

int main() {
    register int i, j, n;
    while (1) {
        lx = 0, ly = 0, lr = 0;
        for (i = 0; i < LN; ++i) {
            x[i] = y[i] = 0;
            r[i] = r[i + LN] = 0;
        }
        while ((ch = getchar()) != NL && (ch != EOF)) {
            x[lx] = (ch - ZERO);
            ++lx;
        }
        if (ch == EOF) break;
        while (((ch = getchar()) != NL) && (ch != EOF)) {
            y[ly] = (ch - ZERO);
            ++ly;
        }
        n = 0;
        if ((lx <= 1 && x[0] == 0) || (ly <= 1 && y[0] == 0)) {
            putchar(48);
        } else {
            for (i = lx - 1; i >= 0; --i) {
                lb = lx - i - 1;
                for (j = ly - 1; j >= 0; --j) {
                    n = (x[i] * y[j]) + r[lb];
                    r[lb] = (n % 10);
                    ++lb;
                    n = n / 10;
                    if (n > 0) {
                        r[lb] = n + r[lb];
                    }
                }
                if (n > 0) {
                    lr = lb;
                } else {
                    lr = lb - 1;
                }
            }
            for (i = lr; i >= 0; --i) {
                printf("%d", r[i]);
            }
        }
        putchar(NL);
        if (ch == EOF)break;
    }
    return 0;
}
