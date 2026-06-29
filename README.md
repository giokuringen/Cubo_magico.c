## Trabalho Final - Resolvedor de Cubo Mágico em C
Pontifícia Universidade Católica do Rio Grande do Sul — PUCRS

**Integrantes:**
- Diovana Freitas
- Felipe de Alvarenga
- Giovana Van Kuringen
- João Marcelo Pacheco

---

## Descrição

Programa em C capaz de ler uma instância de um Cubo Mágico a partir de um arquivo texto, armazená-la em memória e encontrar uma sequência de rotações que leve o cubo ao estado resolvido.

---

## Estrutura do Projeto

```
main.c        — Programa principal
cubo.c        — Funções do cubo (rotações, verificação, solução)
cubo.h        — Enums, structs e declarações
arquivo.c     — Leitura e interpretação do arquivo de entrada
gerador.c     — Gerador de cubos aleatórios
Makefile      — Automação da compilação
arquivo.txt   — Exemplo de cubo já resolvido
interface.c   — Interface do cubo
```

---

## Compilação

**Programa principal:**
```bash
make compile
```

**Compilação geral:**
```bash
make all
```

**Gerador de cubos aleatórios:**
```bash
make compile_gerador
```

**Interface:**
```bash
make conmpile_interface
```
---

## Como Usar

**Programa principal:**
```bash
./build/run <arquivo>
```

**Gerador de cubos aleatórios:**
```bash
./build/gerador <número de cubos>
```
O gerador criará n arquivos de texto com descrições aleatórias de cubos.

**Interface:**
```bash
./build/run_interface <arquivo.txt>
```

---
