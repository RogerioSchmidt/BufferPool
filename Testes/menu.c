
#include<stdio.h>
#include<stdlib.h>

void menu();

int main(){

	menu();
	return 0;
}


void menu(){
	int acao,  continua, opcao, y;

	system("clear");
	printf("\n=>Programa para Inserir/Consultar valores de Tabelas<=");
	printf("\n\nDigite 1 para acessar o menu principal, outro numero para sair: ");
	scanf("%d", &y);
	while(y==1){
		system("clear");
		printf(" -> Tabela Carro\n"
			" -> Tabela Modelo \n"
			" -> Tabela Fabricante \n"
			" -> Tabela Proprietário\n");
		printf(	"\nDentre as tabelas acima, digite: \n1 - Inserir valores\n2 - Imprimir valores\n3 - Sair");
		printf("\nOpcao -> ");
		scanf("%d",&opcao);
		system("clear");
		if(opcao==1){		//inserir valores
			system("clear");
			printf(" 1- Tabela Carro\n"
				" 2- Tabela Modelo \n"
				" 3- Tabela Fabricante \n"
				" 4- Tabela Proprietário\n"
				" 5- Sair\n");
			printf(	"\nEscolha a tabela, dentre uma das mencionadas acima, para inserir valores");
			printf("\nOpcao -> ");
			scanf("%d",&acao);
			system("clear");
		
			switch (acao){
				case 1:		//cadastrar usuarios
					continua=1;
					while(continua==1){
						//insere(1);
						system("clear");
						printf("\ndigite 1 para inserir outra Tupla. Outro numero para voltar ao menu principal:");
						scanf("%d", &continua);
					}//while
					
				break;	//caso 2

				case 2:
					continua=1;
					while(continua==1){
						//insere(2);
						system("clear");
						printf("\ndigite 1 para inserir outra Tupla. Outro numero para voltar ao menu principal: ");
						scanf("%d", &continua);
					}//while
					
				break;	//caso 2
			
				case 3:
					continua=1;
					while(continua==1){
						//insere(3);
						system("clear");
						printf("\ndigite 1 para inserir outra Tupla,  Outro numero para voltar ao menu principal: ");
						scanf("%d", &continua);
					}//while
				break;		//caso 3

				case 4:
					continua=1;
					while(continua==1){
						//insere(4);
						system("clear");
						printf("\ndigite 1 para inserir outra Tupla. Outro numero para voltar ao menu principal: ");
						scanf("%d", &continua);
					}//while 
					
				break;
		
				case 5:		//opcao sair do programa
					return ;
				break;
		
				default:
		
					printf("\nVoce digitou uma opcao invalida! \n\nDigite qualquer numero para voltar ao menu principal... ");
					scanf("%d", & continua);	
				break;					//defoult
			}	
					
		}else if(opcao==2){	//imprimir tabelas
		continua=1;		
		while(continua==1){
		
			system("clear");
				printf(" 1- Tabela Carro\n"
					" 2- Tabela Modelo \n"
					" 3- Tabela Fabricante \n"
					" 4- Tabela Proprietário\n"
					" 5- Sair\n");
				printf(	"\nEscolha a tabela, dentre uma das mencionadas acima para imprimi-la");
				printf("\nOpcao -> ");
				scanf("%d",&acao);
				system("clear");
			
				switch (acao){
					case 1:
						system("clear");
						//imprime("Carro");
						printf("\ndigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
						scanf("%d", &continua);
						
					break;

					case 2:
						system("clear");
						//imprime("Modelo");
						printf("\ndigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
						scanf("%d", &continua);
					
					break;
				
					case 3:
						system("clear");
						//imprime("Fabricante");
						printf("\ndigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
						scanf("%d", &continua);

					break;

					case 4:
						system("clear");
						//imprime("Proprietario");
						printf("\ndigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
						scanf("%d", &continua);
					
					break;
			
					case 5:		//opcao sair do programa
						return ;
					break;
			
					default:
			
						printf("\nVoce digitou uma opcao invalida! \n\ndigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
						scanf("%d", & continua);	
					break;					//defoult
				}
			}
			
		}else if(opcao==3){	//sair
			return ;
		
		}else{		//opcao invalida
			y=1;
		}
		
	}	//while topo
}
