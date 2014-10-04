#include "buffend.c"
	
void insere(int opc){
	int nrTabelas, indc, erro, opcao = 999, opcaoT = 999;    
    nrTabelas = 4;
    table  *tab[nrTabelas];
    column *c = NULL;
	switch (opc){ 
		case 1 :
			/* Cria tabela carro. */    
			if(tab[0] == ERRO_NOME_TABELA_INVALIDO){
				return 0;   
            }
            tab[0] = iniciaTabela("Carro");  
			tab[0] = adicionaCampo(tab[0], "Rnbr", 'S', 20);
			tab[0] = adicionaCampo(tab[0], "Kms", 'I', (sizeof(int)));
			tab[0] = adicionaCampo(tab[0], "DataCompra", 'S', 10);
			tab[0] = adicionaCampo(tab[0], "Ano", 'I', (sizeof(int)));
			tab[0] = adicionaCampo(tab[0], "Modelo", 'I', (sizeof(int)));
			tab[0] = adicionaCampo(tab[0], "Motor", 'D', (sizeof(double)));
			erro = finalizaTabela(tab[0]); 
			c = insereValor(c, "Rnbr", "Um");
			c = insereValor(c, "Kms", "12");
			c = insereValor(c, "DataCompra", "Um");
			c = insereValor(c, "Ano", "20");
			c = insereValor(c, "Modelo", "1");
			c = insereValor(c, "Motor", "1.5");
			erro = finalizaInsert("Carro", c);
			
		case 2:
			/* Cria tabela carro. */    
			if(tab[1] == ERRO_NOME_TABELA_INVALIDO){
				return 0;   
            }
            tab[1] = iniciaTabela("Modelo");  
            tab[1] = adicionaCampo(tab[1], "Modelo"    , 'S', 5);
            tab[1] = adicionaCampo(tab[1], "NomeMod"   , 'S', 10);
            tab[1] = adicionaCampo(tab[1], "Fabricante", 'S', 5);
			erro = finalizaTabela(tab[1]); 
			c = insereValor(c, "Rnbr", "Um");
			c = insereValor(c, "Kms", "12");
			c = insereValor(c, "DataCompra", "Um");
			c = insereValor(c, "Ano", "20");
			c = insereValor(c, "Modelo", "1");
			c = insereValor(c, "Motor", "1.5");
			erro = finalizaInsert("Carro", c);
			
		}
}


int main(){
	int opcao, opc;
	system("clear");
	printf(
		" ----------TABELAS--------- \n"
		"| 1 - Tabela Carros        |\n"
		"| 2 - Tabela Fabricante    |\n"
		"| 3 - Tabela Proprietario  |\n"
		"| 4 - Modelo               |\n"
		" -------------------------- \n");
		
	printf("\nDigite 1 para inserir valores.\nDigite 2 para imprimir uma tabela. \nDigite outro numero para sair.");
	printf("\n\nOPÇÃO -> ");
	scanf("%d", &opcao);
	if(opcao==1){
		system("clear");
		printf(
		" ----------TABELAS--------- \n"
		"| 1 - Tabela Carros        |\n"
		"| 2 - Tabela Fabricante    |\n"
		"| 3 - Tabela Proprietario  |\n"
		"| 4 - Tabela Modelo               |\n"
		" -------------------------- \n");
		printf("\n\nEscolha a Tabela para inserir valores (tuplas), dentre as opções acima -> ");
		scanf("%d", &opc);
		insere(opc);
	}else if(opcao==2){
		system("clear");
		printf(
		" ----------TABELAS--------- \n"
		"| 1 - Tabela Carros        |\n"
		"| 2 - Tabela Fabricante    |\n"
		"| 3 - Tabela Proprietario  |\n"
		"| 4 - Modelo               |\n"
		" -------------------------- \n");
		printf("\n\nEscolha a Tabela para imprimir, dentre as opções acima -> ");
		scanf("%d", &opc);
//		imprimi(& opc);
	}else{
		exit(1);
	}
	return 0;	
	
}
	
