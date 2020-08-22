#include <stdio.h>

int main() {
    char rev[35] = {'A', ' ', ' ', ' ', '3', ' ', ' ', 'H', 'I', 'L', ' ', 'J', 'M', ' ', 'O', ' ', ' ', ' ', '2',
                    'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' '};
    char c, str[20];
    register int l = 0;
    while ((c = getchar()) != EOF) {
        if (c != 10) {
            str[l++] = c;
        } else {
            int len = l, s1 = 0, s2 = 0;;
            register int i = 0;
            while (i <= --l) {
                int p;
                if (str[l] > 64 && str[l] < 91) {
                    p = str[l] - 65;
                } else {
                    p = str[l] - 23;
                }
                if (str[i] != str[l]) {
                    s1 = 1;
                }
                if (str[i] != rev[p]) {
                    s2 = 1;
                }
                ++i;
            }
            for (i = 0; i < len; ++i) {
                putchar(str[i]);
            }
            putchar(32);
            putchar(45);
            putchar(45);
            putchar(32);
            if (s1 == 1 && s2 == 1) {
                printf("is not a palindrome.");
            } else if (s1) {
                printf("is a mirrored string.");
            } else if (s2) {
                printf("is a regular palindrome.");
            } else {
                printf("is a mirrored palindrome.");
            }
            putchar(10);
            putchar(10);
            l = 0;
        }
    }
    return 0;
}
