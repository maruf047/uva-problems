#include <stdio.h>
#include <inttypes.h>

int main() {
    uint64_t n, on, tn;
    while (scanf("%"PRId64"", &on) != EOF) {
        if (on > 1) {
            tn = (on + 1) / 2;
            n = tn * tn;
            printf("%"PRId64" %"PRId64"\n", on, n);
            printf("%"PRId64"\n", (n * n) - ((n - 3) * (n - 3)));
            continue;
        }
        printf("%"PRId64"\n", 0);
    }
    return 0;
}
