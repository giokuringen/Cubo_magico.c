#ifndef CUBO_H
#define CUBO_H

/* Enumerações de acordo com o enunciado */
enum Cores { BRANCO, AMARELO, LARANJA, VERMELHO, VERDE, AZUL };
enum Rotacao { NORTE, SUL, LESTE, OESTE };
enum Direcao { HORARIO, ANTIHORARIO };
enum Face { CIMA, BAIXO, ESQUERDA, DIREITA, FRENTE, TRAS };

/* Usando static para que cada arquivo .c que utilize esse header tenha sua propria copia desses arrays, para evitar multiplas definições*/
static const char letras_cor[6] = {'W', 'Y', 'O', 'R', 'G', 'B'};
static const char letras_face[6] = {'U', 'D', 'L', 'R', 'F', 'B'};

/* Funções de rotação individuais */
void rotacionar_matriz_90(int face[3][3]);
void girar_cima_horario(int cubo[6][3][3]);
void girar_cima_antihorario(int cubo[6][3][3]);
void girar_baixo_horario(int cubo[6][3][3]);
void girar_baixo_antihorario(int cubo[6][3][3]);
void girar_esquerda_horario(int cubo[6][3][3]);
void girar_esquerda_antihorario(int cubo[6][3][3]);
void girar_direita_horario(int cubo[6][3][3]);
void girar_direita_antihorario(int cubo[6][3][3]);
void girar_frente_horario(int cubo[6][3][3]);
void girar_frente_antihorario(int cubo[6][3][3]);
void girar_tras_horario(int cubo[6][3][3]);
void girar_tras_antihorario(int cubo[6][3][3]);

/* Funções principais */
int confere_cubo(int cubo[6][3][3]);
void imprime_cubo(int cubo[6][3][3]);
void imprime_face(int cubo[6][3][3], enum Face f);
void rotacionar_face(int cubo[6][3][3], enum Face face, enum Direcao sentido);
void ler_cubo(char *nome_arquivo, int cubo[6][3][3]);

/* Funções de cópia e resolução */
void copiar_cubo(int origem[6][3][3], int destino[6][3][3]);
void resolve_cubo(int cubo[6][3][3]);
void resolve_cubo_bfs(int cubo[6][3][3]);
int resolver_bfs(int cubo[6][3][3]);

/* Funções de inicialização*/
void popular_cubo(int cubo[6][3][3]);

/* Funções de validação */
int cor_possivel(int cor);
int linha_possivel(int a, int b, int c);
int face_possivel(enum Face face);
int movimento_possivel(enum Rotacao movimento);
int direcao_possivel(enum Direcao direcao);
int verificar_cubo_valido(int cubo[6][3][3]);

#endif