#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

typedef struct node // definir node
{
    int value;
    node *next;
};

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

node *create_node(int item) // criar node
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node -> value = item;
	new_node -> next = NULL;
	return new_node;
}

void print(node *head) // printar a lista
{
	if (head != NULL)
	{
		printf("%d ", head -> value);

		print(head -> next);
	}   
}

node *order_insert(node *head, int item) // inserir ordenadamente
{
	node *new_node = create_node(item);
	node *previous = NULL;
	node *current = head;

	if (head == NULL) // verifica se a lista nao tem nodes
	{
		return new_node;
	}

	if (head -> value >= item) // verifica se tem so um unico node na lista
	{
		new_node -> next = head;

		return new_node;
	}

	while (current != NULL && current -> value <= item) // 
	{
		previous = current;
		current = current -> next;
	}
	
	if (previous -> next == NULL) // verifica ate o ultimo item
	{
		previous -> next = new_node;
		new_node -> next = NULL;
	}

	else 
	{
		previous -> next = new_node; // os ponteiros apontarem ate o new_node

		new_node -> next = current;
	}

	return head;
}

void compare(node *head_1, node *head_2, int *cont)
{
	node *aux = head_1;
	
	if (head_2 == NULL)
	{
		return;
	}
	
	while (aux -> value <= head_2 -> value)
	{
		if (aux -> value == head_2 -> value)
		{
			printf("%d\n", aux -> value);
			*cont += 1;
		}
		
		if (aux -> next == NULL)
		{
			return;
		}
		
		aux = aux -> next;
	}
	
	compare(head_1 = head_1 -> next, head_2 = head_2 -> next, cont);
}

node *linked_list_node() // cria lista atraves de nodes
{
	return NULL;
}

int main()
{   
	int size = 20;
	int list_1[20];
	int list_2[20];
	int aux[20];
	int i;

	node *head_1 = linked_list_node();
	node *head_2 = linked_list_node();

	for (i = 0; i < size; i += 1)
	{    
		scanf("%d", &list_1[i]);
	}
    
	for (i = 0; i < size; i += 1)
	{    
		scanf("%d", &list_2[i]);
		
	}
    
    merge_sort(list_1, 0, size - 1, aux);
    merge_sort(list_2, 0, size - 1, aux);

//     for (i = 0; i < 20; i += 1)
// 	{    
// 		printf("%d ", list_1[i]);
// 		printf("%d ", list_2[i]);
// 	}
	
	printf("\n");

	for (i = 0; i < 20; i += 1)
	{   
		if (list_1[i] != list_1[i + 1])
		{
			head_1 = order_insert(head_1, list_1[i]);  
		}

		if (list_2[i] != list_2[i + 1])
		{
			head_2 = order_insert(head_2, list_2[i]);  
		}
	} 

// 	print(head_1);
// 	printf("\n");
// 	print(head_2);
// 	printf("\n");

	int cont = 0;

	compare(head_1, head_2, &cont);

	if (cont == 0)
	{
		printf("VAZIO");    
	}

	return 0;
}
