#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "interface.h"
#include "util.h"

#define COLUNAS 60
#define ESCAPE 27


void lerArquivo() 
{
    char nome_arquivo[255];
    //função lerNomeArquivo está no arquivo util.c (documentação em util.h)
    lerNomeArquivo(nome_arquivo);
    
    FILE *arquivo = fopen(nome_arquivo, "r"); 
    
    if (arquivo == NULL) {
        printf(" Erro: o arquivo \"%s\" não foi encontrado.\n\n", nome_arquivo);
        return;
    }
    printf("\n");
    
    char leitura_arquivo[COLUNAS];
    
    cabecalhoArquivo(nome_arquivo);
    
    while(fgets(leitura_arquivo, sizeof(leitura_arquivo), arquivo)) {
        printf(" %s\n", leitura_arquivo);
    }
    
    fclose(arquivo);
    printf("\n\n");
}


void criarArquivo() 
{
    char nome_arquivo[255];
    lerNomeArquivo(nome_arquivo);
    
    FILE *arquivo = fopen(nome_arquivo, "r");
    
    if (arquivo != NULL) {         
        fclose(arquivo);
        int arquivo_novo;
        
        printf("\n O arquivo %s já existe.\n Deseja sobreescrevê-lo?\n 0 - Não\n 1 - Sim\n > ", nome_arquivo);
        scanf(" %d", &arquivo_novo);
        limparBuffer();
        if (!arquivo_novo) {
            return;
        }
    }
    
    arquivo = fopen(nome_arquivo, "w");
    char texto[COLUNAS];
    int escrita_arquivo;
    
    cabecalhoArquivo(nome_arquivo);
    printf(" Digite o conteúdo do arquivo:\n");
    printf(" Para sair escreva: \n");
    
    do {
        printf(" > ");
        fgets(texto, sizeof(texto), stdin);
        escrita_arquivo = 0;
        if(!encerrarEscritaArquivo(texto)) {
            fprintf(arquivo, texto);
            escrita_arquivo = 1;
        }
    } while (escrita_arquivo);
    
    fclose(arquivo);
    printf("\n\n");
}


void editarArquivo() 
{
    char nome_arquivo[255];
    lerNomeArquivo(nome_arquivo);
    
    FILE *arquivo = fopen(nome_arquivo, "r");
    
    if (arquivo == NULL) {
        int arquivo_novo;
        printf("\n O arquivo %s não existe.\n Deseja criá-lo?\n 0 - Não\n 1 - Sim\n > ", nome_arquivo);
        scanf(" %d", &arquivo_novo);
        limparBuffer();
        if (!arquivo_novo) {
            return;
        }
    //escrita do arquivo
        arquivo = fopen(nome_arquivo, "w");
        char texto[COLUNAS];
        int escrita_arquivo;
        cabecalhoArquivo(nome_arquivo);
        printf(" Digite o conteúdo do arquivo:\n");
        do {
            printf(" > ");
            fgets(texto, sizeof(texto), stdin);
            escrita_arquivo = 0;
            printf("\n");
            if(!encerrarEscritaArquivo(texto)) {
                fprintf(arquivo, texto);
                escrita_arquivo = 1;
            }
        } while (escrita_arquivo);
    
        fclose(arquivo);
        printf("\n\n");
        return;
    }
    //edicão do arquivo
    char texto[COLUNAS];
    int escrita_arquivo;
    cabecalhoArquivo(nome_arquivo);
    
    while(fgets(texto, sizeof(texto), arquivo)) {
        printf(" %s\n", texto);
    }
    
    fclose(arquivo);
    
    arquivo = fopen(nome_arquivo, "a");

    printf("\n Digite o conteúdo do arquivo:\n");
    do {
        printf(" > ");
        fgets(texto, sizeof(texto), stdin);
        escrita_arquivo = 0;
        printf("\n");
        if(!encerrarEscritaArquivo(texto)) {
            fprintf(arquivo, texto);
            escrita_arquivo = 1;
        }
    } while (escrita_arquivo);
    
    fclose(arquivo);
    printf("\n\n");
    return;
}


void excluirArquivo() 
{   
    char nome_arquivo[255];
    lerNomeArquivo(nome_arquivo);
    
    FILE *arquivo = fopen(nome_arquivo, "r");
    
    if (arquivo == NULL) {
        printf(" Erro: o arquivo \"%s\" não foi encontrado.\n\n", nome_arquivo);
        return;
    }
    
    fclose(arquivo);
    int deletar_arquivo;
    
    printf("\n O arquivo %s será deletado permanentemente.\n Deseja continuar?\n 0 - Não\n 1 - Sim\n > ", nome_arquivo);
    scanf(" %d", &deletar_arquivo);
    limparBuffer();
    if(!deletar_arquivo) {
        return;
    }
    if(remove(nome_arquivo) == 0) {
        printf("\n O arquivo %s foi deletado com sucesso.\n\n", nome_arquivo); 
    }
}


void importarArquivo() 
{
    printf(" Disponível em breve\n\n");
}


void encerrarPrograma() 
{
    printf(" Encerrando o programa..."); 
    exit(EXIT_SUCCESS);
}
