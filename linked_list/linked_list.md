# Vetor: alocação estática.

Precisa **definir** em **tempo de compilação** qual vai ser o **tamanho daquela memória** (precisa declarar quantos elementos ele vai aguentar)

- 1 elemento  [1]
- 2 elementos [2]
- 3 elementos [3]
- ...
- n elementos [n]

Porém nem sempre sabemos quais serão os limites, software para loja de cadastro de tênis, não sabemos quantos clientes vão ter.

Portanto, precisamos de algo que possa se **extender, crescer dinamicamente conforme** a **necessidade.**

# Lista encadeada: 
Consegue crescer dinamicamente conforme a necessidade graças aos **nós**.

Cada **nó** da lista representa **um elemento** (10 elementos -> 10 nós).

## Nó: 
Possui uma variável que guarda o valor do elemento que estamos querendo guardar na nossa lista e um ponteiro para apontar qual é o próximo nó que está na frente dele (os ponteiros permitem que os nós se conectem).

### Como através dos nós podem se comunicar os nós ???
Eles possuem **endereços na memória RAM**(endereços lógicos).

Cada **lista encadeada** tem o seu **final**, e é sinalizado pelo último nó da lista que possui o **ponteiro próximo apontando** para **NULL**(não existe mais nenhum nó la na frente, aponta para vazio)

### Inserir a direita:

Achar o ultimo nó e substituir por outro que veria agora a ser o ultimo.

### Inserir a esquerda:

Achar o primeiro nó e ele não vai ser mais o primeiro.

- Em ambos os casos tem que **atualizar a referência do ponteiro.**

## Operações com lista

1. Criar listas (devolve uma referência para nossa lista onde alocamos o espaço). -> struct node !!!

2. Push (inserir um node no inicio da nossa lista com dados). -> funcao insert_begin !!!

3. Pop (pegar e remover o primeiro node da lista). -> funcao erase !!!

4. Insert (inserir um node em uma parte específica). -> inserção ordenada

5. Erase (apagar um indice [node] especifico). -> funcao erase !!!

6. isEmpty (verifica se a lista esta vazia). -> funcao isempty !!!

7. IndexOf (verifica se o node está ou não na lista).

8. atPosition (se passar um indice negativo ou maior que o tamanho da lista retorna um ponteiro nulo).

9. Minimum (retornar o menor elemento da lista).

10. Maximum (retornar o maior elemento da lista).

11. Exchange (trocar a posição de dois nodes da lista).

12. Sort (ordenar a nossa lista).

13.  Print (imprimir a lista). -> funcao print !!!

- Em **todas** tem que passar **referência da lista.**
- !!! -> ja fiz.

### Para tirar as structs dos nodes:
```

typedef struct node
{
	int value;
	struct node *next;
} node;

```

## Implementações para fazer lista:
1. Criando nodes !!
2. Criando lista !!
