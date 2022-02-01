#include<stdio.h>
int max = 100;
int qtd = 0;



typedef struct alunos{
	int matri;
	char nome[50];
	double nota1;
	double nota2;
	double nota3;
}taluno;

int menu(){
	int op;
	printf(">>Programa para cadastro de alunos<<\n\n");
	
	printf("1: |Insera um novo Estudante|\n\n");
	
	printf("2: |Procurar estudante por nome|\n\n");
	
	printf("3: |Aluno com maior media|\n\n");
	
	printf("4: |Carregar arquivo txt|\n\n");
	
	printf("5: |Alunos que foram aprovados e os que foram reprovados|\n\n");
	
	printf("6: |Mostrar todos os alunos|\n\n");
	
	printf("7: |Salvar este dado em txt|\n\n");
	
	printf("8: |Procurar estudante por matricula|\n\n");
	
	printf("0: |Sair|\n");
	
	scanf("%d",&op);
	
	return op;
}

void cadastrarAluno(taluno aluno[]){
	
	printf("***** Dados para aluno %d *****\n",qtd+1);
	
	printf("Matricula:\n");
	scanf("%d",&aluno[qtd].matri);
	
	printf("Nome:\n");
	fflush(stdin);
	gets(aluno[qtd].nome);
	
	printf("Nota na prova 1:\n");
	scanf("%lf",&aluno[qtd].nota1);
	
	printf("Nota na prova 2:\n");
	scanf("%lf",&aluno[qtd].nota2);
	
	printf("Nota na prova 3:\n");
	scanf("%lf",&aluno[qtd].nota3);
	
	qtd++;
}

void mostraAlunos(taluno aluno[]){
	int k;
	for(k=0;k<qtd;k++){
		
		printf("\n***** Dados para aluno %d *****\n",k+1);
		
		printf("Matricula:%d\n",aluno[k].matri);
		
		printf("Nome:%s\n",aluno[k].nome);
		
		printf("Nota na prova 1:%.2lf\n",aluno[k].nota1);
		
		printf("Nota na prova 2:%.2lf\n",aluno[k].nota2);
		
		printf("Nota na prova 3:%.2lf\n",aluno[k].nota3);
	}
}

void salvarDados(taluno aluno[]){
	int k;
	FILE *arq;
	arq = fopen("alunos.txt","w");
	fprintf(arq,"%d\n",qtd);
	
	for(k=0;k<qtd;k++){
		fprintf(arq,"%i\n",aluno[k].matri);
		
		fprintf(arq,"%s\n",aluno[k].nome);
		
		fprintf(arq,"%lf\n",aluno[k].nota1);
		
		fprintf(arq,"%lf\n",aluno[k].nota2);
		
		fprintf(arq,"%lf\n",aluno[k].nota3);
	}
	printf("Dados salvos com sucesso :)");
}

void carregaDados(taluno aluno[]){
	FILE *arq;
	int k;
	arq = fopen("alunos.txt","r");
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}
	fscanf(arq,"%d",&qtd);
	for(k=0;k<qtd;k++){
		fscanf(arq,"%i",&aluno[k].matri);
		fscanf(arq,"%s",&aluno[k].nome);
		fscanf(arq,"%lf",&aluno[k].nota1);
		fscanf(arq,"%lf",&aluno[k].nota2);
		fscanf(arq,"%lf",&aluno[k].nota3);
	}
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}

void buscarAlunoMatricula(taluno aluno[]){
	int k,matri,encontrou;
	printf("\nDigite a matricula do aluno a ser buscado:\n");
	scanf("%d",&matri);
	for(k=0;k<qtd;k++){
		if(matri == aluno[k].matri){
			
			printf("\n***** Dados para aluno %d *****\n",k+1);
			
			printf("Matricula:%d\n",aluno[k].matri);
			
			printf("Nome:%s\n",aluno[k].nome);
			
			printf("Nota na prova 1:%.2lf\n",aluno[k].nota1);
			
			printf("Nota na prova 2:%.2lf\n",aluno[k].nota2);
			
			printf("Nota na prova 3:%.2lf\n",aluno[k].nota3);	
		}
		
		
	}

}

void buscarAlunoNome(taluno aluno[]){
	
	int k,encontrou;
	char nome[50];
	printf("\nDigite o nome do aluno a ser buscado:\n");
	fflush(stdin);
	gets(nome);
	for(k=0;k<qtd;k++){
		if(strcmp(strupr(nome),strupr(aluno[k].nome)) == 0){
			
			printf("\n***** Dados para aluno %d *****\n",qtd+1);
			
			printf("Matricula:%d\n",aluno[k].matri);
			
			printf("Nome:%s\n",aluno[k].nome);
			
			printf("Nota na prova 1:%.2lf\n",aluno[k].nota1);
			
			printf("Nota na prova 2:%.2lf\n",aluno[k].nota2);
			
			printf("Nota na prova 3:%.2lf\n",aluno[k].nota3);
				
			encontrou=1;
		}
}
}

void maiorMedia(taluno aluno[]){
	int maiorPosicao,k;
	double media,maior;
	maior = (aluno[0].nota1 + aluno[0].nota2 + aluno[0].nota3)/3;
	for(k=0;k<qtd;k++){
		media = (aluno[k].nota1 + aluno[k].nota2 + aluno[k].nota3)/3;
		if(media>maior){
			maior=media;
			maiorPosicao = k;
		}
	}
	
	printf("\n O aluno com maior media e:\n");
	
	printf("\n***** Dados para aluno %d *****\n",maiorPosicao+1);
	
	printf("Matricula:%d\n",aluno[maiorPosicao].matri);
	
	printf("Nome:%s\n",aluno[maiorPosicao].nome);
	
	printf("Nota na prova 1:%.2lf\n",aluno[maiorPosicao].nota1);
	
	printf("Nota na prova 2:%.2lf\n",aluno[maiorPosicao].nota2);
	
	printf("Nota na prova 3:%.2lf\n",aluno[maiorPosicao].nota3);
	
	printf("Media:%.2lf\n",maior);
	

}

void alunosAprovados(taluno aluno[]){
	int k;
	double media;
	
	printf("\nALUNOS APROVADOS:\n");
	printf("MATRICULA - NOME - MEDIA\n");
	for(k=0;k<=qtd;k++){
			media = (aluno[k].nota1 + aluno[k].nota2 + aluno[k].nota3)/3;
		if(media>6){
			media = (aluno[k].nota1 + aluno[k].nota2 + aluno[k].nota3)/3;
			printf("\n%d - %s - %.2lf",aluno[k].matri,aluno[k].nome,media);		
		}
	}
	
	printf("\nALUNOS REPROVADOS:\n");
	printf("MATRICULA - NOME - MEDIA\n");
	for(k=0;k<qtd;k++){
			media = (aluno[k].nota1 + aluno[k].nota2 + aluno[k].nota3)/3;
		if(media<6){
			media = (aluno[k].nota1 + aluno[k].nota2 + aluno[k].nota3)/3;
			printf("\n%d - %s - %.2lf",aluno[k].matri,aluno[k].nome,media);		
		}
	}
	
}

int main(){
	int op=0;
	taluno aluno[max];
	
	do{
		op = menu();
		switch(op){
			case 1:
				cadastrarAluno(aluno);					
				break;
			case 2:
				buscarAlunoNome(aluno);
				break;
			case 3:
				maiorMedia(aluno);
				break;
			case 4:
				carregaDados(aluno);
				break;
			case 5:
				alunosAprovados(aluno);
				break;
			case 6:
				mostraAlunos(aluno);
				break;
			case 7:
				salvarDados(aluno);
				break;	
			case 8:
				buscarAlunoMatricula(aluno);
				break;
		}
		
      	getch();
      	system("cls");
      	
	}while(op!=0);
	
	return 0;
}

