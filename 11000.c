#include <stdio.h>
#include <inttypes.h>

int main() {
    unsigned long int n;
    register int i;
    register uint64_t m, f;
    scanf("%lu", &n);
    while (n != -1) {
        m = 0;
        f = 0;
        i = 0;
        if (n > 0)m = f + m + 1;
        while (++i < n) {
            m = f + m + 1;
            f = m - f - 1;
        }
        printf("%"PRId64" %"PRId64"\n", m, m + f + 1);
        scanf("%lu", &n);
    }
    return 0;
}
