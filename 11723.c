#include <stdio.h>

int main() {
    int r, a;
    register int s, t = 0;
    scanf("%d %d", &r, &a);
    while (r != 0 || a != 0) {
        if (a != 0 && r != 0) {
            s = r / a;
            if (r % a == 0) s--;
            if (s <= 26) {
                printf("Case %d: %d\n", ++t, s);
            } else {
                printf("Case %d: impossible\n", ++t);
            }
            scanf("%d %d", &r, &a);
        } else if (r == 0) {
            printf("Case %d: 0\n", ++t);
            scanf("%d %d", &r, &a);
        } else if (a == 0) {
            printf("Case %d: impossible\n", ++t);
            scanf("%d %d", &r, &a);
        }
    }
    return 0;
}
