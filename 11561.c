#include <stdio.h>

int width, height, map[100][100];

int gold(int y, int x) {
    int ch = map[y][x];
    if (y < 0 || x < 0 || x == width || y == height || ch == 35)return 0;
    map[y][x] = 35;
    int g = ch == 71 ? 1 : 0;
    if (map[y + 1][x] == 84 || map[y - 1][x] == 84 || map[y][x + 1] == 84 || map[y][x - 1] == 84) return g;
    g += gold(y + 1, x);
    g += gold(y - 1, x);
    g += gold(y, x + 1);
    g += gold(y, x - 1);
    return g;
}

int main() {
    register int i, j;
    while (scanf("%d %d\n", &width, &height) == 2) {
        int sx, sy;
        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                map[i][j] = getchar();
                if (map[i][j] == 80) {
                    sy = i, sx = j;
                }
            }
            getchar();
        }
        printf("%d\n", gold(sy, sx));
    }
    return 0;
}
