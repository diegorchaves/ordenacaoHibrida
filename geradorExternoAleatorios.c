#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VALUES 100000 // Número de valores a serem gerados
#define FILENAME "externo_aleatorios.txt" // Nome do arquivo de saída

int main() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_VALUES; i++) {
        fprintf(fp, "%d\n", rand());
    }

    fclose(fp);
    printf("Arquivo \"%s\" gerado com sucesso.\n", FILENAME);

    return 0;
}