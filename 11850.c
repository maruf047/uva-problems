#include <stdio.h>
#include <stdlib.h>

int comp(const void *elem1, const void *elem2) {
    int f = *((int *) elem1);
    int s = *((int *) elem2);
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}

int main() {
    int num;
    scanf("%d", &num);
    while (num != 0) {
        register int n = num, i = 0, l = 0;
        int g[1423], x, s = 0;
        while (i < num)scanf("%d", &g[i++]);
        qsort(g, i, sizeof(*g), comp);
        i = 1;
        while (i < num) {
            if (g[i] - g[i - 1] > 200) {
                s = 1;
                break;
            }
            ++i;
        }
        if (1422 - g[i - 1] > 100)s = 1;
        if (s)printf("IMPOSSIBLE\n"); else printf("POSSIBLE\n");
        scanf("%d", &num);
    }
    return 0;
}
