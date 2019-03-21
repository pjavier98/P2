#ifndef binary_tree_h
#define binary_tree_h

#include "../header.h"

typedef struct binary_tree binary_tree;

struct binary_tree {
	lli item;
	lli height;
	binary_tree *left, *right;
};

/*--------------------------------------------------------------------------*/
// Generic functions for the two trees:

/*
 * Create a binary tree and return the root 
 */
binary_tree *create_empty_binary_tree();

/*
 * @Return: the value of return is a root of alocated tree 
 */
binary_tree *create_binary_tree(lli item, binary_tree *left, binary_tree *right);

/*
 * @Return: if tree is empty
 */
int is_empty(binary_tree *bt);

/*
 * A utility function to get maximum of two integers 
 */
int max_ubt(int a, int b);

/*
 * A utility function to get the height of the tree
 */
int height(binary_tree *bt);

/*
 * Given a non-empty binary search tree, return the 
 * node with minimum key value found in that tree. 
 * Note that the entire tree does not need to be 
 * searched.
 */
binary_tree *min_value_node(binary_tree *bt);

/*
 *	Search a key in a binary tree
 */
binary_tree *search(binary_tree *bt, lli key, lli *cont);

/*
 * A utility function to print preorder traversal of 
 * the tree. 
 * The function also prints height of every node
 */
void print_tree(binary_tree *bt);

/*--------------------------------------------------------------------------*/

// Arvore de Busca Binaria Balanceada(AVL):

/*
 * Get Balance factor of node bt 
 */
int is_balanced_avl(binary_tree *bt);

/*
 * A utility function to left rotate subtree rooted with x 
 * See the diagram given above.
 */
binary_tree *rotate_left_avl(binary_tree *bt);


/*
 * A utility function to right rotate subtree rooted with y 
 * See the diagram given above. 
 */
binary_tree *rotate_right_avl(binary_tree *bt);

/*
 *	Add a node in a binary tree
 */
binary_tree *add_avl(binary_tree *bt, lli key);

/*
 * Recursive function to delete a node with given key 
 * from subtree with given root. It returns root of 
 * the modified subtree. 
 */
binary_tree *delete_node_avl(binary_tree *bt, lli key);


/*--------------------------------------------------------------------------*/

// Arvore de Busca Binaria (ABB):

/*
 * Add a node in a binary tree
 */
binary_tree *add_ubt(binary_tree *bt, lli item);

/*
 * Recursive function to delete a node with given key 
 * from subtree with given root. It returns root of 
 * the modified subtree. 
 */
binary_tree *delete_node_ubt(binary_tree *bt, lli key);

#endif
