#include <math.h>
#include <stdio.h>

int mark[2001] = {0};

int main() {

    int n = 2001;
    register int i;
    mark[1] = 1;
    mark[0] = 1;
    for (i = 4; i <= n; i += 2)mark[i] = 1;
    int limit = sqrt(n * 1.0) + 2;
    for (i = 3; i <= n; i += 2) {
        if (!mark[i]) {
            if (i <= limit) {
                int j;
                for (j = i * i; j <= n; j += i * 2)mark[j] = 1;
            }
        }
    }
    scanf("%d\n", &n);
    register int t = 0;
    char c;
    while (t < n) {
        int ascii[62] = {0};
        while ((c = getchar()) != 10) {
            if (c > 47 && c < 58) {
                ascii[c - 48]++;
            } else if (c > 64 && c < 91) {
                ascii[c - 55]++;
            } else if (c > 96 && c < 123) {
                ascii[c - 61]++;
            } else {
                break;
            }
        }
        printf("Case %d: ", ++t);
        register int s = 1;
        for (i = 0; i < 62; ++i) {
            if (!mark[ascii[i]]) {
                if (i < 10) {
                    putchar(i + 48);
                } else if (i < 36) {
                    putchar(i + 55);
                } else {
                    putchar(i + 61);
                }
                s = 0;
            }
        }
        if (s) {
            putchar(101);
            putchar(109);
            putchar(112);
            putchar(116);
            putchar(121);
        }
        putchar(10);
    }
    return 0;
}
