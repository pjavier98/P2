#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
	int temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void comparar(int quant, int *array, int i, int j)
{
	//int k;

	if (i == 0)
	{
	    return;
	}

	if (j < quant)
	{
		if (array[j] > array[j + 1])
		{
			troca(&array[j], &array[j + 1]); // array crescente
		}

		return comparar(quant, array, i, j + 1);
	}

	/*for (k = 0; k < quant; k += 1) // para ver como vai se dando a ordenação
	{							   // sempre ficando menos um a cada loop
		printf("%d ", array[k]);
	}

	printf("\n");*/

	comparar(quant, array, i - 1, 0);
}

int main()
{
	int quantidade, i;

	printf("Digite o tamanho do array:\n");
	scanf("%d", &quantidade);

	int *array = malloc(quantidade * sizeof(int));

	printf("Digite os elementos do array(total = %d)\n", quantidade);

	for (i = 0; i < quantidade; i += 1)
	{
		scanf("%d", &array[i]);
	}

	comparar(quantidade, array, quantidade - 1, 0);
    
    for (i = 0; i < quantidade; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}