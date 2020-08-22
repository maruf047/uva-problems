#include <stdio.h>
#include <math.h>

int main() {
    int testcase, number;
    register int i, j, t, n, cp, a;
    register double sum;
    int digits[10];
    scanf("%d", &testcase);
    t = testcase;
    while (t--) {
        scanf("%d", &number);
        n = number;
        sum = cp = i = a = 0;
        while (n > 0) {
            digits[i] = n % 10;
            n = n / 10;
            i++;
        }
        while (sum <= number) {
            sum = 0;
            for (j = 0; j < i; j++) {
                sum = sum + pow(digits[j], cp);
            }
            if (sum == number) {
                a = 1;
                break;
            }
            cp++;
        }
        if (a == 0) {
            printf("Not Armstrong\n");
        } else {
            printf("Armstrong\n");
        }
    }
    return 0;
}
