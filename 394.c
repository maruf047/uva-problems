#include <stdio.h>
#include <stdlib.h>

typedef struct array_def {
    int name[10];
    int name_size;
    int base_address;
    int byte_size;
    int dimensions;
    int bounds[10][2];
    int offsets[11];
    struct array_def *next;
} array;

array *base, *curr = NULL;

int main() {

    int num_of_arrays, num_of_references;
    scanf("%d %d", &num_of_arrays, &num_of_references);
    register int t = 0;
    base = curr = malloc(sizeof(array));
    getchar();
    while (t++ < num_of_arrays) {
        array *new_array = malloc(sizeof(array));
        int c = 0, i = 0;
        while ((c = getchar()) == 32);
        new_array->name[i++] = c;
        while ((c = getchar()) != 32) {
            new_array->name[i++] = c;
        }
        new_array->name_size = i;
        scanf("%d %d %d", &new_array->base_address, &new_array->byte_size, &new_array->dimensions);
        for (i = 0; i < new_array->dimensions; ++i) {
            scanf("%d %d", &new_array->bounds[i][0], &new_array->bounds[i][1]);
        }
        new_array->offsets[new_array->dimensions - 1] = new_array->byte_size;
        new_array->offsets[10] = new_array->base_address - (new_array->offsets[new_array->dimensions - 1] *
                                                            new_array->bounds[new_array->dimensions - 1][0]);
        for (i = new_array->dimensions - 2; i >= 0; --i) {
            new_array->offsets[i] =
                    (new_array->bounds[i + 1][1] - new_array->bounds[i + 1][0] + 1) * new_array->offsets[i + 1];
            new_array->offsets[10] = new_array->offsets[10] - (new_array->offsets[i] *
                                                               new_array->bounds[i][0]);
        }
        while ((c = getchar()) != 10);
        curr->next = new_array;
        curr = curr->next;
    }
    curr = base->next;
    t = 0;
    while (t++ < num_of_references) {
        int name[10];
        int indices[10];
        int c = 0, i = 0, name_size = 0;
        while ((c = getchar()) == 32);
        name[i++] = c;
        while ((c = getchar()) != 32) {
            name[i++] = c;
        }
        name_size = i;
        curr = base->next;
        while (curr != NULL) {
            if (curr->name_size != name_size) {
                curr = curr->next;
            } else {
                i = 0;
                while (curr->name[i] == name[i] && i < curr->name_size) {
                    ++i;
                }
                if (i == name_size) {
                    for (i = 0; i < curr->dimensions; ++i) {
                        scanf("%d", &indices[i]);
                    }
                    while ((c = getchar()) != 10);
                    int physical_address = curr->offsets[10];
                    for (i = curr->dimensions - 1; i >= 0; --i) {
                        physical_address += (curr->offsets[i] * indices[i]);
                    }
                    for (i = 0; i < name_size; ++i) {
                        putchar(name[i]);
                    }
                    putchar(91);
                    for (i = 0; i < curr->dimensions - 1; ++i) {
                        printf("%d, ", indices[i]);
                    }
                    printf("%d", indices[curr->dimensions - 1]);
                    putchar(93);
                    printf(" = %d", physical_address);
                    putchar(10);
                    break;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    return 0;
}
