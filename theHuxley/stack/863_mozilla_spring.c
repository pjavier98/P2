#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
typedef struct stack stack;

struct node
{
    char value;
    node *next;
};

struct stack
{   
    node *top;
    int size;
};

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
    new_stack->top = NULL;
    return new_stack;
}

int is_empty(stack *stack)
{
    return (stack->top == NULL);
}

void push(stack *stack, char item)   //add an element
{
    node *new_top = create_node(item);
    stack->size += 1;
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

void pop(stack *stack) //remove an element
{
    if (!is_empty(stack)) 
    {
        stack->size -=  1;
        node *new_node = stack->top;
        stack->top = stack->top->next;
        new_node -> next = NULL;
        free(new_node);
    }
}   

void peek(stack *stack) //print an element
{
    if (!is_empty(stack))
    {
        printf("%c", stack->top->value);
        return;
    }
}

int main()
{
    stack *stack_enter = create_stack(); // declara??o da stack
    stack *stack_back = create_stack(); // declara??o da stack
    stack *stack_forward = create_stack(); // declara??o da stack
    char action[10];
    int i = 0, j = 0, h = 0;
    while (scanf("%s", action) != EOF)
    {

        if (strcmp(action, "ENTER") == 0) // ENTER -> E
        {
            if (i == 1)
            {
                push(stack_enter, 'E');
                push(stack_back, 'B');
                
            }
            pop(stack_forward); 
            i = 1;
        }
        
        else if (strcmp(action, "BACK") == 0) // BACK -> B
        {
            push(stack_forward, 'F');
            pop(stack_back);
        }
        
        else if (strcmp(action, "FORWARD") == 0) // FORWARD -> F
        {
            if (i == 1)
            {
                push(stack_back, 'B'); 
            }
            pop(stack_forward);
            i = 1;
        }
        // printf("%s\n", action);
    }
    //peek(stack_back);

    printf("BACK: %d\nFORWARD: %d\n", stack_back->size, stack_forward->size);

    return 0; 
}