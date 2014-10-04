/*
////////////////////////////////////////////////////////////////////////////////////
//  Alunos: Natan J. Mai, Ricardo Zanuzzo e Rogério Torchelsen                    //
//  Disciplina: Banco de Dados II                                                 //      
//  Curso: Ciência da Computação                                                  //      
//  Universidade Federal da Fronteira Sul                                         //      
//                                                                                //      
//                                                                                //      
//                                                                                //      
////////////////////////////////////////////////////////////////////////////////////
*/

#include "buffend.c"

   
int main(){
    int nrTabelas, indc, opcao = 999, opcaoT = 999, contador, verifica=0;    
    char nomeTab[20];
    table  *tab[50];
	column *col[50];

//    nrTabelas = 4;
    while(opcao != 0){
        printf(
            " ---------------------------- \n"
            "| 0 - Sair                   |\n"
            "| 1 - Iniciar_Criar Tabelas  |\n"
            "| 2 - Consult Tabelas        |\n"
            "| 3 - Remover Tabelas        |\n"
            " ---------------------------- \n");
        scanf("%d", &opcao);

        switch (opcao) { 
            case 1 :
				if(!verifica){
					printf("\nDigite o número de tabelas a serem criadas: ");
					scanf("%d", &nrTabelas);
					verifica++;
				}else{
					printf("\nVoce já criou as tabelas");
					break;
				}
		 
                /* Cria nrTabelas tabelas. */    
                for(contador=0;contador<nrTabelas;contador++){
					printf("\n\nDigite o nome da tabela %d :" , contador+1);
					scanf("%s", nomeTab);
					tab[contador] = iniciaTabela(nomeTab);   
					if(tab[contador] == ERRO_NOME_TABELA_INVALIDO){
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
                if (finalizaTabela(tab[0]) != SUCCESS)  exit(1);

                //Modelo
                tab[1] = adicionaCampo(tab[1], "Modelo"    , 'S', 5);
                tab[1] = adicionaCampo(tab[1], "NomeMod"   , 'S', 10);
                tab[1] = adicionaCampo(tab[1], "Fabricante", 'S', 5);
                if (finalizaTabela(tab[1]) != SUCCESS)  exit(1);

                //Fabricante
                tab[2] = adicionaCampo(tab[2], "FatCod"    , 'S', 5);
                tab[2] = adicionaCampo(tab[2], "NomeFat"   , 'S', 15);
                if (finalizaTabela(tab[2]) != SUCCESS)  exit(1);

                //Proprietário
                tab[3] = adicionaCampo(tab[3], "Rg"        , 'S', 10);    
                tab[3] = adicionaCampo(tab[3], "Nome"      , 'S', 15);    
                tab[3] = adicionaCampo(tab[3], "DataNasc"  , 'S', 8);    
                tab[3] = adicionaCampo(tab[3], "Email"     , 'S', 20);    
                if (finalizaTabela(tab[3]) != SUCCESS)  exit(1);
                

            case 2:
                printf(
                    " ----------INSERIR--------- \n"
                    "| 0 - Sair                 |\n"
                    "| 1 - Tabela Carros        |\n"
                    "| 2 - Tabela Fabricante    |\n"
                    "| 3 - Tabela Proprietario  |\n"
                    " -------------------------- \n");
                scanf("%d", &opcaoT);
        }    
    }


/*
    t = iniciaTabela(tabela);
    t = adicionaCampo(t, "Nome", 'S', 20);
    t = adicionaCampo(t, "Idade", 'I', (sizeof(int)));
    t = adicionaCampo(t, "Sexo", 'C', (sizeof(char)));
    t = adicionaCampo(t, "Endereco", 'S', 40);
    t = adicionaCampo(t, "Altura", 'D', (sizeof(double)));
    erro = finalizaTabela(t);

    printf("Digite o numero de cadastros a ser realizado:");
    scanf("%d",&num);
    
    for(i=0; i<num; i++){
        system("clear");
        printf("\nDigite seu Nome:");
        scanf("%s", nome);
        printf("\nDigite sua Idade:");
        scanf("%s", idade);
        printf("\nDigite seu Sexo:");
        scanf("%s", sexo);
        printf("\nDigite seu Endereço:");
        scanf("%s", end);
        printf("\nDigite sua Altura:");
        scanf("%s", altura);
        
        c = insereValor(c, "Nome", nome);
        c = insereValor(c, "Idade", idade);
        c = insereValor(c, "Sexo", sexo);
        c = insereValor(c, "Endereco", end);
        c = insereValor(c, "Altura", altura);
        

        erro = finalizaInsert(tabela, c);
        
    }
    */
    

/*
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
    
    column *tuplaE = excluirTuplaBuffer(bufferpoll, esquema, objeto, 0, 2); //pg, tupla
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
    
    //-------------------------------------------------------------
*/
    return 0;
}       
