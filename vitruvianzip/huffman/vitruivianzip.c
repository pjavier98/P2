#include "header/header.h"
#include "p_queue/p_queue.h"
#include "file/decompress.h"
#include "file/compress.h"

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

int main() {
	UCH file_path[100];
	USH value = 1;
	printf("##############################\n");
	printf("| BEM VINDO AO VITRUIVIANZIP |\n");
	printf("##############################\n");
	while(value != 0) {
		printf("Digite a opcao desejada:\n[ 1 ] compress file\n[ 2 ] print bits from file\n[ 3 ] decompress file\n[ 0 ] exit\n=> ");
		scanf("%d", &value);

		if (value == 1) {
			printf("Digite o nome do arquivo que deseja comprimir: ");
			scanf(" %[^\n]s", file_path);
			if(!compress(file_path, print, equals)) {
				printf("Arquivo comprimido com sucesso !!!\n");
			} else {
				printf("Erro ao abrir arquivo\n");
			}
		} else if (value == 2) {
			printf("Digite o nome do arquivo que deseja ver o binario: ");
			scanf(" %[^\n]s", file_path);
			FILE *compress_archive = fopen(file_path, "rb");
			UCH byte_compressed;
			while(fscanf(compress_archive, "%c", &byte_compressed) != EOF) {
				for(int i = 7; i >= 0; i--) {
					if(is_bit_i_set(byte_compressed, i)) {
						printf("1");
					} else {
						printf("0");
					}
				}
				printf("|");
				byte_compressed = 0;	
			}
			printf("\n");
			fclose(compress_archive);
		} else if (value == 3) {
			printf("Digite o nome do arquivo que deseja descomprimir: ");
			scanf(" %[^\n]s", file_path);
			if(!decompress(file_path)) {
				printf("Arquivo descomprimido com sucesso !!!\n");
			} else {
				printf("Erro ao abrir arquivo\n");
			}
		}
		printf("\n");
	}
	return 0;
}
