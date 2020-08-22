#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    register int t = 0;
    while (num != 0) {
        int b[50], a;
        register int n = 0, s = 0;
        while (n < num) {
            scanf("%d", &b[n]);
            s += b[n++];
        }
        s /= num;
        num = 0;
        while (--n) {
            num += s < b[n] ? b[n] - s : 0;
        }
        num += s < b[n] ? b[n] - s : 0;
        printf("Set #%d\nThe minimum number of moves is %d.", ++t, num);
        putchar(10);
        putchar(10);
        scanf("%d", &num);
    }
    return 0;
}