#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int size, int element, int *cont)
{	
	int i; // middle
	int begin = 0;
	int end = size;

	while (begin <= end)
	{
		i = (begin + end) / 2;

		*cont += 1;

		if (array[i] > element)
		{
			end = i - 1;
		}

		else if (array[i] < element)
		{
			begin = i + 1;
		}

		else
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int size, element, i;
	int cont = 0;

	printf("Digite o tamanho do array: ");
	scanf("%d", &size);

	printf("Digite o elemento a buscar no array: ");
	scanf("%d", &element);

	int *array = malloc(size * sizeof(int)); // o array precisa estar ordenado
	printf("Digite os elementos do array(total = %d): ", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]); // le e insere os numeros no array
	}

	int posicao = binary_search(array, size, element, &cont);

	if (posicao == -1)
	{
		printf("O elemento procurado nao esta no array\n");
	}

	else
	{
		printf("Casa: %d\n", posicao + 1); // posicao do array que se encontra o elemento procurado
		printf("Custo(tempo): %d\n", cont);
	}



	return 0;
}