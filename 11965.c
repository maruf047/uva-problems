#include <stdio.h>

int main() {
    register int counter;
    int testcase, t = 0;
    scanf("%d", &testcase);
    while (t++ < testcase) {
        printf("Case %d:\n", t);
        int lines, ch;
        scanf("%d", &lines);
        getchar();
        while (lines--) {
            counter = 0;
            while ((ch = getchar()) != 10 && ch != EOF) {
                if (ch != 32) {
                    if (counter == 1)counter = 0;
                    putchar(ch);
                } else if (counter == 0) {
                    putchar(ch);
                    counter = 1;
                }
            }
            putchar(10);
        }
        if (t != testcase)putchar(10);
    }
    return 0;
}
