#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct adj_list ADJ_LIST;
typedef struct graph GRAPH;
typedef struct list LIST;
typedef struct node NODE;

/************************************************************************/
/* => TADS */

struct list {
	char str[15];
	LIST *next;
	LIST *previous;
	NODE *down;
};

struct adj_list {
	int item;
	ADJ_LIST *next;
	ADJ_LIST *previous;
};

struct graph {
	ADJ_LIST *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
};

LIST *create_list(char *word) {
	LIST* new_list = (LIST*) malloc(sizeof(LIST));
	strcpy(new_list->str, word);
	new_list->next = NULL;
	new_list->previous = NULL;
	new_list->down = NULL;
	return new_list;
}

ADJ_LIST* create_adj_list(int item) {
	ADJ_LIST *new_adj_list = (ADJ_LIST*) malloc(sizeof(ADJ_LIST));
	new_adj_list->item = item;
	new_adj_list->next = NULL;
	new_adj_list->previous = NULL;
	return new_adj_list;
}

GRAPH* create_graph() {
	int i;
	GRAPH *new_graph = (GRAPH*) malloc(sizeof(GRAPH));

	for (i = 0; i < MAX_SIZE; i++) {
		new_graph->vertices[i] = NULL;
		new_graph->visited[i] = 0;
	}
	return new_graph;
}

/************************************************************************/
/* => DOUBLE CHAINED LIST */

LIST *create_double_chained_list() {
	return NULL;
} 

int is_empty_list(LIST *head) {
	return (head == NULL);
}

void print_list(LIST *head) {
	LIST *aux = head;
	while (aux != NULL) {
		printf("%s -> ", aux->str);
		aux = aux->next;
	}
	printf("//\n");
}

int search(LIST *head, char *str) {
	LIST *aux = head;
	while (aux != NULL) {
		if (strcmp(aux->str, str) == 0) {
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}

LIST *insert_order(LIST *head, char *str_1) {
	LIST *new_list = create_list(str_1);
	LIST *current = head;
	LIST *previous = NULL;
	if (is_empty_list(head)) {
		return new_list;
	} else if (strcmp(head->str, str_1) > 0) {
		new_list->next = head;
		head->previous = new_list;
		return new_list;
	} else {
		while (current != NULL && strcmp(current->str, str_1) < 0) {
			previous = current;
			current = current->next;
		}
		if (previous->next == NULL) {
			previous->next = new_list;
			new_list->previous = previous;
		} else {
			if (strlen(str_1) < strlen(head->str)) {
				new_list->next = head;
				head->previous = new_list;
				return new_list;
			}
			previous->next = new_list;
			new_list->next = current;
			new_list->previous = previous;
		}
	}
	return head;
}

/************************************************************************/
/* => GRAPH */

void add_edge(GRAPH *new_graph, int vertex1, int vertex2) {
	ADJ_LIST *vertex = create_adj_list(vertex2);
	vertex->next = new_graph->vertices[vertex1];
	new_graph->vertices[vertex1] = vertex;
	/*Undirected graph. Edge to the other direction as well.*/

	// vertex = create_adj_list(vertex1);
	// vertex->next = new_graph->vertices[vertex2];
	// new_graph->vertices[vertex2] = vertex;
}

// void dfs(GRAPH *new_graph, int source, int *parents) {
// 	new_graph->visited[source] = 1;
// 	printf("%d\n", source);
// 	ADJ_LIST *adj_list = new_graph->vertices[source];
// 	while (adj_list != NULL) {
// 		if (parents[adj_list->item] != 0) {
// 			printf("%s\n", new_alphabet->vertices[adj_list->item]->word);
// 		}
// 		if (!new_graph->visited[adj_list->item]) {
// 			dfs(new_graph, adj_list->item, parents, new_alphabet);
// 		}
// 		adj_list = adj_list->next;
// 	}
// }

void print_graph(GRAPH *new_graph) {
	int i;
	for(i = 0; i < MAX_SIZE; i++) {
		if (new_graph->visited[i] == 1) {
			ADJ_LIST *current = new_graph->vertices[i];
			printf("\n%d: ", i);
			while(current != NULL) {
				printf("%d->", current->item);
				current = current->next;
			}
			printf("NULL\n");
		}
	}
}



int main() {
	GRAPH *new_graph = create_graph();
	LIST *new_list = create_double_chained_list();
	int amount;
	scanf("%d", &amount);

	char string_1[15], string_2[15];
	
	while (amount > 0) {
		scanf("%s %s", string_1, string_2);
		//printf("%s %s\n", string_1, string_2);
		
		if (!search(new_list, string_1) && !search(new_list, string_2)) {
			new_list = insert_order(new_list, string_1);
			new_list = insert_order(new_list, string_2);
		}

		// while ()
		// printf("%d\n", new_list->size);
		amount--;
	}
	print_list(new_list);
	//printf("%s -> %s\n", new_node->str, new_node->next->str);	
	//print_list(new_node);
}

// if (strcmp(string_1, string_2) < 0) {
		// 	printf("vai primeiro -> %s\n", string_1);
		// } else if (strcmp(string_1, string_2) > 0) {
		// 	printf("vai primeiro -> %s\n", string_2);
		// }