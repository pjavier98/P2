#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_  // definir lista
{
    Node *front;
    Node *back;
    int size;
} linked_list;

typedef struct node // definir node
{
    int value;
    struct node *next;
} node;

linkedlist* create_linked_list() // criar nova lista
{
    linkedlist* list = (linkedlist*) malloc(sizeof(linkedlist));
    list->size = 0;
    list->front = NULL;
    list->back = NULL;
    return list;
}

node *create_node(int item) // criar node
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> value = item;
    new_node -> next = NULL;
    return new_node;
}

void print(node *head) // printar a lista
{
    while (head != NULL)
    {
        printf("%d\n", head -> value);
        
        head = head -> next;
    }   
}

node* erase(node *head, int item)
{
    node *previous = NULL;      // anterior
    node *current = head;       // atual

    while (current != NULL && current -> value != item)
    {
        previous = current;
        current = current -> next;
    }

    if (current == NULL)
    {
        return head;
    }

    if (previous == NULL)
    {
        head = current -> next;
    }

    else
    {
        previous -> next = current -> next;
    }

    free(current);
    return head;
}

node* search(node *head, int value)
{
    while (head != NULL)
    {
        if (head -> value == value)
        {
            return head;
        }

        head = head -> next;
    }

    return NULL;
}

node* insert_end(node *head, int item) 
{
    node *new_node = create_node(item); 
    new_node -> value = item;
    new_node -> next = NULL;

    if (head != NULL)
    {
        while (head -> next != NULL)
        {
            head = head -> next;
        }

        head -> next = new_node;

        return head;
    }
    else
    {
        return new_node;
    }

}

node *insert_begin(node *head, int item)
{
    node *new_node = create_node(item); 
    new_node -> value = item;
    new_node -> next = head; 
    return new_node;
}

node *linked_list()
{
    return NULL;
} 

int is_empty(node *head)
{
    return (head == NULL);
}

int main()
{
    //node *head = linked_list();

    //head = insert_begin(head, 100);

    //head = insert_end(head, 55);
    
    //head = erase(head, 7);

    //head = search(head, 55);

    //is_empty(node *head);
    
    //print(head);

    return 0;
}

