#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d\n", &a, &b);
    register short int t = 0;
    while (a != 0 || b != 0) {
        register int i = 0, j = 0;
        int m[101][101] = {0};
        char c;
        for (i = 0; i < a; ++i) {
            for (j = 0; j < b; ++j) {
                if (getchar() == 42) {
                    m[i][j] = -1;
                    if (i == 0 && j == 0) {
                        if (m[i + 1][j] != -1)++m[i + 1][j];
                        if (m[i + 1][j + 1] != -1)++m[i + 1][j + 1];
                        if (m[i][j + 1] != -1)++m[i][j + 1];
                    } else if (i == 0) {
                        if (m[i][j + 1] != -1)++m[i][j + 1];
                        if (m[i][j - 1] != -1)++m[i][j - 1];
                        if (m[i + 1][j + 1] != -1)++m[i + 1][j + 1];
                        if (m[i + 1][j - 1] != -1)++m[i + 1][j - 1];
                        if (m[i + 1][j] != -1)++m[i + 1][j];
                    } else if (j == 0) {
                        if (m[i + 1][j] != -1)++m[i + 1][j];
                        if (m[i - 1][j] != -1)++m[i - 1][j];
                        if (m[i + 1][j + 1] != -1)++m[i + 1][j + 1];
                        if (m[i - 1][j + 1] != -1)++m[i - 1][j + 1];
                        if (m[i][j + 1] != -1)++m[i][j + 1];
                    } else if (i == a && j == b) {
                        if (m[i - 1][j] != -1)++m[i - 1][j];
                        if (m[i - 1][j - 1] != -1)++m[i - 1][j - 1];
                        if (m[i][j - 1] != -1)++m[i][j - 1];
                    } else if (i == a - 1) {
                        if (m[i][j + 1] != -1)++m[i][j + 1];
                        if (m[i][j - 1] != -1)++m[i][j - 1];
                        if (m[i - 1][j + 1] != -1)++m[i - 1][j + 1];
                        if (m[i - 1][j - 1] != -1)++m[i - 1][j - 1];
                        if (m[i - 1][j] != -1)++m[i - 1][j];
                    } else if (j == b - 1) {
                        if (m[i + 1][j] != -1)++m[i + 1][j];
                        if (m[i - 1][j] != -1)++m[i - 1][j];
                        if (m[i + 1][j - 1] != -1)++m[i + 1][j - 1];
                        if (m[i - 1][j - 1] != -1)++m[i - 1][j - 1];
                        if (m[i][j - 1] != -1)++m[i][j - 1];
                    } else {
                        if (m[i + 1][j] != -1)++m[i + 1][j];
                        if (m[i - 1][j] != -1)++m[i - 1][j];
                        if (m[i + 1][j + 1] != -1)++m[i + 1][j + 1];
                        if (m[i - 1][j + 1] != -1)++m[i - 1][j + 1];
                        if (m[i][j + 1] != -1)++m[i][j + 1];
                        if (m[i + 1][j - 1] != -1)++m[i + 1][j - 1];
                        if (m[i - 1][j - 1] != -1)++m[i - 1][j - 1];
                        if (m[i][j - 1] != -1)++m[i][j - 1];
                    }
                }
            }
            getchar();
        }
        printf("Field #%hu:\n", ++t);
        for (i = 0; i < a; ++i) {
            for (j = 0; j < b; ++j) {
                if (m[i][j] != -1) {
                    putchar(m[i][j] + 48);
                } else {
                    putchar(42);
                }
            }
            putchar(10);
        }
        scanf("%d %d\n", &a, &b);
        if (a != 0 || b != 0)putchar(10);
    }
    return 0;
}
