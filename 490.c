#include <stdio.h>

int main() {
    char c, sen[101][101];
    int len[101];
    int li, mx = 0;

    register int i = 0, j = 0;

    while ((c = getchar()) != EOF) {
        if (c > 31 && c < 127) {
            sen[i][j++] = c;
        } else if (c == 10 || c == 0) {
            sen[i++][j++] = 32;
            if (mx < j)mx = j;
            len[i - 1] = j;
            j = 0;
        }
    }
    li = i;
    for (i = 0; i < mx - 1; i++) {
        for (j = li - 1; j >= 0; j--) {
            i <= len[j] ? putchar(sen[j][i]) : putchar(32);
        }
        putchar(10);
    }
    return 0;
}
