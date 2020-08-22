#include <stdio.h>

int main() {
    unsigned int a, b;
    register int c, carry = 0;
    scanf("%d %d", &a, &b);
    while (a != 0 || b != 0) {
        carry = c = 0;
        while (a / 10 != 0 || b / 10 != 0) {
            if (a % 10 + b % 10 + carry > 9) {
                c++;
                carry = 1;
            } else {
                carry = 0;
            }
            a = a / 10;
            b = b / 10;
        }
        if (a % 10 + b % 10 + carry > 9)c++;
        scanf("%d %d", &a, &b);
        if (c > 0) {
            if (c == 1) {
                printf("1 carry operation.\n");
                continue;
            }
            printf("%d carry operations.\n", c);
            continue;
        }
        printf("No carry operation.\n");
    }
    return 0;
}

