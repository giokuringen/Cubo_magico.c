#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Rotaciona uma matriz 3x3 em 90 graus no sentido horario */
void rotacionar_matriz_90(int face[3][3]) {
    int temp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[i][j] = face[i][j];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = temp[2 - j][i]; 
}

/* Verificações */

int confere_cubo(int cubo[6][3][3]) {
    for (int face = 0; face < 6; face++) {
        int cor_esperada = cubo[face][1][1];  
        for (int linha = 0; linha < 3; linha++) {
            for (int coluna = 0; coluna < 3; coluna++) {
                if (cubo[face][linha][coluna] != cor_esperada) {
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

/* CIMA - Horario */
void girar_cima_horario(int cubo[6][3][3]) {
    rotacionar_matriz_90(cubo[0]);
    int temp[3];
    for (int i = 0; i < 3; i++) {temp[i] = cubo[4][0][i];}
    for (int i = 0; i < 3; i++) {cubo[4][0][i] = cubo[3][0][i];}
    for (int i = 0; i < 3; i++) {cubo[3][0][i] = cubo[5][0][i];}
    for (int i = 0; i < 3; i++) {cubo[5][0][i] = cubo[2][0][i];}
    for (int i = 0; i < 3; i++) {cubo[2][0][i] = temp[i];}
}

/* CIMA - Anti-horario */
void girar_cima_antihorario(int cubo[6][3][3]) {
    girar_cima_horario(cubo);
    girar_cima_horario(cubo);
    girar_cima_horario(cubo);
}

/* BAIXO - Horario */
void girar_baixo_horario(int cubo[6][3][3]) {
    rotacionar_matriz_90(cubo[1]);
    int temp[3];
    for (int i = 0; i < 3; i++) {temp[i] = cubo[4][2][i];}
    for (int i = 0; i < 3; i++) {cubo[4][2][i] = cubo[2][2][i];}
    for (int i = 0; i < 3; i++) {cubo[2][2][i] = cubo[5][2][i];}
    for (int i = 0; i < 3; i++) {cubo[5][2][i] = cubo[3][2][i];}
    for (int i = 0; i < 3; i++) {cubo[3][2][i] = temp[i];}
}

/* BAIXO - Anti-horario */
void girar_baixo_antihorario(int cubo[6][3][3]) {
    girar_baixo_horario(cubo);
    girar_baixo_horario(cubo);
    girar_baixo_horario(cubo);
}

/* ESQUERDA - Horario */
void girar_esquerda_horario(int cubo[6][3][3]) {
    rotacionar_matriz_90(cubo[2]);
    int temp[3];
    for (int i = 0; i < 3; i++){ temp[i] = cubo[4][i][0];}
    for (int i = 0; i < 3; i++){ cubo[4][i][0] = cubo[0][i][0];}
    for (int i = 0; i < 3; i++){ cubo[0][i][0] = cubo[5][2-i][2];}
    for (int i = 0; i < 3; i++){ cubo[5][i][2] = cubo[1][2-i][0];}
    for (int i = 0; i < 3; i++){ cubo[1][i][0] = temp[i];}
}

/* ESQUERDA - Anti-horario */
void girar_esquerda_antihorario(int cubo[6][3][3]) {
    girar_esquerda_horario(cubo);
    girar_esquerda_horario(cubo);
    girar_esquerda_horario(cubo);
}

/* DIREITA - Horario */
void girar_direita_horario(int cubo[6][3][3]) {
    rotacionar_matriz_90(cubo[3]);
    int temp[3];
    for (int i = 0; i < 3; i++) {temp[i] = cubo[4][i][2];}
    {cubo[4][0][2] = cubo[1][2][2];}
    {cubo[4][1][2] = cubo[1][1][2];}
    {cubo[4][2][2] = cubo[1][0][2];}
    {cubo[1][0][2] = cubo[5][0][0];}  
    {cubo[1][1][2] = cubo[5][1][0];}
    {cubo[1][2][2] = cubo[5][2][0];}
    {cubo[5][0][0] = cubo[0][0][2];}
    {cubo[5][1][0] = cubo[0][1][2];}
    {cubo[5][2][0] = cubo[0][2][2];}
    {cubo[0][0][2] = temp[0];}
    {cubo[0][1][2] = temp[1];}
    {cubo[0][2][2] = temp[2];}
}

/* DIREITA - Anti-horario */
void girar_direita_antihorario(int cubo[6][3][3]) {
    girar_direita_horario(cubo);
    girar_direita_horario(cubo);
    girar_direita_horario(cubo);
}

/* FRENTE - Horario */
void girar_frente_horario(int cubo[6][3][3]) {
    rotacionar_matriz_90(cubo[4]);
    int temp[3];
    for (int i = 0; i < 3; i++){ temp[i] = cubo[0][2][i];}
    for (int i = 0; i < 3; i++){ cubo[0][2][i] = cubo[2][2-i][2];}
    for (int i = 0; i < 3; i++){ cubo[2][i][2] = cubo[1][0][i];}
    for (int i = 0; i < 3; i++){ cubo[1][0][i] = cubo[3][2-i][0];}
    for (int i = 0; i < 3; i++){ cubo[3][i][0] = temp[i];}
}

/* FRENTE - Anti-horario*/
void girar_frente_antihorario(int cubo[6][3][3]) {
    girar_frente_horario(cubo);
    girar_frente_horario(cubo);
    girar_frente_horario(cubo);
}

/* TRAS - Horario */
void girar_tras_horario(int cubo[6][3][3]) {
    rotacionar_matriz_90(cubo[5]);
    int temp[3];
    for (int i = 0; i < 3; i++){ temp[i] = cubo[0][0][i];}
    for (int i = 0; i < 3; i++){ cubo[0][0][i] = cubo[3][i][2];}  
    for (int i = 0; i < 3; i++){ cubo[3][i][2] = cubo[1][2-i][0];}  
    for (int i = 0; i < 3; i++){ cubo[1][i][0] = cubo[2][i][0];}  
    for (int i = 0; i < 3; i++){ cubo[2][i][0] = temp[i];}
}

/* TRAS - Anti-horario */
void girar_tras_antihorario(int cubo[6][3][3]) {
    girar_tras_horario(cubo);
    girar_tras_horario(cubo);
    girar_tras_horario(cubo);
}

/* Rotacionar face */

void rotacionar_face(int cubo[6][3][3], enum Face face, enum Direcao sentido) {
    if (!face_possivel(face) || !direcao_possivel(sentido)) {
        printf("Erro, face ou direcao invalida\n");
        return;
    }
    if (sentido == HORARIO) {
        switch (face) {
            case CIMA: girar_cima_horario(cubo); break;
            case BAIXO: girar_baixo_horario(cubo); break;
            case ESQUERDA: girar_esquerda_horario(cubo); break;
            case DIREITA: girar_direita_horario(cubo); break;
            case FRENTE: girar_frente_horario(cubo); break;
            case TRAS: girar_tras_horario(cubo); break;
        }
    } else {
        switch (face) {
            case CIMA: girar_cima_antihorario(cubo); break;
            case BAIXO: girar_baixo_antihorario(cubo); break;
            case ESQUERDA: girar_esquerda_antihorario(cubo); break;
            case DIREITA: girar_direita_antihorario(cubo); break;
            case FRENTE: girar_frente_antihorario(cubo); break;
            case TRAS: girar_tras_antihorario(cubo); break;
        }
    }
}

/* Copiar cubo */

void copiar_cubo(int origem[6][3][3], int destino[6][3][3]) {
    for (int face = 0; face < 6; face++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                destino[face][i][j] = origem[face][i][j];
}



/* Algoritmo BFS solver */

#define BFS_LIMITE_PROF 8
#define BFS_MAX_NOS 8000000
#define BFS_HASH_CAP (1 << 20)

typedef struct {
    char estado[54];
    char prof;
    int  pai;       // índice do nó pai na fila (-1 para a raiz)
    char mov_face;  // face rotacionada para chegar nesse nó
    char mov_dir;   // direção da rotação
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

static const char *nome_face_bfs(int f) {
    switch (f) {
        case 0: return "U"; case 1: return "D";
        case 2: return "L"; case 3: return "R";
        case 4: return "F"; case 5: return "B";
    }
    return "?";
}

static void imprimir_caminho(NoBFS *fila, int sol_idx) {
    /* Percorre os pais do nó solução até a raiz e inverte */
    char faces[BFS_LIMITE_PROF];
    char dirs[BFS_LIMITE_PROF];
    int  len = 0;

    int idx = sol_idx;
    while (fila[idx].pai != -1) {
        faces[len] = fila[idx].mov_face;
        dirs[len]  = fila[idx].mov_dir;
        len++;
        idx = fila[idx].pai;
    }

    printf("\nSequência de movimentos (%d movimentos):\n", len);
    for (int i = len - 1; i >= 0; i--) {
        printf("%s %s\n",
            nome_face_bfs((int)faces[i]),
            dirs[i] == HORARIO ? "HORARIO" : "ANTIHORARIO");
    }
}

int resolver_bfs(int cubo[6][3][3]) {
    if (confere_cubo(cubo)) return 1;

    NoBFS    *fila = malloc(BFS_MAX_NOS * sizeof(NoBFS));
    BucketBFS *ht  = calloc(BFS_HASH_CAP, sizeof(BucketBFS));
    if (!fila || !ht) { free(fila); free(ht); return -1; }

    int inicio = 0, fim = 0;
    int sol_idx = -1;

    /* Insere estado inicial como raiz */
    codificar(cubo, fila[fim].estado);
    fila[fim].prof     = 0;
    fila[fim].pai      = -1;
    fila[fim].mov_face = -1;
    fila[fim].mov_dir  = -1;
    ht_inserir_bfs(ht, fila[fim].estado);
    fim++;

    while (inicio < fim && sol_idx < 0) {
        int idx_atual = inicio++;

        if ((int)fila[idx_atual].prof >= BFS_LIMITE_PROF) continue;

        int cubo_atual[6][3][3];
        decodificar(fila[idx_atual].estado, cubo_atual);

        for (int face = 0; face < 6 && sol_idx < 0; face++) {
            for (int dir = 0; dir < 2 && sol_idx < 0; dir++) {
                int filho[6][3][3];
                copiar_cubo(cubo_atual, filho);
                rotacionar_face(filho, (enum Face)face, (enum Direcao)dir);

                char est_filho[54];
                codificar(filho, est_filho);
                if (!ht_inserir_bfs(ht, est_filho)) continue;

                if (fim >= BFS_MAX_NOS) {
                    printf("Fila BFS cheia — aumente BFS_MAX_NOS.\n");
                    sol_idx = -2;
                    break;
                }

                memcpy(fila[fim].estado, est_filho, 54);
                fila[fim].prof     = fila[idx_atual].prof + 1;
                fila[fim].pai      = idx_atual;
                fila[fim].mov_face = (char)face;
                fila[fim].mov_dir  = (char)dir;

                if (confere_cubo(filho)) {
                    sol_idx = fim;
                    copiar_cubo(filho, cubo);
                }
                fim++;
            }
        }
    }

    if (sol_idx >= 0)
        imprimir_caminho(fila, sol_idx);

    free(fila);
    free(ht);
    return sol_idx >= 0 ? 1 : 0;
}

void resolve_cubo_bfs(int cubo[6][3][3]) {
    printf("\nIniciando resolução (limite: %d movimentos)...\n", BFS_LIMITE_PROF);
    int r = resolver_bfs(cubo);
    if (r == 1)
        printf("Cubo resolvido!\n");
    else
        printf("Solução não encontrada em %d movimentos.\n", BFS_LIMITE_PROF);
}

void resolve_cubo(int cubo[6][3][3]) {
    resolve_cubo_bfs(cubo);
}


/* Validação do cubo */

int verificar_cubo_valido(int cubo[6][3][3]) {
    int contagem[6] = {0};
    int centro_correto = 1;

    printf("\nVerificando validade do cubo: \n");

    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int cor = cubo[face][i][j];
                if (cor < 0 || cor > 5) {
                    printf("ERRO: Cor invalida %d na face %d\n", cor, face);
                    return 0;
                }
                contagem[cor]++;
            }
        }
    }

    for (int c = 0; c < 6; c++) {
        if (contagem[c] != 9) {
            printf("ERRO: Cor %d aparece %d vezes (deveria ser 9)\n", c, contagem[c]);
            return 0;
        }
    }
    printf(" Correta distribuicao de cores!\n");

    for (int face = 0; face < 6; face++) {
        int centro = cubo[face][1][1];
        if (centro != face) {
            printf("ERRO: Centro da face %d eh %d (deveria ser %d)\n", face, centro, face);
            centro_correto = 0;
        }
    }
    if (centro_correto) {
        printf(" Correto centros das faces!\n");
    }

    return centro_correto;
}

/* Impressão face e cubo */

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

/* Tratamento de erros */

int cor_possivel(int cor) {
    return (cor >= 0 && cor <= 5);
}

int linha_possivel(int a, int b, int c) {
    return (cor_possivel(a) && cor_possivel(b) && cor_possivel(c));
}

int face_possivel(enum Face face) {
    return (face >= 0 && face <= 5);
}

int movimento_possivel(enum Rotacao movimento) {
    return (movimento >= 0 && movimento <= 5);
}

int direcao_possivel(enum Direcao direcao) {
    return (direcao >= 0 && direcao <= 1);
}
