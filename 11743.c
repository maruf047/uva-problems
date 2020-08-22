#include <stdio.h>

int main() {
    int testcase, a, b, c, d;
    register int t, sd, su, dd, i;
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d %d %d %d", &d, &c, &b, &a);
        su = sd = i = 0;
        while (1) {
            if (i == 0) {
                i = 1;
                su += a % 10;
            } else {
                i = 0;
                dd = (a % 10) * 2;
                while (1) {
                    sd += (dd % 10);
                    dd /= 10;
                    if (dd == 0)break;
                }
            }
            a /= 10;
            if (a == 0)break;
        }
        i = 0;
        while (1) {
            if (i == 0) {
                i = 1;
                su += b % 10;
            } else {
                i = 0;
                dd = (b % 10) * 2;
                while (1) {
                    sd += dd % 10;
                    dd /= 10;
                    if (dd == 0)break;
                }
            }
            b /= 10;
            if (b == 0)break;
        }
        i = 0;
        while (1) {
            if (i == 0) {
                i = 1;
                su += c % 10;
            } else {
                i = 0;
                dd = (c % 10) * 2;
                while (1) {
                    sd += dd % 10;
                    dd /= 10;
                    if (dd == 0)break;
                }
            }
            c /= 10;
            if (c == 0)break;
        }
        i = 0;
        while (1) {
            if (i == 0) {
                i = 1;
                su += d % 10;
            } else {
                i = 0;
                dd = (d % 10) * 2;
                while (1) {
                    sd += dd % 10;
                    dd /= 10;
                    if (dd == 0)break;
                }
            }
            d /= 10;
            if (d == 0)break;
        }
        if ((su + sd) % 10 == 0)printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
