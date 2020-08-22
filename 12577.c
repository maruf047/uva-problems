#include <stdio.h>

int main() {
    register int i = 0;
    char c;
    scanf("%c", &c);
    while (c != '*') {
        if (c == 'H') {
            printf("Case %d: Hajj-e-Akbar\n", ++i);
            scanf("%*c%*c%*c%*c");
        } else {
            printf("Case %d: Hajj-e-Asghar\n", ++i);
            scanf("%*c%*c%*c%*c%*c");
        }
        scanf("%c", &c);
    }
    return 0;
}
