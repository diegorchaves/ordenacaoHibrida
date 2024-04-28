#include <stdio.h>
#include "insertionMergeSort.h"

#define MAX_VALUES 10000
#define FILENAME "valores10000.txt"

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
    int middle = n / 2;
    mergeSort(arr, 0, middle, n);
}

void mergeSort(int arr[], int left, int middle, int n) {
    int helper[n];
    int right = n - 1;
    
    for (int i = left; i <= right; i++) {
        helper[i] = arr[i];
    }

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {
        if (helper[i] <= helper[j]) {
            arr[k] = helper[i];
            i++;
        } else {
            arr[k] = helper[j];
            j++;
        }
        k++;    
    }
    
    while (i <= middle) {
        arr[k] = helper[i];
        i++;
        k++;
    }

    while (j <= right) {
        arr[k] = helper[j];
        j++;
        k++;
    }
}

int main() {
    int arr[MAX_VALUES];
    int n = 0;

    // Abrir o arquivo para leitura
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    // Ler os valores do arquivo
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < MAX_VALUES) {
        n++;
    }

    // Fechar o arquivo
    fclose(fp);

    /* printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n"); */

    insertionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}
