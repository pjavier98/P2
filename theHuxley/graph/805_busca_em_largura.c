#include <stdio.h>
#include <stdlib.h>

/************************************************************************/
/* => TADS AND DEFINITIONS */

typedef struct adj_list ADJ_LIST;
typedef struct graph GRAPH;
typedef struct node NODE;
typedef struct queue QUEUE;
typedef struct distance_node DIST_NODE;

/************************************************************************/
/* => DOUBLE CHAINED LIST AND QUEUE */

struct node {
    int item;
    NODE *next;
    NODE *previous;
};

struct distance_node {
    int distance;
    int predecessor;
};

struct queue {
    int size;
    NODE *end;
    NODE *begin;
};

/************************************************************************/
/* => GRAPH */

struct adj_list {
    int amount_nodes;
    NODE *node;
};

struct graph {
    int amount_vertices;
    ADJ_LIST *vertices;
    int *visited;
};

GRAPH* create_graph(int size) {
    int i;
    GRAPH *new_graph = (GRAPH*) malloc(sizeof(GRAPH));
    new_graph->amount_vertices = size;
    new_graph->vertices = (ADJ_LIST *)malloc(sizeof(ADJ_LIST) * (size));
    new_graph->visited = (int*) malloc(sizeof(int) * size);
    
    
    for (i = 0; i < size; i++) {
        new_graph->vertices[i].node = NULL;
        new_graph->vertices[i].amount_nodes = 0;
        new_graph->visited[i] = 0;
    }
    return new_graph;
}

NODE* create_adj_list(int item) {
    NODE *new_adj_list = (NODE*) malloc(sizeof(NODE));
    new_adj_list->item = item;
    new_adj_list->next = NULL;
    new_adj_list->previous = NULL;
    return new_adj_list;
}

/************************************************************************/
/* => THIS FUNCTION IS USED IN DOUBLE CHAINED LIST AND QUEUE */

NODE *create_node(int item) {
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    new_node->item = item;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

DIST_NODE *create_distance_array(int vertices) {
    DIST_NODE *new_array = (DIST_NODE*) malloc(sizeof(DIST_NODE) * vertices);
    int i; 

    for (i = 0; i < vertices; i++) {
        new_array[i].distance = -999;
        new_array[i].predecessor = -1;
    }
    return new_array;
}

/************************************************************************/
/* => DOUBLE CHAINED LIST */

NODE *create_double_chained_list() {
    return NULL;
} 

int is_empty_node(NODE *node) {
    return (node == NULL);
}

void print_list(NODE *node) {
    NODE *aux = node;
    while (aux != NULL) {
        printf("%d <-> ", aux->item);
        aux = aux->next;
    }
    printf("//\n");
}

NODE *erase_node(NODE *node, int item) {
    NODE *current = node;
    while (current != NULL && current->item != item) {
        current = current->next;
    }
    if (current == NULL) {
        return node;
    } else if (node == current) {
        node = current->next;
    } else {
        current->previous->next = current->next;
    }

    if (current->next != NULL) {
        current->next->previous = current->previous;
    }
    free(current);
    return node;
}

NODE* insert_end(NODE *node, int item) {
    NODE *new_node = create_node(item);
    NODE *aux = node; 
    if (!is_empty_node(node)) {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
        new_node->previous = aux;
        return node;
    } else {
      return new_node;
  }
}

NODE *insert_order(NODE *head, int item) {
    NODE *new_node = create_node(item);
    NODE *current = head;
    NODE *previous = NULL;
    if (is_empty_node(head)) {
        return new_node;
    } else if (head->item <= item) {
        new_node->next = head;
        head->previous = new_node;
        return new_node;
    }
    while (current != NULL && current->item > item) {
        previous = current;
        current = current->next;
    }
    if (previous->next == NULL) {
        previous->next = new_node;
        new_node->previous = previous;
    } else {
        previous->next = new_node;
        new_node->next = current;
        new_node->previous = previous;
    }
    return head;
}

/************************************************************************/
/* => QUEUE */

QUEUE *create_queue() {
    QUEUE *new_queue = (QUEUE*) malloc(sizeof(QUEUE));
    new_queue->end = new_queue->begin = NULL;
    return new_queue; 
}

int is_empty_queue(QUEUE *new_q) {
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
    if (is_empty_queue(new_q)) {
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

    if (!is_empty_queue(new_q)) {
        new_q->end->next = new_node;
        new_q->end = new_node;
    } else {
        new_q->begin = new_q->end = new_node;
    }
}

/************************************************************************/
/* => GRAPH */

void print_graph(GRAPH *new_graph) {
    int i;
    for(i = 0; i < new_graph->amount_vertices; i++) {
        NODE *current = new_graph->vertices[i].node;
        printf("\n%d: ", i);
        while(current) {
            printf("%d->", current->item);
            current = current->next;
        }
        printf("NULL\n");
    }
}

DIST_NODE *add_dist_array(DIST_NODE *dist_array, int key, int distance, int predecessor) {
    dist_array[key].distance = distance;
    dist_array[key].predecessor = predecessor;
    return dist_array;
}

void bfs(GRAPH *new_graph, int source, DIST_NODE *dist_array) {
    printf("Iniciando busca em largura a partir de %d\n", source);
    QUEUE *queue = create_queue();
    enqueue(queue, source);

    NODE *adj_list = new_graph->vertices[source].node;
    new_graph->visited[source] = 1;
    dist_array[source].distance = 0;
    dist_array[source].predecessor = -1;
    
    while (!is_empty_queue(queue)) {
        int current_vertex = dequeue(queue);
        adj_list = new_graph->vertices[current_vertex].node;
        while (adj_list != NULL) {
            if (!new_graph->visited[adj_list->item]) {
                dist_array[adj_list->item].distance = dist_array[current_vertex].distance + 1;
                printf("Iniciando busca em largura a partir de %d\n", adj_list->item);
                new_graph->visited[adj_list->item] = 1;
                enqueue(queue, adj_list->item);
                dist_array = add_dist_array(dist_array, adj_list->item, dist_array[adj_list->item].distance, current_vertex);
            }
            adj_list = adj_list->next;
        }
    }
    printf("\n");
}

void add_edge(GRAPH *new_graph, int index_source, int index_destiny) {
    NODE *adj_list = create_adj_list(index_destiny);
    
    adj_list->next = new_graph->vertices[index_source].node;
    new_graph->vertices[index_source].node = adj_list;

//Undirected graph. Edge to the other direction as well.
    // vertex = create_adj_list(vertex1);
    // vertex->next = new_graph->vertices[vertex2];
    // new_graph->vertices[vertex2] = vertex;
}

void zerar(GRAPH *new_graph, int vertices) {
    int i;
    for (i = 0; i < vertices; i++) {
        new_graph->visited[i] = 0;
    }
}

void print_way(DIST_NODE *dist_array, int source, int aux_end, int end) {
    if (dist_array[aux_end].predecessor == -1) {
        printf("Caminho entre %d e %d: ", aux_end, end);
        printf("%d => ", aux_end);
        return;
    }

    print_way(dist_array, aux_end, dist_array[aux_end].predecessor, end);
    if (aux_end != end) {
        printf("%d => ", aux_end);
    } else {
        printf("%d\n", aux_end);
    }
}

int main() {
    int vertices, arestas, tests, index_source, index_destiny;
    scanf("%d %d %d", &vertices, &arestas, &tests);
    GRAPH *new_graph = create_graph(vertices);
    NODE *new_array[arestas];
    DIST_NODE *dist_array = create_distance_array(vertices);
    
    int i; 
    for (i = 0; i < arestas; i++) {
        new_array[i] = NULL;
    }

    for(i = 0; i < arestas; i++) {
        scanf("%d %d", &index_source, &index_destiny);
        new_array[index_source] = insert_order(new_array[index_source], index_destiny);
    }

    for (i = 0; i < arestas; i++) {
        while (new_array[i] != NULL) {
            add_edge(new_graph, i, new_array[i]->item);
            new_array[i] = new_array[i]->next;
        }
    }  

    //print_graph(new_graph);
    int j;
    for(j = 0; j < tests; j++) {
        scanf("%d %d", &index_source, &index_destiny);
        printf("--------\n\n");
        printf("Caso de Teste #%d - BFS(%d)\n\n", j + 1, index_source);
        zerar(new_graph, vertices);
        bfs(new_graph, index_source, dist_array);
        for (i = 0; i < vertices; i++) {
            printf("%d", i);
            printf(" | ");
            if (dist_array[i].distance == -999) {
                printf("-");
            } else {
                printf("%d", dist_array[i].distance);    
            } 

            printf(" | ");

            if (dist_array[i].predecessor == -1) {
                printf("-");
            } else {
                printf("%d", dist_array[i].predecessor);
            }
            printf("\n");
        }
        printf("\n");
        if (dist_array[index_destiny].predecessor == -1) {
            printf("Sem caminho entre %d e %d\n", index_source, index_destiny);
        } else {
            print_way(dist_array, index_source, index_destiny, index_destiny);
        }
        printf("\n");
    }
    printf("--------\n");
    return 0;
}