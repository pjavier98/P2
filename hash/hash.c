#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct element element;
typedef struct hash_table hash;

struct element
{
    int key;
    int value;
};

struct hash // declaracao da hash, um ponteiro para a tabela e dentro dela para key e value.
{
    element *table[size];
    int qtd;
};

hash *create_hash()
{
    hash *new_hash = (hash*) malloc(sizeof(hash));

    int i;

    for (i = 0; i < size; i += 1)
    {
        new_hash->table[i] = NULL;
    }

    return new_hash;
}

void erase_hash(hash *new_hash)
{
    if (hash != NULL)
    {
        int i;

        for (i = 0; i < size; i += 1)
        {
            if (new_hash->element[i] != NULL)
            {
                free(new_hash->element[i]);
            }
            free(new_hash->element);
            free(new_hash);
        }
    }
}

// hashing
// opcao 1 - bit
int key_bit(int chave) // evita o risco de ocorrer um overflow e obter um numero negativo
{
    return (chave & 0x7FFFFFFF) % size; // E bit-a-bit
}

// opcao 2 - multiplicacao 
int key_mult(int chave) // fazer espalhamento
{
    float x = 0.788035878;
    float valor = chave * a;
    valor = valor - (int) valor;
    return (int) (size * val); 
}

// opcao 3 - dobrar array
int key_dobra(int chave)
{
    int number_of_bits = 10;
    int x = chave >> number_of_bits;
    int y = chave & (size - 1);
    return (x ^ y);
}

// opcao 4 - string
int key_string(char *word)
{
    int i, 
    int aux = 7;
    int tamanho = strlen(word);

    for (i = 0; i < tamanho; i += 1)
    {
        aux = 39 * valor + (int) word[i]; 
    }
    return aux;
}

// Tratamento de colisoes
// opcao 1
int sonda_linear(int pos, int i){
    return((pos + i) & 0x7FFFFFFF) % size;
}

// opcao 2
int sonda_quad(int pos, int i){
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % size;
}

// opcao 3
int sonda_hash(int pos, int key, int i){
    int pos_1 = keydiv(key, t_size-1) + 1;
    return ((pos + i*pos_1) & 0x7FFFFFFF) % size;
}

// inserir tratando colisoes
int insert_hash_address_open(hash *new_hash, int item)
{
    if (new_hash == NULL || new_hash->qtd == size)
    {
        return 0;
    }

    int chave = element->key;
    int i, position, new_position;
    position = key_bit(hash);

    for (i = 0; i < size, i += 1)
    {
        new_position = sonda_hash(pos, i);
        if (new_hash->element[new_position] == NULL)
        {
            element *new_element;

            new_element = (element*) malloc(sizeof(element));
            if (new_element == NULL)
            {
                return 0;
            }

            *new_element = element;
            new_hash->element[new_position] = new_element;
            new_hash->qtd++;
            return 1;
        }
    }
}

// busca tratando colisoes
int insert_hash_address_open(hash *new_hash, int item)
{
    if (new_hash == NULL)
    {
        return 0;
    }

    int i, position, new_position;
    position = key_bit(hash);

    for (i = 0; i < size, i += 1)
    {
        new_position = sonda_hash(pos, i);
        if (new_hash->element[new_position] == NULL)
        {
            return 0;

            if (new_hash->element[new_position]->value == item)
            {
                return 1; // se achar o elemento
            }

            *new_element = element;
            new_hash->element[new_position] = new_element;
            new_hash->qtd++;
            return 1;
        }
    }
}


int main()
{
    printf("%d\n", size);
    return 0;
}

// Formas de tratamento das colisoes:
// Enderecamento aberto, enderecamento separado