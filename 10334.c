#include <stdio.h>

#define LAST 250
#define TOTAL 1000

int fib_table[1001][251];
int fib_len[1001];
int indices[251];

int main() {

    register int i = 0, j = 0, s = 0, c = 0;
    int digit_count = 1;

    fib_table[0][LAST] = 1;
    fib_len[0] = 1;
    fib_table[1][LAST] = 2;
    fib_len[1] = 1;
    indices[0] = -1;
    indices[1] = 0;
    digit_count = 2;

    for (i = 2; i <= TOTAL; ++i) {
        j = 0, s = 0, c = 0;
        while (j < fib_len[i - 1]) {
            s = c + fib_table[i - 2][LAST - j] + fib_table[i - 1][LAST - j];
            c = s / 10;
            fib_table[i][LAST - j] = s % 10;
            ++j;
        }
        if (c > 0) {
            fib_table[i][LAST - j] = c;
            ++j;
        }
        fib_len[i] = j;
        if (fib_len[i] == digit_count) {
            indices[digit_count] = i;
            ++digit_count;
        }
    }

    int index, ch;
    while (scanf("%d", &index) == 1) {
        for (j = LAST - fib_len[index] + 1; j < LAST + 1; ++j) {
            printf("%d", fib_table[index][j]);
        }
        putchar(10);
        ch = getchar();
        printf("Char: %d\n", ch);
        if (ch == 32) {
            break;
        }
    }
    return 0;
}
