#include <stdio.h>
#include <stdlib.h> // Certifique-se de que está aqui
#include <string.h>


typedef struct {
    char nome[50];
    int idade;
    char cpf[15];
} Pessoa;

typedef struct no {
    Pessoa p;
    struct no *proximo;
} No;

Pessoa ler_pessoa() {
    Pessoa p;

    printf("\nDigite o nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o '\n'

    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    getchar(); // Limpa o buffer após o número

    printf("Digite o CPF: ");
    fgets(p.cpf, 15, stdin);
    p.cpf[strcspn(p.cpf, "\n")] = '\0'; // Remove o '\n'

    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("\nNome: %s\nIdade: %d\nCPF: %s\n", p.nome, p.idade, p.cpf);
}

No* empilhar(No *topo) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    } else {
        printf("\nErro ao alocar memoria!!\n");
    }
    return NULL;
}

No* desempilhar(No **topo) {
    if (*topo != NULL) {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else {
        printf("\nPilha vazia!\n");
    }
    return NULL;
}

void imprimir_pilha(No *topo) {
    printf("\n------------ PILHA ------------\n");
    while (topo) {
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n---------- FIM PILHA ----------\n");
}

int main() {
    No *remover, *top = NULL;
    int opcao;

    do {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        while ((getchar()) != '\n' && getchar() != EOF); // Limpa o buffer

        switch (opcao) {
            case 1:
                top = empilhar(top);
                break;
            case 2:
                remover = desempilhar(&top);
                if (remover) {
                    printf("Elemento removido com sucesso!\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                } else {
                    printf("\nSem nó para remover!\n");
                }
                break;
            case 3:
                imprimir_pilha(top);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libera a memória restante na pilha
    while (top) {
        remover = desempilhar(&top);
        free(remover);
    }

    printf("Programa encerrado.\n");
    return 0;
}
