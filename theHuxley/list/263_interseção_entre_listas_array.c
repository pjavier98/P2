#include <stdio.h>
#include <stdlib.h>

void binary_search(int *array, int size, int element, int *cont)
{   
    int i; // middle
    int begin = 0;
    int end = size;

    while (begin <= end)
    {
        i = (begin + end) / 2;

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
            printf("%d\n", array[i]);
            *cont += 1;
            return;
        }
    }

    if (begin > end)
    {
        return;
    }
}

void merge(int *array, int begin_1, int end_1, int begin_2, int end_2, int *aux)
{
    int temp = 0;
    int left = begin_1;
    int right = end_2;

    while(begin_1 <= end_1 || begin_2 <= end_2)
    {
        if(begin_1 > end_1)
        {
            while(begin_2 <= end_2) // lista 1 acabou
            {
                aux[temp] = array[begin_2];
                temp += 1;
                begin_2 += 1;
            }
        }
        else if(begin_2 > end_2) // lista 2 acabou
        {
            while(begin_1 <= end_1)
            {
                aux[temp] = array[begin_1];
                temp += 1;
                begin_1 += 1;
            }
        }

        else // as listas nao acabaram
        {
            if(array[begin_1] < array[begin_2])
            {
                aux[temp] = array[begin_1];
                temp += 1;
                begin_1 += 1;
            }

            else 
            {
                aux[temp] = array[begin_2];
                temp += 1;
                begin_2 += 1;
            } 
        }
    }

    temp = 0;
    int i;
    for(i = left; i <= right; i += 1, temp += 1) 
    {
        array[i] = aux[temp];
        // i += 1
        // temp += 1
    }
}

void merge_sort(int *array, int begin, int end, int *aux)
{
    if (begin == end)
    {
        return;
    }

    int mid = (begin + end) / 2;

    merge_sort(array, begin, mid, aux); 
    merge_sort(array, mid + 1, end, aux); 
    merge(array, begin, mid, mid + 1, end, aux);
}

int main()
{
    int i;
    int *array_1 = malloc(20 * sizeof(int));
    int *array_2 = malloc(20 * sizeof(int));
    int *aux_1 = malloc(20 * sizeof(int));
    int *aux_2 = malloc(20 * sizeof(int));

    for (i = 0; i < 20; i += 1)
    {
        scanf("%d", &array_1[i]);
    }

    merge_sort(array_1, 0, 20 - 1, aux_1);

    for (i = 0; i < 20; i += 1)
    {
        scanf("%d", &array_2[i]);
    }
    
    merge_sort(array_2, 0, 20 - 1, aux_2);
    
    int cont = 0;
    
    for (i = 0; i < 20; i += 1)
    {
        if (array_2[i] != array_2[i + 1])
        {
            binary_search(array_1, 20, array_2[i], &cont);
        }
    }
    
    if (cont == 0)
    {
        printf("VAZIO");
    }

    printf("\n");

    return 0;
}