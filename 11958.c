#include <stdio.h>
#include <stdlib.h>

int main() {
    int testcase, c_h, c_m, a_h, a_m, d_m, buses;
    register int t = 0, min, b, time;

    scanf("%d", &testcase);
    while (t < testcase) {
        min = 2441;
        scanf("%d %d:%d", &buses, &c_h, &c_m);
        b = buses;
        while (b--) {
            scanf("%d:%d %d", &a_h, &a_m, &d_m);
            if (a_h < c_h) {
                a_h += 24;
            }
            if (a_m < c_m) {
                if (a_h == c_h) {
                    a_h += 24;
                }
                a_m += 60;
                a_h -= 1;
            }
            time = (a_h - c_h) * 60 + a_m - c_m + d_m;
            if (time < min) {
                min = time;
            }
        }
        printf("Case %d: %d\n", ++t, min);
    }
    return 0;
}
