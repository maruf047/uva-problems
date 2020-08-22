#include <stdio.h>

int max = 50;

int fib_table[50];

int fib(int n) {
    if (fib_table[n] != -1)return fib_table[n];
    if (n <= 1)fib_table[n] = 1;
    else fib_table[n] = fib(n - 2) + fib(n - 1);
    return fib_table[n];
}

int main() {
    register int i;
    for (i = 0; i < max; ++i) {
        fib_table[i] = -1;
    }

    fib(44);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        i = 0;
        while (n >= fib_table[i]) {
            ++i;
        }
        --i;
        while (i > 0) {
            if (n > fib_table[i]) {
                putchar(49);
                n -= fib_table[i];
            } else if (n < fib_table[i]) {
                putchar(48);
            } else {
                putchar(49);
                while (--i) {
                    putchar(48);
                }
            }
            --i;
        }
        putchar(10);
    }
    return 0;
}
