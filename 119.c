#include <stdio.h>
#include <string.h>

int main() {
    int has_money[10];
    register int i, j, k, counter = 0;
    int gift_money[10];
    char name[10][13];

    int id, num_of_people, num_of_getter, money, name_length = 0;

    char getter_name[13], giver_name[13];
    while (scanf("%d", &num_of_people) == 1) {
        for (i = 0; i < num_of_people; i++) {
            scanf("%s", name[i]);
            gift_money[i] = 0;
            has_money[i] = 0;
        }
        for (i = 0; i < num_of_people; i++) {
            scanf("%s", giver_name);
            name_length = strlen(giver_name);
            for (j = 0; j < num_of_people; j++) {
                if (name_length == strlen(name[j])) {
                    if (!strcmp(giver_name, name[j])) {
                        id = j;
                        break;
                    }
                }
            }

            scanf("%d", &money);
            scanf("%d", &num_of_getter);
            gift_money[id] = money;

            if (num_of_getter != 0) {
                has_money[id] = has_money[id] + (money % num_of_getter);
                money = money / num_of_getter;
            } else {
                has_money[id] += money;
            }
            for (j = 0; j < num_of_getter; j++) {
                scanf("%s", getter_name);
                name_length = strlen(getter_name);
                for (k = 0; k < num_of_people; k++) {
                    if (name_length == strlen(name[k])) {
                        if (!strcmp(getter_name, name[k])) {
                            has_money[k] = has_money[k] + money;
                            break;
                        }
                    }
                }
            }
        }
        if (counter != 0) {
            printf("\n");
        } else {
            counter = 1;
        }
        for (i = 0; i < num_of_people; i++) {
            printf("%s %d\n", name[i], has_money[i] - gift_money[i]);

        }
    }
    return 0;
}
