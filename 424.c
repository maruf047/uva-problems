#include <stdio.h>
#include <string.h>

int s[103] = {0};

int main() {
    int len;
    char str[100];
    register int l, c, diff;
    gets(str);
    while (strcmp(str, "0")) {
        len = strlen(str);
        l = len;
        diff = 103 - l;
        c = 0;
        while (l-- > 0 || c > 0) {
            int sum = 0;
            if (l > -1) {
                sum = s[l + diff] + (str[l] - '0') + c;
            } else {
                sum = s[diff + l] + c;
            }
            s[l + diff] = sum % 10;
            if (sum > 9) {
                sum /= 10;
                c = sum % 10;
            } else {
                c = 0;
            }
        }
        gets(str);
    }
    len = 0;
    for (l = 0; l < 103; l++) {
        if (s[l] > 0)len = 1;
        if (len == 1)printf("%d", s[l]);
    }
    printf("\n");
    return 0;
}
