#include <stdio.h>
#define MAX_VALUES 100000
#define FILENAME "externo_inversamente_ordenados.txt"

#define LIMITAR 10

void swap(int vetor[], int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void ordenacaoInsercao(int vetor[], int inicio, int fim) {
    int i;
    for (i = inicio + 1; i <= fim; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= inicio && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int particionar(int vetor[], int inicio, int fim) {
    int j;

    int mid = inicio + (fim - inicio) / 2;
    int pivotIndex = (vetor[inicio] < vetor[mid]) ?
                     ((vetor[mid] < vetor[fim]) ? mid : ((vetor[inicio] < vetor[fim]) ? fim : inicio)) :
                     ((vetor[inicio] < vetor[fim]) ? inicio : ((vetor[mid] < vetor[fim]) ? fim : mid));

    swap(vetor, inicio, pivotIndex);

    int pivo = vetor[inicio];
    int i = (inicio - 1);
    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return (i + 1);
}

void ordenacaoHibrida(int vetor[], int inicio, int fim) {
    while (inicio < fim) {
        if (fim - inicio < LIMITAR) {
            ordenacaoInsercao(vetor, inicio, fim);
            break;
        } else {
            int pi = particionar(vetor, inicio, fim);
            if (pi - inicio < fim - pi) {
                ordenacaoHibrida(vetor, inicio, pi - 1);
                inicio = pi + 1;
            } else {
                ordenacaoHibrida(vetor, pi + 1, fim);
                fim = pi - 1;
            }
        }
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
        
    printf("\n");
}

int main() {
    int vetor[MAX_VALUES];
    int n = 0;

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &vetor[n]) != EOF && n < MAX_VALUES) {
        n++;
    }

    fclose(fp);

    ordenacaoHibrida(vetor, 0, n - 1);
    printf("\nVetor ordenado: \n");
    imprimirVetor(vetor, n);
    return 0;
}
