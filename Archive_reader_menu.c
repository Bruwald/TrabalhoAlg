#include "item.h"
#include "minigoogle.h"




int main (int argc, char *argv[]) {
	FILE *googlebot;
	int opt, relevancia, codigo;
	char *filename, *palChave;
	LISTA *listaa;

	
	listaa = criar_lista();


	while(1){
		
		opt = escolher_opcao();
		
		printf("\n");

		switch(opt){
			
			case 1: 
				scanf("%*c");
				printf("Digite o nome do arquivo: ");
				filename = readline(stdin);
				googlebot = fopen(filename, "r");
				if (googlebot != NULL) googlebot_reader (googlebot, listaa);	
				else {
				printf("O arquivo nao existe.\n");
				free(filename);
				return 0;
				}
				free(filename);
				fclose(googlebot);
				break;
			case 2:
				inserir_site(listaa); 
				break;
			case 3:
				printf("Digite o codigo do site que deseja remover: ");
				scanf("%d", &codigo);
				retirar_item(listaa, codigo);
				break;
			case 4:
				printf("Digite o codigo do site que deseja inserir: ");
				scanf("%d", &codigo);
				fgetc(stdin);
				printf("Digite a nova palavra-chave: ");
				palChave = readline(stdin);
				printf(">>%s<<\n", palChave);
				inserir_palavra_chave(listaa, codigo, palChave);
				break;
			case 5:
				printf("Digite o codigo do site que deseja atualizar: ");
				scanf("%d", &codigo);
				printf("Digite a nova relevancia: ");
				scanf("%d", &relevancia);
				inserir_relevancia(listaa, codigo, relevancia);
				break;
			case 6:
				imprimir_lista(listaa);
				break;
			case 7: 
				apagar_lista(&listaa);
				printf("Saindo do programa...\n");
				return 0;
				
		}
		
		if(opt > 6 || opt < 1){
			printf("numero não valido\n");
		}
	}
	
	return 0;
}
