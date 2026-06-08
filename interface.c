#include <stdio.h>

#include "interface.h"
#include "util.h"

#define COLUNAS 40


int menu() 
{
    int opcao_menu_selecionada;
    
    cabecalhoMenu();
    listarOpcoesMenu();
    printf(" > ");
    scanf(" %d", &opcao_menu_selecionada);
    limparBuffer();
    printf("\n");
    
    return opcao_menu_selecionada;
}


void listarOpcoesMenu() 
{
    const char *opcoes_menu[] = {
        "1 - Ler arquivo", 
        "2 - Criar arquivo", 
        "3 - Editar arquivo", 
        "4 - Importar arquivo", 
        "5 - Apagar arquivo", 
        "6 - Sair do programa"
    };
    
    const int num_opcoes = sizeof(opcoes_menu) / sizeof(opcoes_menu[0]);
    
    for (int i = 0; i < num_opcoes; i++) {
        printf(" %s\n", opcoes_menu[i]);
    }
}


void cabecalhoMenu() 
{
    criarLinha();
    printf("\tDigite a opção desejada:\n");
    criarLinha();
}


void cabecalhoArquivo(char *nome_arquivo) 
{ 
	criarLinha();
	printf("\t%s\n", nome_arquivo);
	criarLinha();
}


void criarLinha() 
{
    for(int i = 0; i < COLUNAS; i++) {
        printf("~");
    }
    printf("\n");
}

