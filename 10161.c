#include <stdio.h>
#include <math.h>

int main() {
    unsigned long int t;
    scanf("%lu", &t);
    while (t != 0) {
        register unsigned long int b = sqrt(t), x, y, r;
        if (b % 2 == 0) {
            if (b * b == t) {
                printf("%lu 1\n", b);
            } else {
                r = b * b + b + 1;
                if (r == t) {
                    printf("%lu %lu\n", b + 1, b + 1);
                } else if (t < r) {
                    printf("%lu %lu\n", b + 1, t - b * b);
                } else {
                    printf("%lu %lu\n", b - t + r + 1, b + 1);
                }
            }
        } else {
            if (b * b == t) {
                printf("1 %lu\n", b);
            } else {
                r = b * b + b + 1;
                if (r == t) {
                    printf("%lu %lu\n", b + 1, b + 1);
                } else if (t < r) {
                    printf("%lu %lu\n", b - r + t + 1, b + 1);
                } else {
                    printf("%lu %lu\n", b + 1, b - t + r + 1);
                }
            }
        }
        scanf("%lu", &t);
    }
    return 0;
}
