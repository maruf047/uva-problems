#include <stdio.h>

int main() {
    unsigned int testcase;
    scanf("%u", &testcase);
    while (testcase--) {
        unsigned int n, d;
        register unsigned int i = 0, mx = 0, mn = 99;
        scanf("%u", &n);
        for (i; i < n; ++i) {
            scanf("%u", &d);
            if (d > mx) {
                mx = d;
            }
            if (d < mn) {
                mn = d;
            }
        }
        printf("%u\n", (mx - mn) << 1);
    }
    return 0;
}
