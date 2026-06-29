#include <stdio.h>

int main() {
    int numeros[5];
    int matriz[2][3];
    int i;
    int j;

    printf("Cadastro de vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("Digite o numero da posicao %d: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\nValores do vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }

    printf("\nCadastro de matriz 2x3:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz digitada:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
