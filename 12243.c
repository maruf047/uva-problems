#include <stdio.h>

int main() {
    char c, f = 0;
    register int s = 0, n = 0;
    while ((c = getchar()) != 42) {
        if (s == 1) {
            if (c == 32) {
                c = getchar();
                if (c != f && c != f + 32 && c != f - 32)n = 1;
            } else if (c == 10) {
                s = 0;
                if (n)putchar(78); else putchar(89);
                putchar(10);
                n = 0;
            }
        } else {
            f = c;
            s = 1;
        }
    }
    return 0;
}
