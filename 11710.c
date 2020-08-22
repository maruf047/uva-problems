#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 450
#define MAX_EDGES 80000

typedef struct edge_def {
    struct node_def *u;
    struct node_def *v;
    int cost;
} edge;

typedef struct node_def {
    int node;
    struct node_def *parent;
    int rank;
} node;

typedef struct city_def {
    char name[11];
    int len;
    int node;
    struct city_def *next;
} city;

edge *edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

city *city_base;

int nv, ne;
int heap_last, node_count, t = 0;

void push_edge(node *u, node *v, int cost) {
    edge_heap[heap_last]->u = u;
    edge_heap[heap_last]->v = v;
    edge_heap[heap_last]->cost = cost;
    int i = heap_last;
    edge *temp;
    while (edge_heap[i / 2]->cost > edge_heap[i]->cost) {
        temp = edge_heap[i];
        edge_heap[i] = edge_heap[i / 2];
        edge_heap[i / 2] = temp;
        i = i / 2;
    }
    ++heap_last;
}

edge *pop_edge() {
    int i = heap_last - 1, ci;
    edge *temp;
    temp = edge_heap[i];
    edge_heap[i] = edge_heap[1];
    edge_heap[1] = temp;
    i = 1;
    while (i < heap_last / 2) {
        if ((edge_heap[2 * i]->cost < edge_heap[2 * i + 1]->cost) || (2 * i == (heap_last - 2))) {
            ci = 2 * i;
        } else {
            ci = 2 * i + 1;
        }
        if (edge_heap[i]->cost > edge_heap[ci]->cost) {
            temp = edge_heap[i];
            edge_heap[i] = edge_heap[ci];
            edge_heap[ci] = temp;
        } else {
            break;
        }
        i = ci;
    }
    --heap_last;
    return edge_heap[heap_last];
}

void make_set() {
    int i;
    for (i = 0; i < nv; ++i) {
        nodes[i]->parent = nodes[i];
        nodes[i]->rank = 0;
    }
}

node *find_set(node *v) {
    if (v != v->parent) {
        v->parent = find_set(v->parent);
    }
    return v->parent;
}

int are_disjoint(node *u, node *v) {
    node *parent_u = find_set(u);
    node *parent_v = find_set(v);
    int are_disjoint = parent_u != parent_v;
    return are_disjoint;
}

void link(node *u, node *v) {
    if (u->rank > v->rank) {
        v->parent = u;
    } else {
        u->parent = v;
        if (u->rank == v->rank) {
            ++v->rank;
        }
    }
}

void union_vertices(node *u, node *v) {
    node *parent_u = find_set(u);
    node *parent_v = find_set(v);
    link(parent_u, parent_v);
}

int mst() {
    int i;
    int sum = 0;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            sum += current_edge->cost;
            --nv;
        }
        if (nv == 1) {
            break;
        }
    }
    if (nv != 1) {
        sum = -1;
    }
    return sum;
}

void set_node() {
    int len = 0, i;
    char name[11], ch;
    city *curr = city_base->next;
    city *prev = city_base;

    while ((ch = getchar()) != 10) {
        name[len] = ch;
        ++len;
    }
    while (curr != NULL) {
        i = 0;
        while (name[i] == curr->name[i] && i < len && i < curr->len) {
            ++i;
        }
        if ((i == len) || (i < len && i != curr->len && name[i] < curr->name[i])) {
            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    if (curr != NULL) {
        city *temp = malloc(sizeof(city));
        temp->len = len;
        for (i = 0; i < len; ++i) {
            temp->name[i] = name[i];
        }
        temp->node = node_count;
        temp->next = curr;
        prev->next = temp;
        node_count++;
    } else {
        curr = malloc(sizeof(city));
        curr->len = len;
        for (i = 0; i < len; ++i) {
            curr->name[i] = name[i];
        }
        curr->node = node_count;
        curr->next = NULL;
        prev->next = curr;
        node_count++;
    }
}

node *get_node() {
    int node_index = 0, len = 0, i;
    char name[11], ch;
    city *curr = city_base->next;

    while ((ch = getchar()) != 32) {
        name[len] = ch;
        ++len;
    }
    while (curr != NULL) {
        i = 0;
        while (name[i] == curr->name[i] && i < len && i < curr->len) {
            ++i;
        }
        if (i == len && name[i - 1] == curr->name[i - 1]) {
            node_index = curr->node;
            break;
        }
        curr = curr->next;
    }

    return nodes[node_index];
}

int main() {

    register int i;
    int cost;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
        nodes[i]->node = i;
    }
    city_base = malloc(sizeof(city));
    scanf("%d %d", &nv, &ne);
    while (nv != 0 || ne != 0) {
        ++t;
        edge_heap[0]->cost = -1;
        heap_last = 1;
        node_count = 0;
        city_base->next = NULL;
        make_set();
        getchar();
        for (i = 0; i < nv; ++i) {
            set_node();
        }
        node *node_u, *node_v;
        for (i = 0; i < ne; ++i) {
            node_u = get_node();
            node_v = get_node();
            scanf("%d", &cost);
            push_edge(node_u, node_v, cost);
            getchar();
        }
        getchar();
        while (getchar() != 10);
        int sum = mst();
        if (sum != -1) {
            printf("%d\n", sum);
        } else {
            printf("Impossible\n");
        }
        scanf("%d %d", &nv, &ne);
    }

    return 0;
}
