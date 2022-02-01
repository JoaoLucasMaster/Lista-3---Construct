#include <stdio.h>
#include <string.h>


typedef struct livro{
	char titulo[30];
	char autor[15];
	int ano;
	int prateleira;
}tlivro;
int qtd=0;
int max;


void addLivro(tlivro l[]){
	printf("***** Dados para livro %d *****\n",qtd+1);
	fflush(stdin);
	printf("Titulo:");
	gets(l[qtd].titulo);
	fflush(stdin);
	printf("Autor:");
	gets(l[qtd].autor);
	printf("Ano:");
	scanf("%d",&l[qtd].ano);
	printf("Prateleira:");
	scanf("%d",&l[qtd].prateleira);
	qtd++;
} 


void buscaLivro(tlivro l[], char nomeBusca[]){
	int i,encontrou;
	 for(i=0;i<qtd;i++){
	 	if(strcmp(nomeBusca,l[i].titulo)==0){
	 	printf("\n----------- Livro %d ---------\n",i+1);
		printf("Titulo:%s\nAutor:%s\nAno:%d\nPrateleira:%d\n",
		l[i].titulo,l[i].autor,l[i].ano,l[i].prateleira);
		printf("-------------------------------\n");
		encontrou=1;
		 }
	 }
	 
	 if(encontrou != 1){
	 	printf("Livro nao encontrado");
	 }
}


void buscaLivroAno(tlivro l[], int ano[]){
	int i,encontrou;
	 for(i=0;i<qtd;i++){
	 	if(l[i].ano>=ano){
	 	printf("\n----------- Livro %d ---------\n",i+1);
		printf("Titulo:%s\nAutor:%s\nAno:%d\nPrateleira:%d\n",
		l[i].titulo,l[i].autor,l[i].ano,l[i].prateleira);
		printf("-------------------------------\n");
		encontrou=1;
		 }
	 }
	 
	 if(encontrou != 1){
	 	printf("Nenhum Livro mais novo que %d encontrado",ano);
	 }
}

void mostraLivros(tlivro l[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n----------- Livro %d ---------\n",i+1);
		printf("Titulo:%s\nAutor:%s\nAno:%d\nPrateleira:%d\n",
		l[i].titulo,l[i].autor,l[i].ano,l[i].prateleira);
		printf("-------------------------------\n");
	}
}


int menu(){
	int op;
	printf(">>Programa para cadastro de livros<<\n\n");
	printf("1: |Colocar novo livro|\n\n");
	printf("2: |Procurar livro por titulo|\n\n");
	printf("3: |Procurar livros mais novos|\n\n");
	printf("4: |Exibir todos os livros cadastrados|\n\n");
	printf("0: |Sair do programa|\n\n");
	scanf("%d",&op);
	return op;
}




int main(){
	int op,ano;
	printf("Quantos livros a serem suportados: \n\n");
	scanf("%d",&max);
	system("cls");
	tlivro livro[max];
	char nomeBusca[30];
    do{
      op = menu();	
      switch(op){
      	case 1: 
		  addLivro(livro);
      	break;
      	case 2: printf("Titulo do livro para buscar:");
      			fflush(stdin); gets(nomeBusca);
      			buscaLivro(livro, nomeBusca);
      	break;
      	case 3: 
		  printf("Ano do livro para buscar:");
      			scanf("%d",&ano);
      			buscaLivroAno(livro, ano);
      	break;		
      	case 4: 
      	mostraLivros(livro);
      	break;
      	
      	case 0: 
		  		printf("Saindo... \n");
      	break;
	  }
      	getch();
      	system("cls");
	}while(op!=0);
	return 0;
}

