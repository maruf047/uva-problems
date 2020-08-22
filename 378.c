#include <stdio.h>

int main() {
    int testcase, x0, x1, x2, x3, y0, y1, y2, y3, s;
    double m0, m1, c0, c1;
    register int t;
    scanf("%d", &testcase);
    t = testcase;
    printf("INTERSECTING LINES OUTPUT\n");
    while (t--) {
        s = 0;
        scanf("%d %d %d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
        if (x0 != x1) {
            m0 = (double) (y0 - y1) / (double) (x0 - x1);
        } else {
            s = 1;
        }
        if (x2 != x3) {
            m1 = (double) (y2 - y3) / (double) (x2 - x3);
        } else {
            if (s == 1)s = 3;
            else s = 2;
        }
        if (s != 1) {
            c0 = y0 - m0 * x0;
        }
        if (s != 2) {
            c1 = y2 - m1 * x2;
        }

        if ((s == 3 && x0 == x2) || (m0 == m1 && c0 == c1)) {
            printf("LINE\n");
        } else if (s == 3 || m0 == m1) {
            printf("NONE\n");
        } else {
            double x, y;
            if (s == 0) {
                x = (c1 - c0) / (m0 - m1);
                y = m0 * x + c0;
            } else if (s == 1) {
                x = x0;
                y = m1 * x + c1;
            } else {
                x = x3;
                y = m0 * x + c0;
            }
            printf("POINT %.2lf %.2lf\n", x, y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}