#include <stdio.h>

int main() {
    int train[50];
    unsigned int testcase;
    unsigned register int t;
    scanf("%u", &testcase);
    t = testcase;
    while (t--) {
        int num_train;
        register int i = 0, j = 0, s = 0;
        scanf("%d", &num_train);
        for (i; i < num_train; ++i) {
            scanf("%d", &train[i]);
        }
        --i;
        for (i; i >= 0; --i) {
            for (j = 0; j < i; ++j) {
                if (train[j] > train[j + 1]) {
                    int temp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = temp;
                    ++s;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", s);
    }
    return 0;
}