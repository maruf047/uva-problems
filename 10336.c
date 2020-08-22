#include <stdio.h>

char o[100][100];
int x, y;

void area(int u, int v, char c) {
    if ((u >= x && v >= y) || (u < 0 && v < 0)) return;
    if (o[u][v] != c)return;
    o[u][v] = '*';
    area(u - 1, v, c);
    area(u, v + 1, c);
    area(u, v - 1, c);
    area(u + 1, v, c);
}

int main() {
    int testcase, h;
    register int i, j, k, t = 0, c;
    scanf("%d", &testcase);
    while (t < testcase) {
        int areac[26] = {0};
        char lang[26];
        h = c = 0;
        scanf("%d %d", &x, &y);
        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
                char ch;
                scanf("%c", &ch);
                if (ch != '\n') {
                    o[i][j] = ch;
                    int index = ch - 97;
                    if (areac[index] == 0) {
                        lang[c++] = ch;
                        areac[index] = 1;
                    }
                } else {
                    j--;
                }
            }
        }
        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
                for (k = 0; k < c; k++) {
                    if (o[i][j] == lang[k]) {
                        area(i, j, lang[k]);
                        if (++areac[lang[k] - 97] > h)h++;
                    }
                }
            }
        }

        printf("World #%d\n", ++t);
        for (i = h; i > 0; i--) {
            for (j = 0; j < 26; j++) {
                if (areac[j] == i)
                    printf("%c: %d\n", j + 97, i - 1);
            }
        }
    }
    return 0;
}
