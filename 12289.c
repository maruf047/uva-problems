#include <stdio.h>
#include <string.h>

int main() {
    int testcase, len;
    register int i, err;
    char c[6];
    char one[4] = "one";
    scanf("%d\n", &testcase);
    while (testcase--) {
        gets(c);
        len = strlen(c);
        if (len > 3) {
            printf("3");
        } else {
            err = i = 0;
            while (i < len) {
                if (c[i] != one[i]) {
                    err++;
                }
                i++;
            }
            if (err <= 1) {
                printf("1");
            } else {
                printf("2");
            }
        }
        printf("\n");
    }
    return 0;
}
