#include <stdio.h>

int main() {
    int h1, h2, m1, m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    while (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0) {
        if (m2 < m1) {
            m2 += 60;
            h2--;
        }
        if (h2 < h1)h2 += 24;
        printf("%d\n", (h2 - h1) * 60 + (m2 - m1));
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    }
    return 0;
}