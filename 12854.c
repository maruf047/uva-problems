#include <stdio.h>

int main() {
    char c;
    register int i = 0, s = 0;
    int x[5];
    while (scanf("%d", &x[0]) == 1) {
        for (i = 1; i < 5; ++i)scanf("%d", &x[i]);
        for (i = 0; i < 5; ++i) {
            int d;
            scanf("%d", &d);
            if (d == x[i])s = 1;
        }
        if (s)putchar(78); else putchar(89);
        putchar(10);
        s = 0;
    }
    return 0;
}
