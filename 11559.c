#include <stdio.h>

int main() {
    int n, b, h, w;
    while (scanf("%d", &n) == 1) {
        scanf("%d %d %d", &b, &h, &w);
        register int i, min = b + 1;
        for (i = 0; i < h; ++i) {
            int p;
            scanf("%d", &p);
            register int s = 0, j;
            for (j = 0; j < w; ++j) {
                int v;
                scanf("%d", &v);
                if (n <= v)s++;
            }
            if (s && p * n < min)min = p * n;
        }
        if (min < b)printf("%d\n", min);
        else printf("stay home\n");
    }
    return 0;
}
