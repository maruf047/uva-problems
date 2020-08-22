#include <stdio.h>

int main() {
    unsigned int testcase, n;
    register unsigned int t, i, a;
    scanf("%u", &testcase);
    t = testcase;
    while (t--) {
        scanf("%u", &n);
        unsigned int digits[10] = {0};
        for (i = 1; i <= n; i++) {
            a = i;
            digits[a % 10]++;
            while (a / 10) {
                a /= 10;
                digits[a % 10]++;
            }
        }
        for (i = 0; i < 10; i++) {
            printf("%d", digits[i]);
            if (i < 9)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
