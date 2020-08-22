#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 210
#define MAX_EDGES 20000

typedef struct edge_def {
    int u;
    int v;
    double distance;
} edge;

typedef struct node_def {
    int x;
    int y;
    int parent;
} node;

typedef struct adjacent_def {
    int w;
    double distance;
} adjacent;

edge *edge_heap[MAX_EDGES], *edge_list[MAX_EDGES];

node *nodes[MAX_VERTICES];

int queue[MAX_VERTICES], degrees[MAX_VERTICES], visited[MAX_VERTICES];
double distances[MAX_VERTICES];

adjacent *graph[MAX_VERTICES][MAX_VERTICES];

int nv, ne;
int last, total_mst_edges, q_head, q_tail;

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

void mst() {
    int i;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            edge_list[total_mst_edges] = current_edge;
            graph[current_edge->u][degrees[current_edge->u]]->w = current_edge->v;
            graph[current_edge->u][degrees[current_edge->u]]->distance = current_edge->distance;
            graph[current_edge->v][degrees[current_edge->v]]->w = current_edge->u;
            graph[current_edge->v][degrees[current_edge->v]]->distance = current_edge->distance;
            degrees[current_edge->u]++;
            degrees[current_edge->v]++;
            ++total_mst_edges;
        }
    }
}

double bfs() {
    int src = 0, dest = 1, i;
    q_head = q_tail = 0;
    queue[q_tail] = src;
    distances[q_tail] = 0;
    ++q_tail;
    int current_vertex = src, degree;
    double distance;
    while (current_vertex != dest) {
        distance = distances[q_head];
        degree = degrees[current_vertex];
        visited[current_vertex] = 1;
        ++q_head;
        for (i = 0; i < degree; ++i) {
            int adjacent_vertex = graph[current_vertex][i]->w;
            if (visited[adjacent_vertex] != 1) {
                queue[q_tail] = adjacent_vertex;
                if (graph[current_vertex][i]->distance > distance) {
                    distances[q_tail] = graph[current_vertex][i]->distance;
                } else {
                    distances[q_tail] = distance;
                }
                ++q_tail;
            }
        }
        current_vertex = queue[q_head];
    }
    distance = distances[q_head];
    return distance;
}

int main() {

    register int i, j;
    int t = 0;
    for (i = 0; i < MAX_EDGES; ++i) {

        edge_heap[i] = malloc(sizeof(edge));
        edge_list[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {

        nodes[i] = malloc(sizeof(node));

        for (j = 0; j < MAX_VERTICES; ++j) {
            graph[i][j] = malloc(sizeof(adjacent));
        }
    }

    scanf("%d", &nv);
    while (nv != 0) {
        ne = (nv * (nv - 1)) / 2;
        for (j = 0; j < nv; ++j) {
            scanf("%d %d", &nodes[j]->x, &nodes[j]->y);
        }
        edge_heap[0]->distance = -1;
        last = 1;
        total_mst_edges = 0;
        make_set();
        for (i = 0; i < nv; ++i) {
            for (j = i + 1; j < nv; ++j) {
                double distance = sqrt(pow((nodes[i]->x - nodes[j]->x), 2) + pow((nodes[i]->y - nodes[j]->y), 2));
                push_edge(i, j, distance);
            }
        }
        for (i = 0; i < MAX_VERTICES; ++i) {
            visited[i] = 0;
            degrees[i] = 0;
        }
        mst();
        printf("Scenario #%d\n", ++t);
        double distance = bfs();
        printf("Frog Distance = %.3lf\n\n", distance);
        getchar();
        getchar();
        scanf("%d", &nv);
    }
    return 0;
}