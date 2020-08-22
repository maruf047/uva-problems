#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    register int t = testcase;
    register int i = 0;
    while (t--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0 || b == 0 || c == 0 || d == 0 || a >= b + c + d || b >= a + c + d || c >= a + b + d ||
            d >= a + b + c) {
            printf("banana\n");
        } else if (a == b && b == c && c == d) {
            printf("square\n");
        } else if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c)) {
            printf("rectangle\n");
        } else {
            printf("quadrangle\n");
        }
    }
    return 0;
}
