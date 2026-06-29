#include <stdio.h>

void trocar(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    int vetor[3] = {1, 2, 3};
    int *p;

    p = vetor;

    printf("Antes da troca:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    trocar(&x, &y);

    printf("\nDepois da troca:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("\nAcessando vetor com ponteiro:\n");
    printf("Primeiro elemento: %d\n", *p);
    printf("Segundo elemento: %d\n", *(p + 1));
    printf("Terceiro elemento: %d\n", *(p + 2));

    return 0;
}
