#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 110
#define MAX_EDGES 5500

typedef struct edge_def {
    int u;
    int v;
    double distance;
} edge;

typedef struct node_def {
    double x;
    double y;
    int parent;
} node;

edge *edge_heap[MAX_EDGES + 1];

node *nodes[MAX_VERTICES];

int nv, ne;
int last;

void push_edge(int u, int v, double distance) {
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

double mst() {
    int i;
    double distance = 0;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            distance += current_edge->distance;
        }
    }
    return distance;
}

int main() {

    register int i, j, k;
    int t;
    for (i = 0; i < MAX_EDGES; ++i) {
        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {
        nodes[i] = malloc(sizeof(node));
    }
    scanf("%d", &t);
    for (k = 0; k < t; ++k) {
        getchar();
        getchar();
        scanf("%d", &nv);
        ne = (nv * (nv - 1)) / 2;
        for (j = 0; j < nv; ++j) {
            scanf("%lf %lf", &nodes[j]->x, &nodes[j]->y);
        }
        edge_heap[0]->distance = -1;
        last = 1;
        make_set();
        for (i = 0; i < nv; ++i) {
            for (j = i + 1; j < nv; ++j) {
                double distance = sqrt(pow((nodes[i]->x - nodes[j]->x), 2) + pow((nodes[i]->y - nodes[j]->y), 2));
                push_edge(i, j, distance);
            }
        }
        double distance = mst();
        printf("%.2lf\n", distance);
        if (k < t - 1) {
            putchar(10);
        }
    }
    return 0;
}
