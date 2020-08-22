#include <stdio.h>
#include <inttypes.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    int t = 0;
    while (t < testcase) {
        int64_t x1, y1, x2, y2;
        int64_t d1, d2;
        scanf("%" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 "", &x1, &y1, &x2, &y2);
        d1 = (x1 + y1) * (x1 + y1 + 1);
        d2 = (x2 + y2) * (x2 + y2 + 1);
        d1 >>= 1;
        d2 >>= 1;
        d1 += x1;
        d2 += x2;
        printf("Case %d: %" PRId64 "\n", ++t, d2 - d1);
    }
    return 0;
}

