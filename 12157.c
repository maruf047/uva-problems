#include <stdio.h>

int main() {
    int testcase, t = 0;
    scanf("%d", &testcase);
    while (t < testcase) {
        int n, d;
        scanf("%d", &n);
        register int i, m = 0, j = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &d);
            m += ((d / 30) + 1) * 10;
            j += ((d / 60) + 1) * 15;
        }
        printf("Case %d: ", ++t);
        if (m < j)printf("Mile %d\n", m);
        else if (j < m)printf("Juice %d\n", j);
        else printf("Mile Juice %d\n", m);
    }
    return 0;
}
