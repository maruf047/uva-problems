#include <stdio.h>

int main() {

    int banks[20];
    int nob, nod, d, c, a, p;
    register int i;
    scanf("%d %d", &nob, &nod);
    while (nob != 0 && nod != 0) {
        for (i = 0; i < nob; ++i) {
            scanf("%d", &banks[i]);
        }
        for (i = 0; i < nod; ++i) {
            scanf("%d %d %d", &d, &c, &a);
            banks[d - 1] -= a;
            banks[c - 1] += a;
        }
        p = 0;
        for (i = 0; i < nob; ++i) {
            if (banks[i] < 0) {
                p = 1;
                break;
            }
        }
        if (p == 0) {
            printf("S\n");
        } else {
            printf("N\n");
        }
        scanf("%d %d", &nob, &nod);
    }

    return 0;
}
