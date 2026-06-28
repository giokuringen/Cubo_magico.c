Trabalho Final - Resolvedor de Cubo Mágico em C
Nomes: Diovana Freita, Felipe de Alvarenga, Giovana Van Kuringen e João Marcelo Pacheco.

Compilação

Programa principal -> make compile 
Gerador -> gcc -o build/gerador gerador.c cubo.c -Wall -I.


Estrutura do projeto

├── main.c       — Programa principal
├── cubo.c       — Funções do programa
├── cubo.h       — Enums, structs e declarações
├── arquivo.c    — Leitura e Interpretação do arquivo de entrada
├── gerador.c    — Gerador de cubos aleatórios
├── Makefile     — Compilação
└── arquivo.txt  — Exemplo de cubo já resolvido

Guia de uso

Programa principal -> ./build/run <arquivo>

Gerador -> ./build/gerador <número de cubos>
