#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 30
#define MAX_EDGES 500

typedef struct edge_def {
    int u;
    int v;
    int cost;
} edge;

typedef struct node_def {
    int parent;
} node;

edge *edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

int nv, ne;
int last;

void push_edge(int u, int v, int cost) {
    edge_heap[last]->u = u;
    edge_heap[last]->v = v;
    edge_heap[last]->cost = cost;
    int i = last;
    edge *temp;
    while ((edge_heap[i / 2]->cost > edge_heap[i]->cost)
           || ((edge_heap[i / 2]->cost == edge_heap[i]->cost) && (edge_heap[i / 2]->u > edge_heap[i]->u))
           || ((edge_heap[i / 2]->cost == edge_heap[i]->cost) && (edge_heap[i / 2]->u == edge_heap[i]->u) &&
               (edge_heap[i / 2]->u > edge_heap[i]->v))) {
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
        if ((edge_heap[2 * i]->cost < edge_heap[2 * i + 1]->cost)
            ||
            ((edge_heap[2 * i]->cost == edge_heap[2 * i + 1]->cost) && (edge_heap[2 * i]->u < edge_heap[2 * i + 1]->u))
            || ((edge_heap[2 * i]->cost == edge_heap[2 * i + 1]->cost) &&
                (edge_heap[2 * i]->u == edge_heap[2 * i + 1]->u) && (edge_heap[2 * i]->v < edge_heap[2 * i + 1]->v))
            || (2 * i == (last - 2))) {
            ci = 2 * i;
        } else {
            ci = 2 * i + 1;
        }
        if ((edge_heap[i]->cost > edge_heap[ci]->cost)
            || ((edge_heap[i]->cost == edge_heap[ci]->cost) && (edge_heap[i]->u > edge_heap[ci]->u))
            || ((edge_heap[i]->cost == edge_heap[ci]->cost) && (edge_heap[i]->u == edge_heap[ci]->u) &&
                (edge_heap[i]->v > edge_heap[ci]->v))
                ) {
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
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            putchar(current_edge->u + 65);
            putchar(45);
            putchar(current_edge->v + 65);
            putchar(32);
            printf("%d", current_edge->cost);
            putchar(10);
        }
    }
}

int main() {

    register int i, j, k;
    int t, c;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
    }
    scanf("%d", &t);
    for (k = 0; k < t; ++k) {
        scanf("%d", &nv);
        edge_heap[0]->cost = -1;
        last = 1;
        ne = 0;
        make_set();
        for (i = 0; i < nv; ++i) {
            for (j = 0; j < nv; ++j) {
                scanf("%d", &c);
                if (i < j && c > 0) {
                    push_edge(i, j, c);
                    ++ne;
                }
                if (j < nv - 1) {
                    getchar();
                }
            }
        }
        printf("Case %d:\n", k + 1);
        mst();
    }
    return 0;
}
