#include <stdio.h>

int main() {
    char c;
    char str[200];
    register int i = 0, j;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n') {
            str[i] = c;
            i++;
        } else {
            while (i--) {
                printf("%c", str[i]);
            }
            i++;
            printf("%c", c);
        }
    }
    return 0;
}