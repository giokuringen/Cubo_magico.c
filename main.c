#include "cubo.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Declarações das funções externas
void ler_cubo(char *nome_arquivo, int cubo[6][3][3]);
void imprime_cubo(int cubo[6][3][3]);
int confere_cubo(int cubo[6][3][3]);
void popular_cubo(int cubo[6][3][3]);
void resolve_cubo_ida(int cubo[6][3][3]);
int verificar_cubo_valido(int cubo[6][3][3]);


int main(int argc, char **argv) {
    srand(time(NULL));
    int cubo[6][3][3];

    if (argc != 2) {
        printf("Uso: %s <arquivo_instancia>\n", argv[0]);
        return 1;
    }
    
    printf("\n========================================");
    printf("\nCARREGANDO ARQUIVO: %s\n", argv[1]);
    printf("========================================\n");
    
    popular_cubo(cubo);
    ler_cubo(argv[1], cubo);
    
    printf("\nESTADO DO CUBO CARREGADO:\n");
    imprime_cubo(cubo);
        
    // Verifica validade
    if (!verificar_cubo_valido(cubo)) {
        printf("\n[AVISO]: O cubo carregado é INVÁLIDO!\n");
        return 1;
    }
    
    if (confere_cubo(cubo)) {
        printf("\n[OK]: Cubo está resolvido!\n");
        return 0;
    }
    
    printf("\n[AVISO]: Cubo não está resolvido!\n");
    
    resolve_cubo(cubo);
    
    printf("\n========================================");
    printf("\nESTADO FINAL:\n");
    printf("========================================\n");
    imprime_cubo(cubo);
        
    if (confere_cubo(cubo)) {
        printf("\nCubo resolvido com sucesso!\n");
    } else {
        printf("\nFalha ao resolver cubo.\n");
    }
    
    return 0;
}