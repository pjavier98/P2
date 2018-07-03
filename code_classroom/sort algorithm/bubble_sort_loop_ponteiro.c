#include <stdio.h>
#include <stdlib.h>

void comparar(int quant, int *array)
{	
	int i, j, temp;
	
	for (i = 0; i < quant; i += 1)
	{
		
		for (j = i + 1; j < quant; j += 1)
		{
			if (array[i] > array[j]) // array crescente
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
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

	comparar(quantidade, array);
    
    for (i = 0; i < quantidade; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}