#include <stdio.h>

int main() {
    char c, p;
    unsigned long int num;
    while (scanf("%lu", &num) == 1) {
        printf("%lu\n", num - 1);
    }
    return 0;
}
