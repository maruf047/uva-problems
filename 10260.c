#include <stdio.h>

int main() {
    int p = 0, sndx[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3,
                           0, 1, 0, 2, 0, 2};

    char c;
    while (c = getchar()) {
        if (c > 64 && c < 91) {
            int d = c - 65;
            int v = sndx[d];
            if (v != 0 && p != v) {
                putchar(v + 48);
            }
            p = v;
        } else {
            putchar(c);
            p = 0;
            if (c == EOF)break;
        }
    }
    return 0;
}