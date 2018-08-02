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

node* search(node *head, int value) //procurar algum elemento na lista
{
    while (head != NULL)
    {
        if (head -> value == value)
        {
            return head;
        }

        head = head -> next;
    }

    return NULL;
}

node *order_insert(node *head, int item) // inserir ordenadamente
{
    node *previous = NULL;
    node *current = head;
    node *new_node = create_node(item);

    if (head == NULL) // verifica se a lista nao tem nodes
    {
        return new_node;
    }

    if (head -> value >= item) // verifica se tem so um unico node na lista
    {
        new_node -> next = head;

        return new_node;
    }

    while (current != NULL && current -> value <= item) // 
    {
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

node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
} 

node *ler(node *head, int size)
{
    int i;
    for (i = 0; i < size; i += 1)
    {    
     int value;
     scanf("%d", &value);
     head = order_insert(head, value);
    }
    return head;
}

int compare(node *head_1, node *head_2, int cont)
{
    node *aux = head_1;
    if (head_2 == NULL)
    {
        return cont;
    }
    
    while (aux -> value <= head_2 -> value)
    {
        if (aux -> value == head_2 -> value)
        {
            cont += 1;
        }
        
        if (aux -> next == NULL)
        {
            return cont;
        }
        
        aux = aux -> next;
    }
    
    compare(head_1 = head_1 -> next, head_2 = head_2 -> next, cont);
}

int main()
{
    node *head_1 = linked_list_node();
    node *head_2 = linked_list_node();

    int size;
    scanf("%d", &size);
    head_1 = ler(head_1, size);
    scanf("%d", &size);
    head_2 = ler(head_2, size);
    // print(head_1);
    // printf("\n");
    // print(head_2);
    // printf("\n");
    
    int res = compare(head_1, head_2, 0);
    
    if (res >= size) // maior ou igual para caso tenham numero repetidos
    {
        printf("1"); // size_1 -> 8 // 1 1 2 3 4 5 6 7 // size_2 -> 5 // 1 3 4 5 7
    }
    
    else
    {
        printf("0");
    }
    
    return 0;
}
