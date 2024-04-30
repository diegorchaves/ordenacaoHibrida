#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUES 10000
#define FILENAME "valores10000.txt"

void swap(int array[], int i, int j)
{
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

int particiona(int array[], int left, int right)
{
    int range = right - left + 1;
    int indexPivot = rand() % range + left;
    swap(array, left, indexPivot);

    int pivot = array[left];
    int i = left;
    for (int j = left+1; j <= right; j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(array, i, j);
        }
    }
    return i;
}

void quickSort(int array[], int left, int right)
{
    int pivot;
    if(left < right)
    {
        pivot = particiona(array, left, right);
        quickSort(array, left, pivot-1);
        quickSort(array, pivot+1, right);
    }
}

int main()
{
    srand(time(NULL));

    int vetor[MAX_VALUES];
    int n = 0;

     // Abrir o arquivo para leitura
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    // Ler os valores do arquivo
    while (fscanf(fp, "%d", &vetor[n]) != EOF && n < MAX_VALUES) {
        n++;
    }

    // Fechar o arquivo
    fclose(fp);

    quickSort(vetor, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
}