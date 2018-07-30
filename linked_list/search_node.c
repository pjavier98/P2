#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *proximo;
};

int search(struct node *first_node, int value)
{
    while (first_node != NULL)
    {
        if (first_node -> value == value)
        {
            return value;
        }

        first_node = first_node -> proximo;
    }

    return -1;
}

struct node* insert_right(struct node *list, int x) 
{
    struct node *first_node = list;
    struct node *new_node = (struct node*) malloc(sizeof(struct node)); 

    new_node -> value = x;
    new_node -> proximo = NULL;

    if (list != NULL)
    {
        while (list -> proximo != NULL)
        {
            list = list -> proximo;
        }

        list -> proximo = new_node;

        return first_node;
    }
    else
    {
        return new_node;
    }

}

struct node* insert_left(struct node *list, int x)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node)); 

    new_node -> value = x;
    new_node -> proximo = list; 
    return new_node;
}

int main()
{
    struct node *first_node = NULL;

    first_node = insert_left(first_node, 100);

    first_node = insert_right(first_node, 55);
    
    int item = search(first_node, 7);

    printf("%d\n", item);

    return 0;
}