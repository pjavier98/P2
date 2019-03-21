#include <stdio.h>
#include <stdlib.h>

void insertion(int *array, int size)
{
	int i, j, atual;

	for (i = 1; i < size; i++) 
	{
		atual = array[i];
		
		for (j = i - 1; (j >= 0) && (atual < array[j]); j--)
		{
			array[j + 1] = array[j];
		}

		array[j+1] = atual;
	}
}

int main()
{
	int size, i;
	
	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));
	
	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]);
	}

	insertion(array, size);

	for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}