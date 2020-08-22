#include <stdio.h>

int main() {
    int fib[45], testcase;
    register int t;
    fib[0] = 1, fib[1] = 2;
    for (t = 2; t < 45; ++t) {
        fib[t] = fib[t - 1] + fib[t - 2];
    }
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        int n, index[50], mx = 0;
        char c, cipher[50];
        scanf("%d", &n);
        register int i, j;
        for (i = 0; i < n; ++i) {
            scanf("%d", &index[i]);
            if (mx < index[i])mx = index[i];
        }
        scanf("\n");
        i = 0;
        while ((c = getchar()) != 10 && c != EOF) {
            if ((c > 64 && c < 91))cipher[i++] = c;
        }
        for (i = 0; fib[i] <= mx; ++i) {
            int k = -1;
            for (j = 0; j < n; ++j) {
                if (index[j] == fib[i])k = j;
            }
            if (k != -1)putchar(cipher[k]); else putchar(32);
        }
        putchar(10);
    }
    return 0;
}
