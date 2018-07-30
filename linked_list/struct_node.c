#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;          // value que a lista ira guardar
    struct node *proximo; // lista que ele aponta 
};

int main()
{
    struct node *first_node = (struct node*) malloc(sizeof(struct node));
    // podemos colocar uma condição para o second_node
    struct node *second_node = (struct node*) malloc(sizeof(struct node));
    /*casting -> coloca o tipo de dado que o ponteiro vai receber, converta o 
    tamanho que eu preciso na struct node formato de ponteiros de node e coloque
    dentro do ponteiro -> first_node*/
    
    first_node -> value = 3; // para acessar um membro de uma struct, utilizar operador ->
    second_node -> value = 7;

    /*como indicar que o second_ node vem depois do first_ node*//*mediante o ponteiro *proximo*/

    first_node -> proximo = second_node;
    /*o proximo elemento do first_node é o second_node*/

    printf("%d\n", first_node -> value);
    printf("%d\n", first_node -> proximo -> value);

    system("pause");

    return 0;
}