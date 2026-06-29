#include <stdio.h>

int main() {
    int opcao;
    int i;
    float nota;
    float soma;
    float media;

    do {
        printf("\nMenu:\n");
        printf("1 - Calcular media de 3 notas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            soma = 0;

            for (i = 1; i <= 3; i++) {
                printf("Digite a nota %d: ", i);
                scanf("%f", &nota);

                while (nota < 0 || nota > 10) {
                    printf("Nota invalida. Digite novamente: ");
                    scanf("%f", &nota);
                }

                soma = soma + nota;
            }

            media = soma / 3;
            printf("Media final: %.2f\n", media);
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    printf("Programa encerrado.\n");

    return 0;
}
