#include <stdio.h>

int main() {
    int testcase, t1, t2, t3, a, h1, h2, h3, h;
    register int t = 0, total;
    scanf("%d", &testcase);
    while (t++ < testcase) {
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &t3, &a, &h1, &h2, &h3);
        if (h1 < h2) {
            if (h1 < h3) {
                h = (h3 + h2) / 2;
            } else {
                h = (h1 + h2) / 2;
            }
        } else {
            if (h2 < h3) {
                h = (h3 + h1) / 2;
            } else {
                h = (h1 + h2) / 2;
            }
        }
        total = t1 + t2 + t3 + a + h;
        printf("Case %d: ", t);
        if (total > 89) {
            printf("A");
        } else if (total > 79) {
            printf("B");
        } else if (total > 69) {
            printf("C");
        } else if (total > 59) {
            printf("D");
        } else {
            printf("F");
        }
        printf("\n");
    }
    return 0;
}
