#include <stdio.h>

char o[100][100];
int x;

void egalse(int u, int v) {
    if((u>=x && v>=x) || (u<0 && v<0) ) return;
    if (o[u][v] != '1')return;
    o[u][v] = '0';
    egalse(u - 1, v + 1);
    egalse(u - 1, v);
    egalse(u - 1, v - 1);
    egalse(u, v + 1);
    egalse(u, v);
    egalse(u, v - 1);
    egalse(u + 1, v);
    egalse(u + 1, v + 1);
    egalse(u + 1, v - 1);
}

int main() {
    register int i, j, c,t=0;
    while (scanf("%d", &x)!=-1) {
        c=0;
        for (i = 0; i < x; i++) {
            for ( j = 0; j < x; j++) {
                scanf(" %c", &o[i][j]);
            }
        }

        for (i = 0; i < x; i++) {
            for ( j = 0; j < x; j++) {
                if (o[i][j] == '1') {
                    egalse(i, j);
                    c++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++t,c);
    }
    return 0;
}