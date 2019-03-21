#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    int item;
    int height;
    binary_tree *left, *right;
};

int is_empty(binary_tree *bt) {
    return bt == NULL;
}

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *bt = (binary_tree*) malloc(sizeof(binary_tree));
    bt->item = item;
    bt->left = bt->right = NULL;
    return bt;
}

binary_tree* construct_binary_tree(char *str, int *pos) {

    binary_tree *bt = NULL; //ponteiro para a arvore
    int i = 0;
    int numInt;       //numero do no (inteiro)
    char numStr[50];  //numero do no (string)

    while(str[*pos] == '(') { //ignora os parenteses abrindo
        *pos += 1;
    }

    if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
        *pos += 1;         // pois o ponteiro eh nulo
        return bt;
    }
    else {
        while(str[*pos] != '(') {    //se for diferente de abre parenteses
            numStr[i++] = str[*pos]; //le o numero string
            *pos += 1;
        }
        numStr[i] = '\0'; //finalizando a string com '/0'
        numInt = atoi(numStr); //converte o numero string para inteiro

        bt = create_binary_tree(numInt, NULL, NULL); //cria um no com o numero inteiro
        bt->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
        bt->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
    }
    *pos += 1;
    return bt; //retorna o ponteiro para a arvore
}

binary_tree *search(binary_tree *bt, int *flag) {
    if (bt == NULL) {
        return bt;
    }   
        if (bt->left != NULL) {
            if (bt->item < bt->left->item) {
            *flag = 1;
            }
        }
        search(bt->left, flag);
        
        if (bt->right != NULL) {
            if (bt->item > bt->right->item) {
                *flag = 1;
            }
        }
        search(bt->right, flag);
}

int main() {
    int pos = 0;
    int flag = 0;
    char str[100];
    binary_tree *bt = NULL;

    scanf("%[^\n]", str);
    int size = strlen(str);
    
    bt = construct_binary_tree(str, &pos);
    search(bt, &flag);
    
    if (flag == 1) {
        printf("FALSO\n");
    } else {
        printf("VERDADEIRO\n");
    }

    return 0;
}