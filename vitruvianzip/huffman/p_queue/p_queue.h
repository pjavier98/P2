#ifndef p_queue_h
#define p_queue_h

#include "../header/header.h"
#include "../huff/huff_tree.h"

typedef struct p_queue P_QUEUE;
typedef struct node NODE;

struct node {
	HUFF_NODE *value;
	NODE *next;
};
	
struct p_queue {
	NODE *head;
	lli size;
};

NODE *create_node(HUFF_NODE *huff_node);
/*
 *
 */

P_QUEUE *create_p_queue();
/*
 *
 */

USH p_queue_is_empty(P_QUEUE *huff_p_queue);
/*
 *
 */

void enqueue(P_QUEUE *huff_p_queue, HUFF_NODE *huff_node);
/*
 *
 */

void print_p_queue(P_QUEUE *huff_p_queue, void (*print)(DATATYPE));
/*
 *
 */

NODE *dequeue(P_QUEUE *huff_p_queue, DATATYPE key, int (*equals)(DATATYPE, DATATYPE));
/*
 *
 */

#endif