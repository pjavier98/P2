#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;          // valor que a lista ira guardar
    struct node *proximo; // lista que ele aponta 
};

int main()
{
    struct node *primeiro_node = (struct node*) malloc(sizeof(struct node));
    // podemos colocar uma condição para o segundo_node
    struct node *segundo_node = (struct node*) malloc(sizeof(struct node));
    /*casting -> coloca o tipo de dado que o ponteiro vai receber, converta o 
    tamanho que eu preciso na struct node formato de ponteiros de node e coloque
    dentro do ponteiro -> primeiro_node*/
    
    primeiro_node -> valor = 3; // para acessar um membro de uma struct, utilizar operador ->
    segundo_node -> valor = 7;

    /*como indicar que o segundo_ node vem depois do primeiro_ node*//*mediante o ponteiro *proximo*/

    primeiro_node -> proximo = segundo_node;
    /*o proximo elemento do primeiro_node é o segundo_node*/

    printf("%d\n", primeiro_node->valor);
    printf("%d\n", primeiro_node->proximo->valor);

    system("pause");

    return 0;
}