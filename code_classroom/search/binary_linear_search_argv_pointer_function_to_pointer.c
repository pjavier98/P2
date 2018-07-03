#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binary_search(int *array, int size, int element, int *cont)
{
	int middle; // middle
	int begin = 0;
	int end = size;

	while (begin <= end)
	{
		*cont += 1;

		middle = (begin + end) / 2;

		if (array[middle] > element)
		{
			end = middle - 1;
		}

		else if (array[middle] < element)
		{
			begin = middle + 1;
		}

		else
		{
			return middle;
		}
	}

	return -1;
}

int linear_search(int *array, int size, int element, int *cont)
{
	int linha;

	for (linha = 0; linha < size; linha += 1)
	{
		*cont += 1;

		if (array[linha] == element)
		{
			return linha;
		}
	}

	return -1;
}

void search(int (*f)(int *, int, int, int *), int *array, int size, int element, int cont) // quatro coisas apos (*f) para ele poder apontar para uma funcao que tem 4 inteiros incluindo dois ponteiros
{	
	int posicao = (*f)(array, size, element, &cont);

	if (posicao == -1)
	{
		printf("O elemento procurado nao esta no array\n");
		return;
	}

	else
	{
		printf("Casa: %d\n", posicao + 1); // posicao do array que se encontra o elemento procurado
		printf("Custo(tempo): %d\n", cont);
		return;
	}
}

int main(int argc, char const *argv[])
{	
	/*
		int / float v[] = { 1, 2, 3, 4,...,15};

		int t = sizeof(v) / sizeof(v[0]);

		usado quando o array é definido dessa forma, ele calcula a quantidade
	*/

	int size, element, i;
	int cont = 0;

	printf("Digite o tamanho do array: ");
	scanf("%d", &size);


	int *array = malloc(size * sizeof(int)); // o array precisa estar ordenado
	printf("Digite os elementos do array(total = %d): ", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]); // le e insere os numeros no array
	}

	printf("Digite o elemento a buscar no array: ");
	scanf("%d", &element);

	if (strcmp(argv[1], "compare") == 0)
	{
		printf("Linear search:\n");
		search(linear_search, array, size, element, 0);

		printf("Binary search:\n");
		search(binary_search, array, size, element, 0);
	}

	else if(strcmp(argv[1], "linear") == 0)
	{
		printf("Linear search:\n");
		search(linear_search, array, size, element, 0);
	}

	else if(strcmp(argv[1], "binary") == 0)
	{
		printf("Binary search:\n");
		search(binary_search, array, size, element, 0);
	}

	/*if (strcmp(argv[2], "compare") == 0)
	{
		printf("Linear search:\n");
		search(linear_search, array, size, element, 0);

		printf("Binary search:\n");
		search(binary_search, array, size, element, 0);
	}

	else if(strcmp(argv[2], "linear") == 0)
	{
		printf("Linear search:\n");
		search(linear_search, array, size, element, 0);
	}

	else if(strcmp(argv[2], "binary") == 0)
	{
		printf("Binary search:\n");
		search(binary_search, array, size, element, 0);
	}*/

	/*argv[x] x -> o x é a string apos o executavel, o argc conta quantos elementos tem apos o executavel

	argv -> pega o/s argumento/s apos o executavel*/

	return 0;
}