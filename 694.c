#include <stdio.h>

#define MAX 715827882

int main() {
    int num, lim;
    register int t = 0;
    scanf("%d %d", &num, &lim);
    while (num >= 0 && lim >= 0) {
        register int count = 1, a = num;
        while (a != 1) {
            if (a % 2 == 0) {
                a = a / 2;
            } else {
                if (a > MAX) break;
                a = 3 * a + 1;
            }
            if (a > lim) break;
            ++count;
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", ++t, num, lim, count);
        scanf("%d %d", &num, &lim);
    }
    return 0;
}
