#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void print(struct node *head) // head == aux, uma outra variavel
{
    while (head != NULL)
    {
        printf("%d\n", head -> value);
    
        head = head -> next;
    }   
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

    print(head); // funcao ou na main
    
    // lista encadeada com 4 elementos 

    /*struct node *head = head; // tem o mesmo endereço, apontam para o mesmo lugar
    
    while (head != NULL) // condição de parada
    {
        printf("%d\n", head -> value);
    
        head = head -> next; // o headiliar vai passar a apontar com o endereço de memória do ponteiro next
        // head passa a apontar para o next de head   
    }*/   

    return 0;
}