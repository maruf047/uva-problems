#include <stdio.h>

int main() {
    char c;
    register int i = 0, counting = 0;
    while ((c = getchar()) != EOF) {
        if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
            if (counting == 0) {
                i++;
                counting = 1;
            }
        } else if (c == '\n') {
            printf("%d\n", i);
            i = 0;
            counting = 0;
        } else {
            counting = 0;
        }
    }
    return 0;
}
