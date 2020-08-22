#include <stdio.h>

int main() {
    int testcase, m, n;
    register int t;
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d %d", &m, &n);
        if ((m - 1) % 3 == 2) {
            m = (m - 1) / 3;
            m++;
        } else {
            m = (m - 1) / 3;
        }
        if ((n - 1) % 3 == 2) {
            n = (n - 1) / 3;
            n++;
        } else {
            n = (n - 1) / 3;
        }
        printf("%d\n", m * n);
    }
    return 0;
}
