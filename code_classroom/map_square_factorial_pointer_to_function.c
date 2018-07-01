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

int factorial(int num)
{
	if (num == 1)
	{
		return 1;
	}

	return num * factorial(num - 1);
}

int main()
{
	int i;
	int array[5];

	for (i = 0; i < 5; i += 1)
	{
		scanf("%d", &array[i]);
	}
	
	printf("Square: ");
	map(square, array, 0);
	printf("\n");
	printf("Factorial: ");
	map(factorial, array, 0);
	printf("\n");
	return 0;
}