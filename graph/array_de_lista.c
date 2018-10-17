#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
	int item;
	NODE *next;
	NODE *previous;
};

NODE *create_node(int item) {
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->item = item;
}

int is_empty(NODE *head) {
	return (head == NULL);
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

int main() {
	int size = 3;
	NODE *new_array[size];
	new_array[0] = NULL;
	new_array[1] = NULL;
	new_array[2] = NULL;

	new_array[0] = insert_end(new_array[0], 1);
	new_array[0] = insert_end(new_array[0], 2);
	new_array[0] = insert_end(new_array[0], 3);
	
	printf("%d\n", new_array[0]->item);
	printf("%d\n", new_array[0]->next->item);
	printf("%d\n", new_array[0]->next->next->item);
}