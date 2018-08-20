#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char value;
    struct node *next;
}node;

typedef struct stack
{   
    node *top;
}stack;

node *create_node(char letra) // criar node
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> value = letra;
    new_node -> next = NULL;
    return new_node;
}

stack *create_stack()
{
    stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack -> top = NULL;
    return new_stack;
}

int is_empty(stack *stack)
{
    return (stack->top == NULL);
}

void push(stack *stack, char item)   //add an element
{
    node *new_top = create_node(item);
    
    if (!is_empty(stack))
    {
        new_top->next = stack->top;
        stack->top = new_top;
    }

    else
    {
        stack->top = new_top;
    }
}

int pop(stack *stack) //remove an element
{
    if (!is_empty(stack)) 
    {
        node *new_node = stack->top;
        stack -> top = stack->top->next;
        new_node -> next = NULL;
        free(new_node);
        return 1;
    }
    return 0;
}   

char peek(stack *stack) //print an element
{
    if (!is_empty(stack))
    {
        return stack->top->value;
    }
    // return '@';
}


int main()
{
	stack *new_stack = create_stack(); // declaração da stack
  	//chamar as funcoes
	return 0; 
}
