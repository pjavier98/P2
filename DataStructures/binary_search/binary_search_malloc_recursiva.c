#include <stdio.h>
#include <stdlib.h>

void binary_search(int *array, int element, int begin, int end, int middle, int cont)
{	
	if (array[middle] == element)
	{
		printf("Casa: %d\n", middle + 1); // posicao do array que se encontra o elemento procurado
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

		if (array[middle] < element) 
		{
			return binary_search(array, element, middle + 1, end, (begin + end) / 2 , cont);
		}

		else if ((array[middle] > element))
		{
			return binary_search(array, element, begin, middle - 1, (begin + end) / 2, cont);
		}
	}
}

int main()
{
	int size, element, i;

	printf("Digite o tamanho do array: ");
	scanf("%d", &size);


	int *array = malloc(size * sizeof(int)); // o array precisa estar ordenado
	printf("Digite os elementos do array(total = %d): ", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]); // le e insere os numeros no array
	}

	while(1)
	{
		printf("Digite o elemento a buscar no array: ");
		scanf("%d", &element);
		
		binary_search(array, element, 0, size - 1, size / 2, 1);
	}

	return 0;
}