#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree binary_tree; // bt = binary_tree

struct binary_tree // um ponteiro para direita e outro pra esquerda
{
    int value;
    binary_tree *left;
    binary_tree *right;
};

binary_tree *create_empty_binary_tree()
{
    return NULL;
}

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right)
{
    binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
    new_bt->left = left;
    new_bt->right = right;
    new_bt->value = item;

    return new_bt;
}

int is_empty(binary_tree *new_bt)
{   
    return new_bt == NULL;
}

binary_tree *add(binary_tree *new_bt, int item)
{
    if (new_bt == NULL)
    {
        new_bt = create_binary_tree(item, NULL, NULL);
    }

    else
    {
        if (new_bt->value > item)
        {
            new_bt->left = add(new_bt->left, item);
        }

        else
        {
            new_bt->right = add(new_bt->right, item);
        }
    }
    return new_bt;
}

binary_tree *search(binary_tree *new_bt, int item)
{
    if (new_bt == NULL || new_bt->value == item) // se estiver vazia ou a raiz for o numero procurado
    {
        return new_bt;
    }

    else
    {
        if (new_bt->value > item)
        {
            return search(new_bt->left, item);
        }

        else
        {
            return search(new_bt->right, item);
        }
    }

}

void print_pre_order(binary_tree *new_bt) // (print, visit, visit)
{
    if (!is_empty(new_bt))
    {
        printf(" ( ");
        printf("%d ", new_bt->value);  

        
        if (new_bt->left == NULL)
        {
            printf(" () ");
        } 

        else
        {
            print_pre_order(new_bt->left);
        }

        if (new_bt->right == NULL)
        {
            printf(" () ");
        } 

        else
        {
            print_pre_order(new_bt->right);
        }

        printf(") ");
    }
}

int main()
{
    int item;
    
    binary_tree *new_bt = create_empty_binary_tree();

    while(scanf("%d", &item) != EOF)
    {
        printf("----\nAdicionando %d\n  ", item);
        new_bt = add(new_bt, item);
        print_pre_order(new_bt);
        printf("\n");
    }
    printf("----");
    return 0;
}