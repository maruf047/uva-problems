#include <stdio.h>
#include <string.h>

int main() {
    int testcase;
    register int i, t, len, cntr, sum;
    char scr[80];
    scanf("%d\n", &testcase);
    t = testcase;
    while (t--) {
        scanf("%s", scr);
        cntr = 1;
        sum = 0;
        len = strlen(scr);
        for (i = 0; i < len; i++) {
            if (scr[i] == 'X') {
                cntr = 1;
                continue;
            }
            sum += cntr++;
            if (scr[i + 1] == '\0')break;
        }
        printf("%d\n", sum);
    }
    return 0;
}

