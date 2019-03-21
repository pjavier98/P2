#ifndef decompress_h
#define decompress_h

#include "../header/header.h"
#include "../huff/huff_tree.h"

/*
 *
 */
HUFF_NODE *building_tree(HUFF_NODE *huff_tree, FILE *compress_archive);

/*
 *
 */
USH decompress(UCH *file_path);

#endif