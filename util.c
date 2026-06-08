#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "util.h"


int encerrarEscritaArquivo(char *texto) 
{
    const char *condicoesParada[] = {
        "parar\n", "Parar\n", "PARAR\n",
        "sair\n", "Sair\n", "SAIR\n",
        "encerrar leitura\n", "Encerrar leitura\n", "ENCERRAR LEITURA\n"
    };
    
    int numValidacoes = sizeof(condicoesParada) / sizeof(condicoesParada[0]);   
    
    for (int i = 0; i < numValidacoes; i++){
        if (*texto == '\n' || strcmp(texto, condicoesParada[i]) == 0) {
           return 1;
        }
    }
    return 0;
}


void lerNomeArquivo(char *nome_arquivo)
{
    printf(" Informe o nome de arquivo: ");
    scanf("%s", nome_arquivo);
    limparBuffer();   
}


void limparBuffer()
{
    while(getchar() != '\n');
}
