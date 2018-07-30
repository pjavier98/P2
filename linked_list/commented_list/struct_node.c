#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;          // value que a lista ira guardar
    struct node *next; // lista que ele aponta 
};

int main()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    // podemos colocar uma condição para o first_node
    struct node *first_node = (struct node*) malloc(sizeof(struct node));
    /*casting -> coloca o tipo de dado que o ponteiro vai receber, converta o 
    tamanho que eu preciso na struct node formato de ponteiros de node e coloque
    dentro do ponteiro -> head*/
    
    head -> value = 3; // para acessar um membro de uma struct, utilizar operador ->
    first_node -> value = 7;

    /*como indicar que o second_ node vem depois do first_ node*//*mediante o ponteiro *next*/

    head -> next = first_node;
    /*o next elemento do head é o first_node*/

    printf("%d\n", head -> value);
    printf("%d\n", head -> next -> value);

    return 0;
}