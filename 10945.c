#include <stdio.h>

int main() {
    register unsigned int l = 0;
    unsigned char c, s[1000];
    int cap[4] = {0};
    int st = 0;
    while (1) {
        c = getchar();
        if (c != 10) {
            if (c > 64 && c < 91) {
                if (l >= 4) {
                    s[l++] = c + 32;
                } else if (l < 4) {
                    cap[l] = 1;
                    s[l++] = c;
                }
                if (l == 4 && s[0] == 68 && s[1] == 79 && s[2] == 78 && s[3] == 69) {
                    break;
                } else if (l == 4) {
                    if (cap[0]) {
                        s[0] = s[0] + 32;
                        cap[0] = 0;
                    }
                    if (cap[1]) {
                        s[1] = s[1] + 32;

                        cap[1] = 0;
                    }
                    if (cap[2]) {
                        s[2] = s[2] + 32;
                        cap[2] = 0;
                    }
                    if (cap[3]) {
                        s[3] = s[3] + 32;
                        cap[3] = 0;
                    }
                }
            } else if (c > 96 && c < 123) {
                if (l == 4) {
                    if (cap[0]) {
                        s[0] = s[0] + 32;
                        cap[0] = 0;
                    }
                    if (cap[1]) {
                        s[1] = s[1] + 32;
                        cap[1] = 0;
                    }
                    if (cap[2]) {
                        s[2] = s[2] + 32;
                        cap[2] = 0;
                    }
                    if (cap[3]) {
                        s[3] = s[3] + 32;
                        cap[3] = 0;
                    }
                }
                s[l++] = c;
            }
        } else {
            register unsigned long int i = 0, m = 1;
            i = 0;
            while (i < l / 2) {
                if (s[i] != s[l - i - 1]) {
                    printf("Uh oh..\n");
                    m = 0;
                    break;
                }
                ++i;
            }
            if (m) {
                printf("You won't be eaten!\n");
            }
            l = 0;
        }
    }
    return 0;
}
