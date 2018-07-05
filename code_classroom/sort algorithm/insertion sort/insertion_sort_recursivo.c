#include <stdio.h>
#include <stdlib.h>

void insertion(int *array, int size, int i, int j, int temp)
{
	printf("%d\n", temp);
	if (i == size)
	{
		return;
	}

	if ((j >= 0) && (array[j] > temp))
	{
		array[j + 1] = array[j];

		insertion(array, size, i, j - 1, temp);
	}
	
	array[j + 1] = temp;

	insertion(array, size, i + 1, i, array[i]);
}

int main()
{
	int size, i;
	printf("Digite a quantidade de elementos do array: ");
	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));
	printf("Digite os elementos do array(total = %d):\n", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]);
		//printf("%d ", array[i]);
	}

	//printf("\n");

	insertion(array, size, 1, 0, array[1]);

	for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	return 0;
}