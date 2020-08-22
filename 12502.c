#include <stdio.h>

int main() {
    int testcase, a, b, z;
    register int t;
    register int h;
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d %d %d", &a, &b, &z);
        h = (a + b) * 20;
        printf("%d\n", (z * (a * 60 - h)) / h);
    }
    return 0;
}
