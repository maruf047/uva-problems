#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a[1000000], b[1000000], sum[1000001], num;
        scanf("\n%d", &num);
        register int n = num, c = 0;
        while (n) {
            --n;
            scanf("%d %d", &a[n], &b[n]);
        }
        while (n < num) {
            int x = a[n] + b[n] + c;
            sum[n] = x % 10;
            c = x > 9 ? 1 : 0;
            ++n;
        }
        if (c)sum[n++] = 1;
        while (n--) {
            putchar(48 + sum[n]);
        }
        putchar(10);
        if (t)putchar(10);
    }
    return 0;
}
