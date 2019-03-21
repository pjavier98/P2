#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    int item;
    int height;
    binary_tree *left, *right;
};

binary_tree *create_empty_binary_tree() {
    return NULL;
}

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *bt = (binary_tree*) malloc(sizeof(binary_tree));
    bt->item = item;
    bt->height = 0;
    bt->left = bt->right = NULL;
    return bt;
}

int is_empty(binary_tree *bt) {
    return bt == NULL;
}

binary_tree *min_value_node(binary_tree *bt) {
    binary_tree *current = bt;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

binary_tree *search(binary_tree *bt, int item, int *cont) {
    if ((bt == NULL) || (bt->item == item)) {
        return bt;
    }

    *cont += 1;
    if (bt->item > item) {
        search(bt->left, item, cont);
    } else {
        search(bt->right, item, cont);
    }
}

binary_tree *search_larger(binary_tree *bt, int item, int *cont) {
    if (bt == NULL) {
        return bt;
    }

    if (bt->item > item) {
        *cont += 1;
    }
    search_larger(bt->left, item, cont);
    search_larger(bt->right, item, cont);
}

binary_tree *search_biggest(binary_tree *bt, int item, int *cont, int *i) {
    if (bt == NULL) {
        return bt;
    }
    if (*i == item) {
        *cont = bt->item;
    }
    *i += 1;
    search_biggest(bt->left, item, cont, i);
    search_biggest(bt->right, item, cont, i);
}

binary_tree *delete_node_bst(binary_tree *bt, int key)
{
    // ETAPA 1: EXECUTAR PADRÃO BST DELETE
    if (bt == NULL) {
        return bt;
    }

    // Se a chave a ser apagada é menor que a
    // chave do bt, então está na subárvore esquerda
    if (key < bt->item) {
        bt->left = delete_node_bst(bt->left, key);
    }
    // Se a chave a ser apagada for maior que a chave
    // chave do bt, então está na subárvore direita
    else if(key > bt->item) {
        bt->right = delete_node_bst(bt->right, key);
    }

    // se a chave é a mesma que a chave do bt, então
    // ele é o nó a ser deletado
    else {
        // node with only one child or no child
        if (bt->left == NULL) {
            binary_tree *temp = bt->right;
            free(bt);
            return temp;
        } else if (bt->right == NULL) {
            binary_tree *temp = bt->left;
            free(bt);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right sbtree)
        binary_tree *temp = min_value_node(bt->right);

        // Copy the inorder successor's content to this node
        bt->item = temp->item;

        // Delete the inorder successor
        bt->right = delete_node_bst(bt->right, temp->item);
    }

    // ETAPA 2: Atualizar a altura do node atual
    return bt;
}


binary_tree *add_bst(binary_tree *bt, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (bt == NULL) {
        return (create_binary_tree(key, NULL, NULL));
    }

    if (key < bt->item) {
        bt->left = add_bst(bt->left, key);
    } else {
        bt->right = add_bst(bt->right, key);
    }
    /* return the (unchanged) bt pointer */
    return bt;
}

void read_operations(int quant) {
    int i; 
    int operation, number;
    binary_tree *bt = create_empty_binary_tree();

    for (i = 0; i < quant; i += 1) {
        scanf("%d %d", &operation, &number);
        //printf("operation -> %d number -> %d\n", operation, number);
        int cont = 0;
        if (operation == 1) {
            if (!search(bt, number, &cont)) {
                bt = add_bst(bt, number);
                printf("%d\n", cont);
            } else {
                printf("%d\n", cont);
            }
        } else if (operation == 2) {
            if (!search(bt, number, &cont)) {
                printf("-1\n");
            } else {
                bt = delete_node_bst(bt, number);
                printf("%d\n", cont);
            }
        } else if (operation == 3) {
            search_larger(bt, number, &cont);
            printf("%d\n", cont);
        } else if (operation == 4) {
            int i = 0;
            if (bt->left == NULL && bt->right == NULL) {
                printf("%d\n", bt->item);
            } else {
                search_biggest(bt, number, &cont, &i);
                printf("%d\n", cont);
            }
        }
    }
    printf("\n");
}

int main() {
    int amount;
    scanf("%d", &amount);

    while (amount > 0) {
        int quant;
        scanf("%d", &quant);
        read_operations(quant); 
        amount -= 1;   
    }
}