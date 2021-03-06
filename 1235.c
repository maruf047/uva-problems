#include <stdio.h>
#include <stdlib.h>

#define LOCK_DIGITS 4
#define MAX_VERTICES 550
#define MAX_EDGES 125000

typedef struct edge_def {
    struct node_def *u;
    struct node_def *v;
    int cost;
} edge;

typedef struct node_def {
    int vertex;
    int digit[4];
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

int get_lock_count(node *node_u, node *node_v) {
    int lock_count = 0, i, x, y, d;
    for (i = 0; i < LOCK_DIGITS; ++i) {
        if (node_u->digit[i] > node_v->digit[i]) {
            x = node_u->digit[i];
            y = node_v->digit[i];
        } else {
            x = node_v->digit[i];
            y = node_u->digit[i];
        }
        d = x - y;
        if (d > 5) {
            d = 10 - d;
        }
        lock_count += d;
    }
    return lock_count;
}

int mst() {
    int i, cost = 0;
    make_set();
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            cost += current_edge->cost;
        }
    }
    return cost;
}

int main() {

    register int i, j;
    int t = 0, tc, c, f;
    int ch;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
        nodes[i]->vertex = i;
    }

    scanf("%d", &tc);
    for (i = 0; i < LOCK_DIGITS; ++i) {
        nodes[0]->digit[i] = 0;
    }
    while (t < tc) {
        ++t;
        getchar();
        scanf("%d", &nv);
        ++nv;
        edge_heap[0]->cost = -1;
        last = 1;
        f = 10000;
        for (i = 1; i < nv; ++i) {
            ch = getchar();
            for (j = 0; j < LOCK_DIGITS; ++j) {
                ch = getchar();
                nodes[i]->digit[j] = ch - 48;
            }
            c = get_lock_count(nodes[0], nodes[i]);
            if (f > c) {
                f = c;
            }
        }
        node *node_u, *node_v;
        for (i = 1; i < nv; ++i) {
            for (j = i + 1; j < nv; ++j) {
                node_u = nodes[i];
                node_v = nodes[j];
                c = get_lock_count(node_u, node_v);
                push_edge(node_u, node_v, c);
            }
        }
        ne = last - 1;
        f += mst();
        printf("%d\n", f);
    }
    return 0;
}