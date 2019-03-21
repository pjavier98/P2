#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("%c ", head -> value);

        print(head -> next);
    }   
}

node* insert_end(node *head, char item) // inserir no final da lista
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


node *linked_list_node() // cria lista atraves de nodes
{
    return NULL;
} 

void compare(node *head, int i, int j, int begin, int end, int flag)
{
    int inicio = 0;
    int final = 0;
    
    if (head == NULL)
    {
        printf("%d %d\n", begin, end);
        return;
    }
    
    while (head -> value == '0')
    {
        inicio = i;
        final = j;
        j += 1;
        head = head -> next;
        
        if (head == NULL)
        {
            if (end - begin < final - inicio)
            {
                end = final;
                begin = inicio;
            }
            printf("%d %d\n", begin, end);
            return;
        }
    }
    
    i = j;
    
    if (end - begin < final - inicio)
    {
        end = final;
        begin = inicio;
    }
    
    compare(head -> next, i + 1, i + 1, begin, end, flag);
}

node *ler()
{
    node *head = linked_list_node();
    int i;
    char line[100];
    scanf("%[^\n]", line);
    getchar();
    int size = strlen(line);
    
    if (line[0] == '0' &&  size == 1)
    {
        return head;
    }

    for (i = 0; i < size; i += 1)
    {
        head = insert_end(head, line[i]);
    }
    
    compare(head, 0, 0, 0, 0, 0);

    ler();
}

int main()
{
    ler();

    return 0;
}
