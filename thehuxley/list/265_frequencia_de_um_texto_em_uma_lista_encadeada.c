#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node // definir node
{
    char value;
    struct node *next;
    struct node *cont;
} node;

node *create_node(char letra, int quant) // criar node
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> value = letra;
    new_node -> next = NULL;
    new_node -> cont = quant;
    return new_node;
}

void print(node *head) // printar a lista
{
    if (head != NULL)
    {
        printf("%c %d\n", head -> value, head -> cont);

        print(head -> next);
    }   
}


node *insert_begin(node *head, char letra, int cont) // inserir no começo da lista
{
    node *new_node = create_node(letra, cont); 
    new_node -> next = head;
    return new_node;
}

node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
} 

void merge(char *array, int begin_1, int end_1, int begin_2, int end_2, char *aux)
{
    int temp = 0;
    int left = begin_1;
    int right = end_2;

    while(begin_1 <= end_1 || begin_2 <= end_2)
    {
        if(begin_1 > end_1)
        {
            while(begin_2 <= end_2) // lista 1 acabou
            {
                aux[temp] = array[begin_2];
                temp += 1;
                begin_2 += 1;
            }
        }
        else if(begin_2 > end_2) // lista 2 acabou
        {
            while(begin_1 <= end_1)
            {
                aux[temp] = array[begin_1];
                temp += 1;
                begin_1 += 1;
            }
        }

        else // as listas nao acabaram
        {
            if(array[begin_1] < array[begin_2])
            {
                aux[temp] = array[begin_1];
                temp += 1;
                begin_1 += 1;
            }

            else 
            {
                aux[temp] = array[begin_2];
                temp += 1;
                begin_2 += 1;
            } 
        }
    }

    temp = 0;
    int i;
    for(i = left; i <= right; i += 1, temp += 1) 
    {
        array[i] = aux[temp];
        // i += 1
        // temp += 1
    }
}

void merge_sort(char *array, int begin, int end, char *aux)
{
    if (begin == end)
    {
        return;
    }

    int mid = (begin + end) / 2;

    merge_sort(array, begin, mid, aux); 
    merge_sort(array, mid + 1, end, aux); 
    merge(array, begin, mid, mid + 1, end, aux);
}

int main()
{
    char text[1000];
    
    scanf("%[^\n]", text);
    
    int size = strlen(text);
    char *aux = malloc(size * sizeof(char));
    merge_sort(text, 0, size - 1, aux);
    
    //printf("%s", text);
    //printf("\n");

    node *head = linked_list_node();

    int i, cont = 1;
    for (i = 0; i < size; i += 1)
    {
        if (text[i] != text[i + 1])
        {
            head = insert_begin(head, text[i], cont);
            cont = 0;
        }

        cont += 1;
    }

    print(head);
    
    return 0;
}
