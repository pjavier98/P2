#include <stdio.h>
#include <stdlib.h>

typedef struct node  // definir heada
{
    int value;
	struct node *next;
	struct node *previous;
} node;

node *create_node(int item) // criar node
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node -> value = item;
	new_node -> next = NULL;
    new_node -> previous = NULL;
	return new_node;
}

void print_backward(node *tail) // printar a lista decrescente // tail -> rabo da lista
{
	if (tail != NULL)
    {
        printf("%d ", tail -> value);
        print_backward(tail -> previous);
    }
}

void print_forward(node *head) // printar a lista crescente // head -> cabeca da lista
{
    if (head != NULL)
    {
        printf("%d ", head -> value);
        print_forward(head -> previous);
    }
}

node *erase(node *head, int item) // apagar node
{
    node *current = head;       // atual

    while (current != NULL && current -> value != item)
    {
    	current = current -> next;
    }

    if (current == NULL)
    {
    	return head;
    }

    if (head == current)
    {
        head = current -> next;
    }

    else
    {
    	current -> previous -> next = current -> next;
    }

    if (current -> next != NULL)
    {
        current -> next -> previous = current -> previous;
    }

    free(current);
    return head;
}

node* search(node *head, int value) //procurar algum elemento na lista
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

    while (current != NULL && current -> value <= item)
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
        current -> next = new_node; // os ponteiros apontarem ate o new_node

        new_node -> next = current;

        new_node -> previous = current -> next;
    }

    return head;
}

node* insert_end(node *head, int item) // inserir no final da lista
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

node *insert_begin(node *head, int item) // inserir no começo da lista
{
	node *new_node = create_node(item); 
	new_node -> value = item;
	new_node -> next = head;
    new_node -> previous = NULL;

    if (head != NULL)
    {
        head -> previous = new_node;
    } 

	return new_node;
}

node *create_linked_with_head()
{
	return NULL;
} 

int is_empty(node *head)
{
	return (head == NULL);
}

int main()
{
	// is_empty(node *head);

	node *head = create_linked_with_head();

	// head = insert_begin(head, 15);

	// head = insert_end(head, 55);

	// head = erase(head, 7);

	// head = search(head, 55);

	for (int i = 0; i < 5; i += 1)
	{	
		int value;
		scanf("%d", &value);
		head = insert_begin(head, value);
		print_forward(head);
	}
    printf("\n");
    head = erase(head, 3);
    print_forward(head);
    printf("\n");

    // print_forward(head);
	// print_backward(head);

	return 0;
}
