#include "binary_tree/binary_tree.h"

void gerate_cases() {
	lli size;
	lli random_number;
	lli i;
	printf("Insira a quantidade de elementos a inserir nas arvores:\n");
	scanf("%lld", &size);

	binary_tree *bt_ubt = create_empty_binary_tree();
	binary_tree *bt_avl = create_empty_binary_tree();

	FILE *avl_ubt_out = fopen("R_graphics/avl_ubt_out", "w");

	fprintf(avl_ubt_out, "value avl abb\n");

	printf("Iniciando a adição nas arvores !!!\n");
	for (i = 1; i <= size; i++) {
		bt_avl = add_avl(bt_avl, i);
		bt_ubt = add_ubt(bt_ubt, i);
	}

	lli cont_avl = 0;
	lli cont_ubt = 0;

	printf("Iniciando a busca nas arvores !!!\n");
	for(i = 1; i <= size; i++) {
		search(bt_avl, i, &cont_avl);
		search(bt_ubt, i, &cont_ubt);

		fprintf(avl_ubt_out, "%lld %lld %lld\n", i, cont_avl, cont_ubt);
		
		cont_avl = 0;
		cont_ubt = 0;
	}

	fclose(avl_ubt_out);
}

int main() {
	gerate_cases();
    printf("Operações concluidas com sucesso !!!\n");
	return 0;
}
