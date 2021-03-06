#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100100
#define MAX_VERTICES 10100

typedef struct edge_def {
    struct node_def *u;
    struct node_def *v;
    int cost;
} edge;

typedef struct node_def {
    struct node_def *parent;
    int rank;
} node;

edge *edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

int nv, ne;
int last;
int airport_cost, min_cost, num_airports;

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
    register int i;
    for (i = 0; i <= nv; ++i) {
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

void mst() {
    register int i, current_cost = 0, road_cost = 0;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            --nv;
            road_cost += current_edge->cost;
            current_cost = road_cost + nv * airport_cost;
            if (min_cost > current_cost) {
                min_cost = current_cost;
                num_airports = nv;
            }
            if (nv == 1) {
                i = ne;
            }
        }
    }
}

int main() {

    register int i;
    int t = 0, num_tests, u, v, cost;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
    }
    scanf("%d", &num_tests);
    while (t++ < num_tests) {
        scanf("%d %d %d", &nv, &ne, &airport_cost);
        edge_heap[0]->cost = -1;
        last = 1;
        num_airports = nv;
        min_cost = num_airports * airport_cost;
        make_set();
        node *node_u, *node_v;
        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            node_u = nodes[u - 1];
            node_v = nodes[v - 1];
            push_edge(node_u, node_v, cost);
        }
        mst();
        printf("Case #%d: %d %d\n", t, min_cost, num_airports);
    }
    return 0;
}
