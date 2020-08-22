#include <stdio.h>


int stack[30][30], pos[30][2], stacked[30];

int main() {
    int num_of_boxes, commanda, commandb, a, b;
    while (scanf("%d", &num_of_boxes) == 1) {
        register int i, j;
        getchar();
        for (i = 0; i < num_of_boxes; ++i) {
            for (j = 0; j < num_of_boxes; ++j) {
                stack[i][j] = i;
            }
            pos[i][0] = i;
            pos[i][1] = 0;
            stacked[i] = 1;
        }
        while ((commanda = getchar()) != 113) {
            getchar();
            getchar();
            getchar();
            scanf("%d", &a);
            getchar();
            getchar();
            commandb = getchar();
            getchar();
            getchar();
            scanf("%d", &b);
            getchar();
            int basea = pos[a][0];
            int baseb = pos[b][0];
            if (basea != baseb && a != b) {
                if (commanda == 109) {
                    for (i = pos[a][1] + 1; i < stacked[basea]; ++i) {
                        int element = stack[basea][i];
                        stack[element][0] = element;
                        pos[element][0] = element;
                        pos[element][1] = 0;
                        stacked[element] = 1;
                    }
                    stacked[basea] = pos[a][1];
                    int new_posa;
                    if (commandb == 110) {
                        for (i = pos[b][1] + 1; i < stacked[baseb]; ++i) {
                            int element = stack[baseb][i];
                            stack[element][0] = element;
                            pos[element][0] = element;
                            pos[element][1] = 0;
                            stacked[element] = 1;
                        }
                        stacked[baseb] = pos[b][1];
                        new_posa = pos[b][1] + 1;
                    } else {
                        new_posa = stacked[baseb];
                    }
                    stack[baseb][new_posa] = a;
                    pos[a][0] = baseb;
                    pos[a][1] = new_posa;
                    stacked[baseb] = new_posa + 1;
                } else {
                    int new_posa;
                    if (commandb == 110) {
                        for (i = pos[b][1] + 1; i < stacked[baseb]; ++i) {
                            int element = stack[baseb][i];
                            stack[element][0] = element;
                            pos[element][0] = element;
                            pos[element][1] = 0;
                            stacked[element] = 1;
                        }
                        stacked[baseb] = pos[b][1] + 1;
                        new_posa = pos[b][1] + 1;
                    } else {
                        new_posa = stacked[baseb];
                    }
                    int old_posa = pos[a][1];
                    for (i = 0; i < stacked[basea] - old_posa; ++i) {
                        int element = stack[basea][i + old_posa];
                        stack[baseb][i + new_posa] = element;
                        pos[element][0] = baseb;
                        pos[element][1] = new_posa + i;
                        ++stacked[baseb];
                    }
                    stacked[basea] = old_posa;
                }
            }
        }
        for (i = 0; i < num_of_boxes; ++i) {
            printf("%d:", i);
            for (j = 0; j < stacked[i]; ++j) {
                printf(" %d", stack[i][j]);
            }
            putchar(10);
        }
        getchar();
        getchar();
        getchar();
    }
    return 0;
}
