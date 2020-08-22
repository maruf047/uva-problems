#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int adj;
    struct node *next;
    struct base_node *self_addr;
} node_t;

typedef struct base_node {
    int vertex;
    node_t *nodes;
    struct base_node *next;
    struct base_node *parent;
    int color;
    int p;
} base_node_t;

node_t *q_head = NULL;
base_node_t *graph = NULL;

int qc = 0;

void add_vertex(node_t **parent_node_head, base_node_t *base_node_addr, int val) {
    node_t *curr;
    curr = *parent_node_head;
    if ((*parent_node_head) != NULL) {
        while (curr->next != NULL && curr->adj != val) {
            curr = curr->next;
        }
    } else {
        (*parent_node_head) = (node_t *) malloc(sizeof(node_t));
        (*parent_node_head)->adj = val;
        (*parent_node_head)->self_addr = base_node_addr;
        (*parent_node_head)->next = NULL;
        return;
    }
    curr->next = (node_t *) malloc(sizeof(node_t));
    curr = curr->next;
    curr->adj = val;
    curr->self_addr = base_node_addr;
    curr->next = NULL;
}

base_node_t *add(int node_val, int val) {
    base_node_t *curr;
    curr = graph;
    if (graph != NULL) {
        while (curr->next != NULL) {
            if (curr->vertex == node_val)break;
            curr = curr->next;
        }
    } else {
        graph = (base_node_t *) malloc(sizeof(base_node_t));
        graph->vertex = node_val;
        graph->next = NULL;
        graph->nodes = NULL;
        graph->color = -1;
        graph->p = -1;
        return graph;
    }
    if (curr->vertex == node_val) {
        return curr;
    }
    curr->next = (base_node_t *) malloc(sizeof(base_node_t));
    curr = curr->next;
    curr->vertex = node_val;
    curr->next = NULL;
    curr->nodes = NULL;
    curr->color = -1;
    curr->p = -1;
    return curr;
}

void build_graph(int v) {
    int e;
    int x, y;
    base_node_t *ax, *ay;
    scanf("%d", &e);
    while (e--) {
        scanf("%d %d", &x, &y);
        ax = add(x, y);
        ay = add(y, x);
        add_vertex(&(ax->nodes), ay, y);
        add_vertex(&(ay->nodes), ax, x);
    }
}

void nq(int val) {
    qc++;
    node_t *curr;
    curr = q_head;
    if (q_head != NULL) {
        while (curr->next != NULL) {
            curr = curr->next;
        }
    } else {
        q_head = (node_t *) malloc(sizeof(node_t));
        q_head->adj = val;
        q_head->next = NULL;
        return;
    }
    curr->next = (node_t *) malloc(sizeof(node_t));
    curr = curr->next;
    curr->adj = val;
    curr->next = NULL;
}

int dq() {
    if (qc == 0) {
        return -1;
    }
    qc--;
    int val;
    val = q_head->adj;
    node_t *curr;
    curr = q_head;
    q_head = q_head->next;
    free(curr);
    return val;
}

void color() {

    base_node_t *curr_base;
    if (graph != NULL) {
        curr_base = graph;
    } else {
        printf("BICOLORABLE.\n");
        free(q_head);
        return;
    }
    curr_base->color = 0;
    qc = 0;
    nq(curr_base->vertex);
    while (qc != 0) {
        int u = dq();
        curr_base = graph;
        while (curr_base->vertex != u) {
            curr_base = curr_base->next;
        }
        node_t *curr = curr_base->nodes;
        while (curr != NULL) {
            int v = curr->adj;
            base_node_t *q_base = curr->self_addr;
            if (q_base->color == -1) {
                q_base->color = (curr_base->color + 1) % 2;
                nq(v);
            } else if (curr_base->color == q_base->color) {
                printf("NOT BICOLORABLE.\n");
                free(q_head);
                return;
            }
            curr = curr->next;
        }
    }
    printf("BICOLORABLE.\n");
    free(q_head);
}

int main() {
    int nv, edge, x, y;
    register int e, c, bc;
    scanf("%d", &nv);
    while (nv != 0) {
        build_graph(nv);
        color();
        free(graph);
        graph = NULL;
        q_head = NULL;
        scanf("%d", &nv);
    }
    return 0;
}
