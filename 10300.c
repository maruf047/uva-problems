#include <stdio.h>

int main() {
    long int testcase, nof, f, p;
    register long int t, s, n;
    scanf("%ld", &testcase);
    t = testcase;
    while (t--) {
        scanf("%ld", &nof);
        n = nof;
        s = 0;
        while (n--) {
            scanf("%ld %*ld %ld", &f, &p);
            s += f * p;
        }
        printf("%ld\n", s);
    }
    return 0;
}
