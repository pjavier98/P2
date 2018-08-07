#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	node *next;
}node;

typedef struct stack
{	
	node *top;
}stack;

stack *create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack -> top = NULL;
	return new_stack;
}

int is_empty(stack *stack)
{
	return (head == NULL);
}

void push(stack *stack, int item)	//add an element
{
	node *new_top = (node*) malloc(sizeof(node));
	new_top -> value = item;
	new_top -> next = stack -> top;
	stack -> top = new_top;
}

node *pop(stack *stack)	//remove an element
{
	if (!is_empty(stack)) 
	{
		node *new_node = stack -> top;
		stack -> top = stack -> top -> next;
		new_node -> next = NULL;
		return new_node;
	}
}	

void peek(stack *stack)	//print an element
{
	if (!is_empty(stack))
	{
		return stack -> top -> value;
	}
}

int main()
{
	stack *new_stack = create_stack(); // declaração da stack
  //chamar as funcoes
	return 0; 
}
