#include <stdio.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>

uint64_t fract(int x) {
    if (x == 1)return 1;
    else return x * fract(x - 1);
}

int main() {
    int testcase, len;
    register int t = 0, i, j;
    char str[21];
    scanf("%d%*c", &testcase);
    while (t++ < testcase) {
        gets(str);
        int alpha[26] = {0};
        int index[26] = {-1};
        len = strlen(str);
        j = 0;
        for (i = 0; i < len; i++) {
            int indx = str[i] - 'A';
            if (alpha[indx] == 0) {
                index[j++] = indx;
            }
            alpha[indx]++;
        }
        uint64_t arng = fract(len);
        for (i = 0; i < j; i++) {
            arng /= fract(alpha[index[i]]);
        }
        printf("Data set %d: %"PRId64"\n", t, arng);
    }
    return 0;
}

