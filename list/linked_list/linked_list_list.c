#include <stdio.h>
#include <stdlib.h>

typedef struct node // definir node
{
	int value;
	struct node *next;
} node;

typedef struct linked_list
{
	int size;
	struct node *front;
	struct node *back;
} linked_list;

node *create_node(int item) // criar node
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node -> value = item;
	new_node -> next = NULL;
	return new_node;
}

linked_list *create_linked_list()
{
	linked_list *list = (linked_list*) malloc(sizeof(linked_list));
	list -> size = 0;
	list -> front = NULL;
	list -> back = NULL;
	return list;
}

int linked_list_size(linked_list* list)
{
    if (list == NULL)
    {
        return -1;
    }

    return list -> size;
}

void print_node(linked_list *list) // printar a lista
{
	if (list == NULL)
	{
		return;
	}

    node *temp = list -> front;

    while (temp != NULL)
    {
        printf("%d ", temp -> value);
        temp = temp -> next;
    }

    printf("\n");
}

node* erase_node(node *head, int item) // apagar node
{
    node *previous = NULL;      // anterior
    node *current = head;       // atual

    while (current != NULL && current -> value != item)
    {
    	previous = current;
    	current = current -> next;
    }

    if (current == NULL)
    {
    	return head;
    }

    if (previous == NULL)
    {
    	head = current -> next;
    }

    else
    {
    	previous -> next = current -> next;
    }

    free(current);
    return head;
}

node* search_node(node *head, int value) //procurar algum elemento na lista
{
	while (head != NULL)
	{
		if (head -> value == value)
		{
			return head;
		}

		head = head -> next;
	}

	return NULL;
}

node *order_insert(node *head, int item) // inserir ordenadamente
{
	node *previous = NULL;
	node *current = head;
	node *new_node = create_node(item);

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

node* insert_back(node *head, int item) // inserir no final da lista
{
	node *new_node = create_node(item); 
	new_node -> value = item;
	new_node -> next = NULL;

	if (head != NULL)
	{
		while (head -> next != NULL)
		{
			head = head -> next;
		}

		head -> next = new_node;

		return head;
	}
	else
	{
		return new_node;
	}
}

node *insert_front(linked_list *list, int item) // inserir no começo da lista
{
	node *new_node = create_node(item); 

	if (list -> size == 0)
	{
		list -> front = new_node;
		list -> back = new_node;
	}

	else
	{
		new_node -> next = list -> front;
		list -> front = new_node;
	}
	
	list -> size++; // ++list -> size 
}

int is_empty(node *head) // verifica se a lista esta vazia
{
	return (head == NULL);
}

int main()
{
	// is_empty(node *head);

	linked_list *list = create_linked_list();

	insert_front(list, 15);
	insert_front(list, 10);
	insert_front(list, 8);
	insert_front(list, 7);

	// head = insert_end(head, 55);

	// head = erase_node(head, 7);

	// head = search_node(head, 55);

	// for (int i = 0; i < 5; i += 1)
	// {	
	// 	int value;
	// 	scanf("%d", &value);
	// 	head = order_insert(head, value);
	// }

	print_node(list);

	return 0;
}
