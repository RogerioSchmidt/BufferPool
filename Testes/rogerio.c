#include "buffend.c"


int main(){
	int erro=0;
	char tabela[20];
	table *t = NULL;
	column *c = NULL;
	printf("\nDigite o nome da Tabela: ");
	scanf("%s", tabela);
//	printf("\n%s", tabela);
	
	t = iniciaTabela(tabela);
	t = adicionaCampo(t, "Nome", 'S', 20);
	t = adicionaCampo(t, "Idade", 'I', (sizeof(int)));
	t = adicionaCampo(t, "Sexo", 'C', (sizeof(char)));
	t = adicionaCampo(t, "Obs", 'S', 40);
	t = adicionaCampo(t, "Media", 'D', (sizeof(double)));
	erro = finalizaTabela(t);
		
	c = insereValor(c, "Nome", "Um");
	c = insereValor(c, "Idade", "40");
	c = insereValor(c, "Sexo", "F");
	c = insereValor(c, "Obs", "Obs. Um");
	c = insereValor(c, "Media", "2.5");
	

	c = insereValor(c, "Nome", "Dois");
	c = insereValor(c, "Idade", "20");
	c = insereValor(c, "Sexo", "M");
	c = insereValor(c, "Obs", "Obs. Dois");
	c = insereValor(c, "Media", "1.67");

	c = insereValor(c, "Nome", "Três");
	c = insereValor(c, "Idade", "30");
	c = insereValor(c, "Sexo", "F");
	c = insereValor(c, "Obs", "Obs. Três");
	c = insereValor(c, "Media", "1.456");
	
	c = insereValor(c, "Nome", "quatrp");
	c = insereValor(c, "Idade", "40");
	c = insereValor(c, "Sexo", "F");
	c = insereValor(c, "Obs", "Obs. Quatro");
	c = insereValor(c, "Media", "1.456");

	erro = finalizaInsert(tabela, c);
	
	/*
	// PARA IMPRIMIR PÁGINA ---------------------------------------
	//-------------------------------------------------------------
	printf("\nPágina armazenada na estrutura column *pagina.\n");
	for(j=0; j < objeto.qtdCampos*bufferpoll[0].nrec; j++){
		
		if(pagina[j].tipoCampo == 'S')
			printf("%s: %s ", pagina[j].nomeCampo,pagina[j].valorCampo);
		else if(pagina[j].tipoCampo == 'I'){
			int *n = (int *)&pagina[j].valorCampo[0];
			printf("%s: %d ",pagina[j].nomeCampo, *n);
		}
		else if(pagina[j].tipoCampo == 'C'){
			printf("%s: %c ",pagina[j].nomeCampo, pagina[j].valorCampo[0]);
		}
		else if(pagina[j].tipoCampo == 'D'){
			double *n = (double *)&pagina[j].valorCampo[0];
			printf("%s: %f ",pagina[j].nomeCampo, *n);
		}
		printf("\n");
	}
	printf("\n\n");
	
	//-------------------------------------------------------------
	*/
	return 0;
}		
