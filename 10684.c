#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    while (num != 0) {
        int s = 0, b;
        register int mx = 0, sm = 0, n = num;
        while (n--) {
            scanf("%d", &b);
            sm += b;

            if (sm < 0) {
                sm = 0;
            } else {
                if (mx < sm)mx = sm;
            }
        }
        if (sm > 0) {
            printf("The maximum winning streak is %d.\n", mx);
        } else {
            printf("Losing streak.\n");
        }
        scanf("%d", &num);
    }
    return 0;
}
