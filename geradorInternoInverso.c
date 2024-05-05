#include <stdio.h>

#define NUM_VALUES 1000 // Número de valores a serem gerados
#define FILENAME "interno_inversamente_ordenados.txt" // Nome do arquivo de saída

int main() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    for (int i = NUM_VALUES; i > 0; i--) {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);
    printf("Arquivo \"%s\" gerado com sucesso.\n", FILENAME);

    return 0;
}
