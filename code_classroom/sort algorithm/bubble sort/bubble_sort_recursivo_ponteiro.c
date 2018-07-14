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

void comparar(int size, int *array, int i, int j)
{
	if (i == 0)
	{
	    return;
	}

	if (j < size)
	{
		if (array[j] > array[j + 1])
		{
			troca(&array[j], &array[j + 1]); // array crescente
		}

		return comparar(size, array, i, j + 1);
	}

	/*for (int k = 0; k < size; k += 1) // para ver como vai se dando a ordenação
	{							   // sempre ficando menos um a cada loop
		printf("%d ", array[k]);
	}

	printf("\n");*/

	comparar(size, array, i - 1, 0);
}

int main()
{
	int size, i;

	printf("Digite o tamanho do array:\n");
	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));

	printf("Digite os elementos do array(total = %d)\n", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]);
	}

	comparar(size, array, size - 1, 0);
    
    for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}