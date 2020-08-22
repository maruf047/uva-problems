#include <stdio.h>

inline void scanint(unsigned long int *x) {
    register char c = getchar();
    *x = 0;
    for (; (c < 48) || (c > 57); c = getchar());
    for (; (c > 47) && (c < 58); c = getchar())
        *x = (int) ((((*x) << 1) + ((*x) << 3)) + c - 48);
}

inline void printint(unsigned long int n) {
    if (n == 0) {
        putchar('0');
    } else {
        char buf[11];
        buf[10] = '\n';
        int i = 9;
        while (n) {
            buf[i--] = n % 10 + '0';
            n /= 10;
        }
        i++;
        while (buf[i] != '\n')
            putchar(buf[i++]);
    }
}

int main() {
    unsigned long int a;
    scanint(&a);
    while (a != 0) {
        putchar('f');
        putchar('9');
        putchar('1');
        putchar('(');
        printint(a);
        putchar(')');
        putchar(' ');
        putchar('=');
        putchar(' ');
        a > 100 ? printint(a - 10) : printint(91);
        putchar('\n');
        scanint(&a);
    }
    return 0;
}
