#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

#define COLUNAS 60
#define ESCAPE 27

const char *condicoes_parada[] = {
        "sair\n", "parar\n", "encerrar escrita\n",
        "exit\n", "stop\n", "stop writing\n",
    };
    
int encerrarEscritaArquivo(char *texto) 
{
    //ponteiro nulo ou string vazia
    if (texto == NULL || texto == 0) {
        return 0;
    }
    //converte o texto original para caixa baixa
    char condicao_parada[COLUNAS+1];
    int rep = COLUNAS > strlen(texto) ? strlen(texto) : COLUNAS;
    for (int i = 0; i <= rep; i++) {
        condicao_parada[i] = tolower(texto[i]);
    }
    
    int num_validacoes = sizeof(condicoes_parada) / sizeof(condicoes_parada[0]);

    for (int i = 0; i < num_validacoes; i++){
        if (*texto == '\n' || *texto == ESCAPE || strcmp(condicao_parada, condicoes_parada[i]) == 0) {
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
