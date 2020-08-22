#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 110
#define MAX_EDGES 1100

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

typedef struct adjacent_def {
    int w;
    int cost;
} adjacent;

edge *edge_heap[MAX_EDGES];

node *nodes[MAX_VERTICES];

int queue[MAX_VERTICES], degrees[MAX_VERTICES], visited[MAX_VERTICES];
int costs[MAX_VERTICES];

adjacent *graph[MAX_VERTICES][MAX_VERTICES];

int nv, ne, nq;
int last, total_mst_edges, q_head, q_tail;

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

void mst() {
    int i;
    for (i = 0; i < ne; ++i) {
        edge *current_edge = pop_edge();
        if (are_disjoint(current_edge->u, current_edge->v)) {
            union_vertices(current_edge->u, current_edge->v);
            graph[current_edge->u->vertex][degrees[current_edge->u->vertex]]->w = current_edge->v->vertex;
            graph[current_edge->u->vertex][degrees[current_edge->u->vertex]]->cost = current_edge->cost;
            graph[current_edge->v->vertex][degrees[current_edge->v->vertex]]->w = current_edge->u->vertex;
            graph[current_edge->v->vertex][degrees[current_edge->v->vertex]]->cost = current_edge->cost;
            degrees[current_edge->u->vertex]++;
            degrees[current_edge->v->vertex]++;
            ++total_mst_edges;
        }
    }
}

int bfs(int src, int dest) {
    int i;
    q_head = q_tail = 0;
    queue[q_tail] = src;
    costs[q_tail] = 0;
    ++q_tail;
    int current_vertex = src, degree;
    int cost;
    while (current_vertex != dest && q_head != q_tail) {
        cost = costs[q_head];
        degree = degrees[current_vertex];
        visited[current_vertex] = 1;
        ++q_head;
        for (i = 0; i < degree; ++i) {
            int adjacent_vertex = graph[current_vertex][i]->w;
            if (visited[adjacent_vertex] != 1) {
                queue[q_tail] = adjacent_vertex;
                if (graph[current_vertex][i]->cost > cost) {
                    costs[q_tail] = graph[current_vertex][i]->cost;
                } else {
                    costs[q_tail] = cost;
                }
                ++q_tail;
            }
        }
        current_vertex = queue[q_head];
    }
    if (q_head != q_tail) {
        cost = costs[q_head];
    } else {
        cost = -1;
    }
    return cost;
}

int main() {

    register int i, j;
    int t = 0, u, v, c;
    for (i = 0; i < MAX_EDGES; ++i) {

        edge_heap[i] = malloc(sizeof(edge));
    }
    for (i = 0; i < MAX_VERTICES; ++i) {

        nodes[i] = malloc(sizeof(node));
        nodes[i]->vertex = i;

        for (j = 0; j < MAX_VERTICES; ++j) {
            graph[i][j] = malloc(sizeof(adjacent));
        }
    }

    scanf("%d %d %d", &nv, &ne, &nq);
    while (1) {
        ++t;
        edge_heap[0]->cost = -1;
        last = 1;
        total_mst_edges = 0;
        make_set();
        node *node_u, *node_v;
        for (i = 0; i < ne; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            node_u = nodes[u];
            node_v = nodes[v];
            push_edge(node_u, node_v, c);
        }
        for (j = 1; j <= nv; ++j) {
            degrees[j] = 0;
        }
        mst();
        printf("Case #%d\n", t);
        for (i = 0; i < nq; ++i) {
            for (j = 1; j <= nv; ++j) {
                visited[j] = 0;
            }
            scanf("%d %d", &u, &v);
            int cost = bfs(u, v);
            if (cost > 0) {
                printf("%d\n", cost);
            } else {
                printf("no path\n");
            }
        }
        scanf("%d %d %d", &nv, &ne, &nq);
        if (nv != 0 && ne != 0 && nq != 0) {
            putchar(10);
        } else {
            break;
        }
    }
    return 0;
}

