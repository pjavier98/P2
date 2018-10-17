#include <stdio.h>
#include <stdlib.h>

/************************************************************************/
/* => TADS AND DEFINITIONS */

typedef struct adj_list ADJ_LIST;
typedef struct graph GRAPH;
typedef struct node NODE;
typedef struct queue QUEUE;

/************************************************************************/
/* => GRAPH */

struct adj_list {
    int amont_nodes;
    NODE *next;
    NODE *previous;
};

struct graph {
    int amount_vertices;
    ADJ_LIST *vertices;
    short visited;
};

GRAPH* create_graph(int size) {
    int i;
    GRAPH *new_graph = (GRAPH*) malloc(sizeof(GRAPH));
    new_graph->vertices = (ADJ_LIST *)malloc(sizeof(ADJ_LIST) * (size));
    new_graph->visited = (int*) malloc(sizeof(int) * size);
    new_graph->amount_vertices = size;
    
    for (i = 0; i < size; i++) {
        new_graph->vertices[i].head = NULL;
        new_graph->vertices[i].amount_nodes = 0;
        new_graph->visited[i] = 0;
    }
    return new_graph;
}

ADJ_LIST* create_adj_list(int item) {
    ADJ_LIST *new_adj_list = (ADJ_LIST*) malloc(sizeof(ADJ_LIST));
    new_adj_list->item = item;
    new_adj_list->next = NULL;
    return new_adj_list;
}

/************************************************************************/
/* => DOUBLE CHAINED LIST AND QUEUE */

struct node {
    int item;
    NODE *next;
    NODE *previous;
};

struct queue {
    int size;
    NODE *end;
    NODE *begin;
};

/************************************************************************/
/* => THIS FUNCTION IS USED IN DOUBLE CHAINED LIST AND QUEUE */

NODE *create_node(int item) {
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    new_node->item = item;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

/************************************************************************/
/* => DOUBLE CHAINED LIST */

NODE *create_double_chained_list() {
    return NULL;
} 

int is_empty(NODE *head) {
    return (head == NULL);
}

void print_list(NODE *head) {
    NODE *aux = head;
    while (aux != NULL) {
        printf("%d <-> ", aux->item);
        aux = aux->next;
    }
    printf("//\n");
}

NODE *erase_node(NODE *head, int item) {
    NODE *current = head;
    while (current != NULL && current->item != item) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    } else if (head == current) {
        head = current->next;
    } else {
        current->previous->next = current->next;
    }

    if (current->next != NULL) {
        current->next->previous = current->previous;
    }
    free(current);
    return head;
}

NODE* insert_end(NODE *head, int item) {
    NODE *new_node = create_node(item);
    NODE *aux = head; 
    if (!is_empty(head)) {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
        new_node->previous = aux;
        return head;
    } else {
      return new_node;
    }
}


/************************************************************************/
/* => QUEUE */

QUEUE *create_queue() {
    QUEUE *new_queue = (QUEUE*) malloc(sizeof(QUEUE));
    new_queue->end = new_queue->begin = NULL;
    return new_queue; 
}

int is_empty(QUEUE *new_q) {
    return new_q->end == NULL;
}

void print_queue(QUEUE *new_q) {
    NODE *aux = new_q->begin;
    while (aux != NULL) {
        printf("%d ", aux->item);
        aux = aux->next;    
    }
    printf("\n");
}

int dequeue(QUEUE *new_q) {
    new_q->size--;
    if (is_empty(new_q)) {
        printf("Fila vazia\n");
        return -1;
    } else if (new_q->begin == new_q->end) {
        NODE *new_node = new_q->begin;
        int item = new_node->item;
        new_q->begin = new_q->end = NULL;
        return item;
    } else {
        NODE *new_node = new_q->begin;
        int item = new_node->item;
        new_q->begin = new_q->begin->next;
        return item;
    }
}

void enqueue(QUEUE *new_q, int item) {
    NODE *new_node = create_node(item);
    new_q->size++;

    if (!is_empty(new_q)) {
        new_q->end->next = new_node;
        new_q->end = new_node;
    } else {
        new_q->begin = new_q->end = new_node;
    }
}

/************************************************************************/
/* => GRAPH */

void printGraph(Graph *new_graph) {
    int i;
    for(i = 0; i < new_graph->quantVertices; i++) {
        ADJ_LIST *current = new_graph->vertices[i].head;
        printf("\n%d: ", i);
        while(current) {
            printf("%d->", current->vertice);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void bfs(GRAPH *new_graph, int source) {
    queue *queue = create_queue();
    int dequeued;

    ADJ_LIST *adj_list = new_graph->vertices[source];
    new_graph->visited[source] = 1;
    enqueue(queue, source);
    while (!is_empty(queue)) {
        dequeued = dequeue(queue);
        adj_list = new_graph->vertices[dequeued];
        while (adj_list != NULL) {
            if (!new_graph->visited[adj_list->item]) {
                printf("%d\n", adj_list->item);
                new_graph->visited[adj_list->item] = 1;
                enqueue(queue, adj_list->item);
            }
            adj_list = adj_list->next;
        }
    }
}

void dfs(GRAPH *new_graph, int source) {
    new_graph->visited[source] = 1;
    printf("%d\n", source);
    adj_list *adj_list = new_graph->vertices[source];
    while (adj_list != NULL) {
        if (!new_graph->visited[adj_list->item]) {
            dfs(new_graph, adj_list->item);
        }
        adj_list = adj_list->next;
    }
}

void add_edge(GRAPH *new_graph, int vertex1, int vertex2) {
    ADJ_LIST *vertex = create_adj_list(vertex2);
    vertex->next = new_graph->vertices[vertex1];
    new_graph->vertices[vertex1] = vertex;
//Undirected graph. Edge to the other direction as well.
    vertex = create_adj_list(vertex1);
    vertex->next = new_graph->vertices[vertex2];
    new_graph->vertices[vertex2] = vertex;
}

int main() {
    return 0;
}