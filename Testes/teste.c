#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    struct fs_objects { // Estrutura usada para carregar fs_object.dat
        char nome[20];
        int cod;
        char nArquivo[20];
        int qtdCampos;
    };

    typedef struct tp_table{ // Estrutura usada para carregar fs_schema.dat
        char nome[20];  
        char tipo;                      
        int tam;                        
        struct tp_table *next;  
    }tp_table;
    
struct fs_objects leObjeto(char *nTabela){
    FILE *dicionario;
    char *tupla = (char *)malloc(sizeof(char)*20);
    int cod;
    dicionario = fopen("fs_object.dat", "a+b"); // Abre o dicionario de dados.

    struct fs_objects objeto;

    if(!verificaNomeTabela(nTabela)){
        printf("Erro GRAVE! na função leObjeto(). Nome da tabela inválido.\nAbortando...\n");
        //exit(1);
    }

    if (dicionario == NULL) {
        printf("Erro GRAVE! na função leObjeto(). Arquivo não encontrado.\nAbortando...\n\n");
        exit(1);
    }
    

    while(fgetc (dicionario) != EOF){
        fseek(dicionario, -1, 1);

        fread(tupla, sizeof(char), 20 , dicionario); //Lê somente o nome da tabela

        if(strcmp(tupla, nTabela) == 0){ // Verifica se o nome dado pelo usuario existe no dicionario de dados.
            strcpy(objeto.nome, tupla);
            fread(&cod,sizeof(int),1,dicionario);   // Copia valores referentes a tabela pesquisada para a estrutura.
            objeto.cod=cod;
            fread(tupla,sizeof(char),20,dicionario);
            strcpy(objeto.nArquivo, tupla);
            fread(&cod,sizeof(int),1,dicionario);
            objeto.qtdCampos = cod;
            
            return objeto;
        }
        fseek(dicionario, 28, 1); // Pula a quantidade de caracteres para a proxima verificacao(4B do codigo, 20B do nome do arquivo e 4B da quantidade de campos).
    }
    return objeto;
}

int verificaNomeTabela(char *nomeTabela){
    FILE *dicionario;
    char *tupla = (char *)malloc(sizeof(char)*20);
    if((dicionario = fopen("fs_object.dat","a+b")) == NULL)
        return -6;

    while(fgetc (dicionario) != EOF){
        fseek(dicionario, -1, 1);

        fread(tupla, sizeof(char), 20, dicionario); //Lê somente o nome da tabela

        if(strcmp(tupla, nomeTabela) == 0){ // Verifica se o nome dado pelo usuario existe no dicionario de dados.
            
            return 1;
        }
        fseek(dicionario, 28, 1);
    }
    fclose(dicionario);
    return 0;
}

int main(){ 
    struct fs_objects objeto;
    objeto = leObjeto("tabela");
    printf("\n retorno: %s", objeto.nome);
    return 0;
}
