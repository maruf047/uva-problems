#include <stdio.h>
#include <math.h>

int mark[18409201] = {0};
int twin[100000];

int main() {

    int n = 18409201;
    register int i, tpc = 0;
    mark[1] = 1;
    mark[0] = 1;
    for (i = 4; i <= n; i += 2)mark[i] = 1;
    int limit = sqrt(n * 1.0) + 2;
    for (i = 3; i <= n; i += 2) {
        if (!mark[i]) {
            if (!mark[i - 2]) twin[tpc++] = i - 2;
            if (i <= limit) {
                int j;
                for (j = i * i; j <= n; j += i * 2)mark[j] = 1;
            }
        }
    }
    while (scanf("%d", &n) == 1) {
        int p = twin[n - 1];
        printf("(%d, %d)\n", p, p + 2);
    }
    return 0;
}
