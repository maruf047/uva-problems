#include <stdio.h>
#include <string.h>

int main() {
    int g, len, lim;
    register int i, j, stopper;
    char str[100];
    scanf("%d%*c", &g);
    while (g != 0) {
        gets(str);
        len = strlen(str);
        lim = len / g;
        j = 0;
        while (j++ < g) {
            i = lim * j;
            stopper = lim * (j - 1);
            while (i-- > stopper) {
                printf("%c", str[i]);
            }
        }
        printf("\n");
        scanf("%d%*c", &g);
    }
    return 0;
}
