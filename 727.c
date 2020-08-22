#include <stdio.h>

#define PLUS 43
#define MINUS 45
#define MULTIPLE 42
#define DIVIDE 47
#define LB 40
#define RB 41
#define NLINE 10

int main() {
    int test;
    int c = 0;
    int result[50], op[50];
    register int res_len = 0, op_len = 0, i;
    scanf("%d", &test);
    c = getchar();
    c = getchar();
    while (test-- > 0) {
        while (c = getchar()) {
            if (c == NLINE || c == EOF) {
                op_len--;
                while (op_len >= 0) {
                    result[res_len++] = op[op_len];
                    op_len--;
                }
                for (i = 0; i < res_len; ++i) {
                    putchar(result[i]);
                }
                putchar(NLINE);
                res_len = 0, op_len = 0;
                break;
            } else if (c == PLUS || c == MINUS) {
                if (op_len > 0) {
                    if (op[op_len - 1] == MULTIPLE || op[op_len - 1] == DIVIDE) {
                        op_len--;
                        result[res_len++] = op[op_len];
                    }
                }
                if (op_len > 0) {
                    if (op[op_len - 1] == PLUS || op[op_len - 1] == MINUS) {
                        op_len--;
                        result[res_len++] = op[op_len];
                    }
                }
                op[op_len++] = c;
            } else if (c == MULTIPLE || c == DIVIDE) {
                if (op_len > 0) {
                    if (op[op_len - 1] == MULTIPLE || op[op_len - 1] == DIVIDE) {
                        op_len--;
                        result[res_len++] = op[op_len];
                    }
                }
                op[op_len++] = c;
            } else if (c == LB) {
                op[op_len++] = c;
            } else if (c == RB) {
                if (op_len > 0) {
                    if (op[op_len - 1] == MULTIPLE || op[op_len - 1] == DIVIDE) {
                        op_len--;
                        result[res_len++] = op[op_len];
                    }
                }
                if (op_len > 0) {
                    if (op[op_len - 1] == PLUS || op[op_len - 1] == MINUS) {
                        op_len--;
                        result[res_len++] = op[op_len];
                    }
                }
                op_len--;
            } else {
                result[res_len++] = c;
            }

            c = getchar();

            if (c == EOF) {
                op_len--;
                while (op_len >= 0) {
                    result[res_len++] = op[op_len];
                    op_len--;
                }
                for (i = 0; i < res_len; ++i) {
                    putchar(result[i]);
                }
                putchar(NLINE);
                res_len = 0, op_len = 0;
                break;
            }
        }
        if (test > 0) {
            putchar(NLINE);
        }
    }
    return 0;
}
