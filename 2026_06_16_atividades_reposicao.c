#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* inserir(No *lista, int valor) {
    No *novo;

    novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = lista;
        lista = novo;
    }

    return lista;
}

void imprimir(No *lista) {
    No *p;

    for (p = lista; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }

    printf("NULL\n");
}

void liberar(No *lista) {
    No *p;

    while (lista != NULL) {
        p = lista;
        lista = lista->prox;
        free(p);
    }
}

int main() {
    No *lista;

    lista = NULL;

    lista = inserir(lista, 30);
    lista = inserir(lista, 20);
    lista = inserir(lista, 10);

    printf("Lista criada na atividade de reposicao:\n");
    imprimir(lista);

    liberar(lista);

    return 0;
}
