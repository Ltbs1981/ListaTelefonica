#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Definição da estrutura para armazenar os contatos

typedef struct contato {
char nome [30];
char numero[15];
struct contato* proximo;
}Contato;
// Função para criar um novo contato
Contato* criarContato(char nome[], char numero[]) {
 Contato* novoContato = (Contato*)malloc(sizeof(Contato));
 if (novoContato == NULL) {
    printf ("Erro ao guardar o espaço na memória para salvar o contato");
    exit (EXIT_FAILURE);    
 }       
 strcpy ( novoContato->nome, nome );
 strcpy (novoContato->numero,numero);
novoContato-> proximo = NULL;
return novoContato;
}
// Função para adicionar um novo contato à lista
Contato* adicionarContato (Contato* lista, char nome[], char numero[]) {
Contato* novoContato = criarContato(nome, numero);
if(lista == NULL) {
    return novoContato;    
}else {
    Contato* atual = lista;
    while (atual-> proximo != NULL){
atual = atual->proximo;
    }
    atual->proximo = novoContato;
    return lista;
}
}

// Função para listar todos os contatos
void listarContatos (Contato* lista){
        printf("Lista de contatos:\n");

Contato* atual  = lista;
while (atual != NULL){
    printf("Nome: %s, Número: %s\n", atual->nome, atual->numero);
    atual = atual->proximo;
}
}

//função main principal

{
    /* code */
}

} 

        /* code */
    }
    
}   
}

