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

Lista* buscar(Lista *l, int valor) {
    Lista *p;

    for (p = l; p != NULL; p = p->prox) {
        if (p->info == valor) {
            return p;
        }
    }

    return NULL;
}

Lista* removerUltimo(Lista *l) {
    Lista *p;

    if (l == NULL) {
        return NULL;
    }

    if (l->prox == NULL) {
        free(l);
        return NULL;
    }

    p = l;

    while (p->prox->prox != NULL) {
        p = p->prox;
    }

    free(p->prox);
    p->prox = NULL;

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
    Lista *resultado;

    lista = NULL;

    lista = inserirInicio(lista, 30);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 10);

    printf("Lista original:\n");
    imprimirLista(lista);

    resultado = buscar(lista, 20);

    if (resultado != NULL) {
        printf("Valor encontrado: %d\n", resultado->info);
    } else {
        printf("Valor nao encontrado.\n");
    }

    lista = removerUltimo(lista);

    printf("\nLista apos remover o ultimo elemento:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}
