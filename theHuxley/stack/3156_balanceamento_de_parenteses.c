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
    return '@';
}

void comp(stack *stack, int size, char line[size], int i)
{
    if (i == size)
    {
        int x = is_empty(stack);
        //printf("%d\n", x);
        if (x == 1)
        {   
            printf("Yes\n");
        }

        else
        {
            printf("No\n");
        }

        return;
    }
    
    if (line[i] == '(' || line[i] == '[')
    {
        //printf("deu push\n");
        push(stack, line[i]);
    }
    
    //printf("%c\n", peek(stack));
    
    else if (peek(stack) == '(' && line[i] == ')' || peek(stack) == '[' && line[i] == ']')
    {
        pop(stack);
    }
    
    else if (is_empty(stack) && line[i] == ')' || is_empty(stack) && line[i] == ']')
    {
        printf("No\n");
        return;
    }
    
    comp(stack, size, line, i + 1);
}

int main()
{
    stack *new_stack = create_stack(); // declara??o da stack
    int quant;
    char line[100];

    scanf("%d", &quant);
    getchar();

    while (quant != 0)
    {
        gets(line);
        int size = strlen(line);
        comp(new_stack, size, line, 0);
        while(new_stack->top != NULL)
        {
            pop(new_stack);
        }
        quant--;
    }  

    return 0; 
}