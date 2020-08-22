#include <stdio.h>

int main() {
    int bin[100][100];
    int l;
    scanf("%d", &l);
    while (l != 0) {
        register unsigned short int i, j, s = 0;
        unsigned short int x, y, a = 0;
        for (i = 0; i < l; ++i) {
            for (j = 0; j < l; ++j) {
                scanf("%d", &bin[i][j]);
                if (bin[i][j])++a;
            }
            if (a % 2) {
                if (s == 0) {
                    x = i;
                    s = 1;
                } else if (s == 1) {
                    s = 2;
                }
            }
            a = 0;
        }
        if (s == 1 || s == 0) {
            for (j = 0; j < l; ++j) {
                for (i = 0; i < l; ++i) {
                    if (bin[i][j])++a;
                }
                if (a % 2) {
                    if (s == 1) {
                        y = j;
                        s = 3;
                    } else if (s == 0) {
                        s = 4;
                        break;
                    } else {
                        s = 4;
                        break;
                    }
                }
                a = 0;
            }
        }
        if (s == 0) {
            printf("OK\n");
        } else if (s == 3) {
            printf("Change bit (%hu,%hu)\n", x + 1, y + 1);
        } else {
            printf("Corrupt\n");
        }
        scanf("%d", &l);
    }
    return 0;
}
