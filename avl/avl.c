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

// Four cases:
// y is left child of z and x is left child of y (Left Left Case)
// y is left child of z and x is right child of y (Left Right Case)
// y is right child of z and x is right child of y (Right Right Case)
// y is right child of z and x is left child of y (Right Left Case)

binary_tree *rotate_right(binary_tree *ubn) { 
	binary_tree *child = ubn->left; 
	binary_tree *right_child = child->right; 

	child->right = ubn; 
	ubn->left = right_child; 

	ubn->height = max(height(ubn->left), height(ubn->right)) + 1; 
	child->height = max(height(child->left), height(child->right)) + 1; 

	return child; 
} 

binary_tree *rotate_left(binary_tree *ubn) { 
	binary_tree *child = ubn->right; 
	binary_tree *left_child = child->left; 

	child->left = ubn; 
	ubn->right = left_child; 

	ubn->height = max(height(ubn->left), height(ubn->right))+1; 
	child->height = max(height(child->left), height(child->right))+1; 

	return child; 
} 

binary_tree *add(binary_tree *root, lli key) { 
	if (root == NULL) 
		return (create_binary_tree(key, NULL, NULL)); 

	if (key < root->item) {
		root->left  = add(root->left, key); 
	}
	else if (key > root->item) {
		root->right = add(root->right, key); 
	}
    else {
    	return root; 
    }
    root->height = 1 + max(height(root->left), height(root->right)); 
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
    return root; 
} 

int is_balanced(binary_tree *bt) { 
	if (bt == NULL) {
		return 0; 
	}
	return height(bt->left) - height(bt->right); 
} 

binary_tree *search(binary_tree *bt, lli item) {
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

binary_tree *delete_node(binary_tree *root, lli key) { 
    // STEP 1: PERFORM STANDARD BST DELETE 
	if (root == NULL) {
		return root; 
	}

    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
	if (key < root->item) { 
		root->left = delete_node(root->left, key); 
	}
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
	else if(key > root->item) {
		root->right = delete_node(root->right, key);
	}
    // if key is same as root's key, then This is 
    // the node to be deleted 
	else { 
        // node with only one child or no child 
		if((root->left == NULL) || (root->right == NULL)) { 
			binary_tree *temp;
			if (root->left == NULL) {
				temp = root->right;
			} else {
				temp = root->left;
			}
            // No child case 
			if (temp == NULL) {
				temp = root; 
				root = NULL; 
			} 
			// One child case 
			else {
				*root = *temp; 
				free(temp);
                // Copy the contents of 
                // the non-empty child  
			}
		} else { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
			binary_tree *temp = min_value_node(root->right); 

            // Copy the inorder successor's data to this node 
			root->item = temp->item; 

            // Delete the inorder successor 
			root->right = delete_node(root->right, temp->item); 
		} 
	} 

    // If the tree had only one node then return 
	if (root == NULL) {
		return root; 
	}

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
	root->height = 1 + max(height(root->left), height(root->right)); 

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
	int balance = is_balanced(root); 

    // If this node becomes unbalanced, then there are 4 cases 
    // Left Left Case 
	if (balance > 1 && is_balanced(root->left) >= 0) {
		return rotate_right(root); 
	}
    // Left Right Case 
	if (balance > 1 && is_balanced(root->left) < 0) { 
		root->left =  rotate_left(root->left); 
		return rotate_right(root); 
	} 
    // Right Right Case 
	if (balance < -1 && is_balanced(root->right) <= 0) {
		return rotate_left(root); 
	}
    // Right Left Case 
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

    // bt = add(bt, i);
    // bt = search(bt, item);
    // bt = delete_node(bt, i);
    // print_tree(bt);

	return 0;
}