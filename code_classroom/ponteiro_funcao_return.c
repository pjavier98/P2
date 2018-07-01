#include <stdio.h>

void map(int (*f)(int num), int array[5], int i)
{
	if (i == 5)
	{
		return;
	}

	printf("%d ", (*f)(array[i]));

	map(f, array, i + 1);
}

int square(int num)
{
	return num * num;
}

int main()
{
	int i;
	int array[5];

	for (i = 0; i < 5; i += 1)
	{
		scanf("%d", &array[i]);
	}
	
	map(square, array, 0);

	return 0;
}