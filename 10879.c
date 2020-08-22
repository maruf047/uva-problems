#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    register int t = 0;
    while (t++ < testcase) {
        int k;
        scanf("%d", &k);
        printf("Case #%d: %d = ", t, k);
        int a = 2;
        while (k % a != 0)++a;
        printf("%d * %d = ", a, k / a);
        ++a;
        while (k % a != 0)++a;
        printf("%d * %d\n", a, k / a);
    }
    return 0;
}
