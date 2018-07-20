#include <stdio.h>
#include <stdlib.h>

void insertion(int *array, int size, int i, int j, int temp)
{
	if (i == size) 
	{
		return;
	}
	
	while ((j >= 0) && (array[j] > temp)) 
	{
		array[j + 1] = array[j]; 

		j -= 1;					
	}							
	
	if (j != i - 1) 
	{
		array[j + 1] = temp;
	}

	insertion(array, size, i + 1, i, array[i + 1]); 
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

	insertion(array, size, 1, 0, array[1]);

	for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}