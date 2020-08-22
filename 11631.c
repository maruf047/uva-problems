#include <stdio.h>
#include <stdlib.h>

#define MAX 201000

typedef struct edge_def {
    struct node_def *u;
    struct node_def *v;
    int cost;
} edge;

typedef struct node_def {
    int vertex;
    struct node_def *parent;
    int rank;
} node;

edge *edge_heap[MAX + 1];

node *nodes[MAX];

int nv, ne;
int last;

void push_edge(node *u, node *v, int cost) {
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
        nodes[i]->parent = nodes[i];
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
    int saved = 0;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
        } else {
            saved += current_edge->cost;
        }
    }
    return saved;
}

int main() {

    register int i;
    int u, v, cost;
    for (i = 0; i < MAX; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
        nodes[i] = malloc(sizeof(node));
    }
    scanf("%d %d", &nv, &ne);
    while (nv != 0 && ne != 0) {

        edge_heap[0]->cost = -1;
        last = 1;
        make_set();
        node *node_u, *node_v;
        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            node_u = nodes[u];
            node_v = nodes[v];
            push_edge(node_u, node_v, cost);
        }
        int saved = mst();
        printf("%d\n", saved);
        scanf("%d %d", &nv, &ne);
    }
    return 0;
}
