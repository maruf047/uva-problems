#include <stdio.h>
#include <math.h>

int mark[1051] = {0};
int prime[180];

int main() {
    int n = 1050, pc = 0, i;
    mark[0] = 0;
    for (i = 4; i <= n; i = i + 2) {
        mark[i - 1] = 1;
    }
    prime[pc++] = 2;
    int limit = sqrt(n * 1.0) + 2;
    for (i = 3; i <= n; i = i + 2) {
        if (!mark[i - 1]) {
            prime[pc++] = i;
            if (i <= limit) {
                int j;
                for (j = i * i; j <= n; j = j + i * 2) {
                    mark[j - 1] = 1;
                }
            }
        }
    }
    char c;
    register int s = 0;
    while (1) {
        c = getchar();
        if (c > 64 && c < 91) {
            s += c - 38;
        } else if (c > 96 && c < 123) {
            s += c - 96;
        } else if (c == 10) {
            printf(mark[s - 1] ? "It is not a prime word.\n" : "It is a prime word.\n");
            s = 0;
        } else {
            break;
        }
    }
    return 0;
}
