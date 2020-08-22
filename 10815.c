#include <stdio.h>

char words[10000][81];

int main() {
    char c;
    register int i = 0, l = 0;
    while ((c = getchar()) != EOF) {
        if (c > 96 && c < 123) {
            words[i][l++] = c;
        } else if (c > 64 && c < 91) {
            c += 32;
            words[i][l++] = c;
        } else {

            l=0;
            ++i;
        }
    }
    return 0;
}
