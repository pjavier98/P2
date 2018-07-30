#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *proximo;
};

void list(struct node *aux)
{
    while (aux != NULL)
    {
        printf("%d\n", aux -> value);
    
        aux = aux -> proximo;
    }   
}

void insert_right(struct node *list, int x) // list -> pode ser qualquer nome (list -> primeiro node da lista)
{
   struct node *new_node = (struct node*) malloc(sizeof(struct node)); // new_node -> novo final da lista

   new_node -> value = x;
   new_node -> proximo = NULL;

   while (list -> proximo != NULL)
   {
        list = list -> proximo;
   }

   list -> proximo = new_node;
}

int main()
{
    struct node *first_node = (struct node*) malloc(sizeof(struct node));
    struct node *second_node = (struct node*) malloc(sizeof(struct node));
    struct node *third_node = (struct node*) malloc(sizeof(struct node));
    struct node *fourth_node = (struct node*) malloc(sizeof(struct node));

    first_node -> value = 3;
    first_node -> proximo = second_node;

    second_node -> value = 5;
    second_node -> proximo = third_node;

    third_node -> value = 7;
    third_node -> proximo = fourth_node;

    fourth_node -> value = 9;
    fourth_node -> proximo = NULL;

    insert_right(first_node, 55); // vao ser os novos finais da lista
    insert_right(first_node, 99);

    list(first_node);
    
    return 0;
}