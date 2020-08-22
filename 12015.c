#include <stdio.h>

int main() {
    int testcase;
    scanf("%d\n", &testcase);
    register int t = 0;
    while (t < testcase) {
        char str[10][110];
        register int i = 0, mx = 0;
        int r[10], len[10];
        while (i < 10) {
            register int j = 0;
            char c;
            while ((c = getchar()) != 32) {
                str[i][j] = c;
                ++j;
            }
            len[i] = j;
            scanf("%d", &r[i]);
            if (mx < r[i])mx = r[i];
            ++i;
            getchar();
        }
        printf("Case #%d:\n", ++t);
        i = 0;
        while (i < 10) {
            if (r[i] == mx) {
                register int j = 0;
                while (j < len[i]) {
                    putchar(str[i][j]);
                    ++j;
                }
                putchar(10);
            }
            ++i;
        }
    }
    return 0;
}
