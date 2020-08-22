#include <stdio.h>

int X, Y;
char sky[105][105];

int star(int x, int y) {
    if (sky[x][y] == 46)return 0;
    if (x < X - 1 && y < Y - 1) {
        if (sky[x - 1][y + 1] == 42)return 0;
        if (sky[x - 1][y] == 42)return 0;
        if (sky[x - 1][y - 1] == 42)return 0;
        if (sky[x][y + 1] == 42)return 0;
        if (sky[x][y - 1] == 42)return 0;
        if (sky[x + 1][y + 1] == 42)return 0;
        if (sky[x + 1][y] == 42)return 0;
        if (sky[x + 1][y - 1] == 42)return 0;
    } else if (x == X - 1 && y < Y - 1) {
        if (sky[x - 1][y + 1] == 42)return 0;
        if (sky[x - 1][y] == 42)return 0;
        if (sky[x - 1][y - 1] == 42)return 0;
        if (sky[x][y + 1] == 42)return 0;
        if (sky[x][y - 1] == 42)return 0;
    } else if (y == Y - 1 && x < X - 1) {
        if (sky[x - 1][y] == 42)return 0;
        if (sky[x - 1][y - 1] == 42)return 0;
        if (sky[x][y - 1] == 42)return 0;
        if (sky[x + 1][y] == 42)return 0;
        if (sky[x + 1][y - 1] == 42)return 0;
    } else {
        if (sky[x - 1][y] == 42)return 0;
        if (sky[x - 1][y - 1] == 42)return 0;
        if (sky[x][y - 1] == 42)return 0;
    }
    sky[x][y] = 46;
    return 1;
}

int main() {
    scanf("%d %d\n", &X, &Y);
    while (X != 0 && Y != 0) {
        register int i, j, n = 0;
        for (i = 0; i < X; ++i) {
            for (j = 0; j < Y; ++j) {
                sky[i][j] = getchar();
            }
            getchar();
        }
        for (i = 0; i < X; ++i) {
            for (j = 0; j < Y; ++j) {
                if (star(i, j) == 1) {
                    ++n;
                }
            }
        }
        printf("%d\n", n);
        scanf("%d %d\n", &X, &Y);
    }
    return 0;
}
