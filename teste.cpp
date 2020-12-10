#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
  struct Nome {
    char sobrenome[30], nome[30];
  };
  int n, cont = 0;

  Nome Pessoas[10];

  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    printf("\nNome da pessoa %d: ", i + 1);
    scanf(" %[^\n]s", Pessoas[i].nome);
    printf("Sobrenome da pessoa %d: ", i + 1);
    scanf(" %[^\n]s", Pessoas[i].sobrenome);
    cont++;
  }

  for(int i = 0; i < n; i++) {
    printf("\nNome da pessoa %d: %s\n", i + 1, Pessoas[i].nome);
    printf("Sobrenome da pessoa %d: %s\n", i + 1, Pessoas[i].sobrenome);
  }

  printf("\nPessoas armazenadas: %d\n", cont);
}