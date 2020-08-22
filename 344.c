#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    while (num != 0) {
        int rem = 0, quo = 0;
        int i = 0, v = 0, x = 0, l = 0, c = 0;
        if (num >= 90) {
            c = num - 89;
        }
        if (num > 39) l = num - 39;
        if (num > 89) l -= num - 89;
        if (num >= 50) {
            x = 75 * (num / 50);
            quo = (num % 50) / 10;
        } else {
            quo = num / 10;
        }
        rem = num % 10;
        x += (rem + 1) * quo;
        if (quo == 4)x -= (rem + 1) * 3;
        if (quo > 0)x += (((quo - 1) * (quo)) / 2) * 10;
        x += quo;
        if (rem == 9)++x;
        v = (num / 10) * 5;
        if (rem > 3)v += rem - 3;
        if (rem > 8) v -= (10 - rem);
        i = (num / 5) * 7;
        rem = num % 5;
        if (rem < 4) {
            i += ((rem) * (rem + 1)) / 2;
        } else {
            i += 7;
        }

        printf("%d: %d i, %d v, %d x, %d l, %d c\n", num, i, v, x, l, c);
        scanf("%d", &num);
    }
    return 0;
}