#include <stdio.h>
#include <math.h>

int main() {
    int n;
    register int i = 0;
    double pi = 2 * acos(0);
    scanf("%d", &n);
    while (n > 2) {
        double a, t = (2 * pi) / n;
        double x = pi / (n * sin(t));
        scanf("%lf", &a);
        printf("Case %d: %.5lf %.5lf\n", ++i, a * ((2 * x) - 1), a * (1 - ((cos(t) + 1) * x)));
        scanf("%d", &n);
    }
    return 0;
}


