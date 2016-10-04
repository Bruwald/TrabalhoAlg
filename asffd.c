#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item{
	
	int codigo;
	char *nome;															// o item armazenas todas as informações do site
	int relevancia;
	char *link;
	char **palavras;
	int numpalavras;
	
};


ITEM *criar_item(int codigo, char *nome, int relevancia, char *link, char **palavras, int numpalavras){	
	
	ITEM *iteem;																	
																					// função para gerar um novo item
	if(nome != NULL && link != NULL && palavras != NULL){				// verifica se os parametros são validos
		
		iteem = (ITEM*) malloc (sizeof(ITEM));							// primeiramente se alloca o espaço do item
	
		if(iteem != NULL){												
			iteem->codigo = codigo;								
			iteem->nome = nome;
			iteem->relevancia = relevancia;
			iteem->link = link;											// se a alocação ocorrer corretamente se guarda os valores
			iteem->palavras = palavras;									// e parametros no item
			iteem->numpalavras = numpalavras;
			
			return iteem;												// e então se retorna o item
		}
		
	}
	
	return NULL;
}




int apagar_item(ITEM **iteem){											// função para liberar e apagar um item
	
	int i;
	
	if(iteem != NULL && *iteem != NULL){								// verifica se o item é valido
		
		free((*iteem)->nome);					
		(*iteem)->nome = NULL;
		
		free((*iteem)->link);									// se examina os parametros os liberando da memória e colocando
		(*iteem)->link = NULL;									// o ponteiro que apontava para este valor como null para não se poder
																// mais acessar aquela posição (segurança e evitar erros)
		
		
		for(i=0; i < (*iteem)->numpalavras; i++){										
			free( (*iteem)->palavras[i] );
			(*iteem)->palavras[i] = NULL;
		}
		
		
		free(*iteem);													// finalmente se libera o item e novamente se coloca null
		*iteem = NULL;													// no seu ponteiro
		
		
		return 1;						
	} 																	// caso ocorra corretamente retorna 1
 
	return 0;
}




int imprimir_item(ITEM *iteem){											// imprime o item
	
	int i;
	
	if(iteem != NULL){
		printf("%d\n", iteem->codigo);
		printf("%s\n", iteem->nome);									// caso seja um item válido apresenta todas suas informações
		printf("%d\n", iteem->relevancia);
		printf("%s\n", iteem->link);
		for(i=0; i < iteem->numpalavras; i++){										
			printf("%s, ", iteem->palavras[i]);
		}
		printf("\n");
		
		return 1;
	}
	
	return 0;
}



int codigo_item(ITEM *iteem){
	
	
	if(iteem != NULL){
		return iteem->codigo;
	}
	
	return 0;
}

int numpalavras_item(ITEM *iteem){
	
	if(iteem != NULL){
		return iteem->numpalavras;
	}
	
	return 0;
}

int relevancia_item(ITEM *iteem){
	
	if(iteem != NULL){
		return iteem->relevancia;
	}
	
	return 0;
}

int mudar_relevancia(ITEM *iteem, int relevancia){
	
	if(iteem != NULL){
		iteem->relevancia = relevancia;
		return 1;
	}
	
	return 0;
}
	
int adicionar_palavra_chave(ITEM *iteem, char *palavranova){
	
	if(iteem != NULL){
		
		iteem->palavras = (char**) realloc (iteem->palavras, sizeof(char*) * (iteem->numpalavras + 1) );
		iteem->palavras[iteem->numpalavras] = palavranova;
		iteem->numpalavras++;
		
		return 1;
	}
	
	
	return 0;
}



