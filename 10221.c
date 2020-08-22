#include <stdio.h>
#include <math.h>

#define PI  3.14159265358979
#define RE 6440

int main() {
    int s;
    while (scanf("%d", &s) == 1) {
        int t;
        char c;
        double a, r;
        scanf("%d ", &t);
        c = getchar();
        if (c == 109) {
            t = t % 21600;
            if (t > 10800)t = 21600 - t;
            a = (t * PI) / 10800;
            getchar();
            getchar();
        } else {
            t %= 360;
            if (t > 180)t = 360 - t;
            a = (t * PI) / 180;
            getchar();
            getchar();
        }
        c = getchar();
        r = (double) s + RE;
        printf("%.6lf %.6lf\n", r * a, 2 * r * sin(a / 2));
    }
    return 0;
}
