#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista* inserirInicio(Lista *l, int valor) {
    Lista *novo;

    novo = (Lista*) malloc(sizeof(Lista));

    if (novo != NULL) {
        novo->info = valor;
        novo->prox = l;
        l = novo;
    }

    return l;
}

void imprimirLista(Lista *l) {
    Lista *p;

    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
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

    printf("Lista encadeada:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}
