#include <stdio.h>
#include <math.h>

int mark[1000001] = {0};
int prime[78500];

int main() {
    int n = 1000000;
    register int i, pc = 0;
    mark[1] = 1;
    mark[0] = 1;
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
        int s = 1;
        for (i = 1; i < pc; ++i) {
            if (!mark[n - prime[i]]) {
                printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
                s = 0;
                break;
            }
        }
        if (s)printf("Goldbach's conjecture is wrong.\n");
        scanf("%d", &n);
    }
    return 0;
}