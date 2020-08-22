#include <stdio.h>

int max = 50;

unsigned long int lookup[47] = {0};

unsigned long int fib_tab(int n) {
    register int i;
    lookup[0] = 1;
    lookup[1] = 2;
    for (i = 2; i <= n; ++i) {
        lookup[i] = lookup[i - 2] + lookup[i - 1];
    }
    return lookup[n];
}

int main() {
    fib_tab(max);
    int num;
    scanf("%d", &num);
    while (num!=0) {
        printf("%lu",lookup[num-1]);
        putchar(10);
        scanf("%d", &num);
    }
    return 0;
}
