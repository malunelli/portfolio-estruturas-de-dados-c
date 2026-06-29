#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main() {
    Aluno a1;

    strcpy(a1.nome, "Maria");
    a1.idade = 18;
    a1.nota = 9.5;

    printf("Dados do aluno:\n");
    printf("Nome: %s\n", a1.nome);
    printf("Idade: %d\n", a1.idade);
    printf("Nota: %.2f\n", a1.nota);

    if (a1.nota >= 6) {
        printf("Situacao: Aprovado\n");
    } else {
        printf("Situacao: Reprovado\n");
    }

    return 0;
}
