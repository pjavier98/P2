#include "decompress.h"

HUFF_NODE *building_tree(HUFF_NODE *huff_tree, FILE *compress_archive) {
    UCH character;
    fscanf(compress_archive, "%c", &character);
    if(character == '*') {
        huff_tree = create_huff_node(0,character, NULL, NULL);
        huff_tree->left = building_tree(huff_tree->left, compress_archive);
        huff_tree->right = building_tree(huff_tree->right, compress_archive);

    } else {
        if(character == '\\')
        {
            fscanf(compress_archive, "%c", &character);
        }
        huff_tree = create_huff_node(0, character, NULL, NULL);
    }
    return huff_tree;
}

USH decompress(UCH *file_archive) {
    FILE *compress_archive = fopen(file_archive,"rb");

    if (compress_archive == NULL) {
        return 1;
    }

    UCH character;
    USH trash_size, tree_size;
    lli file_size = 0;
    int i;

    fscanf(compress_archive, "%c", &character);

    trash_size = character >> 5;  
    tree_size = character << 11; 
    tree_size >>= 3;
    
    fscanf(compress_archive, "%c", &character);
    tree_size |= character;

    HUFF_NODE *huff_tree = building_tree(huff_tree, compress_archive);
    HUFF_NODE *huff_tree_aux = huff_tree;
    printf("Arvore construida com sucesso !!!\n");

    char file_out[100];
    int size = strlen(file_archive);
    
    for(i = 0; i < size - 5; i++) {
        file_out[i] = file_archive[i];
    }
    file_out[i] = '\0';

    //fseeko(compress_archive, 0, SEEK_END);
    //file_size = ftello(compress_archive);
    while(fscanf(compress_archive, "%c", &character) != EOF) {
        file_size++;
    }
    fseeko(compress_archive, 2 + tree_size, SEEK_SET);
    FILE *decompress_archive = fopen(file_out, "wb");

    while(file_size > 0) {

        fscanf(compress_archive, "%c", &character);
        if(file_size != 1)
        {
            for(i = 7; i >= 0; i --) {  
                if(is_bit_i_set(character,i)) {
                    huff_tree_aux = huff_tree_aux->right;
                } else {
                    huff_tree_aux = huff_tree_aux->left;
                }
                if(is_leaf(huff_tree_aux)) {

                    fprintf(decompress_archive, "%c", huff_tree_aux->key);
                    huff_tree_aux = huff_tree;
                }
            }
        } else {
            for(i = 7; i >= trash_size; i--) {  
                if(is_bit_i_set(character,i)) {
                    huff_tree_aux = huff_tree_aux->right;
                } else {
                    huff_tree_aux = huff_tree_aux->left;
                } 
                if(is_leaf(huff_tree_aux)) {
                    fprintf(decompress_archive, "%c", huff_tree_aux->key);
                    huff_tree_aux = huff_tree;
                }
            }
        }
        file_size --;
    }
    fclose(compress_archive);
    fclose(decompress_archive);
    return 0;
}
