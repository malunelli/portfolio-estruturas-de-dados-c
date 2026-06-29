#include <stdio.h>

int main() {
    float media;
    int frequencia;

    printf("Digite a media do aluno: ");
    scanf("%f", &media);

    printf("Digite a frequencia do aluno: ");
    scanf("%d", &frequencia);

    if (media >= 6 && frequencia >= 75) {
        printf("Aluno aprovado.\n");
    } else if (media >= 4 && frequencia >= 75) {
        printf("Aluno em recuperacao.\n");
    } else {
        printf("Aluno reprovado.\n");
    }

    return 0;
}
