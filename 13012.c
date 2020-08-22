#include <stdio.h>

int main() {
    int t;
    while (scanf("%d", &t) == 1) {
        register int i = 5, c = 0;
        while (i--) {
            int g;
            scanf("%d", &g);
            if (t == g)++c;
        }
        putchar(48 + c);
        putchar(10);
    }
    return 0;
}
