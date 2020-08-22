#include <stdio.h>

int main() {
    register int t = 0;
    int num, val[105];
    int k, l;
    while (scanf("%d\n", &num) != EOF) {
        int sum[20005] = {0}, s = 1;
        register int i, j;
        for (i = 0; i < num; ++i) {
            scanf("%d", &val[i]);
        }
        if (val[1] > 0) {
            for (i = 0; i < num - 1; ++i) {
                int a = val[i];
                for (j = i; j < num; ++j) {
                    int b = val[j];
                    if (a <= b && a + b > 1 && a + b < 20005 && sum[a + b] == 0) {
                        sum[a + b] = 1;
                    } else {
                        s = 0;
                        break;
                    }
                }
                if (s == 0)break;
            }
        } else {
            s = 0;
        }
        s ? printf("Case #%d: It is a B2-Sequence.\n\n", ++t) : printf("Case #%d: It is not a B2-Sequence.\n\n", ++t);
    }
    return 0;
}
