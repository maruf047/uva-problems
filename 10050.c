#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    register int t = testcase;
    while (t--) {
        int n, p;
        scanf("%d\n%d", &n, &p);
        int d[3651] = {0};
        register int i, j;
        for (i = 0; i < p; ++i) {
            int x;
            scanf("%d", &x);
            for (j = x - 1; j < n; j += x) {
                d[j] = 1;
            }
        }
        j = 0;
        for (i = 0; i < n; ++i) {
            if (d[i] && (i % 7 != 5) && (i % 7 != 6)) {
                ++j;
            }
        }
        printf("%d\n", j);
    }
    return 0;
}
