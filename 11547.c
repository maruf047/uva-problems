#include <stdio.h>

int main() {
    int testcase, number;
    register int t, n;
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d", &number);
        n = number * 315 + 36962;
        n /= 10;
        n %= 10;
        printf("%d\n", n < 0 ? -n : n);
    }
    return 0;
}
