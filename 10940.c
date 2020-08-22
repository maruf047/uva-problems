#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    while (num != 0) {
        int pow = 1 << 19;
        while (!(num & pow)) {
            pow >>= 1;
        }
        int rem = num - pow;
        printf("%d\n", rem == 0 ? pow : rem << 1);
        scanf("%d", &num);
    }
    return 0;
}