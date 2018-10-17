#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
	int item;
	NODE *next;
	NODE *previous;
};

NODE *create_node(int item) {
	NODE* new_node = (NODE*) malloc(sizeof(NODE));
	new_node->item = item;
	new_node->next = NULL;
	new_node->previous = NULL;
	return new_node;
}

NODE *create_double_chained_list() {
	return NULL;
} 

int is_empty(NODE *head) {
	return (head == NULL);
}

void print_list(NODE *head) {
	NODE *aux = head;
	while (aux != NULL) {
		printf("%d -> ", aux->item);
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

NODE* search(NODE *head, int item) {
	NODE *aux = head;
	while (aux != NULL) {
	  if (aux->item == item) {
		 return aux;
	 }
	 aux = aux->next;
 }
 return NULL;
}

NODE *insert_order(NODE *head, int item) {
    NODE *new_node = create_node(item);
    NODE *current = head;
    NODE *previous = NULL;
    if (is_empty_node(head)) {
        return new_node;
    } else if (head->item >= item) {
        new_node->next = head;
        head->previous = new_node;
        return new_node;
    }
    while (current != NULL && current->item < item) {
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

NODE *insert_begin(NODE *head, int item) {
	NODE *new_node = create_node(item); 
	if (!is_empty(head)) {
		new_node->next = head;
		head->previous = new_node;
	}
	return new_node;
}

int main() {
	NODE *head = create_double_chained_list();
	// head = insert_begin(head, 15);
	// head = insert_end(head, 7);
	// head = insert_order(head, i);
	// head = erase_node(head, 7);
	// print_list(head);
	return 0;
}
