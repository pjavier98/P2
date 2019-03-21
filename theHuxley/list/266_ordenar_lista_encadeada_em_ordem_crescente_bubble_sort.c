#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node // definir node
{
    int value;
    node *next;
};

node *create_node(int item) // criar node
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> value = item;
    new_node -> next = NULL;
    return new_node;
}

void print(node *head) // printar a lista
{
    if (head != NULL)
    {
        printf("%d ", head -> value);
        print(head -> next);
    }   
}

node* insert_end(node *head, int item) // inserir no final da lista
{
    node *new_node = create_node(item); 
    node *aux = head; // para nao perder a referencia do ponteiro
    
    if (head != NULL)
    {
        while (head -> next != NULL)
        {
            head = head -> next;
        }

        head -> next = new_node;

        return aux;
    }

    else
    {
        return new_node;
    }
}

int maximum(node *head, int size)
{
    int max = 0;
    int pos = 0;
    int i;
    for(i = 0; i < size; i++){
        if(head->value > max){
            max = head->value;
            pos = i;
        }
        head = head->next;
    }
    return pos;
}

node *sort(node *head, int max, int size)
{
    int i;
    node *previous = NULL;
    node *current = head;
    node *temp = head;
    node *coming = head->next;
    //printf("%d size(%d)\n", max, size);
    for (i = 0; i < max; i += 1)
    {
        //printf("entrou\n");
        previous = current;
        current = previous->next;
        temp = previous->next;
        coming = current->next; 
        //printf("%d\n", previous->value);
    }

    //printf("prev - %d  current - %d coming - %d\n", previous->value, current->value, coming->value);

    while (max < size - 1)
    {
        //print(head);
        //printf("\n");
        if (previous == NULL)
        {
            //printf("aqui\n");
            current->next = coming->next;
            coming->next = temp;
            head = coming;
            previous = head;
            current = previous->next;
            coming = current -> next;
        }

        else
        {
            //printf("aqui_1\n");
            previous->next = coming;
            current->next = coming->next;
            coming->next = temp;

            previous = previous->next;
            current = previous->next;
            coming = current->next;
        }
        max++;
    }
    return head;
}

node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
} 

int main()
{
    node *head = linked_list_node();
    node *temp;
    int item = 0;
    int size = 0;
    int max = 0;
    int i = 0;
    
    while (scanf("%d", &item) != EOF)  
    {
        head = insert_end(head, item);
        size += 1;   
    }

    while (size != 1)
    {
        temp = head;
        max = maximum(temp, size);
        //printf("%d\n", max);
        head = sort(head, max, size);
        size--;
    }

    print(head);
    printf("\n");

    return 0;
}