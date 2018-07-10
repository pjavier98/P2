#include <stdio.h>
#include <stdlib.h>

void insertion(int *array, int size, int i, int j, int temp)
{
	if (i == size) // condição de parada
	{
		return;
	}
	
	while ((j >= 0) && (array[j] > temp)) // se o valor do array for maior que o valor do temp -> array[i + 1] ele troca os valores
	{
		array[j + 1] = array[j]; // ex: 3 2 1 // j -> 0 , i -> 1 , temp -> array[1] == 2 

		j -= 1;					// j == 0 e temp < array[0] // 3 > 2 // ele troca 
	}							
	
	if (j != i - 1) // para ele nao receber a mesmo valor 
	{
		array[j + 1] = temp;
	}

	insertion(array, size, i + 1, i, array[i + 1]); // i == 2, j == 1 (quem o i era antes da recursao) e array[0 + i] e i == 1, logo array[1]
}

int main()
{
	int size, i;
	printf("Digite a quantidade de elementos do array: ");
	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));
	printf("Digite os elementos do array(total = %d):\n", size);

	for (i = 0; i < size; i += 1)
	{
		scanf("%d", &array[i]);
	}

	insertion(array, size, 1, 0, array[1]);

	for (i = 0; i < size; i += 1)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}