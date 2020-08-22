#include <stdio.h>

/*
 * Just print the number. Total calculation not needed.
 */

int main() {
    int c = 1, n, num=2;
    while (c < 1500) {
        n=num;
        while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
            if (n % 2 == 0) {
                n = n / 2;
                if (n == 1) {
                    ++c;
                    printf("n-> %d c-> %d\n", num, c);
                    break;
                }
            } else if (n % 3 == 0) {
                n = n / 3;
                if (n == 1) {
                    ++c;
                    printf("n-> %d c-> %d\n", num, c);
                    break;
                }
            } else if (n % 5 == 0) {
                n = n / 5;
                if (n == 1) {
                    ++c;
                    printf("n-> %d c-> %d\n", num, c);
                    break;
                }
            } else {
                break;
            }
        }
        ++num;
    }
    return 0;
}