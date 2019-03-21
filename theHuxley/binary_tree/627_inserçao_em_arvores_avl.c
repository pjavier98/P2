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
	bt->height = 1;
	bt->left = bt->right = NULL;
	return bt;
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

binary_tree *min_value_node(binary_tree *bt) {
	binary_tree *current = bt;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) {
		current = current->left;
	}

	return current;
}

int is_balanced_avl(binary_tree *bt) {
	if (bt == NULL) {
		return 0;
	}
	return height(bt->left) - height(bt->right);
}

binary_tree *rotate_right_avl(binary_tree *bt) {
	binary_tree *child = bt->left;
	binary_tree *right_child = child->right;

	// Perform rotation
	child->right = bt;
	bt->left = right_child;

	// Update height_avls
	bt->height = max(height(bt->left), height(bt->right)) + 1;
	child->height = max(height(child->left), height(child->right)) + 1;

	// Return new bt
	return child;
}

binary_tree *rotate_left_avl(binary_tree *bt) {
	binary_tree *child = bt->right;
	binary_tree *left_child = child->left;

	// Perform rotation
	child->left = bt;
	bt->right = left_child;

	//  Update height_avls
	bt->height = max(height(bt->left), height(bt->right))+1;
	child->height = max(height(child->left), height(child->right))+1;

	// Return new bt
	return child;
}

void print_pre_order(binary_tree *bt) {
	if (!is_empty(bt)) {
		printf(" ( ");
		printf("%d ", bt->item);

		if (bt->left == NULL) {
			printf(" () ");
		} else {
			print_pre_order(bt->left);
		} if (bt->right == NULL) {
			printf(" () ");
		} else {
			print_pre_order(bt->right);
		}
		printf(") ");
	}
}

binary_tree *add_avl(binary_tree *bt, int key, int *flag, binary_tree *aux_bt) {
	if (bt == NULL)
		return (create_binary_tree(key, NULL, NULL));

	if (key < bt->item) {
		bt->left  = add_avl(bt->left, key, flag, aux_bt);
	}
	else if (key >= bt->item) {
		bt->right = add_avl(bt->right, key, flag, aux_bt);
	} 

	bt->height = 1 + max(height(bt->left), height(bt->right));

	int balance = is_balanced_avl(bt);
	if (balance > 1 || balance < -1 && *flag == 0) {
		*flag = 1;
		printf("Antes de ajustar balanceamento...\n  ");
		print_pre_order(aux_bt);
		printf("\n");
	}
	
	if (balance > 1 && key < bt->left->item) {
		return rotate_right_avl(bt);
	}
	if (balance < -1 && key >= bt->right->item) {
		return rotate_left_avl(bt);
	}
	if (balance > 1 && key >= bt->left->item) {
		bt->left =  rotate_left_avl(bt->left);
		return rotate_right_avl(bt);
	}
	if (balance < -1 && key < bt->right->item) {
		bt->right = rotate_right_avl(bt->right);
		return rotate_left_avl(bt);
	}
	return bt;
}

int main() {
	binary_tree *bt = create_empty_binary_tree();
	binary_tree *aux_bt;
	int item = 0;
	
	while(scanf("%d", &item) != EOF)
	{
		int flag = 0;
		printf("----\nAdicionando %d\n", item);
		bt = add_avl(bt, item, &flag, aux_bt);
		aux_bt = bt;
		if (flag == 0)
		{
			printf("Continuou AVL...\n  ");
			print_pre_order(bt);
			printf("\n");
		} else {
			printf("Depois de ajustar balanceamento...\n  ");
			print_pre_order(bt);
			printf("\n");
		}
		
	}
	printf("----");
	return 0;
}