#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t l;
    scanf("%"PRId64"", &l);
    while (l >= 0) {
        l != 0 ? printf("%" PRId64 "\n", l * (l + 1) >> 1 + 1) : printf("1\n");
        scanf("%" PRId64 "", &l);
    }
    return 0;
}
