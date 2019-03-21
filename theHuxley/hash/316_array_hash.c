#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculo_hash(int size, char *alfabeto, int i, int cont, int entrada)
{
    if (i == size)
    {
        return cont;
    }
    cont += (alfabeto[i] - 'A') + entrada + i;
    
    calculo_hash(size, alfabeto, i + 1, cont, entrada);
}

int main()
{
    int quant, i, j;
    int entrada = 0;
    int acumulador;
    char alfabeto[50];

    scanf("%d", &quant);

    for (i = 0; i < quant; i += 1)
    {
        int rep;

        scanf("%d", &rep);

        for (j = 0; j < rep; j += 1)
        {
            scanf("%s", alfabeto);
            //printf("%s", alfabeto);
            int size = strlen(alfabeto);
            
            acumulador += calculo_hash(size, alfabeto, 0, 0, entrada);
            entrada += 1;
        }
        printf("%d\n", acumulador);
        acumulador = 0;
        entrada = 0;
    }
    
    return 0;
}