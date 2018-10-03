#ifndef avl_h
#define avl_h

#include "../header.h"
#include "../binary_tree/binary_tree.h"
/*
 * return: o valor de retorno é uma raiz de árvore alocada
 */

binary_tree *create_empty_binary_tree();
/*
 * cria uma arvore binaria e retorna a raiz da arvore
 */

binary_tree *rotate_left(binary_tree *root);
/*
 *
 */

binary_tree *rotate_right(binary_tree *root);
/*
 *
 */

binary_tree *add(binary_tree *root, lli key);
/*
 *
 */

binary_tree *search(binary_tree *root, lli key);
/*
 *
 */

binary_tree *min_value_node(binary_tree *root);
/*
 *
 */


binary_tree *delete_node(binary_tree *root, lli key);
/*
 *
 */

int is_empty(binary_tree *root);
/*
 *
 */

int height(binary_tree *root);
/*
 *
 */

int is_balanced(binary_tree *root);
/*
 *
 */

void print_tree(binary_tree *root);
/*
 *
 */

#endif