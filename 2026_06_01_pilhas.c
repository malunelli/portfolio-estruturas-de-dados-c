#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

Pilha* criarPilha() {
    Pilha *nova;

    nova = (Pilha*) malloc(sizeof(Pilha));

    if (nova != NULL) {
        nova->topo = NULL;
    }

    return nova;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {
    No *novo;

    novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->info = valor;
        novo->prox = p->topo;
        p->topo = novo;
    } else {
        printf("Erro ao alocar memoria.\n");
    }
}

int pop(Pilha *p) {
    No *aux;
    int valor;

    if (!vazia(p)) {
        aux = p->topo;
        valor = aux->info;
        p->topo = aux->prox;
        free(aux);
        return valor;
    } else {
        printf("Pilha vazia.\n");
        return -1;
    }
}

void imprimir(Pilha *p) {
    No *aux;

    aux = p->topo;

    printf("Pilha:\n");

    while (aux != NULL) {
        printf("[%d]\n", aux->info);
        aux = aux->prox;
    }
}

void liberarPilha(Pilha *p) {
    No *aux;

    while (p->topo != NULL) {
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }

    free(p);
}

int main() {
    Pilha *pilha;

    pilha = criarPilha();

    push(pilha, 4);
    push(pilha, 3);
    push(pilha, 2);

    imprimir(pilha);

    printf("\nValor removido: %d\n", pop(pilha));

    printf("\nDepois do pop:\n");
    imprimir(pilha);

    liberarPilha(pilha);

    return 0;
}
