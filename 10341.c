#include <stdio.h>
#include <math.h>

#define LIMIT 1e-9

int main() {
    int p, q, r, s, t, u;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
        double a, b, m, fa, fb, fm;
        a = 0, b = 1;
        fa = p * (1 / exp(a)) + q * sin(a) + r * cos(a) + s * tan(a) + t * a * a + u;
        fb = p * (1 / exp(b)) + q * sin(b) + r * cos(b) + s * tan(b) + t * b * b + u;
        if (fa * fb > 0) {
            printf("No solution\n");
        } else {
            while ((b - a) >= LIMIT) {

                if (fa == 0) {
                    break;
                }
                if (fb == 0) {
                    a = b;
                    break;
                }

                m = (a + b) / 2;
                fm = p * (1 / exp(m)) + q * sin(m) + r * cos(m) + s * tan(m) + t * m * m + u;
                if (fa * fm < 0) {
                    b = m;
                    fb = fm;
                } else {
                    a = m;
                    fa = fm;
                }
            }

            printf("%0.4lf\n", a);
        }
    }
    return 0;
}



