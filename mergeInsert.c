#include <stdio.h>
#include <stdlib.h>

#define LIMITAR 10
#define MAX_VALUES 100000
#define FILENAME "externo_inversamente_ordenados.txt"

void insertionSort(int arr[], int left, int right) {
    int i;
    for (i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void hybridSort(int arr[], int left, int right) {
    if (left < right) {
        if (right - left + 1 <= LIMITAR) {
            insertionSort(arr, left, right);
        } else {
            int middle = left + (right - left) / 2;
            hybridSort(arr, left, middle);
            hybridSort(arr, middle + 1, right);
            merge(arr, left, middle, right);
        }
    }
}

int main() {
    int arr[MAX_VALUES];
    int i, n = 0;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &arr[n]) != EOF && n < MAX_VALUES) {
        n++;
    }

    fclose(fp);

    hybridSort(arr, 0, n-1);

    printf("Array após a ordenação:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
