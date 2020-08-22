#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1100
#define MAX_EDGES 25500

typedef struct edge_def {
    int u;
    int v;
    int cost;
} edge;

typedef struct node_def {
    int parent;
} node;

edge *edge_heap[MAX_EDGES + 1];

node *nodes[MAX_VERTICES];

int nv, ne;
int last;

void push_edge(int u, int v, int cost) {
    edge_heap[last]->u = u;
    edge_heap[last]->v = v;
    edge_heap[last]->cost = cost;
    int i = last;
    edge *temp;
    while (edge_heap[i / 2]->cost > edge_heap[i]->cost) {
        temp = edge_heap[i];
        edge_heap[i] = edge_heap[i / 2];
        edge_heap[i / 2] = temp;
        i = i / 2;
    }
    ++last;
}

edge *pop_edge() {
    int i = last - 1, ci;
    edge *temp;
    temp = edge_heap[i];
    edge_heap[i] = edge_heap[1];
    edge_heap[1] = temp;
    i = 1;
    while (i < last / 2) {
        if ((edge_heap[2 * i]->cost < edge_heap[2 * i + 1]->cost) || (2 * i == (last - 2))) {
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
    --last;
    return edge_heap[last];
}

void make_set() {
    int i;
    for (i = 0; i < nv; ++i) {
        nodes[i]->parent = i;
    }
}

int find_set(int v) {
    int parent = nodes[v]->parent;
    while (parent != nodes[parent]->parent) {
        parent = nodes[parent]->parent;
    }
    return parent;
}

int are_disjoint(int u, int v) {
    int find_set_u = find_set(u);
    int find_set_v = find_set(v);
    int are_disjoint = find_set_u != find_set_v;
    return are_disjoint;
}

void union_vertices(int u, int v) {
    int parent_u = find_set(u);
    int parent_v = find_set(v);
    nodes[parent_u]->parent = nodes[parent_v]->parent;
}

void mst() {
    int i;
    int forest = 0;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
        } else {
            if (forest == 1) {
                putchar(32);
            }
            printf("%d", current_edge->cost);
            forest = 1;
        }
    }
    if (forest == 0) {
        printf("forest");
    }
    putchar(10);
}

int main() {

    register int i;
    int u, v, cost;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
    }
    scanf("%d %d", &nv, &ne);
    while(nv != 0 && ne != 0) {
        edge_heap[0]->cost = -1;
        last = 1;
        make_set();
        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            push_edge(u, v, cost);
        }
        mst();
        scanf("%d %d", &nv, &ne);
    }
    return 0;
}
