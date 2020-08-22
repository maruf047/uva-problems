#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        double a1, a2, a3, b12, b23, c12, c23, g, f, c, r;
        a1 = pow(x1, 2) + pow(y1, 2);
        a2 = pow(x2, 2) + pow(y2, 2);
        a3 = pow(x3, 2) + pow(y3, 2);
        b12 = x1 - x2;
        b23 = x2 - x3;
        c12 = y1 - y2;
        c23 = y2 - y3;
        g = ((c23 * (a2 - a1)) - (c12 * (a3 - a2))) / (2 * (b12 * c23 - b23 * c12));
        f = (a2 - a1 - 2 * g * b12) / (2 * c12);
        c = -a1 - 2 * g * x1 - 2 * f * y1;
        r = sqrt(pow(g, 2) + pow(f, 2) - c);
        printf("(x");
        if (g >= 0)printf(" + %.3lf)^2 + ", g); else printf(" - %.3lf)^2 + ", -g);
        printf("(y");
        if (f >= 0)printf(" + %.3lf)^2 = ", f); else printf(" - %.3lf)^2 = ", -f);
        printf("%.3lf^2\n", r);
        printf("x^2 + y^2");
        if (g >= 0)printf(" + %.3lfx", 2 * g); else printf(" - %.3lfx", -2 * g);
        if (f >= 0)printf(" + %.3lfy", 2 * f); else printf(" - %.3lfy", -2 * f);
        if (c >= 0)printf(" + %.3lf = 0\n\n", c); else printf(" - %.3lf = 0\n\n", -c);
    }
    return 0;
}
