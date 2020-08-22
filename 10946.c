#include <stdio.h>
#include <stdlib.h>

int height, width, map[55][55];

struct hole_name {
    int name;
    struct hole_name *next;
};
struct hole {
    int size;
    struct hole *next;
    struct hole_name *hole_name;
};

int count(int h, int w, int name) {
    if (h < 0 || w < 0 || h == height || w == width || map[h][w] != name) return 0;
    map[h][w] = 46;
    int c = 1;
    c += count(h - 1, w, name);
    c += count(h, w - 1, name);
    c += count(h, w + 1, name);
    c += count(h + 1, w, name);
    return c;
}

int main() {
    register int t = 0;
    scanf("%d %d", &height, &width);
    while (height != 0 && width != 0) {
        getchar();
        register int i, j;
        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                map[i][j] = getchar();
            }
            getchar();
        }
        register int name, c;
        struct hole *base_hole = malloc(sizeof(base_hole));
        base_hole->size = 0;
        base_hole->hole_name = 0;
        base_hole->next = 0;
        struct hole *end_hole = malloc(sizeof(base_hole));
        end_hole->size = 0;
        end_hole->hole_name = 0;
        end_hole->next = 0;
        base_hole->next = end_hole;

        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                name = map[i][j];
                if (name != 46) {
                    c = count(i, j, name);
                    struct hole *current_hole = base_hole->next;
                    struct hole *previous_hole = base_hole;
                    while (c < current_hole->size) {
                        previous_hole = current_hole;
                        current_hole = current_hole->next;
                    }
                    if (c != current_hole->size) {
                        struct hole *new_hole = malloc(sizeof(struct hole));
                        new_hole->size = c;
                        new_hole->next = previous_hole->next;
                        previous_hole->next = new_hole;
                        struct hole_name *new_hole_name = malloc(sizeof(struct hole_name));
                        new_hole_name->name = name;
                        new_hole_name->next = 0;
                        new_hole->hole_name = new_hole_name;
                    } else {
                        if (current_hole->hole_name->name < name) {
                            struct hole_name *previous_hole_name = current_hole->hole_name;
                            struct hole_name *current_hole_name = current_hole->hole_name;
                            while (current_hole_name && name > current_hole_name->name) {
                                previous_hole_name = current_hole_name;
                                current_hole_name = current_hole_name->next;
                            }
                            struct hole_name *new_hole_name = malloc(sizeof(struct hole_name));
                            new_hole_name->name = name;
                            new_hole_name->next = previous_hole_name->next;
                            previous_hole_name->next = new_hole_name;
                        } else {
                            struct hole_name *new_hole_name = malloc(sizeof(struct hole_name));
                            new_hole_name->name = name;
                            new_hole_name->next = current_hole->hole_name;
                            current_hole->hole_name = new_hole_name;
                        }
                    }
                }
            }
        }
        printf("Problem %d:\n", ++t);
        struct hole *current_hole = base_hole->next;
        while (current_hole->size != 0) {
            struct hole_name *current_hole_name = current_hole->hole_name;
            while (current_hole_name) {
                printf("%c %d\n", current_hole_name->name, current_hole->size);
                current_hole_name = current_hole_name->next;
            }
            current_hole = current_hole->next;
        }
        scanf("%d %d", &height, &width);
    }
    return 0;
}
