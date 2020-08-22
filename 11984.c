#include <stdio.h>

int main() {

    int testcase;
    double base, inc;
    register int t = 0;
    scanf("%d", &testcase);
    while (t++ < testcase) {
        scanf("%lf %lf", &base, &inc);
        printf("Case %d: %.2lf\n", t, base + 5.00 / 9.00 * inc);
    }
    return 0;
}
