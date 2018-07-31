#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list  // definir lista
{
	struct linked_list *front;
	struct linked_list *back;
	int value;
} linked_list;

linked_list *create_linked_list(int item) // criar linked_list
{
	linked_list* new_linked_list = (linked_list*) malloc(sizeof(linked_list));
	new_linked_list -> value = item;
	new_linked_list -> front = NULL;
	return new_linked_list;
}

void print(linked_list *list) // printar a lista
{
	while (list != NULL)
	{
		printf("%d ", list -> value);

		list = list -> front;
	}   

	printf("\n");
}

linked_list *erase(linked_list *list, int item) // apagar linked_list
{
    linked_list *previous = NULL;      // anterior
    linked_list *current = list;       // atual

    while (current != NULL && current -> value != item)
    {
    	previous = current;
    	current = current -> front;
    }

    if (current == NULL)
    {
    	return list;
    }

    if (previous == NULL)
    {
    	list = current -> front;
    }

    else
    {
    	previous -> front = current -> front;
    }

    free(current);
    return list;
}

linked_list* search(linked_list *list, int value) //procurar algum elemento na lista
{
	while (list != NULL)
	{
		if (list -> value == value)
		{
			return list;
		}

		list = list -> front;
	}

	return NULL;
}

linked_list *order_insert(linked_list *list, int item) // inserir ordenadamente
{
	linked_list *previous = NULL;
	linked_list *current = list;
	linked_list *new_linked_list = create_linked_list(item);

    if (list == NULL) // verifica se a lista nao tem linked_lists
    {
    	return new_linked_list;
    }

    if (list -> value >= item) // verifica se tem so um unico linked_list na lista
    {
    	new_linked_list -> front = list;

    	return new_linked_list;
    }

    while (current != NULL && current -> value <= item) // 
    {
    	previous = current;
    	current = current -> front;
    }
    
    if (previous -> front == NULL) // verifica ate o ultimo item
    {
    	previous -> front = new_linked_list;
    	new_linked_list -> front = NULL;
    }

    else 
    {
        previous -> front = new_linked_list; // os ponteiros apontarem ate o new_linked_list

        new_linked_list -> front = current;
    }

    return list;
}

linked_list* insert_end(linked_list *list, int item) // inserir no final da lista
{
	linked_list *new_linked_list = create_linked_list(item); 
	new_linked_list -> value = item;
	new_linked_list -> front = NULL;

	if (list != NULL)
	{
		while (list -> front != NULL)
		{
			list = list -> front;
		}

		list -> front = new_linked_list;

		return list;
	}
	else
	{
		return new_linked_list;
	}

}

linked_list *insert_begin(linked_list *list, int item) // inserir no começo da lista
{
	linked_list *new_linked_list = create_linked_list(item); 
	new_linked_list -> value = item;
	new_linked_list -> front = list; 
	return new_linked_list;
}

linked_list *create_linked_with_list()
{
	return NULL;
} 

int is_empty(linked_list *list)
{
	return (list == NULL);
}

int main()
{
	// // is_empty(linked_list *list);

	// linked_list *list = create_linked_with_list();

	// // list = insert_begin(list, 15);

	// // list = insert_end(list, 55);

	// // list = erase(list, 7);

	// // list = search(list, 55);

	// for (int i = 0; i < 10; i += 1)
	// {	
	// 	int value;
	// 	scanf("%d", &value);
	// 	list = order_insert(list, value);
	// 	print(list);
	// }

	// print(list);

	return 0;
}
