#include <stdio.h>

int main() {
    register int has_digit = 0, digit = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '!' || c == '\n') {
            printf("\n");
            has_digit = 0;
        } else if (c > 47 && c < 58) {
            if (has_digit) {
                digit += (c - '0');
                continue;
            }
            has_digit = 1;
            digit = c - '0';
        } else if (c == 'b') {
            has_digit = 0;
            while (digit--) {
                printf(" ");
            }
        } else {
            has_digit = 0;
            while (digit--) {
                printf("%c", c);
            }
        }
    }
    return 0;
}
