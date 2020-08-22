#include <stdio.h>

int main() {
    char c;
    int n;
    scanf("%d\n", &n);
    while (n--) {
        char a[20], b[20];
        register int i = 0, j = 0;
        int la = 0, s = 0;
        while ((c = getchar()) != 10) {
            a[i++] = c;
        }
        la = i;
        i = 0;
        while ((c = getchar()) != 10 && c != EOF) {
            b[i] = c;
            char c1 = a[i++];
            if ((c != c1) && ((c != 97 && c != 101 && c != 105 && c != 111 && c != 117) ||
                              (c1 != 97 && c1 != 101 && c1 != 105 && c1 != 111 && c1 != 117))) {
                s = 1;
            }
        }

        if (la != i) {
            s = 1;
        }
        if (s)printf("No\n"); else printf("Yes\n");
    }
    return 0;
}
