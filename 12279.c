#include <stdio.h>

int main() {
    unsigned short int num;
    scanf("%hu", &num);
    register short int n = num, t = 0;
    while (n != 0) {
        register short int b = 0;
        unsigned short int a;
        while (n--) {
            scanf("%hu", &a);
            a > 0 ? ++b : --b;
        }
        printf("Case %hu: %d\n", ++t, b);
        scanf("%hu", &num);
        n = num;
    }
    return 0;
}
