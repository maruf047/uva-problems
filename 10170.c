#include <stdio.h>
#include <math.h>

int main() {
    long long int s, t, n;
    double d;
    int a;
    while (scanf("%d %lld", &a, &s) == 2) {
        d = (-2 * a + 1 + sqrt(4 * pow(a, 2) - 4 * a + 8 * s + 1)) / 2;
        n = (long long int) d;
        if (d - n > 0) {
            ++n;
        }
        t = a + n - 1;
        printf("%lld\n", t);
    }
    return 0;
}
