#ifndef ITEM_H
#define ITEM_H


typedef struct item ITEM;

ITEM *criar_item(int codigo, char *nome, int relevancia, char *link, char **palavras, int numplavras);
int apagar_item(ITEM **iteem);
int imprimir_item(ITEM *iteem);
int codigo_item(ITEM *iteem);
int numpalavras_item(ITEM *iteem);
int relevancia_item(ITEM *iteem);
int mudar_relevancia(ITEM *iteem, int relevancia);
int adicionar_palavra_chave(ITEM *iteem, char *palavranova);

#endif
