#include "hashtable.h"

HASH *create_hash_table() {
	HASH *hashtable = (HASH*) malloc(sizeof(HASH));
	return hashtable;
}