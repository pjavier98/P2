#ifndef hashtable_h
#define hashtable_h

#include "../header/header.h"

typedef struct hash HASH;
typedef struct table TABLE;

struct table {
	DATATYPE hash_binary[3];
};

struct hash {
	TABLE data[256];
};

/*
 *
 */
HASH *create_hash_table();


#endif