#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    int value;
    binary_tree *left;
    binary_tree *right;
};

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
    new_bt->left = left;
    new_bt->right = right;
    new_bt->value = item;
    return new_bt;
}

binary_tree *create_empty_binary_tree() {
    return NULL;
}


int is_empty(binary_tree *new_bt) {   
    return new_bt == NULL;
}

void tree_to_string_pre(binary_tree *new_bt, int *str, int *index) {
    if (!is_empty(new_bt)) {
        str[*index] = new_bt->value;
        *index += 1;   
        tree_to_string_pre(new_bt->left, str, index);
        tree_to_string_pre(new_bt->right, str, index);
    }
}

void tree_to_string_pos(binary_tree *new_bt, int *str, int *index) {
    if (!is_empty(new_bt)) {
        tree_to_string_pos(new_bt->left, str, index);
        tree_to_string_pos(new_bt->right, str, index);
        str[*index] = new_bt->value;
        *index += 1;
    }
}

void tree_to_string_in(binary_tree *new_bt, int *str, int *index) {
    if (!is_empty(new_bt)) {
        tree_to_string_in(new_bt->left, str, index);
        str[*index] = new_bt->value;
        *index += 1;
        tree_to_string_in(new_bt->right, str, index);
        
    }
}

binary_tree *add(binary_tree *new_bt, int array[][2], int index) {
    if (index == -1) {
        return NULL;
    } else {
        new_bt = create_binary_tree(index, NULL, NULL);
        new_bt->left = add(new_bt->left, array, array[index][0]);
        new_bt->right = add(new_bt->right, array, array[index][1]);
        return new_bt;
    }
}

void print_tree(int *str, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (str[j] == i) {
                if (j - 1 < 0) {
                    printf("Node %d: previous = -1 next = %d\n", i, str[j + 1]);
                } else if (j == size - 1) {
                    printf("Node %d: previous = %d next = -1\n", i, str[j - 1]);
                } else {
                    printf("Node %d: previous = %d next = %d\n", i, str[j - 1], str[j + 1]);
                }  
            } 
        }
    }
}

int main() {
    int quantidade;
    scanf("%d", &quantidade);
    int array[quantidade][2];
    int i, j;

    for(i = 0; i < quantidade; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &array[i][j]);
        }
    }

    int root;
    scanf("%d", &root);
    binary_tree *bt = create_empty_binary_tree();
    bt = add(bt, array, root);

    printf("Pre Order:\n");
    int str[quantidade];
    int index = 0;
    tree_to_string_pre(bt, str, &index);
    print_tree(str, index);

    index = 0;
    printf("In Order\n");
    tree_to_string_in(bt, str, &index);
    print_tree(str, index);

    index = 0;
    printf("Post Order\n");
    tree_to_string_pos(bt, str, &index);
    print_tree(str, index);
    return 0;
}