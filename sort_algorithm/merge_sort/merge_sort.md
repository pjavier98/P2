# Divide and Conquer:

## Explicação sobre o Merge Sort:

### Passos para fazer o Merge Sort:

1. Dividir o array em sub-arrays até chegar em um array de tamanho 1, como este é um array unitário, está ordenado.

2. Depois de dividir ir juntando os sub-arrays sempre verificando as seguintes condições:

- Verificar se o **inicio das metades** é **sempre** **menor que o fim** das mesmas.

- Se isso acontecer e o começo for maior que o fim da primeira metade:

- **Enquanto** o **começo for menor que o fim da segunda metade** -> colocar estes valores no array auxiliar.

- **Senão:**

- Enquanto o começo for menor que o fim da primeira metade -> colocar estes valores no array auxiliar.

3. Se as listas não acabaram:

- **Se o inicio da primeira metade** for **menor que o inicio da segunda metade** -> colocar os valores do começo da primeira metade no array auxiliar.

- **Senão** -> colocar os valores do começo da segunda metade no array auxiliar.

### Big O -> O(n * log n)

![gif do merge](gif/merge_sort.gif)