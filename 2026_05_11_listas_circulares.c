#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* inserirFim(No *lista, int valor) {
    No *novo;
    No *p;

    novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->valor = valor;

        if (lista == NULL) {
            novo->prox = novo;
            lista = novo;
        } else {
            p = lista;

            while (p->prox != lista) {
                p = p->prox;
            }

            p->prox = novo;
            novo->prox = lista;
        }
    }

    return lista;
}

void imprimirLista(No *lista) {
    No *p;

    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    p = lista;

    do {
        printf("%d -> ", p->valor);
        p = p->prox;
    } while (p != lista);

    printf("(volta ao inicio)\n");
}

void liberarLista(No *lista) {
    No *p;
    No *aux;

    if (lista == NULL) {
        return;
    }

    p = lista->prox;

    while (p != lista) {
        aux = p;
        p = p->prox;
        free(aux);
    }

    free(lista);
}

int main() {
    No *lista;

    lista = NULL;

    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);

    printf("Lista circular:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}
