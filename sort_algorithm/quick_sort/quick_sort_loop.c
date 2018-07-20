#include <stdio.h>
#include <stdlib.h>

void quick(int *array, int begin, int end)
{
	int right = end - 1;
	int left = begin;
	int mid = (begin + end) / 2;
	int pivo = array[mid];

	while(left <= right)
	{
		while(left < end && array[left] < pivo)
		{
			left++;
		}

		while(right > begin && array[right] > pivo)
		{
			right--;
		}

		if (right >= left)
		{
			int temp = array[left];		
			array[left] = array[right];	
			array[right] = temp;

			left++;
			right--;
		}
	}

	if (begin < right)
	{
		quick(array, begin, right + 1);
	}

	if (end > left)
	{
		quick(array, left, end);
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

	quick(array, 0, size);

	for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}