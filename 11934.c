#include <stdio.h>

int main() {
    int a, b, c, d, l;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &l);
    while (a != 0 || b != 0 || c != 0 || d != 0 || l != 0) {
        register int i, n = 0;
        for (i = 0; i <= l; ++i) {
            if ((a * i * i + b * i + c) % d == 0) ++n;
        }
        printf("%d\n", n);
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &l);
    }
    return 0;
}