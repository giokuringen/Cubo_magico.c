#include "cubo.h"
#include <stdio.h>

void ler_cubo(char *nome_arquivo, int cubo[6][3][3]);
void imprime_cubo(int cubo[6][3][3]);
int confere_cubo(int cubo[6][3][3]);
void popular_cubo(int cubo[6][3][3]);
void resolve_cubo(int cubo[6][3][3]);

int main(int argc, char **argv) {
  int cubo[6][3][3];

  if (argc != 2) {
    printf("Uso: %s <arquivo_instancia>\n", argv[0]);
    return 1;
  }
  popular_cubo(cubo);
  printf("\n=-=-=-=-=-=-=-=-\nEstado Inicial:\n=-=-=-=-=-=-=-=-=\n");
  ler_cubo(argv[1], cubo);
  imprime_cubo(cubo);

  if (confere_cubo(cubo)) {
    printf("\nCubo resolvido!\n");
  } else {
    printf("\n[AVISO]: Cubo ainda não foi resolvido!\n");
    resolve_cubo(cubo);

    printf("\n=-=-=-=-=-=-=-=-\nEstado Final:\n=-=-=-=-=-=-=-=-=\n");
    imprime_cubo(cubo);

    if (confere_cubo(cubo)) {
      printf("\nCubo resolvido com sucesso!\n");
    } else {
      printf("\nFalha ao resolver cubo...\n");
    }
  }
  return 0;
} 