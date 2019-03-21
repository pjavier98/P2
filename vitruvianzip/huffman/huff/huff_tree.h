#ifndef huff_tree_h
#define huff_tree_h

#include "../header/header.h"
typedef struct huff_node HUFF_NODE;
#include "../p_queue/p_queue.h"

struct huff_node {
	lli frequency;
	DATATYPE key;
	HUFF_NODE *left, *right;
};

USH is_leaf(HUFF_NODE *huff_tree);
/*
 *
 */

HUFF_NODE *create_empty_huff_node();
/*
 *
 */

HUFF_NODE *create_huff_node(lli frequency, DATATYPE key, HUFF_NODE *left, HUFF_NODE *right);
/*
 *
 */

void print_huff_tree(HUFF_NODE *huff_node);
/*
 *
 */

#endif