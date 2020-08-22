#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    register int t = testcase, s = 0;
    while (t--) {
        double l, w, h, m;
        scanf("%lf %lf %lf %lf", &l, &w, &h, &m);
        if (((l <= 56.00 && w <= 45.00 && h <= 25.00) || (l + w + h) <= 125.00) && m <= 7.00) {
            putchar(49);
            ++s;
        } else {
            putchar(48);
        }
        putchar(10);
    }
    printf("%d\n", s);
    return 0;
}
