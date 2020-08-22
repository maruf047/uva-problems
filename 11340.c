#include <stdio.h>
#include <inttypes.h>

int main() {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        int paid_char_count, pc[256] = {0};
        scanf("%d\n", &paid_char_count);
        register int pcc = paid_char_count;
        while (pcc--) {
            unsigned char c;
            int val;
            scanf("%c %d\n", &c, &val);
            pc[c] = val;
        }
        int line;
        scanf("%d\n", &line);
        register int l = line;
        register int_fast64_t sum = 0;
        while (l--) {
            unsigned char c;
            while ((c = getchar()) != 10) {
                sum += pc[c];
            }
            sum += pc[c];
        }
        printf("%.2lf$\n", sum / 100.0);
    }
    return 0;
}
