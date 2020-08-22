#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t n;
    scanf("%" PRId64 "", &n);
    while (n >= 0) {
        printf("%" PRId64 "%%\n", n > 1 ? n * 25 : 0);
        scanf("%" PRId64 "", &n);
    }
    return 0;
}
