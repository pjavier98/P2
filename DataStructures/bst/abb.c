#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
	binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
	new_bt->item = item;
	new_bt->height = 1;
	new_bt->left = new_bt->right = NULL;
	return new_bt;
}

int is_empty(binary_tree *bt) {
	return bt == NULL;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(binary_tree *bt) {
	if (bt == NULL) {
		return -1;
	} else {
		return 1 + max(height(bt->left), height(bt->right));
	}
}

binary_tree *add(binary_tree *root, int key) { 
	if (root == NULL) {
		return create_binary_tree(key, NULL, NULL); 
	} if (key < root->item) {
		root->left  = add(root->left, key); 
	} else if (key > root->item) {
		root->right = add(root->right, key); 
	} else {
		return root; 
	}

	root->height = 1 + max(height(root->left), height(root->right)); 
	return root; 
} 

binary_tree *search(binary_tree *bt, int item) {
	if ((bt == NULL) || (bt->item == item)) {
		return bt;
	} else if (bt->item > item) {
		search(bt->left, item);
	} else {
		search(bt->right, item);
	}
}

binary_tree *min_value_node(binary_tree *node) { 
	binary_tree *current = node; 

	while (current->left != NULL) {
		current = current->left; 
	}
	return current; 
} 

binary_tree *delete_node(binary_tree *root, int key) { 
	if (root == NULL) {
		return root; 
	}

	if (key < root->item) { 
		root->left = delete_node(root->left, key); 
	} else if(key > root->item) {
		root->right = delete_node(root->right, key);
	} else { 
		if (root->left == NULL) { 
			binary_tree *temp = root->right;
			free(root); 
			return temp; 
		} else if (root->right == NULL) { 
			binary_tree *temp = root->left; 
			free(root); 
			return temp; 
		} 
		
		binary_tree *temp = min_value_node(root->right); 
		root->item = temp->item; 
		root->right = delete_node(root->right, temp->item); 
	}

	root->height = 1 + max(height(root->left), height(root->right)); 
	return root; 
}

void print_tree(binary_tree *bt) {
	if (!is_empty(bt)) {
		printf("(");
		printf("%d ", bt->item);  
		if (bt->left == NULL) {
			printf("()");
		} else {
			print_tree(bt->left);
		} if (bt->right == NULL) {
			printf("()");
		} else {
			print_tree(bt->right);
		}
		printf(")");
	}
}

int main() {
	int i;
	binary_tree *bt = create_empty_binary_tree();

	// bt = add(bt, i);
	// bt = search(bt, item);
	// bt = delete_node(bt, i);
	// print_tree(bt);

	return 0;
}