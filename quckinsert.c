#include <stdio.h>

#define LIMITAR 5

void ordenacaoInsercao(int vetor[], int inicio, int fim) {
    for (int i = inicio + 1; i <= fim; i++) {
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
    int pivo = vetor[fim];
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++) {
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
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor não ordenado: \n");
    imprimirVetor(vetor, n);

    ordenacaoHibrida(vetor, 0, n - 1);
    printf("\nVetor ordenado: \n");
    imprimirVetor(vetor, n);
    return 0;
}
