#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
typedef struct hash hash;
typedef struct node node;

struct node
{
    int value;
    node *next;
    node *prev;
};

struct hash
{
    node *table[200];
    int qtd;
};

hash *create_hash(int size)
{
    hash *new_hash = (hash*) malloc(sizeof(hash));
    int i;

    for (i = 0; i < size; i += 1)
    {
        new_hash->table[i] = NULL;
    }

    return new_hash;
}

node *create_node(int item) // criar node
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> value = item;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
}

void print_hash(hash *new_hash, int size, int i, int j)
{
    if (size == i)
    {
        return;
    }

    node *aux = new_hash->table[i];

    while (aux != NULL)
    {
        if (j == 0)
        {
            printf("%d -> %d", i, aux->value);
        }

        else
        {
            printf(" -> %d", aux->value);
        }

        j = 1;
        aux = aux->next;
    }

    if (aux == NULL && j == 1)
    {
        printf(" -> \\\n");

    }

    else
    {
        printf("%d -> \\\n", i);
    }
    
    print_hash(new_hash, size, i + 1, 0);
}

node* insert_end(node *head, int item) // inserir no final da lista
{
    node *new_node = create_node(item); 
    node *aux = head; // para nao perder a referencia do ponteiro
    
    if (aux != NULL)
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = new_node;
        new_node->prev = aux;

        return head;
    }

    else
    {
        return new_node;
    }
}

void erase_hash(hash *new_hash, int size)
{
    int i = 0;
    hash *remove_hash = new_hash->table[size];
    while (i < size)
    {
        if (new_hash->table[i] != NULL)
        {
            node *aux = new_hash->table[i];

            while (aux->next != NULL) // vai ate o ultimo numero da lista
            {
                aux = aux->next;               
            }

            while (aux->prev != NULL) // vai ate o comeco da lista
            {
                node *temp = aux;
                aux = aux->prev;
                free(temp);
            }
        }
        i += 1;
    }

    free(remove_hash);
}

int dispersal_function(int key, int item)
{   
    return item % key;
}

void put(hash *new_hash, int key_hash, int item, int size)
{
    if (new_hash == NULL || new_hash->qtd == size)
    {
        return;
    }

    int key = dispersal_function(key_hash, item);

    if (new_hash->table[key] == NULL)
    {
        node *head = NULL;
        head = insert_end(head, item);
        new_hash->table[key] = head;
        new_hash->qtd++;
    }

    else
    {
        node *aux = new_hash->table[key];
        aux = insert_end(aux, item);
        new_hash->qtd++;
    }  
}

int main()
{
    int quant, i, j;
    scanf("%d", &quant);
    //printf("%d\n", quant);

    for (i = 0; i < quant; i += 1)
    {
        int keys, size;
        scanf("%d %d", &keys, &size);
        //printf("%d %d\n", keys, size);
        hash *new_hash = create_hash(size);

        for (j = 0; j < size; j += 1)
        {
            int element;
            scanf("%d", &element);
            //printf("%d\n", element);
            put(new_hash, keys, element, size);
        }

        print_hash(new_hash, keys, 0, 0);
        erase_hash(new_hash, keys);
        printf("\n");
    }

    return 0;
}
