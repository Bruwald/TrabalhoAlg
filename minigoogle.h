#ifndef MINIGOOGLE_H
#define MINIGOOGLE_H

#include <stdlib.h>
#include <stdio.h>
#include "item.h"

typedef struct node NODE;
typedef struct lista LISTA;
char *readline(FILE *arq_entrada);

LISTA *criar_lista();
int apagar_lista(LISTA **listaa);
int inserir_final_lista(LISTA *listaa, ITEM *iteem);
int inserir_posicao_lista(LISTA *listaa, ITEM *iteem);
int vazio_lista(LISTA *listaa);
int tamanho_lista(LISTA *listaa);
void imprimir_lista(LISTA *listaa);
NODE *fim_lista(LISTA *listaa);
int retirar_item(LISTA *listaa, int codigo);
int inserir_palavra_chave(LISTA *listaa, int codigo, char *palavrachave);
int inserir_relevancia(LISTA *listaa, int codigo, int relevancia);
char *archive_reader(FILE *file, char *c);
char *readLine(int *flag);
char **ler_palavras(int *numpalavras);
void inserir_site(LISTA *listaa);
int escolher_opcao();
void googlebot_reader (FILE *file, LISTA *listaa);


#endif
