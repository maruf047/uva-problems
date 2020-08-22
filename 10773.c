#include <stdio.h>
#include <math.h>

int main() {
    int testcase, t = 0;
    scanf("%d", &testcase);
    while (t++ < testcase) {
        double d, v, u;
        scanf("%lf %lf %lf", &d, &v, &u);
        double sub = u * u - v * v;
        if (sub <= 0 || u == 0 || v == 0) {
            printf("Case %d: can't determine\n", t);
        } else {
            double ts = d / sqrt(u * u), td = d / sqrt(sub);
            if (ts > td)printf("Case %d: %.3lf\n", t, ts - td);
            else printf("Case %d: %.3lf\n", t, td - ts);
        }
    }
    return 0;
}
