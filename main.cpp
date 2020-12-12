#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Livro {
	char titulo[50] = "", classificacao[50] = "", autor[50] = "";
  int qtd = 0, edicao = 0, ano = 0, reservado = 0; // 0 = disponível, 1 = indisponível
};

struct User {
  char nome[50] = "", sobrenome[50] = "", matricula[50] = "", cpf[12] = "";
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
  while(1){
    printf("Quantidade de cópias disponíveis: ");
    scanf("%d", &L[cont].qtd);  
    if(L[cont].qtd < 1) {
      printf("Ao menos uma cópia deve estar disponível para exemplar.\n");
    } else {
      break;
    }
  } 
  printf("Edição do livro: ");
  scanf("%d", &L[cont].edicao);
  printf("Ano de publicação do livro: ");
  scanf("%d", &L[cont].ano);
  L[cont].reservado = 0;
  printf("\nCadastrando livro...\n");
  sleep(1);
  printf("\nLivro cadastrado com sucesso!\n");
  sleep(1);
  cont++;
}

void atualizarL(struct Livro L[]){
  int op = 0, att = 0;
  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro para atualizar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else {
    printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
    printf("Qual livro deseja atualizar? Digite o número do livro após a listagem.\n");
    sleep(2);
    for (int i = 0; L[i].ano != 0; i++) {
        printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
        printf("[%d]:\n", i + 1);
        printf("Título do livro %d: %s\n", i + 1, L[i].titulo);
        printf("Classificação do livro %d: %s\n", i + 1, L[i].classificacao);
        printf("Autor do livro %d: %s\n", i + 1, L[i].autor);
        printf("Quantidade de cópias disponíveis do livro %d: %d\n", i + 1, L[i].qtd);
        printf("Edição do livro %d: %d\n", i + 1, L[i].edicao);
        printf("Ano de publicação do livro %d: %d\n", i + 1, L[i].ano);
    }
  }
  printf("\nLivro a ser atualizado: ");
  scanf("%d", &op);
  op -= 1;
  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("O que deseja alterar?\n\n");
  while(1){
    printf("1- Título\n2- Classificação\n3- Autor\n4- Quantidade\n5- Edição\n6- Ano\n\n");
    printf("Opção escolhida: ");
    scanf("%d", &att);
    if(att == 1 || att == 2 || att == 3 || att == 4 || att == 5 || att == 6) {
      break;
    } else {
      printf("Opção inválida, selecione corretamente.\n\n");
    }
  }  
  printf("\n");
  switch(att) {
    case 1:
      printf("Novo título: ");
      scanf(" %[^\n]s", L[op].titulo);
      break;
    case 2:
      printf("Nova classificação: ");
      scanf(" %[^\n]s", L[op].classificacao);
      break;
    case 3:
      printf("Novo autor: ");
      scanf(" %[^\n]s", L[op].autor);
      break;
    case 4:
      while(1){
        printf("Nova quantidade: ");
        scanf("%d", &L[op].qtd);
        if(L[op].qtd < 1) {
          printf("Ao menos uma cópia deve estar disponível para exemplar.\n");
        } else {
          break;
        }
      } 
      break;
    case 5:
      printf("Nova edição: ");
      scanf("%d", &L[op].edicao);
      break;
    case 6:
      printf("Novo ano de lançamento: ");
      scanf("%d", &L[op].ano);
      break;
    default:
      break;
  }
  printf("\nAlterando...\n");
  sleep(1);
  printf("\nAtualizado com sucesso!\n");
}

void cadastroU(struct User U[]){
  static int cont;
  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("Nome do usuário: ");
  scanf(" %[^\n]s", U[cont].nome);
  printf("Sobrenome do usuário: ");
  scanf(" %[^\n]s", U[cont].sobrenome);
  printf("Matrícula do usuário: ");
  scanf(" %[^\n]s", U[cont].matricula);
  while(1){
    printf("CPF do usuário: ");
    scanf(" %[^\n]s", U[cont].cpf);  
    if(strlen(U[cont].cpf) < 11 || strlen(U[cont].cpf) > 14) {
      printf("CPF deve conter 11 caractéres (sem . -) ou 14 caractéres (com . -).\n");
    } else {
      break;
    }
  } 
  printf("\nCadastrando usuário...\n");
  sleep(1);
  printf("\nUsuário cadastrado com sucesso!\n");
  sleep(1);
  cont++;
}

void atualizarU(struct User U[]){
}

void mostra(struct Livro L[]){
  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro para mostrar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
  } else {
    for (int i = 0; L[i].ano != 0; i++) {
      printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
      printf("Título do livro %d: %s\n", i + 1, L[i].titulo);
      printf("Classificação do livro %d: %s\n", i + 1, L[i].classificacao);
      printf("Autor do livro %d: %s\n", i + 1, L[i].autor);
      printf("Quantidade de cópias disponíveis do livro %d: %d\n", i + 1, L[i].qtd);
      printf("Edição do livro %d: %d\n", i + 1, L[i].edicao);
      printf("Ano de publicação do livro %d: %d\n", i + 1, L[i].ano);
      sleep(1);
    }
  }
}

void reservar(struct Livro L[]){
}

void devolver(struct Livro L[]){
}

void menu(){
	int opcao = 0;
	struct Livro L[30];
  struct User U[30];

	while(1){
		printf("\nBem vindo ao Sistema de Controle de Livros da UFU\n");
		printf("\n1- Cadastrar livro");
    printf("\n2- Atualizar livro");
    printf("\n3- Cadastrar usuário");
    printf("\n4- Atualizar usuário");
		printf("\n5- Mostrar todos os livros");
    printf("\n6- Reservar livro");
    printf("\n7- Devolver livro");
		printf("\n8- Sair ");
		printf("\n\nDigite opção: ");
		scanf("%d", &opcao);
  
		if(opcao == 1) cadastroL(L);
    if(opcao == 2) atualizarL(L);
    if(opcao == 3) cadastroU(U);
    if(opcao == 4) atualizarU(U);
		if(opcao == 5) mostra(L);
    if(opcao == 6) reservar(L);
    if(opcao == 7) devolver(L);
		if(opcao == 8) {
      printf("\nAté mais!\n");
      return;
    };
	}
}

int main(){
	menu();
}
