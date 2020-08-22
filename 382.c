#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("PERFECTION OUTPUT\n");
    while (n != 0) {
        register int i = 2, s = 1;
        if (n != 1) {
            int d = n / i;
            while (i < d) {
                if (n % i == 0) {
                    s += i + d;
                }
                ++i;
                d = n / i;
            }
            if (n % i == 0 && i == d) {
                s += i;
            }
        } else {
            s = 0;
        }
        if (s > n) {
            printf("%5d  ABUNDANT\n", n);
        } else if (s < n) {
            printf("%5d  DEFICIENT\n", n);
        } else {
            printf("%5d  PERFECT\n", n);
        }
        scanf("%d", &n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}