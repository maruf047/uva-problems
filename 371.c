#include <stdio.h>

int main() {
    unsigned long int st[100] = {0};
    unsigned long int a, b;

    register unsigned long int i, m = 0, n, x;
    for (i = 2; i <= 100; ++i) {
        register unsigned long int c = 0;
        n = i;
        if (n % 2 == 0) {
            n = n / 2;
            ++c;
        } else {
            n = 3 * n + 1;
            ++c;
        }
        if (n < 101 && st[n] != 0) {
            c += st[n];
            n = 1;
        }
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
                ++c;
            } else {
                n = 3 * n + 1;
                ++c;
            }
            if (n < 101 && st[n] != 0) {
                c += st[n];
                n = 1;
            }
        }
        if (i != 1 && st[i] == 0) {
            st[i] = c;
        }
    }
    scanf("%lu %lu", &a, &b);
    while (a != 0 || b != 0) {
        register unsigned long int i, m = 0, n, x;
        if (a > b) {
            x = a;
            a = b;
            b = x;
        }
        for (i = a; i <= b; ++i) {
            register unsigned long int c = 0;
            n = i;
            if (i < 101) {
                c = st[i];
            } else {
                if (n % 2 == 0) {
                    n = n / 2;
                    ++c;
                } else {
                    n = 3 * n + 1;
                    ++c;
                }
                if (n < 101 && st[n] != 0) {
                    c += st[n];
                    n = 1;
                }
                while (n != 1) {
                    if (n % 2 == 0) {
                        n = n / 2;
                        ++c;
                    } else {
                        n = 3 * n + 1;
                        ++c;
                    }
                    if (n < 101 && st[n] != 0) {
                        c += st[n];
                        n = 1;
                    }
                }
            }
            if (m < c) {
                m = c;
                x = i;
            }
        }
        printf("Between %lu and %lu, %lu generates the longest sequence of %lu values.\n", a, b, x, m);
        scanf("%lu %lu", &a, &b);
    }
    return 0;
}