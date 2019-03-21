#ifndef compress_h
#define compress_h

#include "../header/header.h"
#include "../p_queue/p_queue.h"
#include "../hash/hashtable.h"

typedef struct data DATA;

struct data {
	lli frequency;
	DATATYPE key;
};

/*
 * set_one_bit: set a bit int "i" position
 * @param: i -> the bit will be set
 * @param: b -> the byte will be bit set
 * @return: a byte with the bit "i" will be set
 */
UCH set_one_bit(int i, UCH byte);

/*
 *
 */
int is_bit_i_set(UCH byte, int i);

/*
 *
 */
HUFF_NODE *build_tree(P_QUEUE *huff_p_queue, int (*equals)(DATATYPE, DATATYPE), void (*print)(DATATYPE));

/*
 *
 */
void tree_to_compressed(HUFF_NODE *huff_node, FILE *compressed_archive, UCH compressed_length, int *trash_size, int binary, HASH *hashtable);

/*
 *
 */
HASH *build_hash(DATATYPE key, UCH compressed_length, HASH *hashtable, USH compress_binary);

/*
 *
 */
void tree_size_to_byte(UCH *first_bytes, FILE *compressed_archive, lli tree_size);

/*
 *
 */
void hash_to_compressed(HASH *hashtable, FILE *original, FILE *compressed_archive, USH trash_size);

/*
 *
 */
void huff_tree_size(HUFF_NODE *huff_node, lli *size);

/*
 *
 */
USH read(UCH *file_path, DATA *array_frequency);

/*
 *
 */
DATA *create_array_frequency();

/*
 *
 */
USH compress(UCH *file_path, void (*print)(DATATYPE), int (*equals)(DATATYPE, DATATYPE));

#endif