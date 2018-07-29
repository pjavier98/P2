#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *proximo;
};

void listar (struct node *aux)
{
    while (aux != NULL)
    {
        printf("%d\n", aux -> valor);
    
        aux = aux -> proximo;
    }   
}

int main()
{
    struct node *primeiro_node = (struct node*) malloc(sizeof(struct node));
    struct node *segundo_node = (struct node*) malloc(sizeof(struct node));
    struct node *terceiro_node = (struct node*) malloc(sizeof(struct node));
    struct node *quarto_node = (struct node*) malloc(sizeof(struct node));

    primeiro_node -> valor = 3;
    primeiro_node -> proximo = segundo_node;

    segundo_node -> valor = 5;
    segundo_node -> proximo = terceiro_node;

    terceiro_node -> valor = 7;
    terceiro_node -> proximo = quarto_node;

    quarto_node -> valor = 9;
    quarto_node -> proximo = NULL;

    listar(primeiro_node); // funcao ou na main
    
    // lista encadeada com 4 elementos 

    /*struct node *aux = primeiro_node; // tem o mesmo endereço, apontam para o mesmo lugar
    
    while (aux != NULL) // condição de parada
    {
        printf("%d\n", aux -> valor);
    
        aux = aux -> proximo; // o auxiliar vai passar a apontar com o endereço de memória do ponteiro proximo
        // aux passa a apontar para o proximo de aux   
    }*/   

    return 0;
}