#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    while (num != 0) {
        register int j = 0, n = num, a = 0, b = 0, m, i = 0;
        while (n > 0) {
            m = n % 2;
            if (m) {
                ++i;
                if (i % 2 == 1) {
                    a += 1 << (j);
                } else {
                    b += 1 << (j);
                }
            }
            ++j;
            n /= 2;
        }
        printf("%d %d\n", a, b);
        scanf("%d", &num);
    }
    return 0;
}
