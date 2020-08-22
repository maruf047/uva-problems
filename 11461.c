#include <stdio.h>
#include <math.h>

int main() {
    long int a, b;
    register int s;
    register long int n;
    scanf("%ld %ld", &a, &b);
    while (a != 0 && b != 0) {
        s = 0;
        n = (long int) ceil(sqrt(a));
        while ((n * n) <= b) {
            s++;
            n++;
        }
        printf("%d\n", s);
        scanf("%ld %ld", &a, &b);
    }
    return 0;
}
