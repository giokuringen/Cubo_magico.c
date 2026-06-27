#ifndef CUBO_H
#define CUBO_H

enum Cores { AMARELO, VERDE, VERMELHO, LARANJA, BRANCO, AZUL };
enum Rotacao { NORTE, SUL, LESTE, OESTE };
enum Direcao { HORARIO, ANTIHORARIO };
enum Face { CIMA, BAIXO, ESQUERDA, DIREITA, FRENTE, TRAS };

/* Usando static para que cada arquivo .c que utilize esse header tenha sua propria copia desses arrays, para evitar multiplas definições*/
static const char letras_cor[6] = {'W', 'Y', 'O', 'R', 'G', 'B'};
static const char letras_face[6] = {'U', 'D', 'L', 'R', 'F', 'B'};

int confere_cubo(int cubo[6][3][3]);
void imprime_cubo(int cubo[6][3][3]);
void imprime_face(int cubo[6][3][3], enum Face f);
void rotacionar_face(int cubo[6][3][3], enum Face face, enum Direcao sentido);
void ler_cubo(char *nome_arquivo, int cubo[6][3][3]);
void rotacionar_matriz_face(int face[3][3]);


void resolve_cubo(int cubo[6][3][3]);
int resolver_bfs(int cubo[6][3][3]);
void resolve_cubo_bfs(int cubo[6][3][3]);
void popular_cubo(int cubo[6][3][3]);

int cor_possivel(int cor);
int linha_possivel(int a, int b, int c);
int face_possivel(int face);
int movimento_possivel(enum Rotacao movimento);
int direcao_possivel(int direcao);

#endif