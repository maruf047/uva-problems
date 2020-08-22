#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double s = (a + b + c) / 2;
        double ta, at, ai, ae;
        ta = sqrt(s * (s - a) * (s - b) * (s - c));
        ai = PI * pow(ta / s, 2);
        at = ta - ai;
        ae = PI * pow((a * b * c) / (4 * ta), 2) - ta;
        printf("%.4lf %.4lf %.4lf\n", ae, at, ai);
    }
    return 0;
}
