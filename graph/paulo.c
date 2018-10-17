#include <stdio.h>
#include <stdlib.h>

/* Nó da lista de adjacência */
typedef struct adjListNode {
    int vertice;
    struct adjListNode *next;
} AdjListNode;

typedef struct adjList {
    int quantNos;
    AdjListNode *head;
} AdjList;

typedef struct graph {
    int quantVertices;
    AdjList *vertices;
    int *visited;
} Graph;

typedef struct queue {
    AdjListNode *front;
    int size;
} Queue;

typedef struct node {
    int dist;
    int pred;
    struct node *next;
} Node;

// ####

typedef struct hashTable {
    float size;
    float current_size;
    Node **table;
} HashTable;

HashTable *createTable(int size);

int hashKey(int size, int value);

Node *createNode(int dist, int pred);

// ####

AdjListNode *createAdjListNode(int vertice);
Graph *createGraph(int size);
void destroyGraph(Graph *g);
void addEdge(Graph *g, int origem, int destino);
void printGraph(Graph *g);
Queue *createQueue();
Queue *enqueue(Queue *q, int value);
int dequeue(Queue *q);
void bfs(Graph *g, int origem, HashTable *ht);
void resetVisited(Graph *g, int size);
void printQueue(Queue *q);
HashTable *addToHash(HashTable *ht, int no, int dist, int pred);
void printTable(HashTable *ht);
void freeTable(HashTable *ht);
void printList(AdjListNode *head);
void reverseSearch(HashTable *ht, int origem, int destino);
AdjListNode *insertNode(AdjListNode *head, int vertice);

int main() {


    int quantVertices, quantArestas, quantCasos, i, origem, destino, teste = 1;
    scanf("%d %d %d", &quantVertices, &quantArestas, &quantCasos);
    Graph *g = createGraph(quantVertices);

    for(i=0;i<quantArestas; i++) {
        scanf("%d %d", &origem, &destino);
        addEdge(g, origem, destino);
    }

    // printGraph(g);
    // printf("\n\n");

        printf("--------\n\n");

    for(i=0;i<quantCasos; i++) {
        HashTable *ht = createTable(quantVertices);
        scanf("%d %d", &origem, &destino);
        printf("Caso de Teste #%d - BFS(%d)\n\n", teste, origem);
        bfs(g, origem, ht);
        reverseSearch(ht, origem, destino);
        resetVisited(g, quantVertices);
        // freeTable(ht);
        printf("\n");
        printf("--------\n\n");
        teste++;
    }


    destroyGraph(g);

    return 0;
}

AdjListNode *addNode(AdjListNode *head, int vertice) {
    // printf("Entering addNode\n");
    AdjListNode *new_node = createAdjListNode(vertice);

    if(!head) {
        head = new_node;
    } else {
        AdjListNode *current = head;
        while(current->next) {
            current = current->next;    
        }
        current->next = new_node;
    }
    // printf("addNode done\n");
    return head;

}

AdjListNode *createAdjListNode(int vertice) {
    // printf("Entering createAdjListNode\n");
    AdjListNode *new_node = (AdjListNode *)malloc(sizeof(AdjListNode));
    if(!new_node) {
        printf("Unable to allocate memory for adjListNode with vertice %d\n", vertice);
        exit(1);
    }
    new_node->vertice = vertice;
    new_node->next = NULL;
    // printf("adjListNode done\n");
    return new_node;
}

Queue *enqueue(Queue *q, int value) {
    // printf("Entering enqueue\n");
    if(q->front == NULL) {
        q->front = createAdjListNode(value);
    }
    else
    {
        AdjListNode *current = q->front, *prev = NULL, *new_node = createAdjListNode(value);
        if(q->front->vertice > value) {
            new_node->next = q->front;
            q->front = new_node;
        } else {
            while(current->next != NULL && current->next->vertice < value) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    q->size++;
    // printf("enqueue done\n");
    return q;
}

Queue *freeQueueElements(Queue *q) {
    // printf("Entering freeQueueElements\n");
    AdjListNode *current = q->front, *aux = NULL;
    while(current != NULL) {
        aux = current;
        current = current->next;
        // free(aux);
    }
    // printf("#############");
    q->front = NULL;
    q->size = 0;
    // printf("freeQueueElements done\n");
    return q;
}

void printQueue(Queue *q) {
    // printf("Entering printQueue\n");
    AdjListNode *current = q->front;
    while(current) {
        printf("%d ", current->vertice);
        current = current->next;
    }
    printf("\n");
    // printf("printQueue done\n");
}

void resetVisited(Graph *g, int size) {
    // printf("Entering resetVisited\n");
    int i;
    for(i=0;i<size;i++) {
        g->visited[i] = 0;
    }
    // printf("resetVisited done\n");
}

int dequeue(Queue *q) {
    // printf("Entering dequeue\n");
    int aux = q->front->vertice;
    AdjListNode *auxp = q->front;
    q->front = q->front->next;
    free(auxp);
    q->size--;
    return aux;
    // printf("dequeue done\n");
}

Queue *createQueue() {
    // printf("Entering createQueue\n");
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(!q) {
        printf("Unable to allocate memory Queue");
        exit(1);
    }
    q->front = NULL;
    q->size = 0;
    return q;
    // printf("createQueue done\n");
}

Queue *mergeQueues(Queue *main, Queue *second) {
    // printf("Entering Merge\n");

    if(!main->front) {
        main->front = second->front;
    } else {
        AdjListNode *currentMain = main->front;
        while(currentMain->next != NULL) {
            currentMain = currentMain->next;
        }
        currentMain->next = second->front;
    }
    main->size += second->size;
    // printf("Merge Done\n");
    return main;
}

Graph *createGraph(int size) {
    // printf("Entering createGraph\n");
    int i;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if(!g) {
        printf("Unable to allocate memory for Graph with %d vertices", size);
        exit(1);
    }
    g->quantVertices = size;
    g->vertices = (AdjList *)malloc(sizeof(AdjList) * (size));
    if(!g->vertices) {
        printf("Unable to allocate memory for adjList array for Graph with size %d", size);
    }
    g->visited = (int *)malloc((size) * sizeof(int));
    if(!g->visited) {
        printf("Unable to allocate memory for visited list\n");
        exit(1);
    }

    for(i = 0; i < size; i++) {
        g->vertices[i].head = NULL;
        g->vertices[i].quantNos = 0;
        g->visited[i] = 0;
    }
    // printf("createGraph done\n");
    return g;
}

void destroyGraph(Graph *g) {
    // printf("Entering destroyGraph\n");
    if(g) {
        if(g->vertices) {
            int i;
            for(i=0;i<g->quantVertices; i++) {
                AdjListNode *current = g->vertices[i].head;
                while(current) {
                    AdjListNode *aux = current;
                    current = current->next;
                    free(aux);
                }
            }
            free(g->vertices);
        }
        free(g);
    }
    // printf("destroyGraph done\n");
}

void printGraph(Graph *g) {
    // printf("Entering printGraph\n");
    int i;
    for(i=0;i<g->quantVertices;i++) {
        AdjListNode *current = g->vertices[i].head;
        printf("\n%d: ", i);
        while(current) {
            printf("%d->", current->vertice);
            current = current->next;
        }
        printf("NULL\n");
    }
    // printf("printGraph done\n");
}

void bfs(Graph *g, int origem, HashTable *ht) {
    // printf("Entering bfs\n");
    int distancia = 0, arrayDist[g->quantVertices + 1];//
    Queue *queue = createQueue();//
    Queue *auxQueue = createQueue();
    g->visited[origem] = 1;//
    queue = enqueue(queue, origem);//
    
    ht = addToHash(ht, origem, distancia, -1);
    arrayDist[origem] = 0;

    while(queue->size > 0) {
        // printQueue(queue);
        int verticeAtual = dequeue(queue);

        //int prevDist = distancia;
        distancia = arrayDist[verticeAtual] + 1;
        printf("Iniciando busca em largura a partir de %d\n", verticeAtual);

        AdjListNode *current = g->vertices[verticeAtual].head;
        while(current) {
            int adjVertice = current->vertice;
            // printf("# %d#\n", g->visited[adjVertice]);

            if(g->visited[adjVertice] == 0) {
                g->visited[adjVertice] = 1;
                enqueue(auxQueue, adjVertice);
                arrayDist[adjVertice] = distancia;
                // printf("Adding to %d: dist(%d) and pred(%d)\n", adjVertice, arrayDist[adjVertice], verticeAtual);
                ht = addToHash(ht, adjVertice, arrayDist[adjVertice], verticeAtual);
            }
            current = current->next;
        }
        // printf("Main Queue: ");
        // printQueue(queue);
        // printf("Aux Queue: ");
        // printQueue(auxQueue);
        queue = mergeQueues(queue, auxQueue);
        auxQueue = freeQueueElements(auxQueue);
    }
    printTable(ht);

    // printf("bfs done\n");
}

Node *createNode(int dist, int pred) {
    // printf("Starting createNode\n");
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->dist = dist;
    new_node->pred = pred;

    return new_node;
    // printf("createNode done\n");
}

HashTable *addToHash(HashTable *ht, int no, int dist, int pred) {
    // printf("Starting addToHash\n");
    int key = hashKey(ht->size, no);

    ht->table[key]->dist = dist;
    ht->table[key]->pred = pred;
    // printf("addToHash done\n");
    return ht;
}

HashTable *createTable(int size) {
    // printf("Starting createTable\n");
    HashTable *new_table = NULL;
    new_table = (HashTable *)malloc(sizeof(HashTable));
    new_table->table = (Node **)malloc(sizeof(Node*) * size);
    new_table->current_size = 0; 
    new_table->size = size;
    int i;
    for(i=0;i<size;i++) {
        new_table->table[i] = createNode(-1, -1);
    }
    // printf("createTable done\n");
    return new_table;   
}

void printTable(HashTable *ht) {
    // printf("Starting printTable\n");
    int i;
    printf("\n");
    for(i=0;i<ht->size;i++) {
        if(ht->table[i]->dist != -1 && ht->table[i]->pred != -1) {
            printf("%d | %d | %d\n", i, ht->table[i]->dist, ht->table[i]->pred);
        } else {
            if(ht->table[i]->dist == -1 && ht->table[i]->pred != -1) {
                printf("%d | - | %d\n", i, ht->table[i]->pred);
            } else if(ht->table[i]->dist != -1 && ht->table[i]->pred == -1) {
                printf("%d | %d | -\n", i, ht->table[i]->dist);
            } else {
                printf("%d | - | -\n", i);
            }
        }
        
    }
    printf("\n");
    // printf("printTable done\n");
}

int hashKey(int size, int value) {
    return value % size;
}

void freeTable(HashTable *ht) {
    // printf("Entering freeTable\n");
    int i;

    for(i=0;i<ht->size;i++) {
        if(ht->table[i] != NULL) {
            free(ht->table[i]);
        }
    }
    // printf("freeTable done\n");
}

void printList(AdjListNode *head) {
    // printf("Entering printList\n");
    AdjListNode *current = head;
    // printf("### ");
    while(current) {
        if(!current->next) {
            printf(" %d\n", current->vertice);
        } else if (current == head) {
            printf("%d =>", current->vertice);
        } else {
            printf(" %d =>", current->vertice);
        }
        current = current->next;
    }
    // printf("###\n");
    // printf("printList done\n");
}

AdjListNode *insertNode(AdjListNode *head, int vertice) {
    // printf("Entering insertNode\n");
    AdjListNode *new_node = createAdjListNode(vertice);
    new_node->next = head;
    head = new_node;
    // printf("insertNode done\n");
    return head;
}

void reverseSearch(HashTable *ht, int origem, int destino) {
    // printf("Entering reverseSearch\n");
    AdjListNode *list = createAdjListNode(destino);

    int key = hashKey(ht->size, destino);


    while(key != origem) {
        // printf("%d =>", ht->table[key]->pred);
        if(ht->table[key]->pred == -1) {
            printf("Sem caminho entre %d e %d\n", origem, destino);
            return;
        }
        list = insertNode(list, ht->table[key]->pred);
        key = hashKey(ht->size, ht->table[key]->pred);
    }
    printf("Caminho entre %d e %d: ", origem, destino);
    printList(list);

    // printf("reverseSearch done\n");
}

void addEdge(Graph *g, int origem, int destino) {
    // printf("Entering addEdge\n");

    AdjListNode *new_node = createAdjListNode(destino);
    new_node->next = g->vertices[origem].head;
    g->vertices[origem].head = new_node;
    g->vertices[origem].quantNos++;

    // new_node = createAdjListNode(origem);
    // new_node->next = g->vertices[destino].head;
    // g->vertices[destino].head = new_node;
    // g->vertices[destino].quantNos++;
    // printf("addEdge done\n");
}