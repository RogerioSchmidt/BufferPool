/*/////////////////////////////////////////////////////////////////////////////////*
//  Alunos: Natan J. Mai, Ricardo Zanuzzo e Rogério Torchelsen                    //
//  Disciplina: Banco de Dados II                                                 //      
//  Curso: Ciência da Computação                                                  //      
//  Universidade Federal da Fronteira Sul                                         //      
//                                                                                //      
//                                                                                //      
//                                                                                //      
//////////////////////////////////////////////////////////////////////////////////*/

#include "buffend.h"

   
int main(){
    int nrTabelas, indc, erro, opcao = 999, opcaoT = 999;    
    char var[20];

    nrTabelas = 4;
    table  *tab[nrTabelas];
    column *c = NULL;

    while(opcao != 0){
        printf(
            " ------------------------ \n"
            "| 0 - Sair               |\n"
            "| 1 - Iniciar Tabelas    |\n"
            "| 2 - Inserir Valores    |\n"
            "| 3 - Consult Tabelas    |\n"
            "| 4 - Remover Tabelas    |\n"
            " ------------------------ \n");
        scanf("%d", &opcao);

        switch (opcao){ 
            case 1 :

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
                
                break;

            case 2:
                printf(
                    " ----------INSERIR--------- \n"
                    "| 0 - Sair                 |\n"
                    "| 1 - Tabela Carros        |\n"
                    "| 2 - Tabela Modelo        |\n"
                    "| 3 - Tabela Fabricante    |\n"
                    "| 4 - Tabela Proprietario  |\n"
                    " -------------------------- \n");
                scanf("%d", &opcaoT);

                if(opcaoT == 1){

                    printf("\nDigite o codigo do Carro (Rnbr):");
                    scanf("%s", var);
                    c = insereValor(c, "Rnbr", var);

                    printf("\nDigite a  Quilometragem do Carro:");
                    scanf("%s", var);
                    c = insereValor(c, "Kms", var);

                    printf("\nDigite a Data da Compra:");
                    scanf("%s", var);
                    c = insereValor(c, "DataCompra", var);

                    printf("\nDigite o Ano do Carro:");
                    scanf("%s", var);
                    c = insereValor(c, "Ano", var);

                    printf("\nDigite o codigo do Modelo do carro:");
                    scanf("%s", var);
                    c = insereValor(c, "Modelo", var);

                    printf("\nDigite a potência Motor do carro:");
                    scanf("%s", var);
                    c = insereValor(c, "Motor", var);
                    
                    erro = finalizaInsert("Carro", c);

                    break;
                }    

                else if(opcaoT == 2){
                    printf("\nDigite o codigo do modelo do carro:");
                    scanf("%s", var);
                    c = insereValor(c, "Modelo", var);
                    
                    printf("\nDigite o Nome do Modelo:");
                    scanf("%s", var);
                    c = insereValor(c, "NomeMod", var);
                    
                    printf("\nDigite a Sigla do Fabricante:");
                    scanf("%s", var);
                    c = insereValor(c, "Fabricante", var);  

                    erro = finalizaInsert("Modelo", c);

                    break;
                }
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
