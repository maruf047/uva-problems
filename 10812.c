#include <stdio.h>

int main() {
    unsigned int testcase;
    unsigned long int a, b;
    unsigned register int t;
    scanf("%u", &testcase);
    t = testcase;
    while (t--) {
        scanf("%lu %lu", &a, &b);
        if (a >= b && ((a + b) % 2) == 0) {
            printf("%lu %lu\n", (a + b) / 2, (a - b) / 2);
            continue;
        }
        printf("impossible\n");
    }
    return 0;
}
