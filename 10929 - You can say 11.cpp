#include <stdio.h>

int main() {
    register int odd = 0, even = 0, s = 1, len = 0, i;
    int diff;
    char c;
    char num[1500];
    while (s != 0) {
        c = getchar();
        if (c > 47 && c < 58) {
            if (s == 1) {
                odd += c - 48;
                s = 2;
            } else {
                even += c - 48;
                s = 1;
            }
            num[len++] = c;
        } else if (c == 10) {
            if (len == 1 && num[--len] == 48) {
                s = 0;
                continue;
            }
            if (odd > even) {
                diff = odd - even;
            } else {
                diff = even - odd;
            }
            for (i = 0; i < len; ++i) {
                putchar(num[i]);
            }
            if (diff % 11 == 0 || diff == 0) {
                printf(" is a multiple of 11.");
            } else {
                printf(" is not a multiple of 11.");
            }
            putchar(c);
            len = 0;
            odd = 0;
            even = 0;
            s=1;
        }
    }
    return 0;
}