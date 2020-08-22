#include <stdio.h>

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char a, b, c;
        a = getchar();
        b = getchar();
        c = getchar();
        getchar();
        int numA, numN;
        char d1, d2, d3, d4;
        d1 = getchar();
        d2 = getchar();
        d3 = getchar();
        d4 = getchar();
        getchar();
        numA = (a - 65) * 676 + (b - 65) * 26 + c - 65;
        numN = (d1 - 48) * 1000 + (d2 - 48) * 100 + (d3 - 48) * 10 + d4 - 48;
        if (numA < numN) {
            if (numN - numA < 101) {
                printf("nice\n");
            } else {
                printf("not nice\n");
            }
        } else {
            if (numA - numN < 101) {
                printf("nice\n");
            } else {
                printf("not nice\n");
            }
        }
    }
    return 0;
}
