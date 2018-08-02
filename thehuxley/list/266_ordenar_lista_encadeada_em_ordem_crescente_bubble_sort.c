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

node *insert_begin(node *head, int item) // inserir no começo da lista
{
    node *new_node = create_node(item); 
    new_node -> value = item;
    new_node -> next = head; 
    return new_node;
}

void bubble_sort(node *head)
{
    node *current = head -> next;
    
    if (head -> next == NULL)
    {
        return;
    }
    
    while(current != NULL)
    {
        if (head -> value > current -> value)
        {
            int aux = head -> value;
            head -> value = current -> value;
            current -> value = aux;
        }
        
        current = current -> next;    
    }

    bubble_sort(head -> next);
}

node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
} 

int main()
{
    node *head = linked_list_node();
    int item;
    while (scanf("%d", &item) != EOF)  
    {
         head = insert_begin(head, item);   
    }

    bubble_sort(head);

    print(head);

    return 0;
}