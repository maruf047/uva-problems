#include <stdio.h>

int main() {
    int testcase, a, b;
    register int t, i, z;
    scanf("%d", &testcase);
    t = testcase;
    printf("Lumberjacks:\n");
    while (t--) {
        z = 1;
        scanf("%d %d", &a, &b);
        if (a > b) {
            for (i = 2; i < 10; i++) {
                a = b;
                scanf("%d", &b);
                if (b >= a) {
                    z = 0;
                }
            }
            if (z)printf("Ordered\n");
            else printf("Unordered\n");
        } else {
            for (i = 2; i < 10; i++) {
                a = b;
                scanf("%d", &b);
                if (a >= b) {
                    z = 0;
                }
            }
            if (z)printf("Ordered\n");
            else printf("Unordered\n");
        }
    }
    return 0;
}
