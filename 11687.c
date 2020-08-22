#include <stdio.h>


int main() {
    register int len = 0, num;
    int ch, i;

    while ((ch = getchar()) != 69) {
        if (ch > 47 && ch < 58) {
            ++len;
            if (len < 2) {
                num = ch - 48;
            }
        } else if (ch == 10) {
            if (len < 2) {
                if (num != 1) {
                    i = 2;
                } else {
                    i = 1;
                }
            } else if (len < 10) {
                i = 3;
            } else {
                i = 4;
            }
            printf("%d\n", i);
            len = 0;
        }
    }
    getchar();
    getchar();
    getchar();
    return 0;
}
