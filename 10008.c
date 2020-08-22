#include <stdio.h>

int main() {
    int testcase;
    scanf("%d\n", &testcase);
    register int t = testcase, mxf = 0;
    int al[26]={0};
    while (t--) {
        char c;
        register int pos = 0;
        while ((c = getchar()) != 10) {
            if (c > 64 && c < 91) {
                pos = c - 65;
                al[pos]++;
            } else if (c > 96 && c < 123) {
                pos = c - 97;
                al[pos]++;
            }
            if (al[pos] > mxf) mxf = al[pos];
        }
    }
    register int i = 0;
    for (i = mxf; i > 0; --i) {
        for (t = 0; t < 26; ++t) {
            if (al[t] == i) {
                putchar(t + 65);
                putchar(32);
                printf("%d", i);
                putchar(10);
            }
        }
    }
    return 0;
}
