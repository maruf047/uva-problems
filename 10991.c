#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        double r1, r2, r3, a, b, c, ac1, ac2, ac3, at, A, B, C;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        a = r1 + r2;
        b = r2 + r3;
        c = r3 + r1;
        A = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
        B = acos((pow(c, 2) + pow(a, 2) - pow(b, 2)) / (2 * c * a));
        C = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
        at = b * c * sin(A);
        ac1 = pow(r1, 2) * B;
        ac2 = pow(r2, 2) * C;
        ac3 = pow(r3, 2) * A;
        printf("%.6lf\n", (at - (ac1 + ac2 + ac3)) / 2);
    }
    return 0;
}
