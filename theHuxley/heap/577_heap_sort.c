#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 500

typedef struct heap heap;

struct heap
{   
    int size;
    int values[MAX];
};

heap *create_heap()
{
    heap *new_heap = (heap*) malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}

int is_empty(heap *new_heap)
{
    return new_heap->size == 0;
}

int get_parents_index(heap *new_heap, int i)
{
    return i / 2;
}

int get_left_index(heap *new_heap, int i)
{
    return 2 * i;
}

int get_right_index(heap *new_heap, int i)
{
    return 2 * i + 1;
}

int item_of_heap(heap *new_heap, int i)
{
    return new_heap->values[i];
}

void swap(int *value_1, int *value_2)
{
    int temp = 0;
    temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

void print_heap(heap *new_heap, int i, int flag)
{
    if (i == new_heap->size+1)
    {
        printf("\n");
        return;
    }

    if (flag == 0)
    {
        printf("%d", new_heap->values[i]);
    }

    else
    {
        printf(" | %d", new_heap->values[i]);
    }
    flag = 1;
    print_heap(new_heap, i + 1, flag);
}

void max_heapify(heap *new_heap, int i)
{
    int largest;
    int left_index = get_left_index(new_heap, i);
    int right_index = get_right_index(new_heap, i);

    if (left_index <= new_heap->size && new_heap->values[left_index] > new_heap->values[i]) 
    {
        largest = left_index;
    }

    else 
    {
        largest = i;
    }

    if (right_index <= new_heap->size && new_heap->values[right_index] > new_heap->values[largest]) 
    {
        largest = right_index;
    }

    if (largest != i) 
    {
        swap(&new_heap->values[i], &new_heap->values[largest]);
        max_heapify(new_heap, largest);
    }
}

void heap_sort(heap *new_heap)
{
    int i = 0; 
    for(i = new_heap->size; i >= 2; i--)
    {
        printf("Maior elemento neste passo: %d\n", new_heap->values[1]);
        swap(&new_heap->values[1], &new_heap->values[i]);
        new_heap->size--;
        max_heapify(new_heap, 1); 
        printf("Estado Atual da Heap: "); 
        print_heap(new_heap, 1, 0);
    } 
}

void build_max_heap(heap *new_heap)
{
    int length = new_heap->size;
    int i = 0;
    for (i = length / 2; i >= 1; i--)
    {
        max_heapify(new_heap, i);
    } 
}

int main()
{
    int item;
    heap *new_heap = create_heap();

    int indice = 1;
    int flag = 0;
    while (scanf("%d", &item) != EOF)
    {
        new_heap->values[indice] = item;

        if (flag == 0)
        {
            printf("Estado inicial: %d", item);
        }
        else
        {
            printf(" | %d", item);
        }

        flag = 1;
        indice += 1;
    }
    
    new_heap->size = indice;
    printf("\n");
    build_max_heap(new_heap);
    new_heap->size = indice - 1;
    printf("Estado Atual da Heap: "); 
    print_heap(new_heap, 1, 0);
    
    heap_sort(new_heap);
    printf("Resultado Final: ");
    new_heap->size = indice - 1;
    print_heap(new_heap, 1, 0);
    printf("\n");
    return 0;
}
