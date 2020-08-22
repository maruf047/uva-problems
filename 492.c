#include <stdio.h>

int main() {
    char c;
    register int has_conso_first = 0, has_first = 0;
    register char c0;
    while ((c = getchar()) != EOF) {
        if ((c < 123 && c > 96) || (c > 64 && c < 91)) {
            if (has_first) {
                printf("%c", c);
            } else {
                if (c == 69 || c == 101 || c == 97 || c == 65 || c == 111 || c == 79 || c == 105 || c == 73 ||
                    c == 117 || c == 85) {
                    printf("%c", c);
                } else {
                    c0 = c;
                    has_conso_first = 1;
                }
                has_first = 1;
            }
        } else {
            if (has_first == 0) {
                printf("%c", c);
            } else if (has_conso_first == 1) {
                printf("%cay%c", c0, c);
                has_first = 0;
                has_conso_first = 0;
            } else {
                printf("ay%c", c);
                has_first = 0;
            }
        }
    }
    return 0;
}
