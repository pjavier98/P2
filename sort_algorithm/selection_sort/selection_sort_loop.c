#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size, i, j, temp, menor;

	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));
	
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
	}

	for (i = 0; i < size; i += 1)    
	{								
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}