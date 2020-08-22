#include <stdio.h>

int main() {
    register int sum = 0, s = 1, len = 0, i;
    char c;
    char num[1010];
    while (s != 0) {
        c = getchar();
        if (c > 47 && c < 58) {
            sum += c - 48;
            num[len++] = c;
        } else if (c == 10) {
            if (len == 1 && num[--len] == 48) {
                s = 0;
                continue;
            }
            for (i = 0; i < len; ++i) {
                putchar(num[i]);
            }
            if (sum % 9 == 0) {
                register int d = 1;
                printf(" is a multiple of 9");
                while (sum >= 9) {
                    ++d;
                    register int n = 0;
                    while (sum / 10 != 0) {
                        n += sum % 10;
                        sum /= 10;
                    }
                    sum = n;
                }
                printf(" and has 9-degree %d.", d);
            } else {
                printf(" is not a multiple of 9.");
            }
            putchar(c);
            len = 0;
            sum = 0;
            s = 1;
        }
    }
    return 0;
}