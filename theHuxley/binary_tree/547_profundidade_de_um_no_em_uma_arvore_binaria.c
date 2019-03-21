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

binary_tree *search(binary_tree *bt, int item, int *cont) {
    binary_tree *new_bt = bt;
    *cont += 1;
    if ((new_bt == NULL) || (new_bt->item == item)) {
        return new_bt;
    } else if (new_bt->item > item) {
        search(new_bt->left, item, cont);
    } else {
        search(new_bt->right, item, cont);
    }
}

int main() {
    int i = 0;
    int pos = 0;
    int cont = -1;
    int item;
    char str[100];
    binary_tree *bt = NULL;
    scanf("%[^\n]", str);
    scanf("%d", &item);
    int size = strlen(str);
    int flag = 0;
    bt = construct_binary_tree(str, &pos);
    if (search(bt, item, &cont)) {
        printf("ESTA NA ARVORE\n%d\n", cont);
    } else {
        printf("NAO ESTA NA ARVORE\n%d\n", -1);
    }
    return 0;
}