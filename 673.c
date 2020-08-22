#include <stdio.h>
#include <string.h>

#define LIMIT 128

char stack[LIMIT];
int tos = 0;

void push(char x) {
    if (tos < LIMIT) {
        stack[tos++] = x;
    }
}

char pop() {
    if (tos >= 0) {
        return stack[--tos];
    }
    return -1;
}

int main() {
    int testcase;
    char c, str[LIMIT];
    register int t, l, i;
    scanf("%d\n", &testcase);
    t = testcase;
    while (t--) {
        gets(str);
        l = strlen(str);
        tos = 0;
        for (i = 0; i < l; i++) {
            c = str[i];
            if (c == ')') {
                if (pop() != '(') {
                    tos = -1;
                    break;
                }
            } else if (c == '}') {
                if (pop() != '{') {
                    tos = -1;
                    break;
                }
            } else if (c == ']') {
                if (pop() != '[') {
                    tos = -1;
                    break;
                }
            } else {
                push(c);
            }
        }
        stack[0] = ' ';
        if (tos == 0) {
            printf("Yes\n");
        } else {
            \
            printf("No\n");
        }
    }
    return 0;
}
