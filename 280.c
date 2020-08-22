#include <stdio.h>

int grid[105][105], vertex[105], num_vert;

int visit(int x) {
    if (vertex[x] == 0)return 0;
    vertex[x] = 0;
    int j, c = 1;
    for (j = 1; j <= num_vert; ++j) {
        if (grid[x][j] == 1) {
            c += visit(j);
        }
    }
    return c;
}

int main() {
    scanf("%d", &num_vert);
    while (num_vert != 0) {

        register int i, j;
        for (i = 1; i <= num_vert; ++i) {
            for (j = 1; j <= num_vert; ++j) {
                grid[i][j] = 0;
            }
        }
        int adj;
        scanf("%d", &adj);
        while (adj != 0) {
            int a;
            scanf("%d", &a);
            while (a != 0) {
                grid[adj][a] = 1;
                scanf("%d", &a);
            }
            scanf("%d", &adj);
        }
        scanf("%d", &adj);
        int c = 0, a;
        for (i = 0; i < adj; ++i) {
            for (j = 1; j <= num_vert; ++j) {
                vertex[j] = 1;
            }
            scanf("%d", &a);
            for (j = 1; j <= num_vert; ++j) {
                if (grid[a][j] == 1) {
                    c += visit(j);
                }
            }
            int un = num_vert - c;
            printf("%d", un);
            for (j = 1; j <= num_vert; ++j) {
                if (vertex[j])printf(" %d", j);
            }
            putchar(10);
            c = 0;
        }
        scanf("%d", &num_vert);
    }
    return 0;
}

