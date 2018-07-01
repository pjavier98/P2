#include <stdio.h>

void map(void (*f)(int *num), int array[5], int i)
{
	if (i == 5)
	{
		printf("\n");
		return;
	}

	(*f)(&array[i]); // chamada da função

	printf("%d ", array[i]); // tem que chamar passando o endereço logico de memoria

	map(f, array, i + 1);
}

void square(int *num)
{
	(*num) *= (*num); // atribui a posicao o valor dela vezes ela mesma
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