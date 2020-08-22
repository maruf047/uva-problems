#include <stdio.h>
#include <math.h>

#define PI  3.14159265358979

int main() {
    double r, n;
    while (scanf("%lf %lf", &r, &n) == 2) {
        printf("%.3lf\n", sin((2 * PI) / n) * pow(r, 2) * n / 2);
    }
    return 0;
}
