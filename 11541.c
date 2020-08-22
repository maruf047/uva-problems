#include <stdio.h>

int main() {
    int testcase, num;
    char c;
    register int t = 0, i;
    scanf("%d%*c", &testcase);
    while (t++ < testcase) {
        printf("Case %d: ", t);
        scanf("%c", &c);
        while (c != '\n') {
            scanf("%d", &num);
            i = 0;
            while (i++ < num) {
                printf("%c", c);
            }
            scanf("%c", &c);
        }
        printf("\n");
    }
    return 0;
}
