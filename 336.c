#include <stdio.h>
#include <stdlib.h>

int tv;

inline void scanint(int *x) {
    register char c = getchar();
    *x = 0;
    for (; (c < 48) || (c > 57); c = getchar());
    for (; (c > 47) && (c < 58); c = getchar())
        *x = (int) ((((*x) << 1) + ((*x) << 3)) + c - 48);
}

inline void printint(int n) {
    if (n == 0) {
        putchar('0');
    } else {
        char buf[11];
        buf[10] = '\n';
        int i = 9;
        while (n) {
            buf[i--] = n % 10 + '0';
            n /= 10;
        }
        i++;
        while (buf[i] != '\n') {
            putchar(buf[i++]);
        }
    }
}

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
    int d;
    int p;
} base_node_t;

node_t *q_head = NULL;
base_node_t *graph = NULL;

int qc = 0;

void add_vertex(node_t **parent_node_head, base_node_t *base_node_addr, int val) {
    node_t *curr;
    curr = *parent_node_head;
    if ((*parent_node_head) != NULL) {
        while (curr->next != NULL) {
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
        graph->color = 0;
        graph->d = -1;
        graph->p = -1;
        tv++;
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
    curr->color = 0;
    curr->d = -1;
    curr->p = -1;
    tv++;
    return curr;
}

void build_graph(int e) {
    int x, y;
    base_node_t *ax, *ay;
    while (e--) {
        scanint(&x);
        scanint(&y);
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

int bfs(int s, int ttl) {
    int rv = 0;
    base_node_t *curr_base;
    if (graph != NULL) {
        curr_base = graph;
    } else {
        return 0;
    }
    while (curr_base->vertex != s) {
        curr_base = curr_base->next;
        if (curr_base == NULL) {
            return 0;
        }
    }
    curr_base->color = 1;
    curr_base->d = 0;
    curr_base->p = -1;
    qc = 0;
    nq(s);
    rv++;
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
            if (q_base->color == 0) {
                q_base->color = 1;
                q_base->d = curr_base->d + 1;
                if (q_base->d <= ttl)rv++;
                q_base->parent = curr_base;
                q_base->p = curr_base->vertex;
                nq(v);
            }
            curr = curr->next;
        }
        curr_base->color = 2;
    }
    return rv;
}

int main() {
    register int t = 0;
    int e;
    scanint(&e);
    while (e != 0) {
        build_graph(e);
        int root, ttl;
        scanint(&root);
        scanint(&ttl);
        while (root != 0 || ttl != 0) {
            int rv = bfs(root, ttl);
            putchar('C');
            putchar('a');
            putchar('s');
            putchar('e');
            putchar(' ');
            printint(++t);
            putchar(':');
            putchar(' ');
            printint(tv - rv);
            putchar(' ');
            putchar('n');
            putchar('o');
            putchar('d');
            putchar('e');
            putchar('s');
            putchar(' ');
            putchar('n');
            putchar('o');
            putchar('t');
            putchar(' ');
            putchar('r');
            putchar('e');
            putchar('a');
            putchar('c');
            putchar('h');
            putchar('a');
            putchar('b');
            putchar('l');
            putchar('e');
            putchar(' ');
            putchar('f');
            putchar('r');
            putchar('o');
            putchar('m');
            putchar(' ');
            putchar('n');
            putchar('o');
            putchar('d');
            putchar('e');
            putchar(' ');
            printint(root);
            putchar(' ');
            putchar('w');
            putchar('i');
            putchar('t');
            putchar('h');
            putchar(' ');
            putchar('T');
            putchar('T');
            putchar('L');
            putchar(' ');
            putchar('=');
            putchar(' ');
            printint(ttl);
            putchar('.');
            putchar('\n');

            free(q_head);
            q_head = NULL;
            base_node_t *curr_base;
            curr_base = graph;
            while (curr_base != NULL) {
                curr_base->color = 0;
                curr_base->d = -1;
                curr_base->p = -1;
                curr_base = curr_base->next;
            }
            scanint(&root);
            scanint(&ttl);
        }
        tv = 0;
        free(graph);
        graph = NULL;
        scanint(&e);
    }
    return 0;
}
