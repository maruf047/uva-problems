#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 800
#define MAX_EDGES 300000

typedef struct edge_def {
    struct node_def *u;
    struct node_def *v;
    double distance;
} edge;

typedef struct node_def {
    int x, y;
    int vertex;
    struct node_def *parent;
    int rank;
} node;

edge *edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

int nv, ne, nce;
int last, connected;

void push_edge(node *u, node *v, double distance) {
    edge_heap[last]->u = u;
    edge_heap[last]->v = v;
    edge_heap[last]->distance = distance;
    int i = last;
    edge *temp;
    while (edge_heap[i / 2]->distance > edge_heap[i]->distance) {
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
        if ((edge_heap[2 * i]->distance < edge_heap[2 * i + 1]->distance) || (2 * i == (last - 2))) {
            ci = 2 * i;
        } else {
            ci = 2 * i + 1;
        }
        if (edge_heap[i]->distance > edge_heap[ci]->distance) {
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

void mst() {
    int i;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            printf("%d %d\n", current_edge->u->vertex, current_edge->v->vertex);
        }
    }
}

int main() {

    register int i, j;
    register double distance;
    int u, v, t = 0, tc;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
        nodes[i]->vertex = i;
    }

    scanf("%d", &tc);
    while (t < tc) {
        ++t;
        getchar();
        getchar();
        scanf("%d", &nv);
        edge_heap[0]->distance = -1;
        last = 1;
        connected = 1;
        for (i = 1; i <= nv; ++i) {
            scanf("%d %d", &nodes[i]->x, &nodes[i]->y);
        }
        node *node_u, *node_v;
        make_set();
        scanf("%d", &nce);
        for (i = 0; i < nce; ++i) {
            scanf("%d %d", &u, &v);
            node_u = nodes[u];
            node_v = nodes[v];
            union_vertices(node_u, node_v);
            ++connected;
        }
        for (i = 1; i <= nv; ++i) {
            for (j = i + 1; j <= nv; ++j) {
                node_u = nodes[i];
                node_v = nodes[j];
                if (are_disjoint(node_u, node_v)) {
                    distance = sqrt(pow((node_u->x - node_v->x), 2) + pow((node_u->y - node_v->y), 2));
                    push_edge(node_u, node_v, distance);
                }
            }
        }
        if (last == 1) {
            ne = 0;
        } else {
            ne = last;
        }
        if (connected != nv) {
            mst();
        } else {
            printf("No new highways need\n");
        }
        if (t < tc) {
            putchar(10);
        }
    }
    return 0;
}
