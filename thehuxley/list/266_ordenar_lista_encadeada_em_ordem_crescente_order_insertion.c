#include <stdio.h>
#include <stdlib.h>

typedef struct node // definir node
{
    int value;
    struct node *next;
} node;

node *create_node(int item) // criar node
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> value = item;
    new_node -> next = NULL;
    return new_node;
}

void print(node *head) // printar a lista
{
    if (head != NULL)
    {
        printf("%d ", head -> value);

        print(head -> next);
    }   
}

node *order_insert(node *head, int item) // inserir ordenadamente
{
    node *previous = NULL;
    node *current = head;
    node *new_node = create_node(item);

    if (head == NULL) // verifica se a lista nao tem nodes
    {
        return new_node;
    }

    if (head -> value >= item) // verifica se tem so um unico node na lista
    {
        new_node -> next = head;

        return new_node;
    }

    while (current != NULL && current -> value <= item) // 
    {
        previous = current;
        current = current -> next;
    }
    
    if (previous -> next == NULL) // verifica ate o ultimo item
    {
        previous -> next = new_node;
        new_node -> next = NULL;
    }

    else 
    {
        previous -> next = new_node; // os ponteiros apontarem ate o new_node

        new_node -> next = current;
    }

    return head;
}

node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
} 

int main()
{
    node *head = linked_list_node();
    int value;
    while (scanf("%d", &value) != EOF)  
    {
        head = order_insert(head, value);
    }

    print(head);

    return 0;
}