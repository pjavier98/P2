#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
	int temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void comparar(int quant, int *array, int i, int j)
{
	if (quant == i)
	{
	    return;
	}

	if (j < quant)
	{
		if (array[i] > array[j])
		{
			troca(&array[i], &array[j]); // array crescente
		}

		comparar(quant, array, i, j + 1);
		
		return;
	}

	comparar(quant, array, i + 1, j = i + 1);
}

int main()
{
	int quantidade, i;

	printf("Digite o tamanho do array:\n");
	scanf("%d", &quantidade);

	int *array = malloc(quantidade * sizeof(int));

	printf("Digite os elementos do array(total = %d)\n", quantidade);

	for (i = 0; i < quantidade; i += 1)
	{
		scanf("%d", &array[i]);
	}

	comparar(quantidade, array, 0, 1);
    
    for (i = 0; i < quantidade; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}