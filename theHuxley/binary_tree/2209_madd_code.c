#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    char item;
    binary_tree *left, *right;
};

binary_tree *create_binary_tree(char item, binary_tree *left, binary_tree *right) {
    binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
    new_bt->item = item;
    new_bt->left = new_bt->right = NULL;
    return new_bt;
}

binary_tree *create_empty_binary_tree() {
    return NULL;
}

int is_empty(binary_tree *bt) {
    return bt == NULL;
}

binary_tree *add(binary_tree *root, char key) { 
    if (root == NULL) {
        return (create_binary_tree(key, NULL, NULL)); 
    } if (key < root->item) {
        root->left  = add(root->left, key); 
    } else if (key > root->item) {
        root->right = add(root->right, key); 
    } else { 
        return root; 
    }
    return root; 
} 

binary_tree *search(binary_tree *bt, char *str, int *cont) {
    if (str[*cont] == '@') {
        printf("%c", bt->item);
        *cont += 2;
        return bt; 
    } else if (str[*cont] == '*') {
        printf("%c", bt->item);
        *cont += 1;
        return bt;
    }  if (str[*cont] == '-') {
        *cont += 1;
        search(bt->left, str, cont);
    } else if (str[*cont] == '|') {
        *cont += 1;
        search(bt->right, str, cont);
    }
    return bt;
}

int main() {
    int i;
    char string[28];
    strcpy(string, "MGTCKQWAEILORUY BDFHJNPSVXZ");
    binary_tree *bt = create_empty_binary_tree();

    for (i = 0; i < 28; i++) {
        bt = add(bt, string[i]);
    }

    char str[1000];
    char letter;
    i = 0;
    while (scanf("%c", &letter) != EOF) {
        if (letter != ' ') {
            str[i] = letter;
            i++;
        }
    }

    int size = strlen(str);
    int cont = 0;

    while (cont < size - 1) {
        bt = search(bt, str, &cont);
    }

    printf("\n");
}