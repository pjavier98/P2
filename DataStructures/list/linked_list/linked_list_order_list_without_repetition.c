#include <stdio.h>
#include <stdlib.h>

typedef struct node // definir node
{
    int value;
    struct node *next;
} node;

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

node *order_insert_without_repetition(node *head, int item) // inserir ordenadamente
{
    node *new_node = create_node(item);
    node *previous = NULL;
    node *current = head;

    if (head == NULL) // verifica se a lista nao tem nodes
    {
        return new_node;
    }
    
    if (head -> value > item && head -> next == NULL) // verifica se tem so um unico node na lista
    {
        new_node -> next = head;
        return new_node;
    }

    if (head -> value > item) // 5 6 12 4 
    {
        new_node -> next = head;
        return new_node;
    }

    while (current != NULL && current -> value <= item)
    {
      if (current -> value == item) // seria para nao repetir os numeros esta parte que fiz???
        {
            return head;
        }
      
        previous = current;
        current = current -> next;
    }
  
    if (previous -> next == NULL) // verifica ate o ultimo item
    {
        previous -> next = new_node;
        new_node -> next = NULL;
    }

    else 
    {
        previous -> next = new_node; // os ponteiros apontarem ate o new_node

        new_node -> next = current;
    }
   
    return head;
}

void compare(node *head_1, node *head_2, int *cont)
{
    node *aux = head_1;
    
    if (head_2 == NULL)
    {
        return;
    }
    
    while (aux -> value <= head_2 -> value)
    {
        if (aux -> value == head_2 -> value)
        {
            printf("%d\n", aux -> value);
            *cont += 1;
        }
        
        if (aux -> next == NULL)
        {
            return;
        }
        
        aux = aux -> next;
    }
    
    compare(head_1 = head_1 -> next, head_2 = head_2 -> next, cont);
}

node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
}

node *ler(node *head)
{
    int item, i;

    for (i = 0; i < 20; i += 1)
    {   
        scanf("%d", &item);
        head = order_insert_without_repetition(head, item);  
    }
    
    return head;
}

int main()
{   
    node *head_1 = linked_list_node();
    
    head_1 = ler(head_1);
    
    // print(head_1);
    // printf("\n");
    // print(head_2);
    // printf("\n");

    int cont = 0;

    //compare(head_1, head_2, &cont);

    if (cont == 0)
    {
        printf("VAZIO");    
    }

    return 0;
}
