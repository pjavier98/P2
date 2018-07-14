#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size, i, j, temp, menor;

	printf("Digite o tamanho do array:\n");
	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));
	printf("Digite os elementos do array(total = %d)\n", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]);
	}

	for (i = 0; i < size; i += 1)
	{
		menor = i;

		for(j = i + 1; j < size; j += 1)
		{
			if (array[menor] > array[j])
			{
				menor = j;

				temp = array[menor];
				array[menor] = array[i];
				array[i] = temp;
			}
		}

		/*for (int k = 0; k < size; k += 1)    // para ver como vai se dando a ordenação
		{								 // sempre ficando menos um a cada loop
			printf("%d ", array[k]);
		}
		printf("\n");*/
	}

	for (i = 0; i < size; i += 1)    
	{								
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}