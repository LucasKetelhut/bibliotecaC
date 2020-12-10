#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Livro {
	char titulo[50], classificacao[50], autor[50];
  int qtd, edicao, ano, reservado = 0; // 0 = disponível, 1 = indisponível
};

struct User {
  char nome[50], sobrenome[50], matricula[50];
  long int cpf;
};

void cadastroL(struct Livro L[]){
  static int cont;

  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("Título do livro: ");
  scanf(" %[^\n]s", L[cont].titulo);
  printf("Classificação do livro: ");
  scanf(" %[^\n]s", L[cont].classificacao);
  printf("Autor do livro: ");
  scanf(" %[^\n]s", L[cont].autor);
  printf("Quantidade de cópias disponíveis: ");
  scanf("%d", &L[cont].qtd);
  printf("Edição do livro: ");
  scanf("%d", &L[cont].edicao);
  printf("Ano de publicação do livro: ");
  scanf("%d", &L[cont].ano);
  L[cont].reservado = 0;
  printf("\nCadastrando...\n");
  sleep(1);
  printf("\nLivro cadastrado com sucesso!\n");
  sleep(1);
  cont++;
}

void excluirL(struct Livro L[]){
}

void atualizarL(struct Livro L[]){
}

void cadastroU(struct User U[]){
}

void excluirU(struct User U[]){
}

void atualizarU(struct User U[]){
}

void mostra(struct Livro L[]){
  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro para mostrar.\n");
  } else {
    for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
        if(strcmp(L[0].titulo, "") == 0) {
          return;
        } else {
          printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
          printf("Título do livro %d: %s\n", i + 1, L[i].titulo);
          printf("Classificação do livro %d: %s\n", i + 1, L[i].classificacao);
          printf("Autor do livro %d: %s\n", i + 1, L[i].autor);
          printf("Quantidade de cópias disponíveis do livro %d: %d\n", i + 1, L[i].qtd);
          printf("Edição do livro %d: %d\n", i + 1, L[i].edicao);
          printf("Ano de publicação do livro %d: %d\n", i + 1, L[i].ano);
        }
    }
  }
}

void reservar(struct Livro L[]){
}

void devolver(struct Livro L[]){
}

void menu(){
	int opcao;
	struct Livro L[30];
  struct User U[30];

	while(1){
		printf("\nBem vindo ao Sistema de Controle de Livros da UFU\n");
		printf("\n1- Cadastrar livro");
    printf("\n2- Excluir livro");
    printf("\n3- Atualizar livro");
    printf("\n4- Cadastrar usuário");
    printf("\n5- Excluir usuário");
    printf("\n6- Atualizar usuário");
		printf("\n7- Mostrar todos os livros");
    printf("\n8- Reservar livro");
    printf("\n9- Devolver livro");
		printf("\n10- Sair ");
		printf("\n\nDigite opção: ");
		scanf("%d", &opcao);
  
		if(opcao == 1) cadastroL(L);
    if(opcao == 2) excluirL(L);
    if(opcao == 3) atualizarL(L);
    if(opcao == 4) cadastroU(U);
    if(opcao == 5) excluirU(U);
    if(opcao == 6) atualizarU(U);
		if(opcao == 7) mostra(L);
    if(opcao == 8) reservar(L);
    if(opcao == 9) devolver(L);
		if(opcao == 10) {
      printf("\nAté mais!\n");
      return;
    };
	}
}

int main(){
	menu();
}
