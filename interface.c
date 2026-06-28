#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "cubo.h"

void iniciar_cores() {
    start_color();
    init_pair(AMARELO + 1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(VERDE + 1, COLOR_GREEN, COLOR_BLACK);
    init_pair(VERMELHO + 1, COLOR_RED, COLOR_BLACK);
    init_pair(LARANJA + 1, COLOR_CYAN, COLOR_BLACK);
    init_pair(BRANCO + 1, COLOR_WHITE, COLOR_BLACK);
    init_pair(AZUL + 1, COLOR_BLUE, COLOR_BLACK);
}

void desenhar_face(WINDOW *win, int cubo[6][3][3], enum Face f, int start_y, int start_x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cor = cubo[f][i][j];
            wattron(win, COLOR_PAIR(cor + 1) | A_BOLD);
            mvwprintw(win, start_y + i, start_x + (j * 2), "%c ", letras_cor[cor]);
            wattroff(win, COLOR_PAIR(cor + 1) | A_BOLD);
        }
    }
}

void desenhar_interface(WINDOW *win, int cubo[6][3][3], const char *status) {
    wclear(win);
    box(win, 0, 0);
    
    mvwprintw(win, 1, 2, "Status: %s", status);
    mvwprintw(win, 2, 2, "[S] Resolver Cubo");
    mvwprintw(win, 3, 2, "[Q] Sair do Programa");

    int offset_y = 6;
    int offset_x = 4;

    mvwprintw(win, offset_y - 1, offset_x + 8, "U (Cima)");
    desenhar_face(win, cubo, CIMA, offset_y, offset_x + 8);
    
    mvwprintw(win, offset_y + 3, offset_x, "L (Esq)");
    desenhar_face(win, cubo, ESQUERDA, offset_y + 4, offset_x);
    
    mvwprintw(win, offset_y + 3, offset_x + 8, "F (Frente)");
    desenhar_face(win, cubo, FRENTE, offset_y + 4, offset_x + 8);
    
    mvwprintw(win, offset_y + 3, offset_x + 16, "R (Dir)");
    desenhar_face(win, cubo, DIREITA, offset_y + 4, offset_x + 16);
    
    mvwprintw(win, offset_y + 3, offset_x + 24, "B (Tras)");
    desenhar_face(win, cubo, TRAS, offset_y + 4, offset_x + 24);
    
    mvwprintw(win, offset_y + 7, offset_x + 8, "D (Baixo)");
    desenhar_face(win, cubo, BAIXO, offset_y + 8, offset_x + 8);
    
    wrefresh(win);
}

int main(int argc, char **argv) {
    int cubo[6][3][3];

    if (argc != 2) {
        printf("Uso: %s <arquivo_instancia>\n", argv[0]);
        return 1;
    }


    popular_cubo(cubo);
    ler_cubo(argv[1], cubo);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    if (has_colors()) {
        iniciar_cores();
    }

    WINDOW *win = newwin(25, 50, 0, 0);
    char status_msg[100] = "Instância carregada.";
    
    int rodando = 1;
    while (rodando) {
        if (confere_cubo(cubo)) {
            strcpy(status_msg, "Cubo Resolvido!");
        }
        
        desenhar_interface(win, cubo, status_msg);
        
        int ch = wgetch(win);
        switch (ch) {
            case 'q':
            case 'Q':
                rodando = 0;
                break;
            case 's':
            case 'S':
                if (confere_cubo(cubo)) {
                    strcpy(status_msg, "O cubo já está resolvido!");
                } else {
                    strcpy(status_msg, "Resolvendo ... Por favor, aguarde.");
                    desenhar_interface(win, cubo, status_msg);
                    
                    int r = resolver_bfs(cubo);
                    if (r == 1) {
                        strcpy(status_msg, "Resolvido com sucesso!");
                    } else {
                        strcpy(status_msg, "Solucão não encontrada no limite de passos.");
                    }
                }
                break;
            default:
                break;
        }
    }

    delwin(win);
    endwin();
    return 0;
}