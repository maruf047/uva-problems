#include <stdio.h>

int main() {
    char c = 1, str[500];
    register int l = 0;
    while (c != EOF) {
        c = getchar();
        if (c > 47 && c < 58) {
            register int d = 0, s = 0;
            while (c != 10 && c != EOF) {
                if (s == 0) {
                    d = c - 48;
                    ++s;
                } else if (s == 1) {
                    d += (c - 48) * 10;
                    ++s;
                } else if (c == 49 && s == 2 && d < 23) {
                    d += 100;
                    str[l++] = d;
                    d = 0;
                    s = 0;
                } else {
                    str[l++] = d;
                    d = c - 48;
                    s = 1;
                }
                c = getchar();
            }
            if (s)str[l++] = d;
            while (l) {
                putchar(str[--l]);
            }
            putchar(c);
            l = 0;
        } else if (c == 10) {
            putchar(10);
        } else {
            str[l++] = c;
            while ((c = getchar()) != 10 && c != EOF)str[l++] = c;
            while (l--) {
                int x = str[l];
                while (x) {
                    putchar(48 + x % 10);
                    x /= 10;
                }
            }
            putchar(c);

            l = 0;
        }
        continue;
    }
    return 0;
}
