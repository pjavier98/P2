#include "binary_tree.h"

binary_tree *create_binary_tree(lli item, binary_tree *left, binary_tree *right) {
	binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
	new_bt->item = item;
	new_bt->height = 1;
	new_bt->left = new_bt->right = NULL;
	return new_bt;
}
