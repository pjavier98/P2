#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head -> value);
    
        head = head -> next;
    }   
}

void insert_end(struct node *head, int x) // head -> pode ser qualquer nome (head -> primeiro node da lista)
{
   struct node *new_node = (struct node*) malloc(sizeof(struct node)); // new_node -> novo final da lista

   new_node -> value = x;
   new_node -> next = NULL;

   while (head -> next != NULL)
   {
        head = head -> next;
   }

   head -> next = new_node;
}

int main()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *first_node = (struct node*) malloc(sizeof(struct node));
    struct node *second_node = (struct node*) malloc(sizeof(struct node));
    struct node *third_node = (struct node*) malloc(sizeof(struct node));

    head -> value = 3;
    head -> next = first_node;

    first_node -> value = 5;
    first_node -> next = second_node;

    second_node -> value = 7;
    second_node -> next = third_node;

    third_node -> value = 9;
    third_node -> next = NULL;

    insert_end(head, 55); // vao ser os novos finais da lista
    insert_end(head, 99);

    print(head);
    
    return 0;
}