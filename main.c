#include <stdio.h>
#include <string.h>

// CONSTANTES
#define MAX_NOME_ARQUIVO 15
#define MAX_LINHAS 30
#define MAX_COLUNAS 40

// FUNÇOES BACANAS QUE AINDA NÃO FAZEM NADA
void lerArquivo(); 
/* {
    função pra reconhecer o arquivo e mostrar ao usuário;
    busca o nome do arquivo; 
    mostra no terminal o nome do arquivo e o conteúdo do arquivo;
    respeitar o MAX_LINHAS e MAX_COLUNAS 
}*/

void criarArquivo();
/* {
    função que cria um novo arquivo na memória;
    pergunta ao usuário o nome do arquivo;
    pergunta ao usuário o que ele gostaria de colocar como conteúdo;
    enter para uma nova linha;
    condição de parada: enter duplo (?);
    respeitar o MAX_LINHAS e MAX_COLUNAS 
}*/

void editarArquivo();
/* {
    pergunta ao usuário o nome do arquivo;
    busca o nome do arquivo na memória. se o arquivo for inexistente, avisar ao usuário;
    abre o arquivo e permite que o usuário edite o nome e o conteúdo existente, podendo apagar tudo ou só adicionar;
    salva as alterações e deleta o conteúdo anterior
}*/

void importarArquivo(); // retirar talvez? não entendo qual o propósito dessa opção e vai ser dificil afuzeu fazer

void apagarArquivo();
/* {
    pede ao usuário o nome do arquivo;
    busca o arquivo, se for inexistente, avisar ao usuário;
    pergunta ao usuário se ele tem certeza que quer excluir o arquivo;
    se sim, apaga o conteúdo total do arquivo (nome e conteúdo interno)
}*/

// MENU BEM RESUMIDO
int main()
{
    char nomeArquivo[MAX_NOME_ARQUIVO];
    int menu = 0;

    while (menu != 6)
    {
        printf("1. Ler arquivo;\n");
        // scanf("%[^\n]s", nomeArquivo);
        printf("2. Criar arquivo;\n");
        printf("3. Editar arquivo;\n");
        printf("4. Importar arquivo;\n");
        printf("5. Apagar arquivo;\n");
        printf("6. Sair do programa;\n");

        scanf("%d", &menu);

        switch(menu) 
        {
            case 1:
            lerArquivo(); // criar funçao
            break;

            case 2:
            criarArquivo();
            break;

            case 3:
            editarArquivo();
            break;

            case 4:
            importarArquivo();
            break;

            case 5:
            apagarArquivo();
            break;

            case 6:
            printf("Encerrando programa...");
            break;

            default:
            printf("Valor inválido.");
        }
    }

    return 0;
}
