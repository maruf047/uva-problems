#include <stdio.h>

int main() {
    int testcase, l, w, h;
    register int t = 0;
    scanf("%d", &testcase);
    while (++t <= testcase) {
        scanf("%d %d %d", &l, &w, &h);
        if (l > 20 || w > 20 || h > 20) {
            printf("Case %d: bad\n", t);
        } else {
            printf("Case %d: good\n", t);
        }
    }
    return 0;
}
