#include <stdio.h>
#include <stdlib.h>

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

    for(int i = left; i <= right; i += 1, temp += 1) 
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
    int size, i;

    scanf("%d", &size);

    int *array = malloc(size * sizeof(int));
    int *aux = malloc(size * sizeof(int));

    for (i = 0; i < size; i += 1)
    {
        scanf("%d", &array[i]);
    }

    merge_sort(array, 0, size - 1, aux);

    for (i = 0; i < size; i += 1)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}