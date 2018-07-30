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

struct node* insert_left(struct node *list, int x)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node)); // new_node -> novo inicio da lista

    new_node -> value = x;
    new_node -> proximo = list; // o proximo vai ser a propria lista

    return new_node;
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

    first_node = insert_left(first_node, 100); // atualizar o primeiro node, ja que ele ja possui um valor
    first_node = insert_left(first_node, 107); // coloque o valor antes do valor da funcao acima
    
    list(first_node); // funcao ou na main

    return 0;
}