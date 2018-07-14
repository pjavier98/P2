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

void comparar(int *array, int size, int i, int j, int menor)
{
	if (i == size)
	{
		return;
	}

	
	if (j == size)
	{
		/*for (int k = 0; k < size; k += 1)    // para ver como vai se dando a ordenação
		{								 // sempre ficando menos um a cada loop
			printf("%d ", array[k]);
		}
		printf("\n");*/

		return comparar(array, size, i + 1, i + 1, menor);
	}

	menor = i;

	if (array[menor] > array[j])
	{
		menor = j;

		troca(&array[i], &array[menor]);
	}

	comparar(array, size, i, j + 1, menor);

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

	comparar(array, size, 0, 1, 0);

	for (i = 0; i < size; i += 1)    
	{								
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}