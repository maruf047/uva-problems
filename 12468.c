#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while (a != -1 && b != -1) {
        int c = a > b ? a - b : b - a;
        int d = a > b ? 100 + b - a : 100 + a - b;
        if (c < d) {
            printf("%d\n", c);
        } else {
            printf("%d\n", d);
        }
        scanf("%d %d", &a, &b);
    }
    return 0;
}
