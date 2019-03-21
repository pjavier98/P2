#include "huff_tree.h"

USH is_leaf(HUFF_NODE *huff_tree) {
    return huff_tree->left == NULL && huff_tree->right == NULL;
}

HUFF_NODE *create_empty_huff_node() {
	HUFF_NODE *new_huff_node = (HUFF_NODE *) malloc(sizeof(HUFF_NODE));
	new_huff_node->frequency = 0;
	new_huff_node->key = NULL;
	new_huff_node->left = NULL;
	new_huff_node->right = NULL;
	return new_huff_node;
}

HUFF_NODE *create_huff_node(lli frequency, DATATYPE key, HUFF_NODE *left, HUFF_NODE *right) {
	HUFF_NODE *new_huff_node = (HUFF_NODE *) malloc(sizeof(HUFF_NODE));
	new_huff_node->frequency = frequency;
	new_huff_node->key = key;
	new_huff_node->left = left;
	new_huff_node->right = right;
	return new_huff_node;
}

void print_huff_tree(HUFF_NODE *huff_node) {
	if (huff_node == NULL) return;
        //printf("(");
        /*if (huff_node->key == ' ') {
        	printf("+");
        }
        else
        {*/
        	printf("%c", huff_node->key);
        //}
        /*if (huff_node->left == NULL) {
            printf("()");
        } else {*/
            print_huff_tree(huff_node->left);
        /*} if (huff_node->right == NULL) {
            printf("()");
        } else {*/
            print_huff_tree(huff_node->right);
        //}
        //printf(")");
}
