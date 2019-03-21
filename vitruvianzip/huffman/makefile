COMPRESS = file/compress.h file/compress.c
DECOMPRESS = file/decompress.h file/decompress.c
HUFF = huff/huff_tree.h huff/huff_tree.c
P_QUEUE = p_queue/p_queue.h p_queue/p_queue.c
HASH = hash/hashtable.h hash/hashtable.c
UTILS = header/header.h 
VZIP = vitruivianzip.c
TEST = test_cunit.c


compile_tree:
	gcc $(UTILS) $(HUFF) $(P_QUEUE) $(HASH) $(COMPRESS) $(DECOMPRESS) $(VZIP) -o vzip -lm -w

compile_tests:
	gcc $(UTILS) $(HUFF) $(LIST) $(HASH) $(COMPRESS) $(DECOMPRESS) $(P_QUEUE) $(TEST) -o tests -lm -w -lcunit