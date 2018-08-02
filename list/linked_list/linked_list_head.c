#include <stdio.h>
#include <stdlib.h>

typedef struct node // definir node
{
	int value;
	struct node *next;
} node;

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

node* insert_end(node *head, int item) // inserir no final da lista
{
    node *new_node = create_node(item); 
    node *aux = head; // para nao perder a referencia do ponteiro
    
    if (head != NULL)
    {
        while (head -> next != NULL)
        {
            head = head -> next;
        }

        head -> next = new_node;

        return aux;
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
	return new_node;
}

node *linked_list_node() // cria lista atraves de nodes
{
	return NULL;
} 

int is_empty(node *head) // verifica se a lista esta vazia
{
	return (head == NULL);
}

int main()
{
	// is_empty(node *head);

	// node *head = linked_list_node();

	// head = insert_begin(head, 15);

	// head = insert_end(head, 55);

	// head = erase_node(head, 7);

	// head = search(head, 55);

	// for (int i = 0; i < 5; i += 1)
	// {	
	// 	int value;
	// 	scanf("%d", &value);
	// 	head = order_insert(head, value);
	// }

	// print(head);

	return 0;
}
