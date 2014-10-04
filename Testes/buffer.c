#include "buffend.h"


int main(){
	int nrTabelas, indc, i, num,menu,erro;    
	char rnbr[10],km[10],dataC[10],ano[10],codM[10],motor[10];
	char codModelo[10],nomeM[10],siglaF[10];
	char sigraFabricante[10],nomeF[10];
    char rg[10],nome[15],dataN[10],email[20]; 
	

    nrTabelas = 4;
    table  *tab[nrTabelas];
    column *colunas = NULL;

    /* Cria nrTabelas tabelas. */    

    tab[0] = iniciaTabela("Carro");    
    tab[1] = iniciaTabela("Modelo");    
    tab[2] = iniciaTabela("Fabricante");    
    tab[3] = iniciaTabela("Proprietário");    

    for(indc = 0; indc < nrTabelas; indc++){
        if(tab[indc] == ERRO_NOME_TABELA_INVALIDO){
            printf("Erro: na função iniciaTabela(). Nome da tabela já existente.\n");
            return 0;
        }
    }

    //Carro
    tab[0] = adicionaCampo(tab[0], "Rnbr"      , 'S' , 3);
    tab[0] = adicionaCampo(tab[0], "Kms"       , 'I' , (sizeof(int)));
    tab[0] = adicionaCampo(tab[0], "DataCompra", 'S' , 5);
    tab[0] = adicionaCampo(tab[0], "Ano"       , 'S' , (sizeof(int)));
    tab[0] = adicionaCampo(tab[0], "Modelo"    , 'I' , (sizeof(int)));
    tab[0] = adicionaCampo(tab[0], "Motor"     , 'S' , 3);

    //Modelo
    tab[1] = adicionaCampo(tab[1], "Modelo"    , 'S', 5);
    tab[1] = adicionaCampo(tab[1], "NomeMod"   , 'S', 10);
    tab[1] = adicionaCampo(tab[1], "Fabricante", 'S', 5);

    //Fabricante
    tab[2] = adicionaCampo(tab[2], "FatCod"    , 'S', 5);
    tab[2] = adicionaCampo(tab[2], "NomeFat"   , 'S', 15);
    

    //Proprietário
    tab[3] = adicionaCampo(tab[3], "Rg"        , 'S', 10);    
    tab[3] = adicionaCampo(tab[3], "Nome"      , 'S', 15);    
    tab[3] = adicionaCampo(tab[3], "DataNasc"  , 'S', 8);    
    tab[3] = adicionaCampo(tab[3], "Email"     , 'S', 20);   
    
	
	
	printf("\nDigite o numero de cadastros a ser realizado:");
		scanf("%d",&num);
		
		for(i=0; i<num; i++){
			system("clear");
			menu=0;
			printf(	"\nSelecione uma das Tabelas a ser Inserido valores:\n"
				" 1- Tabela Carro\n"
				" 2- Tabela Modelo \n"
				" 3- Tabela Fabricante \n"
				" 4- Tabela Proprietário\n"
				"\n=>");
			scanf("%d",&menu);
			switch (menu){
				case 1:
					printf("\nDigite o codigo do Carro (Rnbr):");
					scanf("%s", rnbr);
					printf("\nDigite a Kilometragem do Carro:");
					scanf("%s", km);
					printf("\nDigite a Data da Compra:");
					scanf("%s", dataC);
					printf("\nDigite o Ano do Carro:");
					scanf("%s", ano);
					printf("\nDigite o codigo do Modelo do carro:");
					scanf("%s", codM);
					printf("\nDigite a potência Motor do carro:");
					scanf("%s", motor);
					
					colunas = insereValor(colunas, "Rnbr", rnbr);
					colunas = insereValor(colunas, "Kms", km);
					colunas = insereValor(colunas, "DataCompra", dataC);
					colunas = insereValor(colunas, "Ano", ano);
					colunas = insereValor(colunas, "Modelo", codM);
					colunas = insereValor(colunas, "Motor", motor);

					erro = finalizaInsert("Carro", colunas);		
					
					break;
				case 2:
					printf("\nDigite o codigo do modelo do carro:");
					scanf("%s", codModelo);
					printf("\nDigite o Nome do Modelo:");
					scanf("%s", nomeM);
					printf("\nDigite a Sigla do Fabricante:");
					scanf("%s", siglaF);				
					
					colunas = insereValor(colunas, "Modelo", codModelo);
					colunas = insereValor(colunas, "NomeMod", nomeM);
					colunas = insereValor(colunas, "Fabricante", siglaF);

					erro = finalizaInsert("Modelo", colunas);	
					
					break;
					
				case 3:	
					printf("\nDigite a Sigla do Fabricante:");
					scanf("%s", sigraFabricante);
					printf("\nDigite o Nome do Fabricante:");
					scanf("%s", nomeF);			
					
					colunas = insereValor(colunas, "FatCod", sigraFabricante);
					colunas = insereValor(colunas, "NomeFat", nomeF);

					erro = finalizaInsert("Fabricante", colunas);						
					
					break;
					
				case 4:  
					printf("\nDigite RG do Proprietário do Veículo:");
					scanf("%s", rg);
					printf("\nDigite o Nome do Proprietário do Veículo:");
					scanf("%s", nome);
					printf("\nDigite a data de nascimento do Proprietário do Veículo:");
					scanf("%s", dataN);
					printf("\nDigite o Email do Proprietário do Veículo:");
					scanf("%s", email);			
					
					colunas = insereValor(colunas, "Rg", rg);
					colunas = insereValor(colunas, "Nome", nome);
					colunas = insereValor(colunas, "DataNasc", dataN);
					colunas = insereValor(colunas, "Email", email);

					erro = finalizaInsert("Proprietário", colunas);		
					
					break;

					default:
						printf("\nOpção Invalida!\n");
					break;
			}
		
			
		}
			if(erro != SUCCESS){
			
			return 0;
		}
	
	
	/*
	printf("Deseja Imprimir as tableas criadas (0 = não 1, = sim)? \n");
	scanf("%d",&imprime);
	
	if(imprime==1){
		if(erro != SUCCESS){
			printf("Erro %d: na função finalizaInsert()\n", erro);
			return 0;
		}

		struct fs_objects objeto = leObjeto(tabela);	
		
		tp_table *esquema = leSchema(objeto);

		if(esquema == ERRO_ABRIR_ESQUEMA){
			printf("Erro ao criar o esquema.\n");
			return 0;
		}

		tp_buffer *bufferpoll = initbuffer();

		if(bufferpoll == ERRO_DE_ALOCACAO){
			printf("Erro ao alocar memória para o buffer.\n");
			return 0;
		}

		erro = colocaTuplaBuffer(bufferpoll, 0, esquema, objeto);

		if(erro != SUCCESS){
			printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
			return 0;
		}
		
		erro = colocaTuplaBuffer(bufferpoll, 1, esquema, objeto);

		if(erro != SUCCESS){
			printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
			return 0;
		}
		
		erro = colocaTuplaBuffer(bufferpoll, 2, esquema, objeto);

		if(erro != SUCCESS){
			printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
			return 0;
		}
		
		//column *tuplaE = excluirTuplaBuffer(bufferpoll, esquema, objeto, 0, 2); //pg, tupla
		column *pagina = getPage(bufferpoll, esquema, objeto, 0);

		if(tuplaE == ERRO_PARAMETRO){
			printf("Erro, na função excluirTuplaBuffer(), problemas no parametro.\n");
			return 0;
		}
		if(pagina == ERRO_PARAMETRO){
			printf("Erro, na função getPage(), problemas no parametro.\n");
			return 0;
		}
		
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
	}
	
	//-------------------------------------------------------------
*/
	return 0;
}		