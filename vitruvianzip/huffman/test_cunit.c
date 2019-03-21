#include "huff/huff_tree.h"
#include "hash/hashtable.h"
#include "p_queue/p_queue.h"
#include "file/compress.h"
#include "file/decompress.h"
#include "header/header.h"
#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"

int init_suite(void) {
	return 0;
}

int clear_suite(void) {
	return 0;
}

int equals(DATATYPE d1, DATATYPE d2) {
	UCH x, y;
	x = ((UCH)d1);
	y = ((UCH)d2);
	return x == y;
}

void print(DATATYPE d) {
	UCH x = d;
	printf("%c", x);
}

void hash_tests() {
	HASH *hashtable = NULL;
	CU_ASSERT(hashtable == NULL);
	hashtable = create_hash_table();
	CU_ASSERT(hashtable != NULL);
}

void generate_tree_test_string(HUFF_NODE *huff_node, char *string, int *size) {
	if(huff_node == NULL) {
		string[*size] = '\0';
		return;
	} else {
		if(is_leaf(huff_node)) {
			string[*size] = huff_node->key;
			*size += 1;
		}
		generate_tree_test_string(huff_node->left,string,size);		
		generate_tree_test_string(huff_node->right,string,size);
	}
}

HUFF_NODE *build_tree_test(P_QUEUE *huff_p_queue, int (*equals)(DATATYPE, DATATYPE), void (*print)(DATATYPE)) {
    if(huff_p_queue->size == 1) {
        NODE *aux1 = dequeue(huff_p_queue, huff_p_queue->head->value->key, equals);
        lli frequency = aux1->value->frequency;
        UCH id_dad = '*';
        enqueue(huff_p_queue, create_huff_node(frequency, id_dad, aux1->value, NULL));
    } while(huff_p_queue->size > 1) {
        NODE *aux1 = dequeue(huff_p_queue, huff_p_queue->head->value->key, equals);
        NODE *aux2 = dequeue(huff_p_queue, huff_p_queue->head->value->key, equals);       
        lli frequency = aux1->value->frequency+aux2->value->frequency;
        UCH id_dad = '*';
        enqueue(huff_p_queue, create_huff_node(frequency, id_dad, aux1->value, aux2->value));
    }
    return huff_p_queue->head->value;
}

void huff_tree_tests(){
	P_QUEUE *p_queue = create_p_queue();
	char string_test[10], string_compare[10];
	int i, size = 0;
	HUFF_NODE *huff_node = create_empty_huff_node();

	huff_node = create_huff_node(5, 'a', NULL, NULL);
	enqueue(p_queue,huff_node);
	huff_node = create_huff_node(2, 'b', NULL, NULL);
	enqueue(p_queue,huff_node);
	huff_node = create_huff_node(1, 'c', NULL, NULL);
	enqueue(p_queue,huff_node);
	huff_node = create_huff_node(3, 'd', NULL, NULL);
	enqueue(p_queue,huff_node);

	for(i = 0; i < 10; i++) {
		string_test[i] = '0';
		string_compare[i] = '0';
	}
	huff_node = build_tree_test(p_queue, equals, print);

	string_compare[0] = 'a';
	string_compare[1] = 'c';
	string_compare[2] = 'b';
	string_compare[3] = 'd';
	string_compare[4] = '\0';

	generate_tree_test_string(huff_node, string_test, &size);
	CU_ASSERT(strcmp(string_test,string_compare) == 0);
}

void p_queue_tests() {
	P_QUEUE *p_queue = create_p_queue();
	HUFF_NODE *node = create_empty_huff_node();

	//testando create_p_queue
	CU_ASSERT(p_queue != NULL);
	CU_ASSERT(p_queue->head == NULL);
	CU_ASSERT(!p_queue->size);

	//testando p_queue_is_empty
	CU_ASSERT(p_queue_is_empty(p_queue));

	//testando enqueue
	node = create_huff_node(5, 'a', NULL, NULL);
	enqueue(p_queue,node);
	node = create_huff_node(2, 'b', NULL, NULL);
	enqueue(p_queue,node);
	node = create_huff_node(1, 'c', NULL, NULL);
	enqueue(p_queue,node);
	node = create_huff_node(3, 'd', NULL, NULL);
	enqueue(p_queue,node);
	node = create_huff_node(1, 'e', NULL, NULL);
	enqueue(p_queue,node);
	CU_ASSERT(p_queue->head->value->key == 'e');
	CU_ASSERT(p_queue->head->value->frequency == 1);
	CU_ASSERT(p_queue->head->next->value->key == 'c');
	CU_ASSERT(p_queue->head->next->value->frequency == 1);

	//testando dequeue
	NODE *node_teste = dequeue(p_queue, 'a', equals);
	CU_ASSERT(node_teste->value->key == 'a');
	CU_ASSERT(node_teste->value->frequency == 5);
	node_teste = dequeue(p_queue,'e',equals);
	CU_ASSERT(node_teste->value->frequency == 1);
	CU_ASSERT(node_teste->value->key == 'e');
	CU_ASSERT(p_queue->head->value->key == 'c');
	node = create_huff_node(5, 'a', NULL, NULL);
	enqueue(p_queue, node);
}

int run_tests() {
	p_queue_tests();
	huff_tree_tests();
	hash_tests();
}

int main(void) {
	
	CU_pSuite pSuite = NULL;

	if(CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Basic_Test_Suite", init_suite, clear_suite);
	if(pSuite == NULL){
		return CU_get_error();
	}

	if(NULL == CU_add_test(pSuite, "p_queue_tests", p_queue_tests)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if(NULL == CU_add_test(pSuite, "huff_tree_tests", huff_tree_tests)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if(NULL == CU_add_test(pSuite, "hash_tests", hash_tests)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}