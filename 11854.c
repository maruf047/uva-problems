#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    while (a != 0 || b != 0 || c != 0) {
        if (a > b) {
            if (a > c) {
                if (a * a == b * b + c * c) {
                    printf("right");
                } else {
                    printf("wrong");
                }
            } else {
                if (c * c == b * b + a * a) {
                    printf("right");
                } else {
                    printf("wrong");
                }
            }
        } else {
            if (b > c) {
                if (b * b == a * a + c * c) {
                    printf("right");
                } else {
                    printf("wrong");
                }
            } else {
                if (c * c == b * b + a * a) {
                    printf("right");
                } else {
                    printf("wrong");
                }
            }
        }
        printf("\n");
        scanf("%d %d %d", &a, &b, &c);
    }
    return 0;
}

