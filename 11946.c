#include <stdio.h>

int main() {
    char letter[10] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};
    char c;
    int num;
    scanf("%d\n", &num);
    register int n = num;
    while (n--) {
        register int s = 0;
        while (c = getchar()) {
            if (c != 10 && c != EOF) {
                s = 0;
                if (c > 47 && c < 58) {
                    putchar(letter[c - 48]);
                } else
                    putchar(c);
            } else {
                putchar(c);
                if (s == 0) {
                    s = 1;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}
