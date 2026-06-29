#include <stdio.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    Aluno turma[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Digite o nome: ");
        scanf(" %[^\n]", turma[i].nome);

        printf("Digite a nota: ");
        scanf("%f", &turma[i].nota);
    }

    printf("\n--- LISTA DE ALUNOS ---\n");

    for (i = 0; i < 3; i++) {
        printf("Aluno %d: %s - Nota: %.2f\n", i + 1, turma[i].nome, turma[i].nota);
    }

    return 0;
}
