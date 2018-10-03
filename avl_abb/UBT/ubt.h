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

binary_tree *add(binary_tree *bt, lli item);
/*
 *
 */

binary_tree *search(binary_tree *bt, lli item);
/*
 *
 */

binary_tree *min_value_node(binary_tree *node);
/*
 *
 */

binary_tree *delete_node(binary_tree *bt, lli key);
/*
 *
 */

int max(int a, int b);
/*
 *
 */

int is_empty(binary_tree *bt);
/*
 *
 */

int height(binary_tree *bt);
/*
 *
 */

void print_tree(binary_tree *bt);
/*
 *
 */

#endif