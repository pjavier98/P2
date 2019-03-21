#include "compress.h"

UCH set_one_bit(int i, UCH byte) {
    return  (1 << i) | byte;
}

int is_bit_i_set(UCH byte, int i) {
    return (1 << i) & byte;
}

void hash_to_compressed(HASH *hashtable, FILE *original, FILE *compressed_archive, USH trash_size) {
    int i = 0;    
    UCH character;
    int hash_length = 0, bit_pos = 0, byte_compressed = 0;

    while(fscanf(original, "%c", &character) != EOF) {
        hash_length = hashtable->data[character].hash_binary[0];
        for(i = hash_length - 1; i >= 0; i--) {
            if(i > 7) {
                if(is_bit_i_set(hashtable->data[character].hash_binary[1], i % 8)) {
                    byte_compressed += 1;
                }
            } else {
                if(is_bit_i_set(hashtable->data[character].hash_binary[2], i)) {
                    byte_compressed += 1;
                }
            } if(bit_pos == 7) {
                bit_pos = -1;
                fprintf(compressed_archive, "%c", byte_compressed);
                byte_compressed = 0;
            }
            bit_pos++;
            byte_compressed <<= 1;
        }
    }
    byte_compressed >>= 1;
    byte_compressed <<= trash_size;
    fprintf(compressed_archive, "%c", byte_compressed);
}

HASH *build_hash(DATATYPE key, UCH compressed_length, HASH *hashtable, USH compress_hash_binary) {
    int i;
    for(i = 0; i < 3; i++) {
        hashtable->data[(UCH)key].hash_binary[i] = 0;
    }
    
    hashtable->data[(UCH)key].hash_binary[2] = compress_hash_binary;
    hashtable->data[(UCH)key].hash_binary[1] = compress_hash_binary >> 8;
    hashtable->data[(UCH)key].hash_binary[0] = compressed_length;
    return hashtable;
}

void tree_to_compressed(HUFF_NODE *huff_node, FILE *compressed_archive, UCH compressed_length, int *trash_size, int hash_binary, HASH *hashtable) {
    if(huff_node == NULL) {
        return;
    }
    if(is_leaf(huff_node)) {
        if(huff_node->key == '*' || huff_node->key == '\\'){
            fprintf(compressed_archive,"\\%c", huff_node->key);
        } else {
            fprintf(compressed_archive,"%c", huff_node->key);
        }
        hashtable = build_hash(huff_node->key, compressed_length, hashtable, hash_binary);
        *trash_size += (huff_node->frequency * compressed_length);
    } else { 
        fprintf(compressed_archive,"%c", huff_node->key);
    }
    hash_binary <<= 1;
    tree_to_compressed(huff_node->left, compressed_archive, compressed_length + 1, trash_size,hash_binary, hashtable);
    hash_binary++;
    tree_to_compressed(huff_node->right, compressed_archive, compressed_length + 1, trash_size,hash_binary, hashtable);
}

void tree_size_to_byte(UCH *first_bytes, FILE *compressed_archive, lli tree_size) {
    USH i, bit;

    for(i = 1, bit = 0; tree_size >= 1; bit++) {
        if(bit == 8) {
            i--;
            bit = 0;
        }
        if(tree_size % 2) {
            first_bytes[i] = set_one_bit(bit, first_bytes[i]);
        }
        tree_size /= 2;
    }

    fprintf(compressed_archive, "%c%c", first_bytes[0], first_bytes[1]);
}

void huff_tree_size(HUFF_NODE *huff_node, lli *size) {
    if (huff_node == NULL) {
        return;
    }
    if(is_leaf(huff_node) && huff_node->key == '*' || is_leaf(huff_node) && huff_node->key == '\\') {
        *size += 1;
    }
    *size += 1;
    huff_tree_size(huff_node->left, size);
    huff_tree_size(huff_node->right, size);
}

HUFF_NODE *build_tree(P_QUEUE *huff_p_queue, int (*equals)(DATATYPE, DATATYPE), void (*print)(DATATYPE)) {
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

USH read(UCH *file_path, DATA *array_frequency) {
    FILE *original = fopen(file_path, "rb");
    UCH character;
    if (original == NULL) {
        return 1;
    }
    
    while(fscanf(original, "%c", &character) != EOF) {
        array_frequency[character].frequency++;
        array_frequency[character].key = ((DATATYPE)character);
    }
    fclose(original);
    return 0;
}

DATA *create_array_frequency() {
    DATA *array_frequency = (DATA*) malloc(sizeof(DATA) * 256);
    int i;
    for (i = 0; i < 256; i++) {
        array_frequency[i].key = 0;
        array_frequency[i].frequency = 0;
    }
    return array_frequency;
}

USH compress(UCH *file_path, void (*print)(DATATYPE), int (*equals)(DATATYPE, DATATYPE)) {
    USH i;
    UCH output[100];
    P_QUEUE *huff_p_queue = create_p_queue();
    UCH compressing = 0;

    strcpy(output, file_path);
    strcat(output, ".huff");

    DATA *array_frequency = create_array_frequency();

    if (read(file_path, array_frequency)) {
        return 1;
    }
    
    for(i = 0; i < 256; i++) {
        if(array_frequency[i].frequency > 0) {
            enqueue(huff_p_queue, create_huff_node(array_frequency[i].frequency, array_frequency[i].key, NULL, NULL));
        }
    }
    
    HUFF_NODE *huff_tree;
    huff_tree = build_tree(huff_p_queue, equals, print);
    printf("Arvore construida com sucesso !!!\n");

    lli tree_size = 0;
    huff_tree_size(huff_tree, &tree_size);
    printf("Tamanho da arvore em decimal obtido com sucesso !!!\n");
    
    FILE *original, *compressed_archive;
    original = fopen(file_path, "rb");
    compressed_archive = fopen(output, "wb");

    if(original == NULL || compressed_archive == NULL) {
        return 1;
    }

    USH trash_size = 0;
    UCH first_bytes[2] = {0};
    tree_size_to_byte(first_bytes, compressed_archive, tree_size);
    printf("Tamanho da arvore em binario inserido com sucesso !!!\n");

    HASH *hashtable = create_hash_table();    
    tree_to_compressed(huff_tree, compressed_archive, 0, &trash_size, 0, hashtable);
    printf("Arvore inserida com sucesso !!!\n");

    trash_size = 8 - (trash_size % 8);

    hash_to_compressed(hashtable, original, compressed_archive, trash_size);
    rewind(compressed_archive);
    
    UCH trash_byte = trash_size;
    trash_byte = (trash_size << 5);
    first_bytes[0] |= trash_byte;
    fprintf(compressed_archive, "%c", first_bytes[0]);

    fclose(compressed_archive);
    fclose(original);
    return 0;
}