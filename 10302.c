#include <stdio.h>
#include <inttypes.h>

int main() {
    uint64_t n;
    while (scanf("%" PRIu64 "", &n) == 1) {
        n = n * (n + 1);
        n >>= 1;
        n *= n;
        printf("%" PRIu64 "\n", n);
    }
    return 0;
}