#include <stdio.h>

int main() {
    int testcase, n, k, p;
    register int t = 0, f;
    scanf("%d", &testcase);
    while (t < testcase) {
        scanf("%d %d %d", &n, &k, &p);
        f = (k + p) % n;
        printf("Case %d: %d\n", ++t, f == 0 ? n : f);
    }
    return 0;
}
