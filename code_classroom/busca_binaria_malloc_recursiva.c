#include <stdio.h>
#include <stdlib.h>

void binary_search(int *array, int size, int element, int begin, int end, int i, int cont)
{	
	if (array[i] == element) // i -> middle
	{
		printf("Casa: %d\n", i + 1); // posicao do array que se encontra o elemento procurado
		printf("Custo(tempo): %d\n", cont);
		return;
	}

	if (begin > end)
	{
		printf("O elemento procurado nao esta no array\n");
		return;
	}

	else
	{
		cont += 1; // contador para a o "tempo" que vai ser gasto

		if (array[i] < element) 
		{
			return binary_search(array, size, element, i + 1, end, (i + 1) + end, cont);
		}

		else if ((array[i] > element))
		{
			return binary_search(array, size, element, begin, i - 1, begin + (i - 1), cont);
		}
	}
}

int main()
{
	int size, element, i;

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

	binary_search(array, size, element, 0, size - 1, size / 2, 1);

	return 0;
}