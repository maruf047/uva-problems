#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int64_t n;
        scanf("%" PRId64 "", &n);
        double r = (sqrt(4 * n + 1) - 1) / 2;
        if (r == (int) r) {
            printf("%" PRId64 "\n", (int) r);
        } else {
            printf("%" PRId64 "\n", ((int) r) + 1);
        }
    }
    return 0;
}
