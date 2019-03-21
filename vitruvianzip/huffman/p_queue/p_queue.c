#include "p_queue.h"

NODE *create_node(HUFF_NODE *huff_node) {
	NODE *new_node = (NODE *) malloc(sizeof(NODE));
	new_node->value = huff_node;
	new_node->next = NULL;
	return new_node;
}

P_QUEUE *create_p_queue() {
	P_QUEUE *huff_p_queue = (P_QUEUE*) malloc(sizeof(P_QUEUE));
	huff_p_queue->head = NULL;
	huff_p_queue->size = 0;
	return huff_p_queue;
}

USH p_queue_is_empty(P_QUEUE *huff_p_queue) {
	return huff_p_queue->size == 0;
}	

void enqueue(P_QUEUE *huff_p_queue, HUFF_NODE *huff_node) {	
	NODE *new_node = create_node(huff_node);
	if(p_queue_is_empty(huff_p_queue)) {
		huff_p_queue->head = new_node;
		huff_p_queue->size++;
		return;
	}
	huff_p_queue->size++;
	NODE *current = huff_p_queue->head, *prev = NULL;

	
	while(current != NULL && current->value->frequency < new_node->value->frequency) {
			prev = current;
			current = current->next;
	}

	if(prev == NULL) {
		new_node->next = huff_p_queue->head;
		huff_p_queue->head = new_node;
		return;
	}
	prev->next = new_node;
	new_node->next = current;
}

void print_p_queue(P_QUEUE *huff_p_queue, void (*print)(DATATYPE)) {
	NODE *current = huff_p_queue->head;
	while(current != NULL) {
		printf("(");
		(*print)(current->value->key);
		printf(",%lld)", current->value->frequency);
		current = current->next;
	}
	puts("");
}

NODE *dequeue(P_QUEUE *huff_p_queue, DATATYPE key, int (*equals)(DATATYPE, DATATYPE)) {
	NODE *current = huff_p_queue->head;
	NODE *prev = NULL;	
	while(current != NULL && !equals(current->value->key, key)) {
		prev = current;
		current = current->next;
	}
	if(prev != NULL) {
		prev->next = current->next;
	} else {
		huff_p_queue->head = current->next;
	}
	huff_p_queue->size--;
	current->next = NULL;
	return current;
}