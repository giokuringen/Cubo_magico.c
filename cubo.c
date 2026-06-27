#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubo.h"

/* k = indice da rotação antihoraria */
/* */


/* Verificando o cubo */
int confere_cubo(int cubo[6][3][3]) {
  int face, linha, coluna;
  int cor_pivo;

  for (face = 0; face < 6; face++) {
    cor_pivo = cubo[face][1][1];

    for (linha = 0; linha < 3; linha++) {
      for (coluna = 0; coluna < 3; coluna++) {
        if (cubo[face][linha][coluna] != cor_pivo) {
          return 0;
        }
      }
    }
  }
  return 1;
}

/* Popular cubo */
void popular_cubo(int cubo[6][3][3]) {
  for (int face = 0; face < 6; face++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cubo[face][i][j] = face;
      }
    }
  }
}

/* Exemplo do arquivo_legal.c */
void rotacionar_matriz_90(int face[3][3]) {
  int temp[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      temp[i][j] = face[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face[j][2 - i] = temp[i][j];
    }
  }
}

/* Rotação antihoraria se consegue utilizando a horaria 3 vezes*/
void rotacionar_matriz_270(int face[3][3]){
  for(int k = 0; k < 3; k++){ rotacionar_matriz_90(face);}
}

void girar_cima_horario(int cubo[6][3][3]){
  rotacionar_matriz_90(cubo[0]);
  int temp[3];

  for(int i = 0; i < 3; i++){ temp[i] = cubo[5][0][i];}
  for(int i = 0; i < 3; i++){ cubo[5][0][i] = cubo[2][0][i];}
  for(int i = 0; i < 3; i++){ cubo[2][0][i] = cubo[4][0][i];}
  for(int i = 0; i < 3; i++){ cubo[4][0][i] = cubo[3][0][i];}
  for(int i = 0; i < 3; i++){ cubo[3][0][i] = temp[i];}
}

void girar_cima_antihorario(int cubo[6][3][3]){
  for(int k = 0; k < 3; k++){ girar_cima_horario(cubo);}
}

void girar_baixo_horario(int cubo[6][3][3]){
  rotacionar_matriz_90(cubo[1]);
  int temp[3];

  for(int i = 0; i < 3; i++) {temp[i] = cubo[4][2][i];}
  for(int i = 0; i < 3; i++) {cubo[4][2][i] = cubo[2][2][i];}
  for(int i = 0; i < 3; i++) {cubo[2][2][i] = cubo[5][2][i];}
  for(int i = 0; i < 3; i++) {cubo[5][2][i] = cubo[3][2][i];}
  for(int i = 0; i < 3; i++) {cubo[3][2][i] = temp[i];}

}

void girar_baixo_antihorario(int cubo[6][3][3]){
  for(int k = 0; k < 3; k++){ girar_baixo_horario(cubo); }
}

void girar_esquerda_horario(int cubo[6][3][3]){
  rotacionar_matriz_90(cubo[2]);
  int temp[3];

  for(int i = 0; i < 3; i++){ temp[i] = cubo[0][i][0]; }
  for(int i = 0; i < 3; i++){ cubo[0][i][0] = cubo[5][2 - i][2]; }
  for(int i = 0; i < 3; i++){ cubo[5][i][2] = cubo[1][i][0];}
  for(int i = 0; i < 3; i++){ cubo[1][i][0] = cubo[4][i][0];}
  for(int i = 0; i < 3; i++){ cubo[4][i][0] = temp[i];}
}

void girar_esquerda_antihorario(int cubo[6][3][3]){
  for(int k = 0; k < 3; k++){ girar_esquerda_horario(cubo);}
}

void girar_direita_horario(int cubo[6][3][3]){
  rotacionar_matriz_90(cubo[3]);
  int temp[3];

  for(int i = 0; i < 3;i++) { temp[i] = cubo[0][i][2];}
  for(int i = 0; i < 3;i++) { cubo[0][i][2] = cubo[4][i][2];}
  for(int i = 0; i < 3;i++) { cubo[4][i][2] = cubo[1][i][2];}
  for(int i = 0; i < 3;i++) { cubo[1][i][2] = cubo[5][2 - i][0];}
  for(int i = 0; i < 3;i++) { cubo[5][i][0] = temp[i];}
}

void girar_direita_antihorario(int cubo[6][3][3]){
  for(int k = 0; k < 3; k++){ girar_direita_horario(cubo);}
}

void girar_frente_horario(int cubo[6][3][3]){
  rotacionar_matriz_90(cubo[4]);
  int temp[3];
  
  for(int i = 0; i < 3; i++){ temp[i] = cubo[0][2][i]; }
  for(int i = 0; i < 3; i++){ cubo[0][2][i] = cubo[2][2 - i][2]; }
  for(int i = 0; i < 3; i++){ cubo[2][i][2] = cubo[1][0][i]; }
  for(int i = 0; i < 3; i++){ cubo[1][0][i] = cubo[3][2 - i][0]; }
  for(int i = 0; i < 3; i++){ cubo[3][i][0] = temp[2 - i]; }
}

void girar_frente_antihorario(int cubo[6][3][3]){
  for(int k = 0;k < 3; k++){ girar_frente_horario(cubo);}
}

void girar_tras_horario(int cubo[6][3][3]){
  rotacionar_matriz_90(cubo[5]);
  int temp[3];

  for(int i = 0; i < 3; i++){ temp[i] = cubo[0][0][i];}
  for(int i = 0; i < 3; i++){ cubo[0][0][i] = cubo[3][2][i];}
  for(int i = 0; i < 3; i++){ cubo[3][2][i] = cubo[1][2][i];}
  for(int i = 0; i < 3; i++){ cubo[1][2][i] = cubo[2][0][i];}
  for(int i = 0; i < 3; i++){ cubo[2][0][i] = temp[i]; }
}

void girar_tras_antihorario(int cubo[6][3][3]){
  for(int k = 0; k < 3; k++){ girar_tras_horario(cubo);}
}

/* Rascunho da rotação */
void rotacionar_face(int cubo[6][3][3], enum Face face, enum Direcao sentido) {
  if (!face_possivel((int)face) || !direcao_possivel((int)sentido)) {
    printf("Erro, face ou direção inválida\n");
    return;
  }
  if (sentido == HORARIO){
    switch(face) {
      case CIMA: girar_cima_horario(cubo); break;
      case BAIXO: girar_baixo_horario(cubo); break;
      case ESQUERDA: girar_esquerda_horario(cubo); break;
      case DIREITA: girar_direita_horario(cubo); break;
      case FRENTE: girar_frente_horario(cubo); break;
      case TRAS: girar_tras_horario(cubo); break;
    }
  }
  else{
    switch(face){
      case CIMA: girar_cima_antihorario(cubo); break;
      case BAIXO: girar_baixo_antihorario(cubo); break;
      case ESQUERDA: girar_esquerda_antihorario(cubo); break;
      case DIREITA: girar_direita_antihorario(cubo); break;
      case FRENTE: girar_frente_antihorario(cubo); break;
      case TRAS: girar_tras_antihorario(cubo); break;
    }
  }
}

void copiar_cubo(int origem[6][3][3], int destino[6][3][3]) {
  for (int face = 0; face < 6; face++)
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        destino[face][i][j] = origem[face][i][j];
}

// ===================== BFS Solver =====================

#define BFS_LIMITE_PROF 7
#define BFS_MAX_NOS 400000
#define BFS_HASH_CAP (1 << 20)  // 1M buckets, potência de 2

typedef struct {
    char estado[54];  // cubo codificado (54 células, valores 0-5)
    char prof;
} NoBFS;

typedef struct {
    char chave[54];
    char usado;
} BucketBFS;

static void codificar(int cubo[6][3][3], char est[54]) {
    int k = 0;
    for (int f = 0; f < 6; f++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                est[k++] = (char)cubo[f][i][j];
}

static void decodificar(const char est[54], int cubo[6][3][3]) {
    int k = 0;
    for (int f = 0; f < 6; f++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cubo[f][i][j] = (int)(unsigned char)est[k++];
}

static unsigned int hash_cubo(const char est[54]) {
    unsigned int h = 2166136261u;
    for (int i = 0; i < 54; i++) {
        h ^= (unsigned char)est[i];
        h *= 16777619u;
    }
    return h & (BFS_HASH_CAP - 1);
}

// Retorna 1 se inseriu (estado novo), 0 se já estava na tabela
static int ht_inserir_bfs(BucketBFS *ht, const char est[54]) {
    unsigned int idx = hash_cubo(est);
    while (ht[idx].usado) {
        if (memcmp(ht[idx].chave, est, 54) == 0) return 0;
        idx = (idx + 1) & (BFS_HASH_CAP - 1);
    }
    ht[idx].usado = 1;
    memcpy(ht[idx].chave, est, 54);
    return 1;
}

int resolver_bfs(int cubo[6][3][3]) {
    if (confere_cubo(cubo)) return 1;

    NoBFS *fila = malloc(BFS_MAX_NOS * sizeof(NoBFS));
    BucketBFS *ht = calloc(BFS_HASH_CAP, sizeof(BucketBFS));
    if (!fila || !ht) {
        free(fila);
        free(ht);
        return -1;
    }

    int inicio = 0, fim = 0;
    int resultado = 0;

    char est_inicial[54];
    codificar(cubo, est_inicial);
    memcpy(fila[fim].estado, est_inicial, 54);
    fila[fim].prof = 0;
    fim = (fim + 1) % BFS_MAX_NOS;
    ht_inserir_bfs(ht, est_inicial);

    while (inicio != fim && !resultado) {
        NoBFS no = fila[inicio];
        inicio = (inicio + 1) % BFS_MAX_NOS;

        if ((int)no.prof >= BFS_LIMITE_PROF) continue;

        int cubo_atual[6][3][3];
        decodificar(no.estado, cubo_atual);

        for (int face = 0; face < 6 && !resultado; face++) {
            for (int dir = 0; dir < 2 && !resultado; dir++) {
                int filho[6][3][3];
                copiar_cubo(cubo_atual, filho);
                rotacionar_face(filho, (enum Face)face, (enum Direcao)dir);

                char est_filho[54];
                codificar(filho, est_filho);
                if (!ht_inserir_bfs(ht, est_filho)) continue;

                if (confere_cubo(filho)) {
                    copiar_cubo(filho, cubo);
                    resultado = 1;
                    break;
                }

                int prox = (fim + 1) % BFS_MAX_NOS;
                if (prox == inicio) {
                    printf("Fila BFS cheia — aumente BFS_MAX_NOS.\n");
                    resultado = -1;
                    break;
                }
                memcpy(fila[fim].estado, est_filho, 54);
                fila[fim].prof = no.prof + 1;
                fim = (fim + 1) % BFS_MAX_NOS;
            }
        }
    }

    free(fila);
    free(ht);
    return resultado;
}

void resolve_cubo_bfs(int cubo[6][3][3]) {
    printf("\nIniciando resolução (limite: %d movimentos)...\n", BFS_LIMITE_PROF);
    int r = resolver_bfs(cubo);
    if (r == 1)
        printf("Cubo resolvido!\n");
    else if (r == 0)
        printf("Solução não encontrada em %d movimentos.\n", BFS_LIMITE_PROF);
}

void resolve_cubo(int cubo[6][3][3]) {
    resolve_cubo_bfs(cubo);
}

/* Imprime cubo e faces*/
void imprime_face(int cubo[6][3][3], enum Face f) {
    printf("Face %d:\n", f);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%c ", letras_cor[cubo[f][i][j]]); 
      }
      printf("\n");
  }
}

void imprime_cubo(int cubo[6][3][3]) {
  for (int faces = 0; faces < 6; faces++) {
    imprime_face(cubo, faces);
    printf("\n");
  }
}

int cor_possivel(int cor) {    // verifica se a cor esta certa 
    if (cor >= 0 && cor <= 5) return 1;

   return 0;
}


int linha_possivel(int a, int b, int c){   // verifica a ordem possivel
    if (!cor_possivel(a) || !cor_possivel(b) || !cor_possivel(c)) 
    return 0;

    return 1;
}

int face_possivel (int face){ // verifica as faces do cubo 
    if (face >= 0 && face <=5) return 1;


    return 0;
}

 
int movimento_possivel(enum Rotacao movimento){  // verifica as coordenadas
    if (movimento >= 0 && movimento <= 3) return 1;

    return 0;
}

int direcao_possivel(int direcao){   // verifica rota
    if (direcao >= 0 && direcao <= 1) return 1;

    return 0;
}


