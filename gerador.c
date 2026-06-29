#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_FACES 6
#define NUM_LINCOL 3

void salvar_arquivo(int cubo[6][3][3], const char *nome_arquivo) {
  FILE *arquivo = fopen(nome_arquivo, "w");
  if (!arquivo) {
    printf("Erro ao abrir o arquivo!");
    return;
  }

  for (int face = 0; face < NUM_FACES; face++) {
    fprintf(arquivo, "%c\n", letras_face[face]);
    for (int i = 0; i < NUM_LINCOL; i++) {
      for (int j = 0; j < NUM_LINCOL; j++) {
        fprintf(arquivo, "%c", letras_cor[cubo[face][i][j]]);
      }
      fprintf(arquivo, "\n");
    }
  }
  fclose(arquivo);
}

int embaralhador(int cubo[6][3][3]) {
    int num_movimentos = 5 + rand() % 5;
    
    for(int i = 0; i < num_movimentos; i++) {
        enum Face face = rand() % 6;
        enum Direcao direcao = rand() % 2;
        rotacionar_face(cubo, face, direcao);
    }
    
    return num_movimentos;
}


int main(int argc, char **argv) {

  srand(time(NULL));
  /* Evita segmentatio fault, nao deixando o usuario utilizar o programa sem argumentos*/
  if (argc < 2) {
    printf("Modo de usar: %s <numero_de_cubos [nome]\n", argv[0]);
    printf("Exemplo: %s 5 cubo_embaralhado\n", argv[0]);
    return 1;
  }
  /* atoi vai retornar zero caso o argv[1] seja um número inválido, dai evita loops infinitos e etc*/
  int N = atoi(argv[1]);
  if (N <= 0) {
    printf("Erro: N deve ser maior que zero!\n");
    return 1;
  }
  /* nome padrão caso o usuario nao defina nenhum prefixo para os cubos */
  char nome[100] = "cubo_embaralhado";
  if (argc >= 3) {
    strncpy(nome, argv[2], sizeof(nome) - 1);
    nome[sizeof(nome) - 1] = '\0';
  }

  printf("Gerando %d cubos embaralhados...\n", N);

  for (int i = 0; i < N; i++) {
    int cubo[6][3][3];
    popular_cubo(cubo);
    int movimentos = embaralhador(cubo);
    char nome_arquivo[200];
    sprintf(nome_arquivo, "%s_%02d.txt", nome, i + 1);

    salvar_arquivo(cubo, nome_arquivo);
    printf("Cubo %d: %s (Movimentos utilizados %d)\n", i + 1, nome_arquivo,
           movimentos);
  }

  printf("\n%d Cubos embaralhados com sucesso!\n", N);
  return 0;
}
