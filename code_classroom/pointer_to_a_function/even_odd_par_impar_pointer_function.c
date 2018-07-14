#include <stdio.h>

void filter(int (*f)(int), int array[5], int i) // o nome de chamada pra funcao independe
{
	if (i == 5)
	{
		return;
	}

	if ((*f)(array[i]) == 1) // se a condicao no return for verdadeira ele passa 1, senao 0
	{
		printf("%d ", array[i]);
	}

	filter(f, array, i + 1);
}

int even(int par) // pares
{
	return par % 2 == 0; // passa o valor direto, evitando um bad smell
}

int odd(int impar) // impares
{
	return impar % 2 != 0; // passa o valor direto, evitando um bad smell
}

int main()
{
	int i;
	int array[5];

	for (i = 0; i < 5; i += 1)
	{
		scanf("%d", &array[i]);
	}
	printf("Pares: ");
	filter(even, array, 0); // chama a funcao filter e a even que calcula e printa os numeros pares
	printf("\n");
	printf("Impares: ");
	filter(odd, array, 0); // chama a funcao filter e a odd que calcula e printa os numeros impares
	printf("\n");
	return 0;
}