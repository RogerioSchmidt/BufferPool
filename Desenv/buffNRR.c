/*/////////////////////////////////////////////////////////////////////////////////*/
//  Alunos: Natan J. Mai, Ricardo Zanuzzo e Rogério Torchelsen                    //
//  Disciplina: Banco de Dados II                                                 //      
//  Curso: Ciência da Computação                                                  //      
//  Universidade Federal da Fronteira Sul                                         //      
//                                                                                //      
//                                                                                //      
//                                                                                //      
//////////////////////////////////////////////////////////////////////////////////*/

#include "buffend.h"

void imprime(char nomeTabela[] );
void excluir(char nomeTabela[] );

void imprime(char nomeTabela[]) {

    int j,erro, x;
    struct fs_objects objeto = leObjeto(nomeTabela);    
    
    tp_table *esquema = leSchema(objeto);

    if(esquema == ERRO_ABRIR_ESQUEMA){
        printf("Erro ao criar o esquema.\n");
        return;
    }

    tp_buffer *bufferpoll = initbuffer();

    if(bufferpoll == ERRO_DE_ALOCACAO){
        printf("Erro ao alocar memória para o buffer.\n");
        return;
    }

    erro = SUCCESS;
    for(x = 0; erro == SUCCESS; x++)
        erro = colocaTuplaBuffer(bufferpoll, x, esquema, objeto);        
    

    //erro = colocaTuplaBuffer(bufferpoll, 0, esquema, objeto);

    if(erro != SUCCESS){
        //printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
        //return ;
    }
    /*
    erro = colocaTuplaBuffer(bufferpoll, 1, esquema, objeto);

    if(erro != SUCCESS){
        //printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
        //return 0;
    }
    
    erro = colocaTuplaBuffer(bufferpoll, 2, esquema, objeto);

    if(erro != SUCCESS){
        //printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
        //return 0;
    }
    
    erro = colocaTuplaBuffer(bufferpoll, 3, esquema, objeto);

    if(erro != SUCCESS){
        //printf("Erro %d: na função colocaTuplaBuffer().\n", erro);
        //return 0;
    }*/

    column *pagina = getPage(bufferpoll, esquema, objeto, 0);

    if(pagina == ERRO_PARAMETRO){
        printf("Erro, na função getPage(), problemas no parametro.\n");
        return ;
    }
    
    // PARA IMPRIMIR PÁGINA ---------------------------------------
    //-------------------------------------------------------------
    printf("\nPágina armazenada na estrutura column *pagina.\n");
    for(j=0; j < objeto.qtdCampos*bufferpoll[0].nrec; j++){
        
        if(pagina[j].tipoCampo == 'S')
            printf("%s: %-20s ", pagina[j].nomeCampo,pagina[j].valorCampo);
        else if(pagina[j].tipoCampo == 'I'){
            int *n = (int *)&pagina[j].valorCampo[0];
            printf("%s: %-25d ",pagina[j].nomeCampo, *n);
        }
        else if(pagina[j].tipoCampo == 'C'){
            printf("%s: %-25c ",pagina[j].nomeCampo, pagina[j].valorCampo[0]);
        }
        else if(pagina[j].tipoCampo == 'D'){
            double *n = (double *)&pagina[j].valorCampo[0];
            printf("%s: %-25f ",pagina[j].nomeCampo, *n);
        }
        if(j>=1 && ((j+1)%objeto.qtdCampos)==0){
			printf("\n");
		}
    }
    printf("\n\n");
}

void excluir(char nomeTabela[]){
    int erro=0;
    
    struct fs_objects objeto = leObjeto(nomeTabela);    
    tp_table *esquema = leSchema(objeto);
    tp_buffer *bufferpoll = initbuffer();

    erro = colocaTuplaBuffer(bufferpoll, 0, esquema, objeto);
    erro = colocaTuplaBuffer(bufferpoll, 1, esquema, objeto);
    erro = colocaTuplaBuffer(bufferpoll, 2, esquema, objeto);

    column *tuplaE = excluirTuplaBuffer(bufferpoll, esquema, objeto, 0, 2); //pg, tupla
    column *pagina = getPage(bufferpoll, esquema, objeto, 0);

    if(tuplaE == ERRO_PARAMETRO){
        //printf("Erro, na função excluirTuplaBuffer(), problemas no parametro.\n");
        //return;
    }
    if(pagina == ERRO_PARAMETRO){
        //printf("Erro, na função getPage(), problemas no parametro.\n");
        //return;
    }
    
    if(erro != SUCCESS){

    }
    
    // PARA IMPRIMIR TUPLA EXCLUIDA -----------------------------
    //-------------------------------------------------------------
    printf("\nTupla excluída do Buffer.\n");
    int j = 0;
    for(j=0; j < objeto.qtdCampos; j++){
        
        if(tuplaE[j].tipoCampo == 'S')
            printf("%s: %s ", tuplaE[j].nomeCampo,tuplaE[j].valorCampo);
        else if(tuplaE[j].tipoCampo == 'I'){
            int *n = (int *)&tuplaE[j].valorCampo[0];
            printf("%s: %d ",tuplaE[j].nomeCampo, *n);
        }
        else if(tuplaE[j].tipoCampo == 'C'){
            printf("%s: %c ",tuplaE[j].nomeCampo, tuplaE[j].valorCampo[0]);
        }
        else if(tuplaE[j].tipoCampo == 'D'){
            double *n = (double *)&tuplaE[j].valorCampo[0];
            printf("%s: %f ",tuplaE[j].nomeCampo, *n);
        }
        printf("\n");
    }
    
}

    
int doesFileExist(const char* filename){
    FILE* fptr = fopen(filename, "r");
    if (fptr != NULL){
        fclose(fptr);
//      printf("File exists\n");
        return 1;
    }
//  printf("File doesnt exist\n");
    return 0;
}

int main(){
    int nrTabelas, indc, i,num,menu,erro,aux, object, schema;  
    char var[10];

    nrTabelas = 4;
    table  *tab[nrTabelas];
    column *colunas = NULL;
    
    object=doesFileExist("fs_object.dat");
    schema=doesFileExist("fs_schema.dat");
    if(!object && !schema){
        /* Cria nrTabelas tabelas. */    
        tab[0] = iniciaTabela("Carro");    
        tab[1] = iniciaTabela("Modelo");    
        tab[2] = iniciaTabela("Fabricante");    
        tab[3] = iniciaTabela("Proprietario");    

        for(indc = 0; indc < nrTabelas; indc++){
            if(tab[indc] == ERRO_NOME_TABELA_INVALIDO){
                printf("Erro: na função iniciaTabela(). Nome da tabela já existente.\n");
                return 0;   
            }
        }

        //Carro
        tab[0] = adicionaCampo(tab[0], "Rnbr", 'S', 20);
        tab[0] = adicionaCampo(tab[0], "Kms", 'I', (sizeof(int)));
        tab[0] = adicionaCampo(tab[0], "DataCompra", 'S', 10);
        tab[0] = adicionaCampo(tab[0], "Ano", 'I', (sizeof(int)));
        tab[0] = adicionaCampo(tab[0], "Modelo", 'I', (sizeof(int)));
        tab[0] = adicionaCampo(tab[0], "Motor", 'D', (sizeof(double)));
        erro = finalizaTabela(tab[0]);

        //Modelo
        tab[1] = adicionaCampo(tab[1], "Modelo"    , 'S', 5);
        tab[1] = adicionaCampo(tab[1], "NomeMod"   , 'S', 10);
        tab[1] = adicionaCampo(tab[1], "Fabricante", 'S', 5);
        erro = finalizaTabela(tab[1]);

        //Fabricante
        tab[2] = adicionaCampo(tab[2], "FatCod"    , 'S', 5);
        tab[2] = adicionaCampo(tab[2], "NomeFat"   , 'S', 15);
        erro = finalizaTabela(tab[2]);

        //Proprietário
        tab[3] = adicionaCampo(tab[3], "Rg"        , 'S', 10);    
        tab[3] = adicionaCampo(tab[3], "Nome"      , 'S', 15);    
        tab[3] = adicionaCampo(tab[3], "DataNasc"  , 'S', 8);    
        tab[3] = adicionaCampo(tab[3], "Email"     , 'S', 20);    
        erro = finalizaTabela(tab[3]); 
    }
    
    printf("\nDigite o numero de cadastros a ser realizado:");
        scanf("%d",&num);
        
        for(i=0; i<num; i++){
            system("clear");
            menu=0;
            printf( "\nSelecione uma das Tabelas a ser Inserido valores:\n"
                " 1- Tabela Carro\n"
                " 2- Tabela Modelo \n"
                " 3- Tabela Fabricante \n"
                " 4- Tabela Proprietário\n"
                "\n=>");
            scanf("%d",&menu);
            switch (menu){
                case 1:
                    printf("\nDigite o codigo do Carro (Rnbr):");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Rnbr", var);
                    
                    printf("\nDigite a Kilometragem do Carro:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Kms", var);
                    
                    printf("\nDigite a Data da Compra:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "DataCompra", var);
                    
                    printf("\nDigite o Ano do Carro:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Ano", var);
                    
                    printf("\nDigite o codigo do Modelo do carro:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Modelo", var);
                    
                    printf("\nDigite a potência Motor do carro:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Motor", var);
                    
                    erro = finalizaInsert("Carro", colunas);    
                    printf("Erro1: %d\n", erro);
                    return 0;
                    
                    break;
                case 2:
                    printf("\nDigite o codigo do modelo do carro:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Modelo", var);
                    
                    printf("\nDigite o Nome do Modelo:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "NomeMod", var);
                    
                    printf("\nDigite a Sigla do Fabricante:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Fabricante", var);              

                    erro = finalizaInsert("Modelo", colunas);   

                    break;
                    
                case 3: 
                    printf("\nDigite a Sigla do Fabricante:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "FatCod", var);
                    
                    printf("\nDigite o Nome do Fabricante:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "NomeFat", var);         

                    erro = finalizaInsert("Fabricante", colunas);                       
                    
                    break;
                    
                case 4:  
                    printf("\nDigite RG do Proprietário do Veículo:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Rg", var);
                    
                    printf("\nDigite o Nome do Proprietário do Veículo:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Nome", var);
                    
                    printf("\nDigite a data de nascimento do Proprietário do Veículo:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "DataNasc", var); 
                    
                    printf("\nDigite o Email do Proprietário do Veículo:");
                    scanf("%s", var);
                    colunas = insereValor(colunas, "Email", var);           

                    erro = finalizaInsert("Proprietario", colunas);     
                    
                    break;

                    default:
                        printf("\nOpção Invalida!\n");
                    break;
            }
        
            
        }

        if(erro != SUCCESS){
            //printf("Erro %d: na função finalizaInsert()\n", erro);
            //return 0;
        }
//-------------------------------------------------------------------------------------------       
        menu=0;
        system("clear");
        while(menu!=5){
            
            printf( "\nSelecione uma das Tabelas a para Excluir\n"
                " 1- Tabela Carro\n"
                " 2- Tabela Modelo \n"
                " 3- Tabela Fabricante \n"
                " 4- Tabela Proprietário\n"
                " 5- Sair\n"
                "\n=>");
            scanf("%d",&menu);
            switch (menu){
                case 1:
                    excluir("Carro");
                    
                    break;
                case 2:
                    excluir("Modelo");
                    
                    break;
                case 3: 
                    excluir("Fabricante");
                    
                    break;
                case 4:  
                    excluir("Proprietario");
                    
                    break;
                case 5: 
                   
                    break;

                default:
                    printf("\nOpção Invalida!\n");
                    
                    break;
            }
        }

//-------------------------------------------------------------------------------------------
        
        printf("Deseja Imprimir as tableas criadas (0 = não 1, = sim)? \n");
        scanf("%d",&aux);
        
        if(aux==1){
            menu=0;

            system("clear");
            while(menu!=5){
                
                printf( "\nSelecione uma das Tabelas a para Imprimir\n"
                    " 1- Tabela Carro\n"
                    " 2- Tabela Modelo \n"
                    " 3- Tabela Fabricante \n"
                    " 4- Tabela Proprietário\n"
                    " 5- Sair\n"
                    "\n=>");
                scanf("%d",&menu);

                switch (menu){
                    case 1:
                        imprime("Carro");
                        
                        break;
                    case 2:
                        imprime("Modelo");                        

                        break;
                        
                    case 3: 
                        imprime("Fabricante");                        
                        
                        break;
                        
                    case 4:  
                        imprime("Proprietario");

                        break;
                    case 5: 
                        printf("\nPrograma Finalizado!\n");
                        return 0;

                        break;

                    default:
                        printf("\nOpção Invalida!\n");

                        break;
                }
            }
        }
    
    //-------------------------------------------------------------

    return 0;
}       
