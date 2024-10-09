# Implementação do Algoritmo Merge Sort em uma Estrutura de Dados de Lista em C

Este repositório contém um resumo e a implementação do algoritmo **Merge Sort** aplicado a uma estrutura de dados de lista estática em linguagem C, com o objetivo de ordenar registros de alunos com base no número de matrícula.

## Resumo

O trabalho descreve a implementação do algoritmo de ordenação **Merge Sort** para ordenar uma lista de até 1000 registros de alunos, com foco no número de matrícula. Além disso, apresenta uma visão geral de outros algoritmos de ordenação: **Bubble Sort**, **Selection Sort**, **Insertion Sort** e **Merge Sort**, detalhando suas características e complexidades.

### Algoritmos de Ordenação Apresentados:
1. **Bubble Sort**: Algoritmo simples de complexidade O(n²), que compara e troca elementos adjacentes.
2. **Selection Sort**: Seleciona o menor elemento da parte não ordenada e o coloca na parte ordenada. Também tem complexidade O(n²).
3. **Insertion Sort**: Constrói a lista ordenada inserindo elementos um a um. É eficiente para listas pequenas ou quase ordenadas.
4. **Merge Sort**: Algoritmo eficiente de ordenação com complexidade O(n log n) baseado na técnica de "dividir para conquistar".

## Principais Funções

Abaixo está um trecho da implementação da função **mergeSort** que realiza a ordenação dos registros de alunos:

```c
void mergeSort(Aluno arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira metade
        mergeSort(arr, left, mid);
        // Ordena a segunda metade
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
    }
}
