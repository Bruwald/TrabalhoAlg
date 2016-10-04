#include "minigoogle.h"

#define ENTER 10
#define VIRGULA 44

struct lista{
												
	NODE *fim;															// a lista é a estrutura que irá guardar o tamanho,	
	NODE *inicio;														// o endereço do primeiro e o endereço do ultimo item da lista
	int tamanho;
	
};

struct node{
	
	ITEM *iteem;														// armazena um item e um ponteiro para o proximo nó
	NODE *proximo;
	
};


char *readline(FILE *arq_entrada){                                      //função para ler ate a quebra de linha

    int cont = 0;
    char *string = NULL, c;

    do{
        c = fgetc(arq_entrada);
		string = (char*) realloc (string, sizeof(char) * (cont+1) );    //le o caractere e o salva enquanto este n for
		string[cont] = c;                                               //um fim de linha
		cont++;
        
    }while(c != '\n' && c != EOF && c != ',');

    string[cont - 1] = '\0'; 
    /////                       					//adiciona um \0 no final da linha para indicar uma string

    return string;                      								//retorna a string
}




LISTA *criar_lista(){
	
	LISTA *listaa;
 
	listaa = (LISTA *) malloc(sizeof(LISTA));							// alloca espaço para guardar os dados da lista

	if(listaa != NULL) {
		listaa->inicio = NULL;
		listaa->fim = NULL;												// caso seja alocado o espaço inicializa os dados
		listaa->tamanho = 0;
	}
 
 return (listaa);
}





int inserir_final_lista(LISTA *listaa, ITEM *iteem){

	NODE *no;
		
	no = (NODE *) malloc(sizeof (NODE));								// alloca um novo no
	
    if (listaa != NULL && iteem != NULL){								// caso a lista e o item sejam validos
	
		if (listaa->inicio == NULL){
			no->iteem = iteem;
			listaa->inicio = no;										// se a lista estiver vazia coloca o primeiro item
			no->proximo = NULL;
			listaa->fim = no;
			listaa->tamanho++;
		}
		else {
			listaa->fim->proximo = no;									// caso contrario coloca o item no final dalista
			no->iteem = iteem;
			no->proximo = NULL;
			listaa->fim = no;
			listaa->tamanho++;
		}
		
		return 1;
	
	}
	
	
	return 0;
}






int vazio_lista(LISTA *listaa){
	
	if(listaa != NULL){
		
		if(listaa->inicio == NULL){										// retorna se a lista esta vazia ou não
			return 1;
		}
	}
	
	return 0;
}






int tamanho_lista(LISTA *listaa){
	
	if(listaa != NULL){
		return listaa->tamanho;											// retorna o tamanho da lista
	}
	
	return 0;
}





NODE *fim_lista(LISTA *listaa){
	
	if(listaa != NULL){
		return listaa->fim;												// retorna o ultimo no da lista
	}
	
	return NULL;
}







int retirar_item(LISTA *listaa, int codigo) {
	
	NODE *aux1, *aux2;
	
	aux1 = listaa->inicio;												// inicia dois auxiliares para percorrer a lista
	aux2 = NULL;
	
	if (listaa != NULL  && !vazio_lista(listaa) ){
		
		while(aux1 != NULL && (codigo_item(aux1->iteem)) != codigo) { 		
			aux2 = aux1; 												// procura o item a ser etirado
			aux1 = aux1->proximo;
		}
		
		if(aux1 != NULL) {
		
			if(aux1 == listaa->inicio) { 									
				listaa->inicio = aux1->proximo;							// caso encontre faz todos os tratamentos para verificar em que posição
				aux1->proximo = NULL;									// ele esta e faz sua retirada
				apagar_item( &(aux1->iteem) );
				listaa->tamanho--;
				free(aux1);
			}
		
			else {
				aux2->proximo = aux1->proximo;
				aux1->proximo = NULL;
				apagar_item( &(aux1->iteem) );
				listaa->tamanho--;
				free(aux1);
			}
			
			if(aux1 == listaa->fim){
				listaa->fim = aux2;
			}
			 
			return 1;
		}
	}
	
	return 0;
}







int inserir_posicao_lista(LISTA *listaa, ITEM *iteem){
	
	NODE *aux1, *aux2;
	NODE *no;
		
	no = (NODE *) malloc(sizeof (NODE));								//alloca o no e declara os auxiliares
	
	aux1 = listaa->inicio;
	aux2 = NULL;
	
    if (listaa != NULL && iteem != NULL && no != NULL){					// caso o item e a lista e o no sejam validos inicia
	
		if( vazio_lista(listaa) ){
			no->iteem = iteem;
			listaa->inicio = no;										//faz todos os tratamentos para verificar em que posição será inserido o item
			no->proximo = NULL;
			listaa->fim = no;
			listaa->tamanho++;
		}else{
		
			while(aux1 != NULL && codigo_item(aux1->iteem) > codigo_item(iteem) ){
				aux2 = aux1;
				aux1 = aux1->proximo;
			}
			
			if(aux1 != NULL && codigo_item(aux1->iteem) == codigo_item(iteem) ){
				return 0;
			}else{
			
				if(aux2 == listaa->fim){
					no->iteem = iteem;
					listaa->fim->proximo = no;
					listaa->fim = no;
					no->proximo = NULL;
					listaa->tamanho++;
				}else{
			
					if(aux1 == listaa->inicio){
						no->iteem = iteem;
						no->proximo = aux1;
						listaa->inicio = no;
						listaa->tamanho++;	
					}else{
						no->iteem = iteem;
						no->proximo = aux1;
						aux2->proximo = no;
						listaa->tamanho++;
					}
					
				}
				
			}
		}
		
		
		return 1;
	
	}
	
	return 0;
}




void imprimir_lista(LISTA *listaa){
	
	NODE *aux;
	
	if(listaa != NULL){													// caso a lista seja valida passa pela lista imprimindo todos os itens
		
		aux = listaa->inicio;
		
		while(aux != NULL){
			imprimir_item(aux->iteem);
			aux = aux->proximo;
		}
	
	}
	
	return;
}

int apagar_lista(LISTA **listaa){
	
	NODE *aux;
	
	if(listaa != NULL && *listaa != NULL){								// recebe os dados e caso sejam validos libera os nós e todos os dados
																		// colocando NULL em seus ponteiros desta forma se apaga a lista
		while( (*listaa)->inicio != NULL){
			
			aux = (*listaa)->inicio;
			(*listaa)->inicio = (*listaa)->inicio->proximo;
			aux->proximo = NULL;
			apagar_item(&(aux->iteem));
			free(aux);
			aux = NULL;
		}
	
		(*listaa)->fim = NULL;
	
		free(*listaa);
		*listaa = NULL;
		
		
		return 1;
	
	}
	
	
	return 0;
}

int inserir_palavra_chave(LISTA *listaa, int codigo, char *palavrachave){
	
	NODE *aux1;
	
	aux1 = listaa->inicio;												// verifica a validade dos dados, caso sejam validos faz a busca do item
	
	if(listaa != NULL && palavrachave != NULL){							
	
		while(aux1 != NULL && codigo_item(aux1->iteem) != codigo ){
			aux1 = aux1->proximo;
		}
		
		if(aux1 != NULL){
			
			adicionar_palavra_chave(aux1->iteem, palavrachave);			// caso encontre o item chama a função que adicionará uma nova palavra chave
	
		}else{
			return 0;
		}
	
	
	}
	
	return 0;
}

int inserir_relevancia(LISTA *listaa, int codigo, int relevancia){
	
	NODE *aux;
	
	if(listaa != NULL){
		
		aux = listaa->inicio;											// verifica a validade dos dados, caso sejam validos faz a busca do item
		
		while(aux != NULL && codigo_item(aux->iteem) != codigo ){
			aux = aux->proximo;
		}
		
		
		if(aux != NULL){
			
			mudar_relevancia(aux->iteem, relevancia);					// caso encontre o item chama a função que atualiza a relevancia
			
		}else{
			return 0;
		}
		
		
	}
	
	
	return 0;
}


char *archive_reader(FILE *file, char *c) {
	char *sequence=NULL;
		int i=0;
		
		do {
			sequence = (char *) realloc(sequence, sizeof(char)*(i+1));							// faz a leitura do arquivo pegando os itens de forma
			*(sequence+i) = fgetc(file);														// correta para as funçoes
			i++;
		} while (*(sequence+i-1)!= VIRGULA && *(sequence+i-1)!=EOF && *(sequence+i-1)!=ENTER);
		
		*c = *(sequence+i-1);
		*(sequence+i-1) = '\0';
		
		return sequence;
}


char *readLine(int *flag){
	int counter = 0;
	char c, *string = NULL;

	do{
		c = fgetc(stdin);
		string = (char *) realloc(string, sizeof(char) * (counter+1));			// faz a leitura utilizando uma flag para parar no momento correto
		string[counter++] = c;
		if(c == ENTER) *flag = 1;
	} while(c != VIRGULA && c != ENTER);

	string[--counter] = '\0';

	return string;
}


char **ler_palavras(int *numpalavras){
	
	char **palavras = NULL, *string = NULL;
	int i = 0, flag = 0;

	do{
		string = readLine(&flag);
		palavras = (char **) realloc(palavras, sizeof(char *) * (i+1));			// le as palavras chaves e marca a quantidade de palavras
		palavras[i++] = string;
	} while(!flag);

	*numpalavras = i;

	return palavras;
}

void inserir_site(LISTA *listaa) {
	
	int codigo, relevancia, numpalavras;
	char **pal = NULL, *nome = NULL, *link_site = NULL;							// faz a leitura dos dados para inserção a partir do teclado
	ITEM *iteem;

	printf("Codigo do site: ");
	scanf("%d", &codigo);
	fgetc(stdin);
	printf("Nome do site: ");
	nome = readline(stdin);
	printf("Relevancia: ");
	scanf("%d", &relevancia);
	fgetc(stdin);
	printf("Link do site: ");
	link_site = readline(stdin);
	printf("Palavras-chave (separadas por virgula): ");
	pal = ler_palavras(&numpalavras);
	iteem = criar_item(codigo, nome, relevancia, link_site, pal, numpalavras);
	inserir_posicao_lista(listaa, iteem);

}


int escolher_opcao(){
	int opt;
		printf("=======================================\n");			// apresenta o menu
		printf("=                 MENU                =\n");
		printf("=     1. Inserir dados de arquivo     =\n");
		printf("=         2. Inserir um site          =\n");
		printf("=         3. Remover um site          =\n");
		printf("=      4. Inserir palavra-chave       =\n");
		printf("=       5. Atualizar relevancia       =\n");
		printf("=          6. Imprimir Lista          =\n");
		printf("=               7. Sair               =\n");
		printf("=======================================\n\n");

		printf("Digite uma opcao: ");
		scanf("%d", &opt);

		return opt;
}


void googlebot_reader (FILE *file, LISTA *listaa) {							// junto com outras funçoes faz a leitura completa dos itens de um arquivo
	
	char c, *nome, *site, **palavras=NULL;
	int chave, prioridade, quantidade=0;
	ITEM *iteem;
	
	
	while (c!=EOF) {
		
		
		fscanf(file, "%d%c", &chave, &c);
				
		nome = archive_reader(file, &c);
			
		fscanf(file, "%d%c", &prioridade, &c);
				
		site = archive_reader(file, &c);
			
		while (c!=ENTER && c!=EOF) {
			palavras = (char **) realloc(palavras, sizeof(char *)*(quantidade+1));
				*(palavras+quantidade) = archive_reader(file, &c);
				quantidade++;
		}
			
		iteem = criar_item(chave, nome, prioridade, site, palavras, quantidade);
		inserir_posicao_lista(listaa, iteem);
		
		palavras = NULL;	
			
		quantidade=0;
		

	}
}
