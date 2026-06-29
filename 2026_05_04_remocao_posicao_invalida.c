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

Lista* removerPorPosicao(Lista *l, int posicao) {
    Lista *p;
    Lista *ant;
    int i;

    if (l == NULL) {
        printf("Lista vazia. Nao ha elementos para remover.\n");
        return l;
    }

    if (posicao < 0) {
        printf("Posicao invalida.\n");
        return l;
    }

    if (posicao == 0) {
        p = l;
        l = l->prox;
        free(p);
        printf("Elemento da posicao 0 removido.\n");
        return l;
    }

    ant = l;
    p = l->prox;
    i = 1;

    while (p != NULL && i < posicao) {
        ant = p;
        p = p->prox;
        i++;
    }

    if (p == NULL) {
        printf("Posicao invalida. A posicao informada esta fora do tamanho da lista.\n");
        return l;
    }

    ant->prox = p->prox;
    free(p);

    printf("Elemento removido da posicao %d.\n", posicao);

    return l;
}

void imprimirLista(Lista *l) {
    Lista *p;

    for (p = l; p != NULL; p = p->prox) {
        printf("[%d] -> ", p->info);
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

    printf("Lista antes da remocao:\n");
    imprimirLista(lista);

    lista = removerPorPosicao(lista, 5);

    printf("\nLista depois da tentativa de remocao:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}
