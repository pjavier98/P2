#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
typedef struct stack stack;
typedef struct node_stack node_stack;

struct node
{
    int value;
    node *next;
};

struct node_stack
{
    node *head;
    node_stack *down;    
};

struct stack // a stack tem um ponteiro para node_stack que permite apontar para head e para down
{   
    node_stack *top; 
};

node *create_node(int item) 
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = item;
    new_node->next = NULL;
    return new_node;
}

node_stack *create_node_stack()
{
    node_stack *new_node_stack = (node_stack*) malloc(sizeof(node_stack));
    new_node_stack->head = NULL;
    new_node_stack->down = NULL;
    return new_node_stack;
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

void print(node *head, int i) // printa a lista
{
    if (head == NULL) // enquanto a lista nao acabar ele printa
    {
        printf("\n");
        return;
    }
    
    if (i == 0)
    {
        printf("%d", head->value);    
    }
    
    else
    {
        printf(" %d", head->value);    
    }
    i = 1;
    print(head->next, i); // recursao para incrementar o head
}

node *insert_end(node *head, int item) // insere no final
{
    node *new_node = create_node(item); // cria o node
    node *aux = head; // faz o aux apontar para head tambem para nao perder o ponteiro da cabeça

    if (head == NULL) // quando a lista nao tiver nenhum valor
    {
        return new_node;
    }

    while (aux->next != NULL) // quando ele nao for o final ele vai mudando pro proximo
    {
        aux=aux->next;
    }

    aux->next = new_node;
    return head;    
}

void push(stack *stack, node *head)   //add an element
{   
    node_stack *new_node_stack = create_node_stack();
    new_node_stack->head = head;
    if(is_empty(stack)) 
    {
      stack->top = new_node_stack;
      return;
    }
    new_node_stack->down = stack->top;
    stack->top = new_node_stack;
    //print(stack->top->head);
}

void pop(stack *stack) //remove an element
{
    if (!is_empty(stack)) 
    {
        node *new_s = stack->top->head;
        //print(stack->top->head);
        print(new_s, 0);
        stack->top = stack->top->down;
        free(new_s);
        return;
    }
    
    printf("EMPTY STACK\n");
    return;
}

int main()
{
    stack *new_stack = create_stack(); // declaração da stack
    
    char action[10];
    char letter;
    int number;

    while (scanf("%s", action) != EOF)
    {
        
        if (strcmp(action, "PUSH") == 0)
        {
            node *head = NULL;
            //printf("aqui 1\n");
            while (1)
            {
                scanf("%d%c", &number, &letter);
                head = insert_end(head, number);
                if (letter == '\n')
                {
                    //print(head);
                    break;
                }
            }
            push(new_stack, head);
        }

        if (strcmp(action, "POP") == 0)
        {
            //printf("aqui\n");
            pop(new_stack);
        }
    }

    return 0; 
}
