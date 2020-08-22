#include <stdio.h>
#include <math.h>

#define LIMIT 1000005

int mark[LIMIT] = {0}, prime[79000];


int main() {
    register int i, pc = 0;
    mark[0] = 1;
    mark[1] = 1;
    for (i = 4; i < LIMIT; i += 2) {
        mark[i] = 1;
    }
    prime[pc++] = 2;
    int limit = sqrt(LIMIT * 1.0) + 2;
    for (i = 3; i < LIMIT; i += 2) {
        if (!mark[i]) {
            prime[pc++] = i;
            if (i < limit) {
                int j;
                for (j = i * i; j < LIMIT; j += i * 2) {
                    mark[j] = 1;
                }
            }
        }
    }
    int num;
    while (scanf("%d", &num) == 1) {
        if (mark[num]) {
            printf("%d is not prime.\n", num);
        } else {
            register int n = num, r = 0, m = 1;
            while (n > 0) {

                r = r * 10 + n % 10;
                n /= 10;
            }

            if (mark[r] == 0 && num != r) {
                printf("%d is emirp.\n", num);
            } else {
                printf("%d is prime.\n", num);
            }
        }
    }

    return 0;
}
