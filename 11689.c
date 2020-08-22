#include <stdio.h>

int main() {
    int testcase, e, f, c;
    register int t, b, reb;
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d %d %d", &e, &f, &c);
        b = (e + f) / c;
        reb = (e + f) % c + b;
        while (reb >= c) {
            b += reb / c;
            reb = reb % c + reb / c;
        }
        printf("%d\n", b);
    }
    return 0;
}
