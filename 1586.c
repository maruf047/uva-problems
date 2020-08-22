#include <stdio.h>
#include <string.h>

#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01

int main() {
    unsigned int testcase;
    register unsigned int t;
    register int len, has_digit;
    register double mass, m;
    char mlcl[81];
    scanf("%u%*c", &testcase);
    t = testcase;
    while (t--) {
        gets(mlcl);
        len = strlen(mlcl);
        mass = 0.000;
        has_digit = 0;
        m = 1.000;
        while (len--) {
            if (mlcl[len] == 'C') {
                mass += C * m;
                has_digit = 0;
                m = 1.000;
            } else if (mlcl[len] == 'H') {
                mass += H * m;
                has_digit = 0;
                m = 1.000;
            } else if (mlcl[len] == 'O') {
                mass += O * m;
                has_digit = 0;
                m = 1.000;
            } else if (mlcl[len] == 'N') {
                mass += N * m;
                has_digit = 0;
                m = 1.000;
            } else if (mlcl[len] > 47 && mlcl[len] < 58) {
                if (has_digit) {
                    m += 10.000 * (mlcl[len] - '0');
                    has_digit = 0;
                    continue;
                }
                m = mlcl[len] - '0';
                has_digit = 1;
            } else {
                m = 1.00;
                has_digit = 0;
            }
        }
        printf("%.3lf\n", mass);
    }
    return 0;
}
