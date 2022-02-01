#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct banda{
	int qtdintegrantes;
	int ranking;
	char nomeban[50];
	char generban[50];
}tbanda;


int quantidade=0;

int adicionabanda(tbanda banda[]){
	if (quantidade==MAX)
	return 0;
	printf(">>Dados para adicionar sobre a banda\n<<",quantidade+1);
	
	fflush(stdin);
	printf("Nome para banda: \n");
	gets(banda[quantidade].nomeban);
	printf("Genero para banda: \n");
	gets(banda[quantidade].generban);
	printf("Numero de integrantes da banda: \n");
	scanf("%d",&banda[quantidade].qtdintegrantes);
	printf("Ranking de bandas: \n");
	scanf("%d",&banda[quantidade].ranking);
	quantidade++;
	return 1;
}
void buscarbanda(tbanda banda[], char buscarnome[]){
	int i, encontrada=0;
	char nomebanda[50];
	
	for(i=0;i<quantidade;i++)
	{
		strcpy(nomebanda, banda[i].nomeban);
		if(strcmp(strupr(nomebanda) , strupr(buscarnome) )==0){
			printf(">>>>>Banda %d<<<<<",i+1);
			printf("Nome da banda: %s\nGenero da banda: %s\nNumero de integrantes: %d\nRanking da banda: %d",
		        banda[i].nomeban,banda[i].generban,banda[i].qtdintegrantes,banda[i].ranking);
		        printf("-----------------/n");
		        encontrada=1;
		        
		        break;
		}
	}
	if(!encontrada)
	printf("Banda não encontrada!");
	
}
void deletarbanda(tbanda banda[], char buscarnome[]){
	int i, encontrada=0, resposta;
	char nomebanda[50];
	for(i=0;i<quantidade;i++){
		strcpy(nomebanda, banda[i].nomeban);
		if(strcmp(strupr(nomebanda) , strupr(buscarnome) )==0){
			
		  printf("Vai mesmo deletar a banda %s? [1- Sim 2- Nao]\n",banda[i].nomeban);
		  scanf("%d",&resposta);
		  if(resposta==1){
		  	banda[i] = banda[quantidade-1];
		  	quantidade--;
		  }
		encontrada=1;   
		break; 
	   }
	}
	    if(!encontrada)
	      printf("Banda nao encontrada! /n");
	  else
	      printf("Banda deletada com sucesso!\n");   
}
void mostrarbandas(tbanda banda[]){
	int i;
	for(i=0;i<quantidade;i++){
		printf("\n>>>>>Banda %d<<<<\n",i+1);
		printf("Nome da banda: %s\nGenero da banda: %s\nNumero de integrantes: %d\nRanking da banda: %d",
		       banda[i].nomeban, banda[i].generban,banda[i].qtdintegrantes, banda[i].ranking);
		printf("-------------------------------\n"); 
	}
}
void favoritas(tbanda banda[]){
	int i, contador=0;
	for(i=0; i<quantidade; i++){
		
		if(banda[i].ranking >=1 && banda[i].ranking <=3){
			printf("Nome da banda: %s\nGenero da banda: %s\nNumero de integrantes: %d\nRanking da banda: %d",
		     banda[i].nomeban, banda[i].generban,banda[i].qtdintegrantes, banda[i].ranking);
		printf("-------------------------------\n");
		contador++;
		}
	}
	
	printf("Possuem %d banda(s) favoritas\n",contador);
}

    void alterarbanda(tbanda banda[], char buscarnome[]){
	   int i, encontrada=0;
	   char nomebanda[50];
	     for(i=0;i<quantidade;i++){
		    strcpy(nomebanda, banda[i].nomeban);
		  if(strcmp(strupr(nomebanda) , strupr(buscarnome) )==0){ 
		  
		    printf(">>>Dados novos para banda %s<<<\n",banda[i].nomeban);
			printf("Nome novo [%s]:",banda[i].nomeban);
			fflush(stdin); 
			gets(banda[i].nomeban);
			printf("Novos números de Integrantes[%d]:",banda[i].qtdintegrantes);
			scanf("%d",&banda[i].qtdintegrantes);
			printf("Novo Genero da banda [%s]:",banda[i].generban);
			fflush(stdin);
			gets(banda[i].generban);
			printf("Novo Ranking[%d]:",banda[i].ranking);
			scanf("%d",&banda[i].ranking);
		encontrada=1;
			
		break; 
	   }
	}
	if(!encontrada) 
	   printf("Banda nao encontrada!");
	else
	
	   printf("Dados alterados com sucesso!");
}
void buscarranking(tbanda banda[], int rnk){
	int i, contador=0;
	for(i=0; i<quantidade; i++){
		if(banda[i].ranking == rnk){
			printf("Nome da banda: %s\nGenero da banda: %s\nNumero de integrantes: %d\nRanking da banda: %d",
		     banda[i].nomeban, banda[i].generban,banda[i].qtdintegrantes, banda[i].ranking);
		printf("-------------------------------\n");
		contador++;
		}
	}
	printf("Possuem %d banda(s) neste ranking\n",contador);
}
void salvarDados(tbanda banda[]){
	int i;
	FILE *arq;
	arq = fopen("bandas.txt","w"); 
	fprintf(arq,"%d\n",quantidade); 
	for(i=0;i<quantidade;i++){
		fprintf(arq,"%s\n",banda[i].nomeban);
		fprintf(arq,"%s\n",banda[i].generban);
		fprintf(arq,"%d\n",banda[i].qtdintegrantes);
		fprintf(arq,"%d\n",banda[i].ranking);
	}
	printf("Dados salvos com sucesso :)\n");
}

void carregaDados(tbanda banda[]){
	FILE *arq;
	int i;
	arq = fopen("bandas.txt","r"); 
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}
	fscanf(arq,"%d",&quantidade);
	for(i=0;i<quantidade;i++){
		fscanf(arq,"%s",&banda[i].nomeban);
		fscanf(arq,"%s",&banda[i].generban);
		fscanf(arq,"%d",&banda[i].qtdintegrantes);
		fscanf(arq,"%d",&banda[i].ranking);
	}
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}

void salvaArquivoBinario(tbanda bandas[]){
	FILE *arq;
	arq=fopen("dadosBinario.txt","wb");
	fwrite(&bandas[0],sizeof(tbanda),quantidade,arq);
	printf("Dados salvos com sucesso - binario\n");
	fclose(arq);
}

void carregaBinario(tbanda bandas[]){
	FILE *arq;
	arq=fopen("dadosBinario.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }
	 while(fread(&bandas[quantidade],sizeof(tbanda),1,arq) >0  )
	      quantidade++;  
	 printf("Dados carregados com sucesso - binario !\n");
	fclose(arq);
}
int menu(){
	int opcao;
	printf(">>>>>SISTEMA DE CADASTRO DE BANDAS<<<<<\n\n");
	printf("1: |Colocar nova banda|\n\n");
	printf("2: |Procurar banda por nome|\n\n");
	printf("3: |Mostrar todas as bandas|\n\n");
	printf("4: |Procurar banda ranking|\n\n");
	printf("5: |Favoritos|\n\n");
	printf("6: |Procurar banda favorita por nome|:\n\n");
	printf("7: |Alterar banda|\n\n");
	printf("8: |Procurar banda genero|\n\n");
	printf("9: |Deletar banda|\n\n");
	printf("10: |Carregar as bandas|\n\n");
	printf("11: |Salvar todas as bandas|\n\n");
	printf("0: |Sair deste programa|\n\n");
	scanf("%d",&opcao);
	return opcao;
}
        void buscaGenero(tbanda banda[], char buscagenero[]){
	      int i, encontrada=0;
	      char nomebanda[50];
	      for(i=0;i<quantidade;i++){
		  strcpy(nomebanda, banda[i].generban);
		  if(strcmp(strupr(nomebanda) , strupr(buscagenero) )==0){
		  printf("\n>>>>Banda %d<<<<\n",i+1);
		  printf("Nome da banda: %s\nGenero da banda: %s\nNumero de integrantes: %d\nRanking da banda: %d",
		       banda[i].nomeban, banda[i].generban,banda[i].qtdintegrantes, banda[i].qtdintegrantes);
		  printf("-------------------------------\n");
		  encontrada=1;
	   }
	   }
	    if(!encontrada)
	   printf("Nenhuma banda encontrada com esse genero!");
}
void buscabandafavorita(tbanda banda[], char buscarnome[]){
	int i, encontrada=0;
	char nomebanda[50];
	for(i=0;i<quantidade;i++){
		strcpy(nomebanda, banda[i].nomeban);
		if(strcmp(strupr(nomebanda) , strupr(buscarnome) )==0){ 
		printf("\n>>>>Banda %d<<<<\n",i+1);
		printf("Nome da banda: %s\nGenero da banda: %s\nNumero de integrantes: %d\nRanking da banda: %d",
		       banda[i].nomeban, banda[i].generban,banda[i].qtdintegrantes, banda[i].qtdintegrantes);
		printf("-------------------------------\n");
		encontrada=1;
		if(banda[i].ranking<=3){
			printf("Esta banda %s fica no ranking %d e e uma das favoritas.",banda[i].nomeban,banda[i].ranking);
		}else{
			printf("Esta banda %s fica no ranking %d e não e uma das favoritas.",banda[i].nomeban,banda[i].ranking);
		}
		break; 
	   }
	}
	     if(!encontrada) 
	      printf("Banda nao encontrada!");
}
int main(){
	tbanda bandas[MAX];
	char buscarnome[50];
	int opcao, rnk;
    do{
      opcao = menu();	
      switch(opcao){
      	case 1: 
		  if(adicionabanda(bandas)==0){
		  	printf("\nLimite %d bandas foi atigido.",MAX);
		  }
      	break;
      	case 2: printf("Nome da banda para buscar:");
      			fflush(stdin); gets(buscarnome);
      			buscarbanda(bandas, buscarnome);
      	break;
      	case 3: mostrarbandas(bandas);
      	break;		
      	case 4: printf("Ranking para busca:");
      			scanf("%d",&rnk);
      			buscarranking(bandas, rnk);
      			
      	break;
      	case 6: printf("Nome da banda para buscar(com favorito):");
      			fflush(stdin); gets(buscarnome);
      			buscabandafavorita(bandas, buscarnome);
      	break;	
		case 7: printf("Nome da banda para alterar:");
      			fflush(stdin); gets(buscarnome);
      			alterarbanda(bandas, buscarnome);
      	break;
		case 8: printf("Genero da banda para buscar:");
      			fflush(stdin); gets(buscarnome);
      			buscaGenero(bandas, buscarnome);
      	break;
		case 9: printf("Nome da banda para remover:");      
      			fflush(stdin); gets(buscarnome);
      			deletarbanda(bandas, buscarnome);
      	break;
		case 10:
			carregaBinario(bandas);
      	break;
		case 11:
			salvaArquivoBinario(bandas);
      	break;	  	
      	case 0: 
		  		printf("Saindo... \n");
      	break;
	  }
      	
	}while(opcao!=0);
	return 0;
}
