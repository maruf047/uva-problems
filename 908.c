#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000500
#define MAX_VERTICES 1000500

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

edge *edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

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
    for (i = 1; i <= nv; ++i) {
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
    int uc = 0;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            uc += current_edge->cost;
        }
    }
    return uc;
}

int main() {

    register int i;
    int u, v, cost, ch, newe;
    int init_v = 0, init_e = 0;
    int oc, uc;

    edge_heap[0] = malloc(sizeof(edge));
    edge_heap[0]->cost = -1;

    while (1) {
        scanf("%d", &nv);
        if (init_v < nv) {
            for (i = init_e; i <= nv; ++i) {
                nodes[i] = malloc(sizeof(node));
                nodes[i]->vertex = i;
            }
            init_v = nv;
        }

        ne = nv - 1;
        if (init_e < ne) {
            for (i = init_e + 1; i <= ne; ++i) {
                edge_heap[i] = malloc(sizeof(edge));
            }
            init_e = ne;
        }

        last = 1;
        oc = 0;
        make_set();
        node *node_u, *node_v;

        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            node_u = nodes[u];
            node_v = nodes[v];
            push_edge(node_u, node_v, cost);
            oc += cost;
        }
        scanf("%d", &newe);
        ne += newe;
        if (init_e < ne) {
            for (i = init_e + 1; i <= ne; ++i) {
                edge_heap[i] = malloc(sizeof(edge));
            }
            init_e = ne;
        }
        for (i = nv - 1; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            node_u = nodes[u];
            node_v = nodes[v];
            push_edge(node_u, node_v, cost);
        }
        uc = mst();
        printf("%d\n", oc);
        printf("%d\n", uc);
        scanf("%d", &ne);
        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
        }
        ch = getchar();
        if (ch != EOF) {
            ch = getchar();
            if (ch != EOF) {
                putchar(10);
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return 0;
}
