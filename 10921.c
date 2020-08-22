#include <stdio.h>

int main() {
    int map[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    char c;
    while ((c = getchar()) != EOF) {
        if (c > 64 && c < 91) {
            putchar(map[c - 65] + 48);
        } else {
            putchar(c);
        }
    }
    return 0;
}