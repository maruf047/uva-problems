#include <stdio.h>
#include <math.h>

int mark[1000001] = {0};
int prime[79000];

int main() {
    int num = 1000001;
    register int pc = 0, i;
    mark[1] = 1;
    for (i = 4; i <= num; i = i + 2) {
        mark[i - 1] = 1;
    }
    prime[pc++] = 2;
    int limit = sqrt(num * 1.0) + 2;
    for (i = 3; i <= num; i = i + 2) {
        if (!mark[i - 1]) {
            prime[pc++] = i;
            if (i <= limit) {
                register int j;
                for (j = i * i; j <= num; j = j + i * 2) {
                    mark[j - 1] = 1;
                }
            }
        }
    }

    for (i = 0; i < 9600; ++i) {
        int pn = prime[i];
        register int l = 0, j = 0;
        int digits[6];
        while (pn != 0) {
            digits[l++] = pn % 10;
            pn /= 10;
        }
        int lim = l / 2, s = 1;
        for (j = 0; j < lim; ++j) {
            if (digits[j] != digits[l - j - 1])s = 0;
        }
        if (s) {
            mark[prime[i]] = -1;
        }
    }

    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", n << 1);
        if (mark[n] == -1)break;
    }
    return 0;
}
