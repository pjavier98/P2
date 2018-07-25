# Divide and Conquer:

## Explicação sobre o Quick Sort:

### Passos para fazer o quick sort:

1. Enquanto o inicio for menor ou igual ao fim:

- É selecionado um pivô, (geralmente no meio do array).

- É selecionado o primeiro elemento a esquerda que for maior que o pivô.

- É selecionado o primeiro elemento a direita que for menor que o pivô.

- Estes elementos trocam de lugar, e o processo acontece ate acabar o array.

- É chamada uma recursão dividindo o array em 2 e é feito o processo diversas vezes até o array ficar ordenado. 

### Big O -> O(n * log n)

![gif do merge](gif/quick_sort.gif)