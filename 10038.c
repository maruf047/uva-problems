#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums, a, b;
    register int i, n, x;
    while (scanf("%d", &nums) != EOF) {
        n = nums;
        int diff[2999] = {0};
        scanf("%d", &b);
        while (n-- > 1) {
            a = b;
            scanf("%d", &b);
            diff[abs(a - b)] = 1;
        }
        x = 1;
        for (i = 1; i < nums; ++i) {
            if (diff[i] != 1) {
                printf("Not jolly\n");
                x = 0;
                break;
            }
        }
        if (x) {
            printf("Jolly\n");
        }
    }

    return 0;
}
