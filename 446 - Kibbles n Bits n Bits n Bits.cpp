#include <stdio.h>

//Could be more clean
int main() {
    int testcase;
    scanf("%d\n", &testcase);
    int bin[16] = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};
    register int t = testcase;
    while (t--) {
        char c;
        int dec[3] = {0};
        int dec1[3] = {0};
        int s = 0, l = 0;
        register int i = 0, d;
        while ((c = getchar()) != 32) {
            if (c > 47 && c < 58) {
                d = c - 48;
                dec[i++] = d;
            } else {
                d = c - 55;
                dec[i++] = d;
            }
            ++l;
        }
        putchar(48);
        if (l == 3) {
            s += dec[0] * 256 + dec[1] * 16 + dec[2];
            printf("%04d%04d%04d", bin[dec[0]], bin[dec[1]], bin[dec[2]]);
        } else if (l == 2) {
            putchar(48);
            putchar(48);
            putchar(48);
            putchar(48);
            s += dec[0] * 16 + dec[1];
            printf("%04d%04d", bin[dec[0]], bin[dec[1]]);
        } else {
            putchar(48);
            putchar(48);
            putchar(48);
            putchar(48);
            putchar(48);
            putchar(48);
            putchar(48);
            putchar(48);
            s += dec[0];
            printf("%04d", bin[dec[0]]);
        }
        putchar(c);
        c = getchar();
        l = i = 0;
        if (c == 43) {
            getchar();
            putchar(c);
            putchar(32);
            putchar(48);
            while ((c = getchar()) != 10) {
                if (c > 47 && c < 58) {
                    d = c - 48;
                    dec1[i++] = d;
                } else {
                    d = c - 55;
                    dec1[i++] = d;
                }
                ++l;
            }
            if (l == 3) {
                s += dec1[0] * 256 + dec1[1] * 16 + dec1[2];
                printf("%04d%04d%04d", bin[dec1[0]], bin[dec1[1]], bin[dec1[2]]);
            } else if (l == 2) {
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                s += dec1[0] * 16 + dec1[1];
                printf("%04d%04d", bin[dec1[0]], bin[dec1[1]]);
            } else {
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                s += dec1[0];
                printf("%04d", bin[dec1[0]]);
            }
        } else {
            getchar();
            putchar(c);
            putchar(32);
            putchar(48);
            while ((c = getchar()) != 10) {
                if (c > 47 && c < 58) {
                    d = c - 48;
                    dec1[i++] = d;
                } else {
                    d = c - 55;
                    dec1[i++] = d;
                }
                l++;
            }
            if (l == 3) {
                s -= dec1[0] * 256 + dec1[1] * 16 + dec1[2];
                printf("%04d%04d%04d", bin[dec1[0]], bin[dec1[1]], bin[dec1[2]]);
            } else if (l == 2) {
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                s -= dec1[0] * 16 + dec1[1];
                printf("%04d%04d", bin[dec1[0]], bin[dec1[1]]);
            } else {
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                putchar(48);
                s -= dec1[0];
                printf("%04d", bin[dec1[0]]);
            }
        }
        putchar(32);
        putchar(61);
        putchar(32);
        printf("%d\n", s);
    }
    return 0;
}