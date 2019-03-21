#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
//Insira o código aqui

void Calculadora(STACK *calculadora, int size)
{
    char letter[5];

    while(size > 0)
    {
        scanf(" %s", letter);
        //printf("%c\n", letter);

        if (letter[0] == '+' || letter[0] == '-' || letter[0] == '*' || letter[0] == '/')
        {
            //printf("%c\n", letter);
            result(calculadora, letter[0]);
        }

        else
        {
            int number = 0;
            //number = letter - '0'; // converter char para inteiro
            number = atoi(letter); // converter string para inteiro
            //printf("%d\n", number);
            PUSH(calculadora, number);
        }

        size -= 1;
    }   
}

void result(STACK* stack, char operation)
{
    if (operation == '+')
    {
        int top_1 = POP(stack);
        int top_2 = POP(stack);
        int result = top_2 + top_1;
        PUSH(stack, result);
    }

    else if (operation == '-')
    {
        int top_1 = POP(stack);
        int top_2 = POP(stack);
        int result = top_2 - top_1;
        PUSH(stack, result);
    }

    else if (operation == '*')
    {
        int top_1 = POP(stack);
        int top_2 = POP(stack);
        int result = top_2 * top_1;
        PUSH(stack, result);
    }

    else if (operation == '/')
    {
        int top_1 = POP(stack);
        int top_2 = POP(stack);
        int result = top_2 / top_1;
        PUSH(stack, result);
    }
}

STACK* Create_stack()
{
    STACK *stack = (STACK*) malloc(sizeof(STACK));
    stack->head = NULL;
    return stack;

}

NODE* create_node(int element)
{
    NODE *new_NODE = (NODE*) malloc(sizeof(NODE));
    new_NODE->element = element;
    new_NODE->next = NULL;
    return new_NODE;
}

void PUSH(STACK* stack, int element)
{
    NODE *new_top = create_node(element);

    new_top->next = stack->head;
    stack->head = new_top;
    
    printf("%d\n", new_top->element);
}


int POP(STACK* stack)
{
    if (!IS_EMPTY(stack))
    {
        NODE *new_NODE = stack->head;
        stack->head = stack->head->next;
        new_NODE->next = NULL;
        int item = new_NODE->element; // guarda o valor para dar o free
        free(new_NODE);
        return item;
    }
}

int IS_EMPTY(STACK* stack)
{
    return (stack->head == NULL);
}
