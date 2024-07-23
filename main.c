#include <stdio.h>
#include <stdlib.h>
#define N 5 
//tamanho do array

struct lista {
    int vector[N];
    int controle;
    int tam;
} listas;

void criarLista(struct lista *l);
int estaCheia(struct lista *l);
int estaVazia(struct lista *l);
int tamLista(struct lista *l);
int consultarLista(struct lista *l, int pos);
void insereLista(struct lista *l, int pos, int valor);
void removerLista(struct lista *l, int pos);
void imprimeLista(struct lista *l);

int main(void) {
    struct lista l1;
    criarLista(&l1); //inicia a lista vazia

    int opcao = -1, pos, valor;

    while(opcao != 0){
        printf("\nMenu:\n");
        printf("1. Verificar se a lista está cheia\n");
        printf("2. Verificar se a lista está vazia\n");
        printf("3. Tamanho atual da lista\n");
        printf("4. Consultar um valor na lista\n");
        printf("5. Inserir um valor na lista\n");
        printf("6. Remover um valor da lista\n");
        printf("7. Imprimir a lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                if (estaCheia(&l1))
                    printf("A lista está cheia\n");
                else
                    printf("A lista não está cheia\n");
                break;
            case 2:
                if (estaVazia(&l1))
                    printf("A lista está vazia\n");
                else
                    printf("A lista não está vazia\n");
                break;
            case 3:
                printf("Tamanho atual da lista: %d\n", tamLista(&l1));
                break;
            case 4: 
                printf("Digite a posição a ser consultada: ");
                scanf("%d", &pos);
                valor = consultarLista(&l1, pos);
                if (valor != -1)
                    printf("Valor na posição %d: %d\n", pos, valor);
                else
                    printf("Posição inválida\n");
                break;
            case 5:
                printf("Digite a posição e o valor a serem inseridos: ");
                scanf("%d %d", &pos, &valor);
                insereLista(&l1, pos, valor);
                break;
            case 6:
                printf("Digite a posição a ser removida: ");
                scanf("%d", &pos);
                removerLista(&l1, pos);
                break;
            case 7:
                imprimeLista(&l1);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    }
    return 0;
}

void criarLista(struct lista *l){ //função para inicializar a lista
    l->controle = 0;
    l->tam = N;
}

int estaCheia(struct lista *l){ 
    return l->controle == l->tam; //retorna 1 se a lista estiver cheia
}

int estaVazia(struct lista *l){
    return l->controle == 0; //retorna 1 se a lista estiver vazia
}

int tamLista(struct lista *l){
    return l->controle; //retorna o tamanho atual da lista
}

int consultarLista(struct lista *l, int pos){
    if (pos >= 0 && pos < l->controle){
        return l->vector[pos]; //retorna o valor da posição informada
    }else{
        return -1; //retorna -1 se a posição não existir
    }
}

void insereLista(struct lista *l, int pos, int valor){
    if (pos < 0 || pos > l->controle) {
        printf("Posição inválida\n");
        return;
    }
    if (!estaCheia(l)){
        for(int i = l->controle; i > pos; i--){
            l->vector[i] = l->vector[i-1];
        }
        l->vector[pos] = valor;
        l->controle++;
    } else {
        printf("Não é possível inserir, a lista está cheia\n");
    }
}

void removerLista(struct lista *l, int pos){
    if (pos < 0 || pos >= l->controle) {
        printf("Posição inválida\n");
        return;
    }
    if (!estaVazia(l)){
        for(int i = pos; i < l->controle - 1; i++){
            l->vector[i] = l->vector[i+1];
        }
        l->controle--;
    } else {
        printf("Não é possível remover, a lista está vazia\n");
    }
}

void imprimeLista(struct lista *l) {
    if (estaVazia(l)) {
        printf("A lista está vazia\n");
    } else {
        printf("Conteúdo da lista: ");
        for (int i = 0; i < l->controle; i++) {
            printf("%d ", l->vector[i]);
        }
        printf("\n");
    }
}
