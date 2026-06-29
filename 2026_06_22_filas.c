#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int frente;
    int fim;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->fim = -1;
}

int vazia(Fila *f) {
    return f->fim < f->frente;
}

int cheia(Fila *f) {
    return f->fim == MAX - 1;
}

void enfileirar(Fila *f, int valor) {
    if (cheia(f)) {
        printf("Fila cheia. Nao foi possivel inserir.\n");
    } else {
        f->fim++;
        f->dados[f->fim] = valor;
        printf("Valor %d inserido na fila.\n", valor);
    }
}

int desenfileirar(Fila *f) {
    int valor;
    int i;

    if (vazia(f)) {
        printf("Fila vazia. Nao ha elementos para remover.\n");
        return -1;
    }

    valor = f->dados[f->frente];

    for (i = 0; i < f->fim; i++) {
        f->dados[i] = f->dados[i + 1];
    }

    f->fim--;

    return valor;
}

int consultarFrente(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia.\n");
        return -1;
    }

    return f->dados[f->frente];
}

void imprimirFila(Fila *f) {
    int i;

    if (vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");

    for (i = f->frente; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }

    printf("\n");
}

int main() {
    Fila fila;

    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    imprimirFila(&fila);

    printf("Primeiro elemento da fila: %d\n", consultarFrente(&fila));

    printf("Elemento removido: %d\n", desenfileirar(&fila));

    imprimirFila(&fila);

    return 0;
}
