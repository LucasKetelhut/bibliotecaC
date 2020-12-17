#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Livro {
	char titulo[50] = "", classificacao[50] = "", autor[50] = "";
  int qtd = 0, edicao = 0, ano = 0;
};

struct User {
  char nome[50] = "", sobrenome[50] = "", matricula[50] = "", cpf[20] = "";
  int reservados = 0;
};

void cadastroL(struct Livro L[]){
  static int cont;
  char verTitulo[50] = "";
  int aux = 0;

  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");

  printf("Título do livro: ");
  scanf(" %[^\n]s", verTitulo);
  while(1) {  
    for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
      if (strcasecmp (verTitulo, L[i].titulo) == 0) {
        printf("\n[ERRO] Este título já está cadastrado, escolha outro.\n\n");
        aux = 1;
        break;
      }
    }
    if (aux == 1) {
      printf("Título do livro: ");
      scanf(" %[^\n]s", verTitulo);
      aux = 0;
    } else {
      strcpy (L[cont].titulo, verTitulo);
      break;
    }
  } 
  printf("Classificação do livro: ");
  scanf(" %[^\n]s", L[cont].classificacao);
  printf("Autor do livro: ");
  scanf(" %[^\n]s", L[cont].autor);
  while(1){
    printf("Quantidade de cópias disponíveis: ");
    scanf("%d", &L[cont].qtd);  
    if(L[cont].qtd < 1) {
      printf("\n[ERRO] Ao menos uma cópia deve estar disponível para exemplar.\n\n");
    } else {
      break;
    }
  } 
  printf("Edição do livro: ");
  scanf("%d", &L[cont].edicao);
  printf("Ano de publicação do livro: ");
  scanf("%d", &L[cont].ano);
  printf("\nCadastrando livro...\n");
  sleep(1);
  printf("\nLivro cadastrado com sucesso!\n");
  sleep(1);
  cont++;
}

void atualizarL(struct Livro L[]){
  int op = 0, att = 0, cont = 0, aux = 0;
  char verTitulo[50] = "";

  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro para atualizar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else {
    printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
    printf("Qual livro deseja atualizar? Digite o número do livro após a listagem.\n");
    sleep(2);
    for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
        printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
        printf("[%d]:\n", i + 1);
        printf("Título do livro %d: %s\n", i + 1, L[i].titulo);
        printf("Classificação do livro %d: %s\n", i + 1, L[i].classificacao);
        printf("Autor do livro %d: %s\n", i + 1, L[i].autor);
        printf("Quantidade de cópias disponíveis do livro %d: %d\n", i + 1, L[i].qtd);
        printf("Edição do livro %d: %d\n", i + 1, L[i].edicao);
        printf("Ano de publicação do livro %d: %d\n", i + 1, L[i].ano);
        cont++;
    }
  }
  while(1){
    printf("\nLivro a ser atualizado: ");
    scanf("%d", &op);
    if(op > cont || op <= 0) {
      printf("\n[ERRO] Opção inválida. Escolha uma opção de livro disponível.\n\n");
    } else {
      op--;
      break;
    }
  }
  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("O que deseja alterar?\n\n");
  while(1){
    printf("1- Título\n2- Classificação\n3- Autor\n4- Quantidade\n5- Edição\n6- Ano\n\n");
    printf("Opção escolhida: ");
    scanf("%d", &att);
    if(att == 1 || att == 2 || att == 3 || att == 4 || att == 5 || att == 6) {
      break;
    } else {
      printf("\n[ERRO] Opção inválida, selecione corretamente.\n\n");
    }
  }  
  printf("\n");
  switch(att) {
    case 1:
      printf("Novo título: ");
      scanf(" %[^\n]s", verTitulo);
      while (strcasecmp (verTitulo, L[op].titulo) == 0) {
        printf("\n[ERRO] Este já é o título atual do livro, digite um título diferente.\n\n");
        printf("Novo título: ");
        scanf(" %[^\n]s", verTitulo);
      }
      while(1) {  
        for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
          if (strcasecmp (verTitulo, L[i].titulo) == 0) {
            printf("\n[ERRO] Este título já está cadastrado, escolha outro.\n\n");
            aux = 1;
            break;
          }
        }
        if (aux == 1) {
          printf("Novo título: ");
          scanf(" %[^\n]s", verTitulo);
          aux = 0;
        } else {
          strcpy (L[op].titulo, verTitulo);
          break;
        }
      } 
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
          printf("\n[ERRO] Ao menos uma cópia deve estar disponível para exemplar.\n\n");
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
  printf("\nAlterando dados do livro...\n");
  sleep(1);
  printf("\nLivro atualizado com sucesso!\n");
}

void cadastroU(struct User U[]){
  static int cont;
  int aux1 = 0, aux2 = 0;
  char verCPF[20] = "", verMatricula[50] = "";

  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("Nome do usuário: ");
  scanf(" %[^\n]s", U[cont].nome);
  printf("Sobrenome do usuário: ");
  scanf(" %[^\n]s", U[cont].sobrenome);
  printf("Matrícula do usuário: ");
  scanf(" %[^\n]s", verMatricula);
  while(1) {  
    for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
      if (strcasecmp (verMatricula, U[i].matricula) == 0) {
        printf("\n[ERRO] Este número de matrícula já está cadastrado, escolha outro.\n\n");
        aux2 = 1;
        break;
      }
    }
    if (aux2 == 1) {
      printf("Matrícula do usuário: ");
      scanf(" %[^\n]s", verMatricula);
      aux2 = 0;
    } else {
      strcpy (U[cont].matricula, verMatricula);
      break;
    }
  }
  while(1){
    printf("CPF do usuário: ");
    scanf(" %[^\n]s", verCPF);
    while(1) {  
    for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
      if (strcasecmp (verCPF, U[i].cpf) == 0) {
        printf("\n[ERRO] Este CPF já está cadastrado, escolha outro.\n\n");
        aux1 = 1;
        break;
      }
    }
    if (aux1 == 1) {
      printf("CPF do usuário: ");
      scanf(" %[^\n]s", verCPF);
      aux1 = 0;
    } else {
      strcpy (U[cont].cpf, verCPF);
      break;
    }
  } 
    if(strlen(verCPF) != 14) {
      printf("\n[ERRO] CPF deve conter \".\" e \"-\" (exemplo: 123.456.789-00)\n\n");
    } else {
      break;
    } 
  }
  U[cont].reservados = 0; 
  printf("\nCadastrando usuário...\n");
  sleep(1);
  printf("\nUsuário cadastrado com sucesso!\n");
  sleep(1);
  cont++;
}

void atualizarU(struct User U[]){
  int op = 0, att = 0, cont = 0, aux1 = 0, aux2 = 0;
  char verCPF[20] = "", verMatricula[50] = "";

  if(strcmp(U[0].cpf, "") == 0) {
    printf("\nNenhum usuário para atualizar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else {
    printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
    printf("Qual usuário deseja atualizar? Digite o número do usuário após a listagem.\n");
    sleep(2);
    for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
        printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
        printf("[%d]:\n", i + 1);
        printf("Nome do usuário %d: %s\n", i + 1, U[i].nome);
        printf("Sobrenome do usuário %d: %s\n", i + 1, U[i].sobrenome);
        printf("Matrícula do usuário %d: %s\n", i + 1, U[i].matricula);
        printf("CPF do usuário %d: %s\n", i + 1, U[i].cpf);
        cont++;
    }
  }
  while(1){
    printf("\nUsuário a ser atualizado: ");
    scanf("%d", &op);
    if(op > cont || op <= 0){
      printf("\n[ERRO] Opção inválida. Escolha uma opção de usuário disponível.\n\n");
    } else {
      op--;
      break;
    }
  }
  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("O que deseja alterar?\n\n");
  while(1){
    printf("1- Nome\n2- Sobrenome\n3- Matrícula\n4- CPF\n\n");
    printf("Opção escolhida: ");
    scanf("%d", &att);
    if(att == 1 || att == 2 || att == 3 || att == 4) {
      break;
    } else {
      printf("\n[ERRO] Opção inválida, selecione corretamente.\n\n");
    }
  }  
  printf("\n");
  switch(att) {
    case 1:
      printf("Novo nome: ");
      scanf(" %[^\n]s", U[op].nome);
      break;
    case 2:
      printf("Novo sobrenome: ");
      scanf(" %[^\n]s", U[op].sobrenome);
      break;
    case 3:
      printf("Nova matrícula: ");
      scanf(" %[^\n]s", verMatricula);
      while (strcasecmp(verMatricula, U[op].matricula) == 0) {
        printf("\n[ERRO] Este número de matrícula já é o atual do usuário. Digite outro.\n\n");
        printf("Nova matrícula: ");
        scanf(" %[^\n]s", verMatricula);
      }
      while(1) {  
        for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
          if (strcasecmp (verMatricula, U[i].matricula) == 0) {
            printf("\n[ERRO] Este número de matrícula já está cadastrado, escolha outro.\n\n");
            aux2 = 1;
            break;
          }
        }
        if (aux2 == 1) {
          printf("Nova matrícula: ");
          scanf(" %[^\n]s", verMatricula);
          aux2 = 0;
        } else {
          strcpy (U[op].matricula, verMatricula);
          break;
        }
      }
      break;
    case 4:
      while(1){
      printf("Novo CPF: ");
      scanf(" %[^\n]s", verCPF);  
      while (strcasecmp(verCPF, U[op].cpf) == 0) {
        printf("\n[ERRO] Este CPF já é o atual do usuário. Digite outro.\n\n");
        printf("Novo CPF: ");
        scanf(" %[^\n]s", verCPF);
      }
      while(1) {  
        for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
          if (strcasecmp (verCPF, U[i].cpf) == 0) {
            printf("\n[ERRO] Este CPF já está cadastrado, escolha outro.\n\n");
            aux1 = 1;
            break;
          }
        }
        if (aux1 == 1) {
          printf("Novo CPF: ");
          scanf(" %[^\n]s", verCPF);
          aux1 = 0;
        } else {
          strcpy (U[op].cpf, verCPF);
          break;
        }
      }
      if(strlen(U[op].cpf) != 14) {
        printf("\n[ERRO] CPF deve conter \".\" e \"-\" (exemplo: 123.456.789-00)\n\n");
      } else {
        break;
      }
      } 
      break;
    default:
      break;
  }
  printf("\nAlterando dados do usuário...\n");
  sleep(1);
  printf("\nUsuário atualizado com sucesso!\n");
}

void mostraL(struct Livro L[]){
  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro para mostrar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
  } else {
    for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
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

void mostraU(struct User U[]){
  if(strcmp(U[0].cpf, "") == 0) {
    printf("\nNenhum usuário para mostrar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
  } else {
    for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
      printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
      printf("Nome do usuário %d: %s\n", i + 1, U[i].nome);
      printf("Sobrenome do usuário %d: %s\n", i + 1, U[i].sobrenome);
      printf("Matrícula do usuário %d: %s\n", i + 1, U[i].matricula);
      printf("CPF do usuário %d: %s\n", i + 1, U[i].cpf);
      printf("Livros reservados pelo usuário %d: %d\n", i + 1, U[i].reservados);
      sleep(1);
    }
  }
}

void reservar(struct Livro L[], struct User U[]){
  int reservado = 0, reservando = 0, cont1 = 0, cont2 = 0; 
  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro disponível para reservar.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else if(strcmp(U[0].cpf, "") == 0) {
    printf("\nNenhum usuário disponível para fazer uma reserva.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else {
    printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
    printf("Qual livro deseja reservar? Digite o número do livro após a listagem.\n");
    sleep(2);
    for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
        printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
        printf("[%d]:\n", i + 1);
        printf("Título do livro %d: %s\n", i + 1, L[i].titulo);
        printf("Classificação do livro %d: %s\n", i + 1, L[i].classificacao);
        printf("Autor do livro %d: %s\n", i + 1, L[i].autor);
        printf("Quantidade de cópias disponíveis do livro %d: %d\n", i + 1, L[i].qtd);
        printf("Edição do livro %d: %d\n", i + 1, L[i].edicao);
        printf("Ano de publicação do livro %d: %d\n", i + 1, L[i].ano);
        cont1++;
    }
  }
  while(1){
    printf("\nLivro a ser reservado: ");
    scanf("%d", &reservado);
    if (reservado > cont1 || reservado <= 0) {
      printf("\n[ERRO] Opção incorreta, digite uma opção válida de livro disponível.\n\n");
    } else if (L[reservado - 1].qtd == 1){
      printf("\n[ERRO] Este livro só tem uma cópia disponível, e esta deve ficar de exemplar dentro da biblioteca. Escolha outro livro para reservar.\n\n");
      sleep(2);
    } else {
      reservado--;
      L[reservado].qtd--;
      break;
    }
  }
  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("Qual usuário está fazendo a reserva? Digite o número do usuário após a listagem.\n");
  sleep(2);
  for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
      printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
      printf("[%d]:\n", i + 1);
      printf("Nome do usuário %d: %s\n", i + 1, U[i].nome);
      printf("Sobrenome do usuário %d: %s\n", i + 1, U[i].sobrenome);
      printf("Matrícula do usuário %d: %s\n", i + 1, U[i].matricula);
      printf("CPF do usuário %d: %s\n", i + 1, U[i].cpf);
      printf("Livros reservados pelo usuário %d: %d\n", i + 1, U[i].reservados);
      cont2++;
  }
  while(1){
  printf("\nUsuário que está fazendo a reserva: ");
  scanf("%d", &reservando);
  if (reservando > cont2 || reservando <= 0) {
    printf("\n[ERRO] Opção incorreta, digite uma opção válida de usuário disponível.\n\n");
  } else {
    reservando--;
    U[reservando].reservados++;
    break;
  } 
  }
  printf("\nFazendo reserva...\n");
  sleep(1);
  printf("\nLivro reservado com sucesso!\n");
}

void devolver(struct Livro L[], struct User U[]){
  int devolvido = 0, devolvendo = 0, cont1 = 0, cont2 = 0; 
  if(strcmp(L[0].titulo, "") == 0) {
    printf("\nNenhum livro disponível para fazer uma devolução.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else if(strcmp(U[0].nome, "") == 0) {
    printf("\nNenhum usuário disponível para fazer uma devolução.\n");
    printf("\nRetornando ao menu...\n");
    sleep(1);
    return;
  } else {
    printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
    printf("Qual livro está sendo devolvido? Digite o número do livro após a listagem.\n");
    sleep(2);
    for (int i = 0; strcmp(L[i].titulo, "") != 0; i++) {
        printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
        printf("[%d]:\n", i + 1);
        printf("Título do livro %d: %s\n", i + 1, L[i].titulo);
        printf("Classificação do livro %d: %s\n", i + 1, L[i].classificacao);
        printf("Autor do livro %d: %s\n", i + 1, L[i].autor);
        printf("Quantidade de cópias disponíveis do livro %d: %d\n", i + 1, L[i].qtd);
        printf("Edição do livro %d: %d\n", i + 1, L[i].edicao);
        printf("Ano de publicação do livro %d: %d\n", i + 1, L[i].ano);
        cont1++;
    }
  }
  while(1){
    printf("\nLivro a ser devolvido: ");
    scanf("%d", &devolvido);
    if (devolvido > cont1 || devolvido <= 0) {
      printf("\n[ERRO] Opção incorreta, digite uma opção válida de livro disponível.\n\n");
    } else {
      devolvido--;
      L[devolvido].qtd++;
      break;
    }
  }
  printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
  printf("Qual usuário está fazendo a devolução? Digite o número do usuário após a listagem.\n");
  sleep(2);
  for (int i = 0; strcmp(U[i].cpf, "") != 0; i++) {
      printf("\n*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*---*\n\n");
      printf("[%d]:\n", i + 1);
      printf("Nome do usuário %d: %s\n", i + 1, U[i].nome);
      printf("Sobrenome do usuário %d: %s\n", i + 1, U[i].sobrenome);
      printf("Matrícula do usuário %d: %s\n", i + 1, U[i].matricula);
      printf("CPF do usuário %d: %s\n", i + 1, U[i].cpf);
      printf("Livros reservados pelo usuário %d: %d\n", i + 1, U[i].reservados);
      cont2++;
  }
  while(1){
  printf("\nUsuário que está fazendo a reserva: ");
  scanf("%d", &devolvendo);
  if (devolvendo > cont2 || devolvendo <= 0) {
    printf("\n[ERRO] Opção incorreta, digite uma opção válida de usuário disponível.\n\n");
  } else if (U[devolvendo - 1].reservados == 0) {
    printf("\n[ERRO] Este usuário não possui nenhum livro reservado para fazer uma devolução.\n\n");
  } else {
    devolvendo--;
    U[devolvendo].reservados--;
    break;
  } 
  }
  printf("\nFazendo devolução...\n");
  sleep(1);
  printf("\nLivro devolvido com sucesso!\n");
}

void menu(){
	int opcao = 0;
	struct Livro L[30];
  struct User U[30];

	while(1){
    while (1) {
		printf("\nBem vindo ao Sistema de Controle de Livros da UFU\n");
		printf("\n1- Cadastrar livro");
    printf("\n2- Cadastrar usuário");
    printf("\n3- Atualizar livro");
    printf("\n4- Atualizar usuário");
		printf("\n5- Mostrar todos os livros");
    printf("\n6- Mostrar todos os usuários");
    printf("\n7- Reservar livro");
    printf("\n8- Devolver livro");
		printf("\n9- Sair ");
		printf("\n\nDigite opção: ");
		scanf("%d", &opcao);
    if (opcao < 1 || opcao > 9) { 
      printf("\n[ERRO] Opção inválida. Escolha uma opção válida.\n");
    } else {
      break;
    }
    }
		if(opcao == 1) cadastroL(L);
    if(opcao == 2) cadastroU(U);
    if(opcao == 3) atualizarL(L);
    if(opcao == 4) atualizarU(U);
		if(opcao == 5) mostraL(L);
    if(opcao == 6) mostraU(U);
    if(opcao == 7) reservar(L, U);
    if(opcao == 8) devolver(L, U);
		if(opcao == 9) {
      printf("\nEncerrando o programa...\n");
      sleep(1);
      printf("\nAté mais!\n\n");
      return;
    };
	}
}

int main(){
	menu();
}
