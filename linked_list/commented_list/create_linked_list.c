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

node *linked_list()
{
    return NULL;
} 

int main()
{
    node* head = linked_list()

    print(head);

    return 0;
}

