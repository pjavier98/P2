#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void print(node *head)
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
    node *current = head; // atual

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

node* insert_end(node *head, int x) 
{
    node *head = head;
    node *new_node = (node*) malloc(sizeof(node)); 

    new_node -> value = x;
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

node* insert_begin(node *head, int x)
{
    node *new_node = (node*) malloc(sizeof(node)); 

    new_node -> value = x;
    new_node -> next = head; 
    return new_node;
}

int isempty()
{
    return (head == NULL);
}

int main()
{
    node *head = isempty;

    head = insert_begin(head, 100);

    head = insert_end(head, 55);

    head = insert_end(head, 7);

    head = erase(head, 7);
    
    print(head);

    return 0;
}

