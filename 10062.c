#include <stdio.h>

int main() {
    char c;
    int ascii[256] = {0};
    register int f = 0;
    int s = 0;
    while ((c = getchar())) {
        if (c > 31 && c < 127) {
            ascii[c]++;
            if (f < ascii[c])f = ascii[c];
        } else if (c == 10 || c == 13 || c == EOF) {
            register int i, j;
            for (i = 1; i <= f; ++i) {
                for (j = 126; j > 31; --j) {
                    if (ascii[j] == i) {
                        if (s)putchar(10); else s = 1;
                        printf("%d %d", j, i);
                        ascii[j] = 0;
                    }
                }
            }
            if (c != EOF) putchar(10); else break;
            f = 0;
        }
    }
    return 0;
}
