#include <stdio.h>

int main() {
    unsigned long int num;
    scanf("%lu", &num);
    while (num != 0) {
        unsigned char b[32];
        register unsigned long int l = 0, n = num, i = 32;
        while (n) {
            if (n % 2 == 1) {
                ++l;
                b[--i] = 49;
            } else {
                b[--i] = 48;
            }
            n = n >> 1;
        }
        printf("The parity of ");
        while (i < 32) {
            putchar(b[i++]);
        }
        printf(" is %lu (mod 2).\n", l);
        scanf("%lu", &num);
    }
    return 0;
}
