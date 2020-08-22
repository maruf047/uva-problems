#include <stdio.h>

#define LAST 101
#define TOTAL 490

int fib_table[501][102];
int fib_len[501];
int indices[103];

int main() {

    register int i = 0, j = 0, s = 0, c = 0;
    int num[2][102], num_len[2];
    int digit_count = 1;

    fib_table[1][LAST] = 1;
    fib_len[1] = 1;
    fib_table[2][LAST] = 2;
    fib_len[2] = 1;
    indices[1] = 1;
    digit_count = 2;

    for (i = 3; i <= TOTAL; ++i) {
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

    int ch = 0, num_temp[102], start, first_index, second_index;
    while (1) {
        i = 0, j = 0;
        while ((ch = getchar()) != 10) {
            if (ch == 32) {
                num_len[i] = j;
                start = LAST - num_len[i] + 1;
                for (j = 0; j < num_len[i]; ++j) {
                    num[i][start + j] = num_temp[LAST - j];
                }
                ++i, j = 0;
                continue;
            }
            num_temp[LAST - j] = ch - 48;
            ++j;
        }
        num_len[i] = j;
        start = LAST - num_len[i] + 1;
        for (j = 0; j < num_len[i]; ++j) {
            num[i][start + j] = num_temp[LAST - j];
        }

        if (num_len[1] == 1 && num[1][101] == 0) {
            break;
        }

        first_index = second_index = 0;

        start = LAST - num_len[0] + 1;
        for (i = indices[num_len[0] + 1] - 1; i >= indices[num_len[0]]; --i) {
            j = 0;
            while (j < num_len[0]) {
                if (fib_table[i][start + j] > num[0][start + j]) {
                    break;
                } else if (fib_table[i][start + j] < num[0][start + j]) {
                    first_index = i + 1;
                    break;
                }
                ++j;
            }
            if (first_index != 0) {
                break;
            } else if (j == num_len[0]) {
                first_index = i;
                break;
            }
        }
        if (first_index == 0) {
            first_index = i + 1;
        }

        start = LAST - num_len[1] + 1;
        for (i = indices[num_len[1] + 1] - 1; i >= indices[num_len[1]]; --i) {
            j = 0;
            while (j < num_len[1]) {
                if (fib_table[i][start + j] > num[1][start + j]) {
                    break;
                } else if (fib_table[i][start + j] < num[1][start + j]) {
                    second_index = i;
                    break;
                }
                ++j;
            }
            if (second_index != 0) {
                break;
            } else if (j == num_len[1]) {
                second_index = i;
                break;
            }
        }
        if (second_index == 0) {
            second_index = i;
        }
        printf("%d\n", (second_index - first_index + 1));
    }
    return 0;
}
