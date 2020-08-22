#include <stdio.h>
#include <math.h>

int mark[32770] = {0};
int prime[3515];

int main() {
    int n = 32770;
    register int i, pc = 0;
    mark[1] = 0;
    mark[0] = 1;
    prime[pc++] = 1;
    for (i = 4; i <= n; i = i + 2) {
        mark[i] = 1;
    }
    prime[pc++] = 2;
    int limit = sqrt(n * 1.0) + 2;
    for (i = 3; i <= n; i = i + 2) {
        if (!mark[i]) {
            prime[pc++] = i;
            if (i <= limit) {
                int j;
                for (j = i * i; j <= n; j = j + i * 2) {
                    mark[j] = 1;
                }
            }
        }
    }
    scanf("%d", &n);
    while (n != 0) {
        register int c = 0;
        for (i = 1; i < pc; ++i) {
            int num = prime[i];
            if (!mark[n - num]) {
                if (num > n - num)break;
                ++c;
            }
        }
        printf("%d\n", c);
        scanf("%d", &n);
    }
    return 0;
}
