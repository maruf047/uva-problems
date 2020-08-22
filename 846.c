#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a != b) {
            int n;
            double d = (sqrt(1 + 4 * (b - a)) - 1) / 2;
            if (d == (int) d) {
                n = d;
            } else {
                n = d + 1;
            }
            if (b - a <= n * n) {
                printf("%d\n", 2 * n - 1);
            } else {
                printf("%d\n", 2 * n);
            }
        } else {
            printf("0\n");
        }
    }
    return 0;
}

