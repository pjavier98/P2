#include <stdio.h>
#include <stdlib.h>

void comparar(int size, int *array)
{	
	int i, j, temp, k;
	
	for (i = size - 1; i >= 0; i -= 1)
	{
		for (j = 0; j < i; j += 1)
		{
			if (array[j] > array[j + 1]) // array crescente
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

		/*for (k = 0; k < size; k += 1) // para ver como vai se dando a ordenação
		{								 // sempre ficando menos um a cada loop
			printf("%d ", array[k]);
		}

		printf("\n");*/
	}
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

	comparar(size, array);

	for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}