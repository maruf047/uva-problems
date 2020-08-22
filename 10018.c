#include <stdio.h>

int main() {
    int testcase;
    unsigned int num;
    scanf("%d", &testcase);
    while (testcase--) {
        int a[11], b[11], sum[11] = {0};
        register unsigned int i = 0, l, iter = 0;
        register unsigned int nn, p = 1, c = 0, len = 0;
        scanf("%u", &num);
        l = 0;
        nn = num;
        while (nn) {
            a[l++] = nn % 10;
            nn /= 10;
        }
        len = l;
        while (l--)b[len - l - 1] = a[l];
        while (p) {
            p = 0;
            i = 0, l = len;
            while (i < l) {
                int x = a[i] + b[i] + c;
                sum[i++] = x % 10;
                c = x > 9 ? 1 : 0;
            }

            if (c)sum[i++] = 1;
            len = l = i;
            --l;
            ++iter;
            for (i = 0; i < l; ++i, --l) {
                if (sum[i] != sum[l]) {
                    p = 1;
                    c = 0;
                    for (i = 0; i < len; ++i) {
                        a[i] = b[len - i - 1] = sum[i];
                    }
                }
            }
            if (p)continue;
            else {
                printf("%d ", iter);
                for (i = 0; i < len; ++i) {
                    printf("%d", sum[i]);
                }
                putchar(10);
            }
        }
    }

    return 0;
}
