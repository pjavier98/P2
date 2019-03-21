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

binary_tree *search_sum(binary_tree *bt, int item, int sum, int *pointer) {
    if (bt == NULL) {
        return bt;
    }
    sum += bt->item;
    if (bt->left == NULL && bt->right == NULL) {
        if (item == sum) {
            *pointer = 1;
        }
    }
    search_sum(bt->left, item, sum, pointer); 
    search_sum(bt->right, item, sum, pointer);
}

void print_pre_order(binary_tree *bt) {
    if (!is_empty(bt)) {
        printf("(");
        printf("%d ", bt->item);

        if (bt->left == NULL) {
            printf("()");
        } else {
            print_pre_order(bt->left);
        } if (bt->right == NULL) {
            printf("()");
        } else {
            print_pre_order(bt->right);
        }
        printf(")");
    }
}

void read() {
    while (1) {
        binary_tree *bt = NULL;
        char str[10000] = {0};
        int i = 0, item = 0, cont = 0, pos = 0, pointer = 0;
        char caracter;
        scanf("%d", &item);
        if (item == -1000) {
            break;
        }
        while (1) {
            scanf(" %c", &caracter);
            if (caracter != ' ') {
                str[i] = caracter;
                i++;
                if (caracter == '(') {
                    cont += 1;
                } else if (caracter == ')') {
                    cont -= 1;
                }
            }
            if (cont == 0) {
                break;
            }   
            
        }
        str[i] = '\0';
        bt = construct_binary_tree(str, &pos);
        search_sum(bt, item, 0, &pointer);
        if (pointer == 1) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
}

int main() {
    read();
    return 0;
}