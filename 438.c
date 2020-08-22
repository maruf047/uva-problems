#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        double a, b, c, s, t, r;
        a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        s = (a + b + c) / 2;
        t = sqrt(s * (s - a) * (s - b) * (s - c));
        r = (a * b * c) / (4 * t);
        printf("%.2lf\n", 2 * PI * r);
    }
    return 0;
}
