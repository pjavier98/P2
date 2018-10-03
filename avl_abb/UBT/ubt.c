#include "ubt.h"

binary_tree *create_empty_binary_tree() {
	return NULL;
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

binary_tree *add(binary_tree *root, lli key) 
{ 
	/* 1.  Perform the normal BST rotation */
	if (root == NULL) {
		return (create_binary_tree(key, NULL, NULL)); 
	} if (key < root->item) {
		root->left  = add(root->left, key); 
	} else if (key > root->item) {
		root->right = add(root->right, key); 
	} else {// Equal keys not allowed 
		return root; 
	}
	/* 2. Update height of this ancestor root */
	root->height = 1 + max(height(root->left), height(root->right)); 
	
	/* return the (unchanged) root pointer */
	return root; 
} 

binary_tree *search(binary_tree *bt, lli item)
{
	binary_tree *new_bt = bt;

	if ((new_bt == NULL) || (new_bt->item == item)) {
		return new_bt;
	} else if (new_bt->item > item) {
		search(new_bt->left, item);
	} else {
		search(new_bt->right, item);
	}
}

binary_tree *min_value_node(binary_tree *node) 
{ 
	binary_tree *current = node; 

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) {
		current = current->left; 
	}

	return current; 
} 

binary_tree *delete_node(binary_tree *root, lli key) 
{ 
	// ETAPA 1: EXECUTAR PADRÃO BST DELETE  
	if (root == NULL) {
		return root; 
	}

	// Se a chave a ser apagada é menor que a
	// chave do root, então está na subárvore esquerda
	if (key < root->item) { 
		root->left = delete_node(root->left, key); 
	}
	// Se a chave a ser apagada for maior que a chave
	// chave do root, então está na subárvore direita
	else if(key > root->item) {
		root->right = delete_node(root->right, key);
	}

	// se a chave é a mesma que a chave do root, então
	// ele é o nó a ser deletado
	else { 
		// node with only one child or no child 
		if (root->left == NULL) { 
			binary_tree *temp = root->right;
			free(root); 
			return temp; 
		} else if (root->right == NULL) { 
			binary_tree *temp = root->left; 
			free(root); 
			return temp; 
		} 
		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		binary_tree *temp = min_value_node(root->right); 

		// Copy the inorder successor's content to this node 
		root->item = temp->item; 

		// Delete the inorder successor 
		root->right = delete_node(root->right, temp->item); 
	}

	root->height = 1 + max(height(root->left), height(root->right)); 
	// ETAPA 2: Atualizar a altura do node atual 
	return root; 
}

void print_tree(binary_tree *bt) // (print, visit, visit)
{
	if (!is_empty(bt)) {
		printf(" ( ");
		printf("%lld ", bt->item);  

		if (bt->left == NULL) {
			printf(" () ");
		} else {
			print_tree(bt->left);
		} if (bt->right == NULL) {
			printf(" () ");
		} else {
			print_tree(bt->right);
		}
		printf(") ");
	}
}

int main() {
	int i;
	binary_tree *bt = create_empty_binary_tree();

	for (i = 1; i <= 20; i++) {
		bt = add(bt, i);
		print_tree(bt);
		printf("\n");
		printf("\n");	
	}


	for (i = 1; i <= 20; i++)
	{
		bt = delete_node(bt, i);
		print_tree(bt);

		if (bt == NULL) {
			printf("Arvore Vazia\n");
		}
		printf("\n");
		printf("\n");
	}	
}