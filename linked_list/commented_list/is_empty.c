#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

int is_empty(node *head)
{
	return (head == NULL);
}

int main()
{
	is_empty(node *head); // colocar condição
}