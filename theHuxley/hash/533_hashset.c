#include <stdio.h>
#include <string.h>
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
    node **table; // ponteiro duplo para a o tamanho ser alocado dinamicamente
    int qtd;
};

hash *create_hash(int size)
{
    hash *new_hash = (hash*) malloc(sizeof(hash));
    new_hash->table = (node*) malloc(size * sizeof(node)); // ponteiro duplo
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

int dispersal_div(int item, int key)
{
    return item % key;
}

node *insert_begin(node *head, int item) // inserir no começo da lista
{
    node *new_node = create_node(item);

    if (head == NULL)
    {
        return new_node;
    }

    new_node -> next = head;
    head->prev = new_node;
    return new_node;
}

void print_hash(hash *new_hash, int size, int i)
{
    if (size == i)
    {
        return;
    }

    node *aux = new_hash->table[i];

    while (aux != NULL)
    {   
        printf("key -> %d --- value -> %d\n", i, aux->value);
        aux = aux->next;
    }

    print_hash(new_hash, size, i + 1);
}

int HASH(hash *new_hash, int item, int size, int *cont)
{
    int key = dispersal_div(item, size);
    node *aux = new_hash->table[key];

    while (aux != NULL)
    {
        *cont += 1;
        if (aux->value == item)
        {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

int DEL(hash *new_hash, int item, int size, int *cont)
{
    if (new_hash == NULL)
    {
        return 0;
    }

    int key = dispersal_div(item, size);
    node *aux = new_hash->table[key];
    while (aux != NULL)
    {
        *cont += 1;
        if (aux->value == item)
        {
            if (aux->prev == NULL && aux->next == NULL) // se for a cabeca e tiver so um elemento
            {
                new_hash->table[key] = NULL;
                free(aux);
            }

            else if (aux->prev == NULL) // se ele for a cabeca
            {
                node *temp = aux->next;
                new_hash->table[key] = temp;
                temp->prev = NULL;
                free(aux);
            }

            else if (aux->next == NULL) // se o elemento for o ultimo
            {
                node *previous = aux->prev; // o ponteiro do anterior aponta para null 
                previous->next = NULL;
                aux->prev = NULL;
                free(aux);
            }

            else // se estiver no meio
            {
                node *coming = aux->next;
                node *previous = aux->prev;

                previous->next = coming;
                coming->prev = previous;

                free(aux);
            }
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void ADD_REHASH(hash *new_hash, int item, int size)
{
    if (new_hash == NULL)
    {
        return;
    }

    new_hash->qtd++;
    int key = dispersal_div(item, size);
    
    if (new_hash->table[key] == NULL)
    {
        node *head = NULL;
        head = insert_begin(head, item);
        new_hash->table[key] = head;
    }

    else
    {
        node *aux = new_hash->table[key];
        aux = insert_begin(aux, item);
        new_hash->table[key] = aux;
    }
}

int ADD(hash *new_hash, int item, int size, int *cont)
{
    if (new_hash == NULL)
    {
        return 0;
    }

    int key = dispersal_div(item, size);
    
    if (new_hash->table[key] == NULL) // se nao tiver elemento na cabeca
    {
        node *head = NULL;
        head = insert_begin(head, item);
        new_hash->table[key] = head;
        return 1;
    }

    else
    {
        node *head = new_hash->table[key];
        node *aux = head;

        if (aux->next == NULL) // se tiver apenas um elemento na cabeca
        {
            *cont = 1;
            if (aux->value == item) // para nao se repetir
            {
                return 0;
            }

            else
            {
                head = insert_begin(head, item);
                new_hash->table[key] = head;
                return 1;
            }
        }

        else
        {
            while (aux != NULL) // 
            {
                *cont += 1;
                if (aux->value == item)
                {
                    return 0;
                    break;
                }

                if (aux->next == NULL)
                {
                    break;
                }

                aux = aux->next;
            }

            if (aux->value != item)
            {
                head = insert_begin(head, item);
                new_hash->table[key] = head;
                return 1;
            }
        }
    }
}

int longer_list(hash *new_hash, int size)
{
    int cont = 0;
    int longer = 0;
    int i = 0;

    while (size != i)
    {
        node *aux = new_hash->table[i];

        while (aux != NULL)
        {
            cont += 1;
            aux = aux->next;
        }    

        if (cont > longer)
        {
            longer = cont;
        }
        cont = 0;
        i += 1;
    }

    return longer;
}

hash *REHASH(hash *new_hash, int new_size)
{
    int i = 0;
    hash *big_hash = create_hash(new_size);

    while (new_size != i)
    {
        node *aux = new_hash->table[i];
        while (aux != NULL) 
        {
            ADD_REHASH(big_hash, aux->value, new_size);
            aux = aux->next;
        }
        i += 1;
    }
    return big_hash;
}

int main()
{
    int size = 7;
    int item = 0;
    int number = 0;
    int result = 0;
    int cont = 0;
    char operation[3];
    hash *new_hash = create_hash(size);

    while (scanf("%s", operation) != EOF)
    {
        printf("%d ", number);
        if (strcmp(operation, "ADD") == 0)
        {
            scanf("%d", &item);
            result = ADD(new_hash, item, size, &cont);
            printf("%d %d\n", result, cont);
            cont = 0;
            if (result == 1)
            {
                new_hash->qtd++;
            } 
            //print_hash(new_hash, size, 0); 
        }

        else if (strcmp(operation, "DEL") == 0)
        {
            scanf("%d", &item);
            result = DEL(new_hash, item, size, &cont);
            printf("%d %d\n", result, cont);
            cont = 0;
            if (result == 1)
            {
                new_hash->qtd--;
            } 
            //print_hash(new_hash, size, 0); 
        }

        else if (strcmp(operation, "HAS") == 0)
        {
            scanf("%d", &item);
            result = HASH(new_hash, item, size, &cont);
            printf("%d %d\n", result, cont);
            cont = 0;
        }

        else if (strcmp(operation, "PRT") == 0)
        {
            printf("%d %d %d\n", size, new_hash->qtd, longer_list(new_hash, size));
        }
        
        double factor = (double)new_hash->qtd / (double)size;

        if (factor >= 0.75)
        {
            size = (2 * size) - 1;
            new_hash = REHASH(new_hash, size);
        }   

        number += 1;
    }
    //print_hash(new_hash, size, 0);

    return 0;
}