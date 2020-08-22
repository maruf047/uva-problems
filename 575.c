#include <stdio.h>

int main() {
    char c;
    register short int s = 0, l = 0;
    int skwbin[32];
    while (c = getchar()) {
        if (c != 10) {
            if (s == 1 && c == 48) {
                break;
            } else {
                s = 0;
            }
            skwbin[l++] = c - 48;
        } else {
            register long int pow = 1, sum = 0;
            while (l) {
                pow <<= 1;
                sum += skwbin[--l] * (pow - 1);
            }
            printf("%ld\n", sum);
            s = 1;
            l = 0;
        }
    }
    return 0;
}