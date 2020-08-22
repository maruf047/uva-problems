#include <stdio.h>
#include <math.h>

int main() {

    register unsigned long int c = 0;
    int eq_type;
    register double x, y;
    double u, v, a, s, t;

    scanf("%d", &eq_type);

    while (eq_type != 0) {
        if (eq_type == 1) {
            scanf("%lf %lf %lf", &u, &v, &t);
            a = (v - u) / t;
            s = (u * t) + (.5 * a * t * t);
            printf("Case %lu: %.3lf %.3lf\n", ++c, s, a);
        } else if (eq_type == 2) {
            scanf("%lf %lf %lf", &u, &v, &a);
            t = (v - u) / a;
            s = (.5 * (v * v - u * u)) / a;
            printf("Case %lu: %.3lf %.3lf\n", ++c, s, t);
        } else if (eq_type == 3) {
            scanf("%lf %lf %lf", &u, &a, &s);
            v = sqrt(u * u + 2 * a * s);
            t = (v - u) / a;
            printf("Case %lu: %.3lf %.3lf\n", ++c, v, t);
        } else if (eq_type == 4) {
            scanf("%lf %lf %lf", &v, &a, &s);
            u = sqrt(v * v - 2 * a * s);
            t = (v - u) / a;
            printf("Case %lu: %.3lf %.3lf\n", ++c, u, t);
        }
        scanf("%d", &eq_type);
    }
    return 0;
}
