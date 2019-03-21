#include "binary_tree.h"

binary_tree *create_empty_binary_tree() {
	return NULL;
}

binary_tree *create_binary_tree(lli item, binary_tree *left, binary_tree *right) {
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

binary_tree *min_value_node(binary_tree *bt) {
    binary_tree *current = bt;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

binary_tree *search(binary_tree *bt, lli item, lli *cont) {
    binary_tree *new_bt = bt;
    *cont += 1;
    if ((new_bt == NULL) || (new_bt->item == item)) {
        return new_bt;
    } else if (new_bt->item > item) {
        search(new_bt->left, item, cont);
    } else {
        search(new_bt->right, item, cont);
    }
}

void print_tree(binary_tree *bt) {
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

/*--------------------------------------------------------------------------*/
// AVL:

int is_balanced_avl(binary_tree *bt) {
    if (bt == NULL) {
        return 0;
    }
    return height(bt->left) - height(bt->right);
}

// Four cases:
// y is left child of z and x is left child of y (Left Left Case)
// y is left child of z and x is right child of y (Left Right Case)
// y is right child of z and x is right child of y (Right Right Case)
// y is right child of z and x is left child of y (Right Left Case)

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

// A utility function to left rotate subtree bted with x
// See the diagram given above.
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

binary_tree *add_avl(binary_tree *bt, lli key) {
    /* 1.  Perform the normal BST rotation */
	if (bt == NULL)
		return (create_binary_tree(key, NULL, NULL));

	if (key < bt->item) {
		bt->left  = add_avl(bt->left, key);
	}
	else if (key > bt->item) {
		bt->right = add_avl(bt->right, key);
	} else {// Equal keys not allowed
         return bt;
    }
    /* 2. Update height_avl of this ancestor bt */
    bt->height = 1 + max(height(bt->left), height(bt->right));

    /* 3. Get the balance factor of this ancestor
          bt to check whether this bt became
          unbalanced */
    //printf("bt -> item %lld /// key -> %lld\n", bt->item, key);
    int balance = is_balanced_avl(bt);

    // If this bt becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < bt->left->item) {
    	return rotate_right_avl(bt);
    }

    // Right Right Case
    if (balance < -1 && key > bt->right->item) {
    	return rotate_left_avl(bt);
    }

    // Left Right Case
    if (balance > 1 && key > bt->left->item) {
    	bt->left =  rotate_left_avl(bt->left);
    	return rotate_right_avl(bt);
    }

    // Right Left Case
    if (balance < -1 && key < bt->right->item) {
    	bt->right = rotate_right_avl(bt->right);
    	return rotate_left_avl(bt);
    }

    /* return the (unchanged) bt pointer */
    return bt;
}

binary_tree *delete_node_avl(binary_tree *bt, lli key) {
	// ETAPA 1: EXECUTAR PADRÃO BST DELETE
	if (bt == NULL) {
		return bt;
	}

    // Se a chave a ser apagada é menor que a
    // chave do bt, então está na subárvore esquerda
	if (key < bt->item) {
		bt->left = delete_node_avl(bt->left, key);
	}
    // Se a chave a ser apagada for maior que a chave
    // chave do bt, então está na subárvore direita
	else if(key > bt->item) {
		bt->right = delete_node_avl(bt->right, key);
	}

    // se a chave é a mesma que a chave do bt, então
    // ele é o nó a ser deletado
	else
	{
        // node com apenas um filho ou sem filho
		if((bt->left == NULL) || (bt->right == NULL))
		{
        	//binary_tree *temp = bt->left ? bt->left : bt->right;
			binary_tree *temp;

			if (bt->left == NULL) {
				temp = bt->right;
			} else {
				temp = bt->left;
			}

            // Caso sem filhos
			if (temp == NULL) {
				temp = bt;
				bt = NULL;
			}
			// Case de um filho
			else {
            	// Copie o conteúdo de a criança não vazia
            	// se nao usar esses ponteiros a saida fica assim quando for eliminar a cabeca:
 				//( 94555905660672  ()  () )
				*bt = *temp;
				free(temp);
			}
		} else {
            // node com dois filhos: pegar o sucessor
            // em ordem (menor na subarvore a direita)
			binary_tree *temp = min_value_node(bt->right);

            // copiar o conteudo do sucessor em ordem para este node
			bt->item = temp->item;

            // deletar este sucessor em ordem
			bt->right = delete_node_avl(bt->right, temp->item);
		}
	}

    // se a arvore tem apenas um node entao retorna
	if (bt == NULL) {
		return bt;
	}

    // ETAPA 2: Atualizar a altura do node atual
	bt->height = 1 + max(height(bt->left), height(bt->right));

    // STEP 3: Pegar o fator de balanceamento deste node(para
    // verificar se o node se tornou desbalanceou
	int balance = is_balanced_avl(bt);
	//printf("%d\n", balance);
    // Se este nó se tornar desbalanceado, existem 4 casos

    // Caso esquerda esquerda
	if (balance > 1 && is_balanced_avl(bt->left) >= 0) {
		return rotate_right_avl(bt);
	}

    // Caso Esquerda Direita
	if (balance > 1 && is_balanced_avl(bt->left) < 0) {
		bt->left =  rotate_left_avl(bt->left);
		return rotate_right_avl(bt);
	}

    // Caso Direita Direita
	if (balance < -1 && is_balanced_avl(bt->right) <= 0) {
		return rotate_left_avl(bt);
	}

    // Caso Direita Esquerda
	if (balance < -1 && is_balanced_avl(bt->right) > 0) {
		bt->right = rotate_right_avl(bt->right);
		return rotate_left_avl(bt);
	}

	return bt;
}

/*--------------------------------------------------------------------------*/
// ABB:

binary_tree *add_ubt(binary_tree *bt, lli key)
{
	/* 1.  Perform the normal BST rotation */
	if (bt == NULL) {
		return (create_binary_tree(key, NULL, NULL));
	}

	binary_tree *aux = bt;
	binary_tree *previous;

	while (aux != NULL) {
		previous = aux;
		if (key < aux->item) {
			aux = aux->left;
		} else {
			aux = aux->right;
		}
	}

	if (key < previous->item) {
		previous->left = create_binary_tree(key, NULL, NULL);
	} else {
		previous->right = create_binary_tree(key, NULL, NULL);
	}

	/* return the (unchanged) bt pointer */
	return bt;
}

binary_tree *delete_node_ubt(binary_tree *bt, lli key)
{
	// ETAPA 1: EXECUTAR PADRÃO BST DELETE
	if (bt == NULL) {
		return bt;
	}

	// Se a chave a ser apagada é menor que a
	// chave do bt, então está na subárvore esquerda
	if (key < bt->item) {
		bt->left = delete_node_ubt(bt->left, key);
	}
	// Se a chave a ser apagada for maior que a chave
	// chave do bt, então está na subárvore direita
	else if(key > bt->item) {
		bt->right = delete_node_ubt(bt->right, key);
	}

	// se a chave é a mesma que a chave do bt, então
	// ele é o nó a ser deletado
	else {
		// node with only one child or no child
		if (bt->left == NULL) {
			binary_tree *temp = bt->right;
			free(bt);
			return temp;
		} else if (bt->right == NULL) {
			binary_tree *temp = bt->left;
			free(bt);
			return temp;
		}
		// node with two children: Get the inorder successor (smallest
		// in the right sbtree)
		binary_tree *temp = min_value_node(bt->right);

		// Copy the inorder successor's content to this node
		bt->item = temp->item;

		// Delete the inorder successor
		bt->right = delete_node_ubt(bt->right, temp->item);
	}

	bt->height = 1 + max(height(bt->left), height(bt->right));
	// ETAPA 2: Atualizar a altura do node atual
	return bt;
}
