#include <stdio.h>
#include <inttypes.h>

uint64_t fract(int x) {
    if (x == 1)return 1;
    else return x * fract(x - 1);
}

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        if (a < 0) {
            if (a % 2 == 0)printf("Underflow!\n");
            else printf("Overflow!\n");
        } else if (a < 8) {
            printf("Underflow!\n");
        } else if (a > 13) {
            printf("Overflow!\n");
        } else {
            printf("%"PRId64"\n", fract(a));
        }
    }
    return 0;
}

