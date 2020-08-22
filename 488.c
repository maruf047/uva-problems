#include <stdio.h>

int main() {
    int testcase, a, f;
    register int t, i, j, k;
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d %d", &a, &f);
        for (i = 0; i < f; i++) {
            for (j = 1; j <= a; j++) {
                for (k = 1; k <= j; k++) {
                    printf("%d", j);
                }
                printf("\n");
            }
            for (j = a - 1; j > 0; j--) {
                for (k = j; k > 0; k--) {
                    printf("%d", j);
                }
                printf("\n");
            }
            if (i < f - 1)printf("\n");
        }
        if (t)printf("\n");
    }
    return 0;
}
