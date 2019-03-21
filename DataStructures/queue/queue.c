#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct queue QUEUE;

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

NODE *create_node(int item) {
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node->item = item;
	new_node->next = NULL;
	new_node->previous = NULL;
	return new_node;
}

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

void enqueue_priority(QUEUE *new_q, int item) {
	NODE *new_node = create_node(item);
	new_q->size++;
	if(new_q->begin == NULL) {	
		new_q->begin = new_q->end = new_node;
	} else {
		NODE *temp = new_q->begin;
		NODE *prev;
		while(temp != NULL && temp->item >= item) { 
			temp = temp->next;
		}

		if(temp == NULL) {
			new_q->end->next = new_node;
			new_node->previous = new_q->end;
			new_q->end = new_node;
		} else if(temp->previous == NULL) {
			new_q->begin->previous = new_node;
			new_node->next = new_q->begin;
			new_q->begin = new_node;
		} else {
			prev = temp->previous;
			prev->next = new_node;
			new_node->previous = prev;
			new_node->next = temp;
			temp->previous = new_node;
		}
	}
}

int main()
{
	QUEUE *new_queue = create_queue();
	enqueue(new_queue, 1);
	enqueue_priority(new_queue, 7);
	print_queue(new_queue);
	dequeue(new_queue);
	print_queue(new_queue);
	printf("size: %d\n", new_queue->size);
}
