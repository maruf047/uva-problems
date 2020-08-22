#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while (a != 0 || b != 0 || c != 0 || d != 0) {
        printf("%d\n", 1080 + (a < b ? 40 + a - b : a - b) * 9 + (c < b ? 40 + c - b : c - b) * 9 +
                       (c < d ? 40 + c - d : c - d) * 9);
        scanf("%d %d %d %d", &a, &b, &c, &d);
    }
    return 0;
}
