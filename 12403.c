#include <stdio.h>

int main() {
    unsigned int testcase, d;
    unsigned register int sum = 0, t;
    char str[10];
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%s", str);
        if (str[0] == 'd') {
            scanf("%d", &d);
            sum += d;
        } else {
            printf("%d\n", sum);
        }
    }
    return 0;
}


