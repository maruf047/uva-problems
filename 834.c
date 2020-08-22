#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        printf("[%d", a / b);
        if (a % b != 0)printf(";");
        else printf("]\n");
        a = a % b;
        while (a % b != 0) {
            a = a + b;
            b = a - b;
            a = a - b;
            printf("%d", a / b);
            a = a % b;
            if (a % b != 0)printf(",");
            else printf("]\n");
        }
    }
    return 0;
}
