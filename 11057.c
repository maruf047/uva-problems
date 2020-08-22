#include <stdio.h>

int main() {
    unsigned int n, b, books[10000], temp;
    unsigned register int i, j, min = 1000001, b1, b2;
    while (scanf("%u", &n) == 1) {
        for (i = 0; i < n; i++) {
            scanf("%u", &books[i]);
        }
        scanf("%u", &b);
        b1 = books[0];
        b2 = books[n - 1];
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if ((books[i] + books[j] == b)) {
                    if (books[i] >= books[j] && ((books[i] - books[j]) < min)) {
                        min = books[i] - books[j];
                        b1 = books[i];
                        b2 = books[j];
                    } else if ((books[j] - books[i]) < min) {
                        min = books[j] - books[i];
                        b1 = books[i];
                        b2 = books[j];
                    }
                }
            }
        }
        if (b2 < b1) {
            temp = b1;
            b1 = b2;
            b2 = temp;
        }
        printf("Peter should buy books whose prices are %u and %u.\n\n", b1, b2);
        min = 1000001;
    }
    return 0;
}
