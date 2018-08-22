#include <stdio.h>
#include <stdlib.h>

#define DEBUG(x, s) if(x)printf("%s\n", s);

typedef struct node
{
	int value; // pega o valor da entrada e faz o node atual apontar a ele
	struct node *next; // faz o node apontar pro next
}node;

node *create_node(int item) // cria um node
{
	node *head = (node*) malloc(sizeof(node)); // aloca memoria para node
	head->value = item; // adiciona o valor ao node
	head->next = NULL; // faz o next do node apontar para NULL
	return head; // retorna a cabeça
}

node *insert_end(node *head, int item) // insere no final
{
	node *new_node = create_node(item); // cria o node
	node *aux = head; // faz o aux apontar para head tambem para nao perder o ponteiro da cabeça

	if (head == NULL) // quando a lista nao tiver nenhum valor
	{
		return new_node;
	}

	while (aux->next != NULL) // quando ele nao for o final ele vai mudando pro proximo
	{
		aux=aux->next;
	}

	aux->next = new_node;
	return head;	
}

node *insert_begin(node *head, int item) // insere no começo
{
	node *new_node = create_node(item); // cria o node
	new_node->next = head; // faz o new node apontar para a cabeça
	return new_node;
}

void print(node *head) // printa a lista
{
	if (head == NULL) // enquanto a lista nao acabar ele printa
	{
		printf("\n");
		return;
	}
	printf("%d ", head->value);
	print(head->next); // recursao para incrementar o head
}

int search(node *head, int item) // procura algum elemento na lista
{
	if (head != NULL)
	{
		if (head->value == item)
		{
			return 1;
		}

		return search(head->next, item); // return permite a execução da parte abaixo dele do codigo
	}

	return 0;
}

node *erase(node *head, int item) // elimina um node de uma lista
{
	node *previous = NULL; // salva o anterior
	node *current = head; // salva o atual

	if (current != NULL && current->value == item) // se o elemento a eliminar for a cabeça
	{
		head = current->next;
		current->next = NULL;
		free(current);
		return head;
	}

	while (current != NULL) // se o elemento a eliminar for diferente da cabeça
	{
		if (current->value == item)
		{
			previous->next = current->next;
			free(current); // libera o node
			return head;
		}
		previous = current; // vai incrementando o previous
		current = current->next; // vai incrementando o current
	}

	return head;
}

int main()
{
	node *head = NULL;
	//DEBUG(0, "linha 102");
	head = insert_begin(head, 3);
	//DEBUG(0, "linha 104");
	head = insert_begin(head, 7);
	head = insert_begin(head, 9);
	head = insert_end(head, 13);
	head = insert_end(head, 17);
	head = insert_end(head, 22);
	print(head);
	//DEBUG(0, "linha 111");
	head = erase(head, 9);
	print(head);
	head = erase(head, 13);
	print(head);
	head = erase(head, 22);
	print(head);
	if(search(head, 3)) {
		printf("3 encontrado\n");
	} else {
		printf("3 nao encontrado\n");
	}
	if(search(head, 10000)) {
		printf("10000 encontrado\n");
	} else {
		printf("100000 nao encontrado\n");
	}
	return 0;
}
