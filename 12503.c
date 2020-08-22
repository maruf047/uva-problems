#include <stdio.h>

int main() {
    int t, n, p, a, c, instructions[100];
    register int i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        getchar();
        p = 0;
        for (i = 0; i < n; ++i) {
            c = getchar();
            if (c == 76) {
                instructions[i] = -1;
                j = 0;
                while (j < 4) {
                    getchar();
                    ++j;
                }
            } else if (c == 82) {
                instructions[i] = 1;
                j = 0;
                while (j < 5) {
                    getchar();
                    ++j;
                }
            } else {
                j = 0;
                while (j < 7) {
                    getchar();
                    ++j;
                }
                scanf("%d", &a);
                getchar();
                instructions[i] = instructions[a - 1];
            }
            p = p + instructions[i];
        }
        printf("%d\n", p);
    }
    return 0;
}
