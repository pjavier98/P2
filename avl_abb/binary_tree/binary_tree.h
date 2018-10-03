#ifndef binary_tree_h
#define binary_tree_h

#include "../header.h"

typedef struct binary_tree binary_tree;

struct binary_tree {
	lli item;
	lli height;
	binary_tree *left, *right;
};

binary_tree *create_binary_tree(lli item, binary_tree *left, binary_tree *right);

#endif