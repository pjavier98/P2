/*
 * Essa função recebe a string com a arvore em notacao de parenteses
 * e um ponteiro para inteiro para construir a arvore binaria a 
 * partir da string
 */
bt* construct_binary_tree(char *str, int *pos) {

    bt *btree = NULL; //ponteiro para a arvore
    int i = 0;
    int numInt;       //numero do no (inteiro)
    char numStr[50];  //numero do no (string)
 
    while(str[*pos] == '(') { //ignora os parenteses abrindo
        *pos += 1;
    }

    if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
        *pos += 1;         // pois o ponteiro eh nulo
        return NULL;
    }
    else {
        while(str[*pos] != '(') {    //se for diferente de abre parenteses
            numStr[i++] = str[*pos]; //le o numero string
            *pos += 1;
        }
        numStr[i] = '\0'; //finalizando a string com '/0'
        numInt = atoi(numStr); //converte o numero string para inteiro

        btree = create_binary_tree(numInt, NULL, NULL); //cria um no com o numero inteiro
        btree->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
        btree->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
    }

    *pos += 1;
    return btree; //retorna o ponteiro para a arvore
}