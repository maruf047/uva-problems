#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1010
#define MAX_EDGES 500000

typedef struct edge_def {
    struct node_def *u;
    struct node_def *v;
    double distance;
} edge;

typedef struct node_def {
    int x;
    int y;
    struct node_def *parent;
    int rank;
} node;

edge *road_edge_heap[MAX_EDGES], *rail_edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

int nv, road_ne, rail_ne;
int road_last, rail_last;

void push_road_edge(node *u, node *v, double distance) {
    road_edge_heap[road_last]->u = u;
    road_edge_heap[road_last]->v = v;
    road_edge_heap[road_last]->distance = distance;
    int i = road_last;
    edge *temp;
    while (road_edge_heap[i / 2]->distance > road_edge_heap[i]->distance) {
        temp = road_edge_heap[i];
        road_edge_heap[i] = road_edge_heap[i / 2];
        road_edge_heap[i / 2] = temp;
        i = i / 2;
    }
    ++road_last;
}

void push_rail_edge(node *u, node *v, double distance) {
    rail_edge_heap[rail_last]->u = u;
    rail_edge_heap[rail_last]->v = v;
    rail_edge_heap[rail_last]->distance = distance;
    int i = rail_last;
    edge *temp;
    while (rail_edge_heap[i / 2]->distance > rail_edge_heap[i]->distance) {
        temp = rail_edge_heap[i];
        rail_edge_heap[i] = rail_edge_heap[i / 2];
        rail_edge_heap[i / 2] = temp;
        i = i / 2;
    }
    ++rail_last;
}

edge *pop_road_edge() {
    int i = road_last - 1, ci;
    edge *temp;
    temp = road_edge_heap[i];
    road_edge_heap[i] = road_edge_heap[1];
    road_edge_heap[1] = temp;
    i = 1;
    while (i < road_last / 2) {
        if ((road_edge_heap[2 * i]->distance < road_edge_heap[2 * i + 1]->distance) || (2 * i == (road_last - 2))) {
            ci = 2 * i;
        } else {
            ci = 2 * i + 1;
        }
        if (road_edge_heap[i]->distance > road_edge_heap[ci]->distance) {
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

edge *pop_rail_edge() {
    int i = rail_last - 1, ci;
    edge *temp;
    temp = rail_edge_heap[i];
    rail_edge_heap[i] = rail_edge_heap[1];
    rail_edge_heap[1] = temp;
    i = 1;
    while (i < rail_last / 2) {
        if ((rail_edge_heap[2 * i]->distance < rail_edge_heap[2 * i + 1]->distance) || (2 * i == (rail_last - 2))) {
            ci = 2 * i;
        } else {
            ci = 2 * i + 1;
        }
        if (rail_edge_heap[i]->distance > rail_edge_heap[ci]->distance) {
            temp = rail_edge_heap[i];
            rail_edge_heap[i] = rail_edge_heap[ci];
            rail_edge_heap[ci] = temp;
        } else {
            break;
        }
        i = ci;
    }
    --rail_last;
    return rail_edge_heap[rail_last];
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

double mst_road() {
    int i;
    double distance = 0;
    for (i = 0; i < road_ne; ++i) {
        edge *current_edge = pop_road_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            distance += current_edge->distance;
            --nv;
        }
    }
    return distance;
}

double mst_rail() {
    int i;
    double distance = 0;
    for (i = 0; i < rail_ne; ++i) {
        edge *current_edge = pop_rail_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            distance += current_edge->distance;
        }
    }
    return distance;
}

int round_distance(double d) {
    int val = (int) (d * 10.0);
    int rounded_val;
    if ((val % 10) > 4) {
        rounded_val = (int) (d + 1);
    } else {
        rounded_val = (int) d;
    }
    return rounded_val;
}

int main() {

    register int i, j, k;
    int t, threshold;
    for (i = 0; i < MAX_EDGES; ++i) {
        road_edge_heap[i] = malloc(sizeof(edge));
        rail_edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
    }
    scanf("%d", &t);
    for (k = 0; k < t; ++k) {
        scanf("%d %d", &nv, &threshold);
        for (j = 0; j < nv; ++j) {
            scanf("%d %d", &nodes[j]->x, &nodes[j]->y);
        }
        road_edge_heap[0]->distance = -1;
        rail_edge_heap[0]->distance = -1;
        road_last = 1;
        rail_last = 1;
        make_set();
        node *node_u, *node_v;
        for (i = 0; i < nv; ++i) {
            for (j = i + 1; j < nv; ++j) {
                double distance = sqrt(pow((nodes[i]->x - nodes[j]->x), 2) + pow((nodes[i]->y - nodes[j]->y), 2));
                node_u = nodes[i];
                node_v = nodes[j];
                if (distance < threshold) {
                    push_road_edge(node_u, node_v, distance);
                } else {
                    push_rail_edge(node_u, node_v, distance);
                }
            }
        }
        road_ne = road_last - 1;
        rail_ne = rail_last - 1;
        double road_distance = mst_road();
        double rail_distance = mst_rail();
        printf("Case #%d: %d %d %d\n", k + 1, nv, round_distance(road_distance), round_distance(rail_distance));
    }
    return 0;
}
