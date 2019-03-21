#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

typedef struct node // definir node
{
    int value;
    node *next;
};

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

node* insert_end(node *head, int item) // inserir no final da lista
{
    node *new_node = create_node(item); 
    node *aux = head; // para nao perder a referencia do ponteiro
    
    if (head != NULL)
    {
        while (head -> next != NULL)
        {
            head = head -> next;
        }

        head -> next = new_node;

        return aux;
    }

    else
    {
        return new_node;
    }

}

node *reverse(node *head)
{
    node *current = head;
    node *coming = head -> next;

    node *temp = head -> next; // preserva o ponteiro para caminhar dentro do encadeamento
    
    while(coming != NULL)
    {
        temp = temp -> next;

        coming -> next = current;

        current = coming;

        coming = temp;
    }

    head -> next = NULL;

    head = current;

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
        head = insert_end(head, value);
    }

    head = reverse(head);

    print(head);

    return 0;
}
