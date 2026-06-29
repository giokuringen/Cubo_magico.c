#include <stdio.h>
#include <string.h>
#include "cubo.h"


/* Ler arquivo do cubo, ignorando comentários e quebras de linha */
void ler_cubo(char *nome_arquivo, int cubo[6][3][3]){
  FILE *arquivo;
  arquivo = fopen(nome_arquivo, "r");

  if (!arquivo) { 
    printf("Erro, não foi possível abrir o arquivo '%s'\n", nome_arquivo);
    return;
    }

  char linha[256];
  int face = 0;
  int linha_face = 0;
  
/* Enquanto face for menor q 6 e fgets lendo a linha for diferente de NULL, remove comentarios e quebra de linhas */
  while(face < 6 && fgets(linha, sizeof(linha), arquivo) != NULL) {    
    linha[strcspn(linha, "#")] = '\0';
    linha[strcspn(linha, "\r\n")] = '\0';
    int cores[3];
    int qtd_cores = 0;
    
    int len = strlen(linha);
    if(len == 0) { continue; }

    if(len == 1 && strchr("UDLRFB", linha[0])) {
      printf("Lendo face: %c\n", linha[0]);
      continue;
    }


    for(int i = 0; linha[i] != '\0' && qtd_cores < 3; i++){
      char c = linha[i];
      int cor = -1;
      switch(c) {
        case 'W' : cor = BRANCO; break;
        case 'Y' : cor = AMARELO; break;
        case 'O' : cor = LARANJA; break;
        case 'R' : cor = VERMELHO; break;
        case 'G' : cor = VERDE; break;
        case 'B' : cor = AZUL; break;
        default : continue;
      }
      if (cor >= 0){
        cores[qtd_cores++] = cor;
      }
    }

    if (qtd_cores == 3){
      if (!linha_possivel(cores[0], cores[1],cores[2])){
        printf("Erro, cor inválida na face %d, linha %d\n", face, linha_face);
        fclose(arquivo);
        return; 
      }
      for(int j = 0; j < 3; j++){
        cubo[face][linha_face][j] = cores[j];
      }
      linha_face++;
      if(linha_face == 3){
        face++;
        linha_face = 0;
      }
    }
  }
  fclose(arquivo);

  if (face < 6) {
    printf("Aviso: Apenas %d faces foram lidas - esperado 6\n", face);
  }
}
