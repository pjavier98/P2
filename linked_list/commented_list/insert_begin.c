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

struct node* insert_begin(struct node *head, int x)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node)); // new_node -> novo inicio da lista

    new_node -> value = x;
    new_node -> next = head; // o next vai ser a propria lista

    return new_node;
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

    head = insert_begin(head, 100); // atualizar o primeiro node, ja que ele ja possui um valor
    head = insert_begin(head, 107); // coloque o valor antes do valor da funcao acima
    
    print(head); // funcao ou na main

    return 0;
}