#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* criarNo(int valor) {
    No *novo;

    novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }

    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    No *raiz;

    raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);

    printf("Elementos em ordem: ");
    emOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}
