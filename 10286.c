#include <stdio.h>
#include <math.h>

int main() {
    double side;
    double pi = acos(-1);
    while (scanf("%lf", &side) == 1) {
        printf("%.10lf\n", (side * sin((108 * pi) / 180)) / sin((63 * pi) / 180));
    }
    return 0;
}
