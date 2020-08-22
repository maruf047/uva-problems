#include <stdio.h>

int main() {
    int line;
    scanf("%d", &line);
    while (line != 0) {
        register int i, j;
        int spaces[20] = {0}, mn = 26;
        char c = getchar();
        for (i = 0; i < line; ++i) {
            register int s = 0;
            for (j = 0; j < 25; ++j) {
                c = getchar();
                if (c == 32)++s;
            }
            if (s < mn)mn = s;
            spaces[i] = s;
            while ((c = getchar()) != 10);
        }
        register int t = 0;
        for (i = 0; i < line; ++i) {
            t += spaces[i] - mn;
        }

        printf("%d\n", t);
        scanf("%d", &line);
    }
    return 0;
}


