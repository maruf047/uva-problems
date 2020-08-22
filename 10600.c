#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 110
#define MAX_EDGES 5000

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

edge *edge_heap[MAX_EDGES], *mst_edges[MAX_EDGES], *non_mst_edges[MAX_EDGES];

node *nodes[MAX_VERTICES];

int nv, ne;
int last, mst_last, non_mst_last;

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
    int i, cost = 0;
    make_set();
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            cost += current_edge->cost;
            mst_edges[mst_last] = current_edge;
            ++mst_last;
        } else {
            non_mst_edges[non_mst_last] = current_edge;
            ++non_mst_last;
        }
    }
    return cost;
}

int second_mst(int f) {
    int i, j = 0, cost = 0, min_cost = 30500;
    while (j < non_mst_last && min_cost != f) {
        cost = 0;
        make_set();
        edge *current_edge = non_mst_edges[j];
        cost += current_edge->cost;
        union_vertices(current_edge->u, current_edge->v);
        for (i = 0; i < mst_last; ++i) {
            current_edge = mst_edges[i];
            if (are_disjoint(current_edge->u, current_edge->v)) {
                union_vertices(current_edge->u, current_edge->v);
                cost += current_edge->cost;
            }
        }
        if (min_cost >= cost) {
            min_cost = cost;
        }
        ++j;
    }
    return min_cost;
}

int main() {

    register int i;
    int t = 0, tc, u, v, c, f, s;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
        mst_edges[i] = malloc(sizeof(edge));
        non_mst_edges[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
        nodes[i]->vertex = i;
    }

    scanf("%d", &tc);
    while (t < tc) {
        ++t;
        scanf("%d %d", &nv, &ne);
        edge_heap[0]->cost = -1;
        last = 1;
        mst_last = non_mst_last = 0;
        node *node_u, *node_v;
        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            node_u = nodes[u];
            node_v = nodes[v];
            push_edge(node_u, node_v, c);
        }
        f = mst();
        s = second_mst(f);
        printf("%d %d\n", f, s);
    }
    return 0;
}
