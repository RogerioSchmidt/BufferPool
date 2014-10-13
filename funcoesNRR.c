/*/////////////////////////////////////////////////////////////////////////////////*/
//  Alunos: Natan J. Mai, Ricardo Zanuzzo e Rogério Torchelsen                    //
//  Disciplina: Banco de Dados II                                                 //      
//  Curso: Ciência da Computação                                                  //      
//  Universidade Federal da Fronteira Sul                                         //      
//                                                                                //      
//////////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include "buffend.h"
#include "funcoesNRR.h"

/***********************************************************************************|
|* FUNÇÃO: Utilizada no controle do 'menu', com todas as opcoes.                   */   

void menu(){
    int acao,  continua, opcao, y;
    system("clear");
    y = 1;

    while(y){
        system("clear");
        printf(" -> Tabela Carro\n"
            " -> Tabela Modelo \n"
            " -> Tabela Fabricante \n"
            " -> Tabela Proprietário\n");

        printf( "\nDentre as tabelas acima, digite: \n1 - Inserir valores\n2 - Imprimir valores\n3 - Excluir valores\n4 - Sair");
        printf("\nOpcao -> ");
        scanf("%d",&opcao);
        system("clear");

        if(opcao == 1){     //inserir valores
                                   
            system("clear");
            printf(" 1- Tabela Carro\n"
                " 2- Tabela Modelo \n"
                " 3- Tabela Fabricante \n"
                " 4- Tabela Proprietário\n"
                " 5- Sair\n");

            printf( "\nEscolha a tabela, dentre uma das mencionadas acima, para inserir valores");
            printf("\nOpcao -> ");
            scanf("%d",&acao);
            system("clear");
        
            switch (acao){

                case 1:     //cadastrar usuarios
                    continua = 1;
                    while(continua==1){
                        insere(1);
                        system("clear");
                        printf("\nDigite 1 para inserir outra Tupla na mesma Tabela. Outro numero para voltar ao menu principal:");
                        scanf("%d", &continua);
                    }//while
                    
                    break;  

                case 2:
                    continua = 1;
                    while(continua == 1){
                        insere(2);
                        system("clear");
                        printf("\nDigite 1 para inserir outra Tupla na mesma Tabela. Outro numero para voltar ao menu principal: ");
                        scanf("%d", &continua);
                    }
                    
                    break;  

                case 3:
                    continua = 1;
                    while(continua){
                        insere(3);
                        system("clear");
                        printf("\nDigite 1 para inserir outra Tupla na mesma Tabela. Outro numero para voltar ao menu principal: ");
                        scanf("%d", &continua);
                    }//while

                    break;     

                case 4:
                    continua = 1;
                    while(continua == 1){
                        insere(4);
                        system("clear");
                        printf("\nDigite 1 para inserir outra Tupla na mesma Tabela. Outro numero para voltar ao menu principal: ");
                        scanf("%d", &continua);
                    }
                    
                    break;        

                case 5:     
                    return;
                    break;
        
                default:
                    printf("\nVoce digitou uma opcao invalida! \n\nDigite qualquer numero para voltar ao menu principal... ");
                    scanf("%d", &continua);    
                    break;      //default
            }   
                    
        }
        else if(opcao == 2){ //imprimir tabelas
        
            continua = 1;     
            while(continua==1){
        
                system("clear");
                printf(" 1- Tabela Carro\n"
                    " 2- Tabela Modelo \n"
                    " 3- Tabela Fabricante \n"
                    " 4- Tabela Proprietário\n"
                    " 5- Retornar ao menu Principal\n"
                    " 6- Sair\n");

                printf( "\nEscolha a tabela para imprimir, dentre uma das mencionadas acima.");
                printf("\nOpcao -> ");
                scanf("%d",&acao);
                system("clear");
            
                switch (acao){
                    case 1:
                        system("clear");
                        imprime("Carro");
                        printf("\nDigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
                        scanf("%d", &continua);
                        
                        break;

                    case 2:
                        system("clear");
                        imprime("Modelo");
                        printf("\nDigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
                        scanf("%d", &continua);
                    
                        break;

                    case 3:
                        system("clear");
                        imprime("Fabricante");
                        printf("\nDigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
                        scanf("%d", &continua);

                        break;  

                    case 4:
                        system("clear");
                        imprime("Proprietario");
                        printf("\nDigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
                        scanf("%d", &continua);
                    
                        break;

                    case 5:
                        continua = 2;
                        
                        break;

                    case 6:     //opcao sair do programa
                        return;
                        break;
            
                    default:
                        printf("\nVoce digitou uma opcao invalida! \n\ndigite 1 para voltar ao menu de impressao, outro numero para o menu principal:");
                        scanf("%d", & continua);    

                        break;  //default
                }
            }
            
        }
        else if(opcao == 4){    //sair
            return;
        }
        else if(opcao == 3){
            
            continua = 1;     
            while(continua==1){
                system("clear");
                printf(" 1- Tabela Carro\n"
                    " 2- Tabela Modelo \n"
                    " 3- Tabela Fabricante \n"
                    " 4- Tabela Proprietário\n"
                    " 5- Sair\n");

                printf( "\nEscolha a tabela, dentre uma das mencionadas acima para exclui-la");
                printf("\nOpcao -> ");
                scanf("%d",&acao);
                system("clear");
            
                switch (acao){
                    case 1:
                        system("clear");
                        excluir("Carro");
                        printf("\nDigite 1 para voltar ao menu de exclusao, outro numero para o menu principal:");
                        scanf("%d", &continua);
                        
                        break;

                    case 2:
                        system("clear");
                        excluir("Modelo");
                        printf("\nDigite 1 para voltar ao menu de exclusao, outro numero para o menu principal:");
                        scanf("%d", &continua);
                    
                        break;

                    case 3:
                        system("clear");
                        excluir("Fabricante");
                        printf("\nDigite 1 para voltar ao menu de exclusao, outro numero para o menu principal:");
                        scanf("%d", &continua);

                        break;

                    case 4:
                        system("clear");
                        excluir("Proprietario");
                        printf("\nDigite 1 para voltar ao menu de exclusao, outro numero para o menu principal:");
                        scanf("%d", &continua);
                    
                        break;            

                    case 5:     //opcao sair do programa
                        return;
                        break;
            
                    default:
                        printf("\nVoce digitou uma opcao invalida! \n\ndigite 1 para voltar ao menu de exclusao, outro numero para o menu principal:");
                        scanf("%d", & continua);    

                        break;   //default
                }
            }
            
        }
        else{      //opcao invalida
            y = 1;
        }  
    } 
}

/***********************************************************************************|
|* FUNÇÃO: Utilizada na impressão das tabelas, conforme nomeTabela                 */   
    
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
    

    column *pagina = getPage(bufferpoll, esquema, objeto, 0);

    if(pagina == ERRO_PARAMETRO){
        printf("Erro, na função getPage(), problemas no parametro.\n");
        return ;
    }
    
    // PARA IMPRIMIR PÁGINA
    for(j=0; j < objeto.qtdCampos*bufferpoll[0].nrec; j++){
        
        if(pagina[j].tipoCampo == 'S')
            printf("%s: %-15s ", pagina[j].nomeCampo,pagina[j].valorCampo);
        else if(pagina[j].tipoCampo == 'I'){
            int *n = (int *)&pagina[j].valorCampo[0];
            printf("%s: %-15d ",pagina[j].nomeCampo, *n);
        }
        else if(pagina[j].tipoCampo == 'C'){
            printf("%s: %-15c ",pagina[j].nomeCampo, pagina[j].valorCampo[0]);
        }
        else if(pagina[j].tipoCampo == 'D'){
            double *n = (double *)&pagina[j].valorCampo[0];
            printf("%s: %-15f ",pagina[j].nomeCampo, *n);
        }
        if(j>=1 && ((j+1)%objeto.qtdCampos)==0){
            printf("\n");
        }
    }
    printf("\n\n");
}

/***********************************************************************************|
|* FUNÇÃO: Inserir tuplas na tabela selecionada conforme 'menu'.                   */   
    
void insere(int menu){
    int nrTabelas,erro, object, schema, carro, modelo, fabricante, proprietario;  
    char var[10];
	nrTabelas = 4;
    table  *tab[nrTabelas];
    column *colunas = NULL;
    
    object         = existeArquivo("fs_object.dat");
    schema         = existeArquivo("fs_schema.dat");
    carro          = existeArquivo("Carro.dat");
    modelo         = existeArquivo("Modelo.dat");
    fabricante     = existeArquivo("Fabricante.dat");
    proprietario   = existeArquivo("Proprietario.dat");
    if(!object || !schema){

        //Carro
        if(!carro){
            tab[0] = iniciaTabela("Carro");   
            tab[0] = adicionaCampo(tab[0], "Rnbr"       , 'S', 20);
            tab[0] = adicionaCampo(tab[0], "Kms"        , 'I', (sizeof(int)));
            tab[0] = adicionaCampo(tab[0], "DataCompra" , 'S', 10);
            tab[0] = adicionaCampo(tab[0], "Ano"        , 'I', (sizeof(int)));
            tab[0] = adicionaCampo(tab[0], "Modelo"     , 'I', (sizeof(int)));
            tab[0] = adicionaCampo(tab[0], "Motor"      , 'D', (sizeof(double)));
            erro = finalizaTabela(tab[0]);
        }

        //Modelo
        if(!modelo){
            tab[1] = iniciaTabela("Modelo"); 
            tab[1] = adicionaCampo(tab[1], "Modelo"     , 'S', 5);
            tab[1] = adicionaCampo(tab[1], "NomeMod"    , 'S', 10);
            tab[1] = adicionaCampo(tab[1], "Fabricante" , 'S', 5);
            erro = finalizaTabela(tab[1]);
        }

        //Fabricante
        if(!fabricante){
            tab[2] = iniciaTabela("Fabricante"); 
            tab[2] = adicionaCampo(tab[2], "FatCod"    , 'S', 5);
            tab[2] = adicionaCampo(tab[2], "NomeFat"   , 'S', 15);
            erro = finalizaTabela(tab[2]);
        }

        //Proprietário
        if(!proprietario){
            tab[3] = iniciaTabela("Proprietario");
            tab[3] = adicionaCampo(tab[3], "Rg"        , 'S', 10);    
            tab[3] = adicionaCampo(tab[3], "Nome"      , 'S', 15);    
            tab[3] = adicionaCampo(tab[3], "DataNasc"  , 'S', 8);    
            tab[3] = adicionaCampo(tab[3], "Email"     , 'S', 20);    
            erro = finalizaTabela(tab[3]); 
        }
    }

    switch (menu){
        case 1:
            printf("\nDigite o codigo do Carro (Rnbr):");
            setbuf(stdin, NULL);
            fgets(var, 20, stdin);
            colunas = insereValor(colunas, "Rnbr", var);
            
            printf("\nDigite a Kilometragem do Carro:");
            scanf("%s", var);
            colunas = insereValor(colunas, "Kms", var);
            
            printf("\nDigite a Data da Compra:");
            setbuf(stdin, NULL);
            fgets(var, 10, stdin);
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

    if(!erro){
        printf("Erro na criação das tabelas!\n");
        return;
    }

    
}
        
/***********************************************************************************|
|* FUNÇÃO: Verifica a existência do arquivo da tabela 'filename'.                  */   
    
int existeArquivo(const char* filename){
    FILE* fptr = fopen(filename, "r");
    if (fptr != NULL){
        fclose(fptr);
        
        return 1;
    }

    return 0;
}

/***********************************************************************************|
|* FUNÇÃO: Exclui a tabela com 'nomeTabela'                                        */   
    
void excluir(char nomeTabela[]){
    int status, x, j;
    
    struct fs_objects objeto = leObjeto(nomeTabela);    
    tp_table  *esquema     = leSchema(objeto);
    tp_buffer *bufferpoll = initbuffer();

    status = SUCCESS;
    for(x = 0; status == SUCCESS; x++)
        status = colocaTuplaBuffer(bufferpoll, x, esquema, objeto);    

    column *tuplaE = excluirTuplaBuffer(bufferpoll, esquema, objeto, 0, x - 2); //pg, tupla
    //column *pagina = getPage(bufferpoll, esquema, objeto, 0);


    if(tuplaE == ERRO_PARAMETRO){
        printf("Erro na função excluirTuplaBuffer(), problemas no parametro.\n");
        return;
    }
    /*if(pagina == ERRO_PARAMETRO){
        printf("Erro na função getPage(), problemas no parametro.\n");
        return;
    }*/
        
    // PARA IMPRIMIR TUPLA EXCLUIDA 
    printf("\nTupla excluída do Buffer.\n");
    for(j = 0; j < objeto.qtdCampos; j++){
        
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
