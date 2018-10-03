#include "avl.h"

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

// Four cases:
// y is left child of z and x is left child of y (Left Left Case)
// y is left child of z and x is right child of y (Left Right Case)
// y is right child of z and x is right child of y (Right Right Case)
// y is right child of z and x is left child of y (Right Left Case)

binary_tree *rotate_right(binary_tree *ubn) { 
	binary_tree *child = ubn->left; 
	binary_tree *right_child = child->right; 

    // Perform rotation 
	child->right = ubn; 
	ubn->left = right_child; 

    // Update heights 
	ubn->height = max(height(ubn->left), height(ubn->right)) + 1; 
	child->height = max(height(child->left), height(child->right)) + 1; 

    // Return new root 
	return child; 
} 

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
binary_tree *rotate_left(binary_tree *ubn) { 
	binary_tree *child = ubn->right; 
	binary_tree *left_child = child->left; 

    // Perform rotation 
	child->left = ubn; 
	ubn->right = left_child; 

    //  Update heights 
	ubn->height = max(height(ubn->left), height(ubn->right))+1; 
	child->height = max(height(child->left), height(child->right))+1; 

    // Return new root 
	return child; 
} 

binary_tree *add(binary_tree *root, lli key) { 
    /* 1.  Perform the normal BST rotation */
	if (root == NULL) 
		return (create_binary_tree(key, NULL, NULL)); 

	if (key < root->item) {
		root->left  = add(root->left, key); 
	}
	else if (key > root->item) {
		root->right = add(root->right, key); 
	}
    else {// Equal keys not allowed 
    	return root; 
    }
    /* 2. Update height of this ancestor root */
    root->height = 1 + max(height(root->left), height(root->right)); 

    /* 3. Get the balance factor of this ancestor 
          root to check whether this root became 
          unbalanced */
    int balance = is_balanced(root); 

    // If this root becomes unbalanced, then there are 4 cases 

    // Left Left Case 
    if (balance > 1 && key < root->left->item) {
    	return rotate_right(root); 
    }

    // Right Right Case 
    if (balance < -1 && key > root->right->item) {
    	return rotate_left(root); 
    }

    // Left Right Case 
    if (balance > 1 && key > root->left->item) { 
    	root->left =  rotate_left(root->left); 
    	return rotate_right(root); 
    } 

    // Right Left Case 
    if (balance < -1 && key < root->right->item) { 
    	root->right = rotate_right(root->right); 
    	return rotate_left(root); 
    } 

    /* return the (unchanged) root pointer */
    return root; 
} 

int is_balanced(binary_tree *bt) { 
	if (bt == NULL) {
		return 0; 
	}
	return height(bt->left) - height(bt->right); 
} 

binary_tree *search(binary_tree *bt, lli item) {
	binary_tree *new_bt = bt;

	if ((new_bt == NULL) || (new_bt->item == item)) {
		return new_bt;
	} else if (new_bt->item > item) {
		search(new_bt->left, item);
	} else {
		search(new_bt->right, item);
	}
}

binary_tree *min_value_node(binary_tree *node) { 
	binary_tree *current = node; 

    /* loop down to find the leftmost leaf */
	while (current->left != NULL) {
		current = current->left; 
	}

	return current; 
} 

binary_tree *delete_node(binary_tree *root, lli key) { 
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
	else
	{ 
        // node com apenas um filho ou sem filho
		if((root->left == NULL) || (root->right == NULL)) 
		{ 
        	//binary_tree *temp = root->left ? root->left : root->right;
			binary_tree *temp;
			
			if (root->left == NULL) {
				temp = root->right;
			} else {
				temp = root->left;
			}

            // Caso sem filhos
			if (temp == NULL) {
				temp = root; 
				root = NULL; 
			} 
			// Case de um filho 
			else {
            	// Copie o conteúdo de a criança não vazia
            	// se nao usar esses ponteiros a saida fica assim quando for eliminar a cabeca:
 				//( 94555905660672  ()  () )
				*root = *temp; 
				free(temp); 
			}
		} else { 
            // node com dois filhos: pegar o sucessor  
            // em ordem (menor na subarvore a direita) 
			binary_tree *temp = min_value_node(root->right); 

            // copiar o conteudo do sucessor em ordem para este node 
			root->item = temp->item; 

            // deletar este sucessor em ordem 
			root->right = delete_node(root->right, temp->item); 
		} 
	} 

    // se a arvore tem apenas um node entao retorna 
	if (root == NULL) {
		return root; 
	}

    // ETAPA 2: Atualizar a altura do node atual 
	root->height = 1 + max(height(root->left), height(root->right)); 

    // STEP 3: Pegar o fator de balanceamento deste node(para 
    // verificar se o node se tornou desbalanceou 
	int balance = is_balanced(root); 
	//printf("%d\n", balance);
    // Se este nó se tornar desbalanceado, existem 4 casos 

    // Caso esquerda esquerda 
	if (balance > 1 && is_balanced(root->left) >= 0) {
		return rotate_right(root); 
	}

    // Caso Esquerda Direita 
	if (balance > 1 && is_balanced(root->left) < 0) { 
		root->left =  rotate_left(root->left); 
		return rotate_right(root); 
	} 

    // Caso Direita Direita 
	if (balance < -1 && is_balanced(root->right) <= 0) {
		return rotate_left(root); 
	}

    // Caso Direita Esquerda 
	if (balance < -1 && is_balanced(root->right) > 0) { 
		root->right = rotate_right(root->right); 
		return rotate_left(root); 
	} 

	return root; 
}

void print_tree(binary_tree *bt) { // (print, visit, visit) 
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

	int x;
        
    
	for (i = 1; i <= 100; i++) {
        x = rand() % 100;
        //printf("%d\n", x);

		bt = add(bt, i);	
	}
	print_tree(bt);
	printf("\n");
	printf("\n");
	
	for (i = 1; i <= 50; i++)
	{
        x = rand() % 100;
        //printf("%d\n", x);

		bt = delete_node(bt, x);
		print_tree(bt);

		if (bt == NULL) {
			printf("Arvore Vazia\n");
		}
		printf("\n");
		printf("\n");
	}
}