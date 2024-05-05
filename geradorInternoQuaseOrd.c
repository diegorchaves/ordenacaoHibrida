#include <stdio.h>
#include <stdlib.h>

#define NUM_VALUES 1000 // Número de valores a serem gerados
#define FILENAME "interno_quase_ordenados.txt" // Nome do arquivo de saída

int main() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    for (int i = 0; i < NUM_VALUES; i++) {
        fprintf(fp, "%d\n", i + rand() % 10); // Adiciona uma pequena variação
    }

    fclose(fp);
    printf("Arquivo \"%s\" gerado com sucesso.\n", FILENAME);

    return 0;
}
