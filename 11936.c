#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    register int t = testcase;
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a < b + c && b < c + a && c < a + b ? printf("OK") : printf("Wrong!!");
        putchar(10);
    }
    return 0;
}