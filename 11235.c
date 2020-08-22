#include <stdio.h>

int main() {
    int num, cumi[100000];
    scanf("%d", &num);
    while (num != 0) {
        int n = 0, q, cn, pn = -100001;
        scanf("%d", &q);
        register int c = 1;
        scanf("%d", &pn);
        while (c < num) {
            scanf("%d", &cn);
            if (cn != pn) {
                pn = cn;
                cumi[n++] = c;
            }
            ++c;
        }
        cumi[n++] = c;
        while (q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            register int i = 0, f;
            while (cumi[i++] < a);
            f = cumi[i - 1] - (a - 1);
            if (b > cumi[i - 1]) {
                while (cumi[i] < b && i < n) {
                    if (cumi[i] - cumi[i - 1] > f)f = cumi[i] - cumi[i - 1];
                    ++i;
                }
                if (b - cumi[i - 1] > f)f = b - cumi[i - 1];
            } else {
                f = b - a + 1;
            }
            printf("%d\n", f);
        }
        scanf("%d", &num);
    }
    return 0;
}
