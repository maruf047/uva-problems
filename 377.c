#include <stdio.h>

#define NUM_LEN 5
#define RES_LEN 8
#define BASE 4

int main() {
    int num_of_tablets;
    scanf("%d", &num_of_tablets);
    printf("COWCULATIONS OUTPUT\n");
    while (num_of_tablets--) {
        register int i = 0, j = 0;
        int num1[NUM_LEN], num2[RES_LEN];
        for (i = 0; i < NUM_LEN; ++i) {
            num1[i] = 0;
        }
        for (i = 0; i < RES_LEN; ++i) {
            num2[i] = 0;
        }
        i = NUM_LEN;
        int c = getchar();
        while (i > 0) {
            --i;
            c = getchar();
            if (c == 86) {
                num1[i] = 0;
            } else if (c == 85) {
                num1[i] = 1;
            } else if (c == 67) {
                num1[i] = 2;
            } else if (c == 68) {
                num1[i] = 3;
            }
        }
        c = getchar();
        i = NUM_LEN;
        while (i > 0) {
            --i;
            c = getchar();
            if (c == 86) {
                num2[i] = 0;
            } else if (c == 85) {
                num2[i] = 1;
            } else if (c == 67) {
                num2[i] = 2;
            } else if (c == 68) {
                num2[i] = 3;
            }
        }
        c = getchar();
        j = 0;
        while (j++ < 3) {
            c = getchar();
            if (c == 65) {
                int carry = 0, sum = 0;
                i = 0;
                while (i < RES_LEN) {
                    sum = carry + num2[i];
                    if (i < NUM_LEN) {
                        sum += num1[i];
                    }
                    num2[i] = sum % BASE;
                    carry = sum / BASE;
                    ++i;
                }

            } else if (c == 82) {
                i = 0;
                while (i < RES_LEN - 1) {
                    num2[i] = num2[i + 1];
                    i++;
                }
                num2[RES_LEN - 1] = 0;
            } else if (c == 76) {
                i = RES_LEN - 1;
                while (i > 0) {
                    num2[i] = num2[i - 1];
                    --i;
                }
                num2[0] = 0;
            }
            c = getchar();
        }
        i = RES_LEN;
        int y = 1;
        while (i > 0) {
            --i;
            c = getchar();
            if (c == 86) {
                if (num2[i] != 0) {
                    y = 0;
                }
            } else if (c == 85) {
                if (num2[i] != 1) {
                    y = 0;
                }
            } else if (c == 67) {
                if (num2[i] != 2) {
                    y = 0;
                }
            } else if (c == 68) {
                if (num2[i] != 3) {
                    y = 0;
                }
            }
        }
        if (y == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
