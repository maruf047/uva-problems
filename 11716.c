#include <stdio.h>
#include <math.h>

int main() {
    char cipher[10000], c;
    int testcase;
    scanf("%d\n", &testcase);
    register int t = testcase;
    while (t--) {
        int l;
        register int i = 0, j = 0, x = 0;
        while (c = getchar()) {
            if (c != 10 && c != EOF) {
                cipher[i++] = c;
            } else {
                l = sqrt(x = i);
                if (sqrt(i) == l) {
                    for (i = 0; i < l; ++i) {
                        for (j = 0; j < x; j += l) {
                            putchar(cipher[j + i]);
                        }
                    }
                } else {
                    printf("INVALID");
                }
                putchar(10);
                break;
            }
        }
    }
    return 0;
}
