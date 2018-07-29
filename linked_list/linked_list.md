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