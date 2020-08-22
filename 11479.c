#include <stdio.h>

int main() {
    int testcase;
    long long int a, b, c;
    unsigned register int t = 0;
    scanf("%d", &testcase);
    while (t++ < testcase) {
        scanf("%lli %lli %lli", &a, &b, &c);

        if (a >= b + c || b >= a + c || c >= a + b || a <= 0 || b <= 0 || c <= 0) {
            printf("Case %u: Invalid\n", t);
        } else if (a == b && b == c) {
            printf("Case %u: Equilateral\n", t);
        } else if (a == b || b == c || a == c) {
            printf("Case %u: Isosceles\n", t);
        } else {
            printf("Case %u: Scalene\n", t);
        }
    }
    return 0;
}
