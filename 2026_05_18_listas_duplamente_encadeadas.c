#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *ant;
    struct lista *prox;
} Lista;

Lista* inserirInicio(Lista *l, int valor) {
    Lista *novo;

    novo = (Lista*) malloc(sizeof(Lista));

    if (novo != NULL) {
        novo->info = valor;
        novo->ant = NULL;
        novo->prox = l;

        if (l != NULL) {
            l->ant = novo;
        }

        l = novo;
    }

    return l;
}

void imprimirInicioFim(Lista *l) {
    Lista *p;

    printf("Lista do inicio ao fim:\n");

    for (p = l; p != NULL; p = p->prox) {
        printf("%d <-> ", p->info);
    }

    printf("NULL\n");
}

void imprimirFimInicio(Lista *l) {
    Lista *p;

    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    p = l;

    while (p->prox != NULL) {
        p = p->prox;
    }

    printf("Lista do fim ao inicio:\n");

    while (p != NULL) {
        printf("%d <-> ", p->info);
        p = p->ant;
    }

    printf("NULL\n");
}

void liberarLista(Lista *l) {
    Lista *p;

    while (l != NULL) {
        p = l;
        l = l->prox;
        free(p);
    }
}

int main() {
    Lista *lista;

    lista = NULL;

    lista = inserirInicio(lista, 30);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 10);

    imprimirInicioFim(lista);
    imprimirFimInicio(lista);

    liberarLista(lista);

    return 0;
}
