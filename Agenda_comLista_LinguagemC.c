//GABRIEL ANDRIOLA, TRABALHO 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
//declaração de variáveis
char pesquisanome[30];

struct p{
	char nome[30];
	int idade;
	char cel[9];
	char sexo;
	char cidade[30];
	struct p *prox;
}p;
	struct p *ini, *ult, *aux;
	
//início das funções
void cadastrar()
{
			    system("cls");
				printf("\nCadastrar");
				
				if(ini==NULL) //testando para ver se é o primeiro cadastro.
					{	
					ini = (struct p*) malloc (sizeof(struct p));
						if(ini){
								fflush(stdin);
								printf("\ndigite o nome: ");
								fgets(ini->nome, 30, stdin);
								
								fflush(stdin);
								printf("\nDigite a idade:");
								scanf("%i", &ini->idade);
								
								fflush(stdin);
								printf("\nDigite o telefone: ");
								fgets(ini->cel, 9, stdin);
								
								fflush(stdin);
								printf("\nDigite o seu sexo [M ou F]: ");
								scanf("%c", &ini->sexo);
								
								fflush(stdin);
								printf("\nDigite a sua cidade: ");
								fgets(ini->cidade, 30, stdin);
								
								system("cls");
								printf("Cadastrado!");	
								ini -> prox=NULL;
								ult = ini;
								}
		         	}
				else //segundo cadastro e os demais.
				{
					aux=(struct p *) malloc (sizeof(struct p));
					if(aux){
								fflush(stdin);
								printf("\ndigite o nome: ");
								fgets(aux->nome, 30, stdin);
								
								fflush(stdin);
								printf("\nDigite a idade:");
								scanf("%i", &aux->idade);
								
								fflush(stdin);
								printf("\nDigite o telefone: ");
								fgets(aux->cel, 9, stdin);
								
								fflush(stdin);
								printf("\nDigite o seu sexo [M ou F]: ");
								scanf("%c", &aux->sexo);
								
								fflush(stdin);
								printf("\nDigite a sua cidade: ");
								fgets(aux->cidade, 30, stdin);
								
								system("cls");
								printf("Cadastrado!");	
							aux -> prox=NULL;
							ult -> prox=aux;
							ult=aux;
					}
				}
			
				printf("\n Pressione uma tecla para voltar ao menu");
}

void listar(){
				system("cls");
				printf("\nListar");
				aux=ini;
				while(aux){
							printf("\n______________________________");
							printf("\nNome : %s",aux->nome);
							printf("\nIdade: %i",aux->idade);
							printf("\nFone : %s",aux->cel);
							printf("\nSexo : %c",aux->sexo);
							printf("\nCity : %s",aux->cidade);
							aux=aux->prox;
							}
				printf("\n Pressione uma tecla para voltar ao menu");
	
}

void pesquisa()
{     
	   	        system("cls");
				printf("\nPesquisar por nome.");
				printf("\nDigite o nome: ");
				fflush(stdin);
				fgets(pesquisanome, 30, stdin);
				aux=ini;
				while(aux){
							if(stricmp(pesquisanome, aux->nome) == 0)
							{
								printf("\nNome : %s",aux->nome);
								printf("\nIdade: %i",aux->idade);
								printf("\nFone : %s",aux->cel);
								printf("\nSexo : %c",aux->sexo);
								printf("\nCity : %s",aux->cidade);
							}
							aux=aux->prox;
							}
}	

void excluir()
{
				system("cls");
				printf("\nExcluir por nome.");
				printf("\nDigite o nome: ");
				fflush(stdin);
				fgets(pesquisanome, 30, stdin);
				aux=ini;
				while(aux){
							if(stricmp(pesquisanome, aux->nome) == 0)
							{		
								ini=ini->prox;
								free(aux);
								printf("\nExcluido com sucesso!");				
							}
							aux=aux->prox;
							}
}

//main
main(){
int menu;
ini=NULL;
do{
	system("cls");
	fflush(stdin);
	printf("| MENU DE CADASTRO |\n");
	printf("----------------------------------------\n");
	printf("\n 1 - Cadastrar");
	printf("\n 2 - listar");
	printf("\n 3 - Pesquisar por nome.");
	printf("\n 4 - Excluir por nome");
	printf("\n 5 - Sair.");
	printf("\n\nOpcao: ");
	scanf("%i", &menu);
	fflush(stdin);
				
	switch (menu){
		case 1: cadastrar();  getch();	break;	
		case 2: listar();  getch();	break;		
		case 3: pesquisa(); getch(); break;	
		case 4: excluir(); 	getch();	break;
		case 5: system("cls");
				printf("\nSistema encerrado.");
				getch();
				break;
				
			}
	}while(menu!=5);
	getch();
}

