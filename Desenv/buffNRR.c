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
    
table** criarTabelas(int nrTabelas){
    int  i;
    char nome[20];

    table **vetor = (table **) malloc( nrTabelas * sizeof(table*));
    
    for(i = 0; i < nrTabelas; i++){   
       printf("Digite o nome da tabela %d: \n", i);
       scanf("%s", nome);
       vetor[i] = iniciaTabela(nome);

    }
        
    return vetor;
}


int main(){
    int erro,num,i, indc;
    char tabela[20];
    
    char nome[20],sexo[10],end[40],idade[10],altura[10];
    table **tabelas;
    
    table *t = NULL;
    column *c = NULL;
    
    tabelas = criarTabelas(4);
    for(indc = 0; indc < 4; indc++)
        printf("%s\n", tabelas[indc][0].nome);
    
    



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
