#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
#define READ(x) scanf("%lld", &x) // ler um numero
#define DEBUG(x, s) if(x)printf("%s\n", s); // se for preciso debugar o programa verifica o x passado se for verdade imprime uma string passada
#define MAX_SIZE (1 << 20) // tamanho m�ximo (2 elevado a 20)
 
// defini��es para tipos
typedef long long lli;
typedef struct graph GRAPH;
typedef struct node NODE;
typedef struct list LIST;
typedef struct queue QUEUE;
 
// estruturas
struct node {
    NODE *next; // guarda o n� para o pr�ximo elemento
    lli value; // valor do n�
};
 
struct list {
    NODE *head; // salva a cabe�a da lista
    lli size; // salva o tamanho da lista
};
 
struct queue {
    NODE *start, *end; // ponteiros pro inicio e pro fim da fila
    lli size; // tamanho da fila
};
 
struct graph {
    LIST *vertice[MAX_SIZE]; // lista de adjecencia de cada vertice do grafo
    short visited[MAX_SIZE]; // marca os vertices j� visitados
    lli dist[MAX_SIZE]; // distancia de um vertice para um vertice origem qualquer
    lli p[MAX_SIZE]; // predecessor de um vertice em rela��o a um vertice origem qualquer
};
 
// cria, inicializa e retorna um n�
NODE *create_node(lli value) {
    NODE *n = (NODE *) malloc(sizeof(NODE));
    n->value = value;
    n->next = NULL;
    return n;
}
 
// cria, inicializa e retorna uma lista
LIST *create_list() {
    LIST *l = (LIST *) malloc(sizeof(LIST));
    l->size = 0;
    l->head = NULL;
    return l;
}
 
// cria, inicializa e retorna uma fila
QUEUE *create_queue() {
    QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
    q->start = q->end = NULL;
    q->size = 0;
    return q;
}
 
// cria, inicializa e retorna um grafo
GRAPH *create_graph(lli vertex) {
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH)); // aloca mem�ria pro grafo
    lli i; // posi��es a serem verificadas
    for( i = 0; i < vertex; i++) {
        g->vertice[i] = create_list(); // inicializa a lista de adjacencia de todas as posi��es
        g->visited[i] = 0; // marca todos os n�s como n�o visitados
        g->dist[i] = MAX_SIZE; // inicia todas as distancias com um valor grande
        g->p[i] = -1; // inicia todos os predecessores com -1 (valor que n�o seta nenhuma posi��o de array, se o predecessor for -1, quer dizer que ele n�o existe)
    }
    return g; // retorna o grafo
}
 
// linked list functions
// insere ordenado na lista
void insert_ordered(LIST *l, lli value) {
    NODE *n = create_node(value);
    if(l->head == NULL || value < l->head->value) {
        n->next = l->head;
        l->size++;
        l->head = n;
        return;
    }
    NODE *c = l->head;
    NODE *prev = NULL;
    while(c != NULL && c->value < value) {
        prev = c;
        c = c->next;
    }
    if(prev != NULL) {
        prev->next = n;
    } else {
        l->head = n;
    }
    n->next = c;
}
// busca um elemento na lista
lli search_element_list(LIST *l, lli value) {
    NODE *c = l->head;
    while(c != NULL) {
        if(c->value == value) return 1;
        c = c->next;
    }
    return 0;
}
// remove um elemento da lista
void remove_element(LIST *l, lli value) {
    NODE *n = l->head;
    NODE *p = NULL;
    while(n != NULL) {
        if(n->value == value){
            if(p == NULL) {
                l->head = l->head->next;
                free(n);
            } else {
                p->next = n->next;
                free(n);
            }
            l->size--;
            return;
        }
        p = n;
        n = n->next;
    }
}
// exibe uma lista
void print_list(LIST *l) {
    NODE *c = l->head;
    while(c != NULL) {
        printf("%lld ", c->value);
        c = c->next;
    }
    printf("\n");
}
 
// queue functions
// enfileira um elemento no fim da fila
void enqueue(QUEUE *q, lli value) {
    NODE *nn = create_node(value);
    if(!q->size) {
        q->start = nn;
        q->end = nn;
        q->size++;
        return;
    }
    q->size++;
    q->end->next = nn;
    q->end = nn;
}
 
// remove e retorna o elemento removido da fila
lli dequeue(QUEUE *q) {
    NODE *c = q->start;
    lli aux;
    aux = c->value;
    q->start = q->start->next;
    q->size--;
    free(c);
    return aux;
}
 
// graph functions
 
// adiciona uma aresta
void add_edge_directed(GRAPH *g, lli vertex1, lli vertex2) {
    insert_ordered(g->vertice[vertex1], vertex2);
}
// faz a busca em largura com um dijkstra para determinar a menor distancia de uma aresta a outra e quem � o predecessor de um vertice com rela��o a menor distancia
void bfs(GRAPH *g, lli source) {
    printf("Iniciando busca em largura a partir de %lld\n", source);
    g->visited[source] = 1; // marca o source como visitado (de onde come�a a busca)
    g->dist[source] = 0; // a distancia de source para source � 0
    g->p[source] = -1; // source n�o tem um predecessor, a busca inicia nele
    NODE *adj_list = g->vertice[source]->head; // cria um n� com a lista de adjacencia de source
    QUEUE *q = create_queue(); // cria uma fila
    enqueue(q, source); // enfileira o source
    lli dequeued; // elemento que vai guardar quem foi removido da fila
    while(q->size) { // enquanto a fila n�o estiver vazia executa o while
        dequeued = dequeue(q); // remove o elemento
        adj_list = g->vertice[dequeued]->head; // pega a lista de adjacencia do elemento removido
        while(adj_list != NULL) { // enquanto a lista de adjacencia n�o estiver fazia executa o while
            if(!g->visited[adj_list->value])  {  // verifica se o vertice n�o foi visitado
                // if(g->dist[adj_list->value] > g->dist[dequeued] + 1) { // verifica se a distancia at� esse vertice atualmente � maior do que a dist�ncia a partir do vertice atual (como todo custo � um, basta verificar a soma com um, caso contr�rio, tem de haver um novo atributo com o custo pra cada aresta)
                    g->dist[adj_list->value] = g->dist[dequeued] + 1; // se o custo � menor atualiza o custo
                    g->p[adj_list->value] = dequeued; // atribui o vertice predecessor do vertice a partir da distancia
                printf("Iniciando busca em largura a partir de %lld\n", adj_list->value); // inicia uma nova busca
                g->visited[adj_list->value] = 1; // marca o vertice atual como visitado
                enqueue(q, adj_list->value); // enfileita o vertice atual na fila para ser verificado
            }
            adj_list = adj_list->next; // vai para o pr�ximo vertice da lista de adjacencia
        }
    }
    printf("\n");
}
// exibe todas as listas de adjacencia de todos os vertices
void print_adj_list(GRAPH *g, int qtd_vertex) {
    lli i;
    for(i = 0; i < qtd_vertex; i++) {
        NODE *h = g->vertice[i]->head;
        printf("%lld: ", i);
        while(h != NULL) {
            printf("%lld ", h->value);
            h = h->next;
        }
        printf("\n");
    }
}
// reinicia todos os vertices como n�o visitados, distancia m�xima e sem predecessores para uma busca a partir de uma origem direfente
void restart_vertices(GRAPH *g, lli vertex) {
    lli i;
    for(i = 0; i < vertex; i++) {
        g->visited[i] = 0;
        g->dist[i] = MAX_SIZE;
        g->p[i] = -1;
    }
}
 
void print_highway(GRAPH *g, lli from, lli to, lli last) {
    if(g->p[to] == -1) {
        printf("Caminho entre %lld e %lld: ", to, last);
        printf("%lld => ", to);
        return;
    }
    print_highway(g, to, g->p[to], last);
    if(to == last) printf("%lld\n", to);
    else printf("%lld => ", to);
}
 
int main() {
    lli vertex, edges, tests, i, o, d, j;
    int a = 0;
    scanf("%lld %lld %lld", &vertex, &edges, &tests); // le quantos vertices, quantas arestas e quantas buscas o programa vai ter/fazer
    GRAPH *g = create_graph(vertex);// cria o grafo
    for(i = 0; i < edges; i++){ // le e cria as arestas
        scanf("%lld %lld", &o, &d);
        add_edge_directed(g, o, d);
    }
    // faz as buscas
    for(i = 0; i < tests; i++) {
        scanf("%lld %lld", &o, &d); // le de onde vai (o) e pra onde deseja ir (d)
        restart_vertices(g, vertex); // inicia os vertices
        printf("--------\n\nCaso de Teste #%lld - BFS(%lld)\n\n", i+1, o); // print pra quest�o
        bfs(g, o); // faz a busca em largura aplicando djikstra para obter a menor distancia entre os vertices
        for(j = 0; j < vertex; j++) {
            printf("%lld | ", j); // printa o vertices
            if(g->dist[j] == MAX_SIZE) printf("- | "); // se a distancia for a incial n�o tem como acessar o vertice a partir da origem lida, ent�o printa um -
            else printf("%lld | ", g->dist[j]); // sen�o, existe a distancia contida na posi��o j do vetor dist do grafo g
            if(g->p[j] == -1) printf("-\n"); // se o predecessor est� como -1 ele n�o existe
            else printf("%lld\n", g->p[j]); //sen�o printa o predecessor
        }
        printf("\n"); // quebra de linha pra formata��o de sa�da da quest�o
        if(g->p[d] != -1) print_highway(g, o, d, d); // se o predecessor de 'd' existe printe o caminho at� ele
        else printf("Sem caminho entre %lld e %lld\n", o, d); // sen�o, exibe que n�o existe caminho de o at� d
        printf("\n"); // formata��o de sa�da da quest�o
    }
    printf("--------");// formata��o de sa�da da quest�o*/
    return 0;
}