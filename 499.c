#include <stdio.h>

int main() {

    int l[52] = {0};
    register int m = 0;
    char c;
    while ((c = getchar()) != EOF) {

        register int i;
        if (c != 10) {
            if (c > 96 && c < 123) {
                i = c - 71;
                m < ++l[i] ? m = l[i] : m;
            } else if (c > 64 && c < 91) {
                i = c - 65;
                m < ++l[i] ? m = l[i] : m;
            }
        } else {

            for (i = 0; i < 52; ++i) {
                if (l[i] == m) {
                    i < 26 ? putchar(i + 65) : putchar(i + 71);
                }
                l[i] = 0;
            }
            putchar(32);
            printf("%d", m);
            putchar(10);
            m = 0;
        }
    }
    return 0;
}
