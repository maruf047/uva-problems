#include <stdio.h>


int main() {
    int hn[5850] = {1};
    register int i, t2 = 0, t3 = 0, t5 = 0, t7 = 0, tmp;

    for (i = 1; i < 5842; ++i) {
        while (hn[t2] * 2 <= hn[i - 1]) t2++;
        while (hn[t3] * 3 <= hn[i - 1]) t3++;
        while (hn[t5] * 5 <= hn[i - 1]) t5++;
        while (hn[t7] * 7 <= hn[i - 1]) t7++;
        tmp = hn[t2] * 2;
        if (hn[t3] * 3 < tmp) tmp = hn[t3] * 3;
        if (hn[t5] * 5 < tmp) tmp = hn[t5] * 5;
        if (hn[t7] * 7 < tmp) tmp = hn[t7] * 7;
        hn[i] = tmp;
    }
    int n;
    scanf("%d", &n);
    while (n != 0) {
        i = hn[n - 1];
        if (n % 10 == 1 && n % 100 != 11) {
            printf("The %dst humble number is %d.\n", n, i);
        } else if (n % 10 == 2 && n % 100 != 12) {
            printf("The %dnd humble number is %d.\n", n, i);
        } else if (n % 10 == 3 && n % 100 != 13) {
            printf("The %drd humble number is %d.\n", n, i);
        } else {
            printf("The %dth humble number is %d.\n", n, i);
        }
        scanf("%d", &n);
    }
    return 0;
}