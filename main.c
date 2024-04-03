#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para armazenar os contatos
typedef struct contato {
    char nome[50];
    char numero[15];
    struct contato* proximo;
} Contato;

// Função para criar um novo contato
Contato* criarContato(char nome[], char numero[]) {
    Contato* novoContato = (Contato*)malloc(sizeof(Contato));
    if (novoContato == NULL) {
        printf("Erro ao alocar memória para o novo contato.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->numero, numero);
    novoContato->proximo = NULL;
    return novoContato;
}

// Função para adicionar um novo contato à lista
Contato* adicionarContato(Contato* lista, char nome[], char numero[]) {
    Contato* novoContato = criarContato(nome, numero);
    if (lista == NULL) {
        return novoContato;
    } else {
        Contato* atual = lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoContato;
        return lista;
    }
}

// Função para listar todos os contatos
void listarContatos(Contato* lista) {
    printf("Lista de contatos:\n");
    Contato* atual = lista;
    while (atual != NULL) {
        printf("Nome: %s, Número: %s\n", atual->nome, atual->numero);
        atual = atual->proximo;
    }
}

// Função principal
int main() {
    Contato* lista = NULL;
    char nome[50];
    char numero[15];
    int opcao;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Registrar um contato\n");
        printf("2. Listar todos os contatos\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o nome do contato: ");
                scanf("%s", nome);
                printf("Digite o número de telefone do contato: ");
                scanf("%s", numero);
                lista = adicionarContato(lista, nome, numero);
                break;
            case 2:
                listarContatos(lista);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    // Liberar memória alocada para os contatos
    Contato* atual = lista;
    while (atual != NULL) {
        Contato* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
