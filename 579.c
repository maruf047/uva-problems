#include <stdio.h>

int main() {
    int h, m;
    register double angle;
    scanf("%d:%d", &h, &m);
    while (h != 0 || m != 0) {
        if (h == 12)h = 0;
        angle = (h * 30.00) - m * (5.50);
        if (angle < 0.00) {
            angle = -angle;
        }
        if (angle > 180.00) {
            angle = 360.00 - angle;
        }
        printf("%.3f\n", angle);
        scanf("%d:%d", &h, &m);
    }
    return 0;
}
