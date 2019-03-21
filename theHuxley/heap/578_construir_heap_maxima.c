    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    #define MAX 1000

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

    void print_heap(heap *new_heap, int i, int flag)
    {
        if (i == new_heap->size)
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

    void swap(int *value_1, int *value_2)
    {
        int temp = 0;
        temp = *value_1;
        *value_1 = *value_2;
        *value_2 = temp;
    }

    void max_heapify(heap *new_heap, int i)
    {
        int largest;
        int left_index = get_left_index(new_heap, i);
        int right_index = get_right_index(new_heap, i);

        if (left_index <= new_heap->size && new_heap->values[left_index] > new_heap->values[i]) {
            largest = left_index;
        } else {
            largest = i;
        }

        if (right_index <= new_heap->size && new_heap->values[right_index] > new_heap->values[largest]) {
            largest = right_index;
        }

        if (largest != i) {
            swap(&new_heap->values[i], &new_heap->values[largest]);
            max_heapify(new_heap, largest);
        }
    }

    void build_max_heap(heap *new_heap)
    {
        int length = new_heap->size - 1;
        int i = 0;
        for (i = length / 2; i >= 1; i--)
        {
            printf("Estado Atual: ");
            max_heapify(new_heap, i);
            print_heap(new_heap, 1, 0);
        } 
    }

    int main() {
        int item;
        heap *new_heap = create_heap();

        int indice = 1;
        int flag = 0;
        while (scanf("%d", &item) != EOF) {
            new_heap->values[indice] = item;
            indice += 1;
        }
        new_heap->size = indice;
        printf("Estado inicial: ");
        print_heap(new_heap, 1, 0);
        build_max_heap(new_heap);
        printf("Resultado Final: ");
        print_heap(new_heap, 1, 0);
        //printf("\n");
        return 0;
    }