#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n;
        scanf("%d %d", &m, &n);
        register int c, r, s = 0;
        r = m % n;
        c = m / n;
        s = c + s;
        c += r;
        while (c >= n) {
            r = c % n;
            c = c / n;
            s = c + s;
            c += r;
        }
        if (c == 1) {
            printf("%d\n", s);
        } else {
            printf("cannot do this\n");
        }
    }
    return 0;
}
