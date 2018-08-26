#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *previous;
}node;

typedef struct queue
{
	node *end;
	node *begin;
	int size;
}queue;

node *create_node(int item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->value = item;
	new_node->next = NULL;
	new_node->previous = NULL;
	return new_node;
}

queue *create_queue()
{
	queue *new_queue = (queue*) malloc(sizeof(queue));
	new_queue->end = new_queue->begin = NULL;
	return new_queue; 
}

int is_empty(queue *new_q)
{
	return new_q->end == NULL;
}

void printar(queue *new_q)
{
    node *aux = new_q->front;
    
    while (aux != NULL)
    {
        printf("%d ", aux->value);
        aux = aux->next;    
    }
    printf("\n");

}

void enqueue(queue *new_q, int item)
{
	node *new_node = create_node(item);
	new_q->size++;

	if (!is_empty(new_q))
	{
		new_q->end->next = new_node;
		new_q->end = new_node;
	}

	else
	{
		new_q->begin = new_q->end = new_node;
	}
}

int dequeue(queue *new_q)
{
	new_q->size--;

	if (is_empty(new_q))
	{
		printf("Fila vazia\n");
		return -1;
	}

	else if (new_q->begin == new_q->end)
	{
		node *new_node = new_q->begin;
		int item = new_node->value;
		new_q->begin = new_q->end = NULL;
		return item;
	}

	else 
	{
		node *new_node = new_q->begin;
		int item = new_node->value;
		new_q->begin = new_q->begin->next;
		return item;
	}
}

void enqueue_priority(queue *new_q, int value)
{
	node *new_node = create_node(value);

	if(new_q->begin == NULL)
	{
		printf("aqui\n");
		new_q->begin = new_q->end = new_node;
	}

	else 
	{
		node *temp = new_q->begin;
		node *prev;
		while(temp != NULL && temp->value >= value)
		{ 
			temp = temp->next;
		}

		if(temp == NULL)
		{
			new_q->end->next = new_node;
			new_node->previous = new_q->end;
			new_q->end = new_node;
		}

		else if(temp->previous == NULL)
		{
			new_q->begin->previous = new_node;
			new_node->next = new_q->begin;
			new_q->begin = new_node;
		}

		else 
		{
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
	queue *new_queue = create_queue();

	enqueue(new_queue, 6);
	enqueue(new_queue, 7);
	enqueue(new_queue, 9);
	enqueue(new_queue, 8);
	enqueue(new_queue, 4);
	enqueue_priority(new_queue, 9);
	enqueue_priority(new_queue, 8);
	//printf("size: %d\n", new_queue->size);
	// printf("remove %d\n", dequeue(new_queue));
	// printf("remove %d\n", dequeue(new_queue));
	// printf("remove %d\n", dequeue(new_queue));
	//printf("elemento que ficou:\n");
	printar(new_queue);
	//printf("size: %d\n", new_queue->size);
}
