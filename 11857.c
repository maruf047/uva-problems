#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000000
#define MAX_EDGES 1000010

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

edge *road_edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

int nv, road_ne;
int road_last;

void push_road_edge(node *u, node *v, int cost) {
    road_edge_heap[road_last]->u = u;
    road_edge_heap[road_last]->v = v;
    road_edge_heap[road_last]->cost = cost;
    int i = road_last;
    edge *temp;
    while (road_edge_heap[i / 2]->cost > road_edge_heap[i]->cost) {
        temp = road_edge_heap[i];
        road_edge_heap[i] = road_edge_heap[i / 2];
        road_edge_heap[i / 2] = temp;
        i = i / 2;
    }
    ++road_last;
}

edge *pop_road_edge() {
    int i = road_last - 1, ci;
    edge *temp;
    temp = road_edge_heap[i];
    road_edge_heap[i] = road_edge_heap[1];
    road_edge_heap[1] = temp;
    i = 1;
    while (i < road_last / 2) {
        if ((road_edge_heap[2 * i]->cost < road_edge_heap[2 * i + 1]->cost) || (2 * i == (road_last - 2))) {
            ci = 2 * i;
        } else {
            ci = 2 * i + 1;
        }
        if (road_edge_heap[i]->cost > road_edge_heap[ci]->cost) {
            temp = road_edge_heap[i];
            road_edge_heap[i] = road_edge_heap[ci];
            road_edge_heap[ci] = temp;
        } else {
            break;
        }
        i = ci;
    }
    --road_last;
    return road_edge_heap[road_last];
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

int mst_road() {
    int i;
    int range = 0;
    for (i = 0; i < road_ne; ++i) {
        edge *current_edge = pop_road_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            if (range < current_edge->cost) {
                range = current_edge->cost;
            }
            --nv;
        }
    }
    return range;
}

int main() {

    register int i, j, k;
    int u, v, cost;
    for (i = 0; i < MAX_EDGES; ++i) {
        road_edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
        nodes[i]->node = i;
    }
    scanf("%d %d", &nv, &road_ne);
    while (nv != 0 || road_ne != 0) {
        road_edge_heap[0]->cost = -1;
        road_last = 1;
        make_set();
        node *node_u, *node_v;
        for (i = 0; i < road_ne; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            node_u = nodes[u];
            node_v = nodes[v];
            push_road_edge(node_u, node_v, cost);
        }
        int range = mst_road();
        if (nv <= 1) {
            printf("%d\n", range);
        } else {
            printf("IMPOSSIBLE\n");
        }
        scanf("%d %d", &nv, &road_ne);
    }

    return 0;
}
