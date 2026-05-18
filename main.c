#include <stdio.h>   // padrão entrada(input) e saída(output)
#include <stdlib.h>  // biblioteca padrão  - manipulação de arquivos, malloc/realloc;
#include <string.h>  //
#include <stdbool.h> //

// CONSTANTES
#define MAX_NOME_ARQUIVO 15
#define MAX_LINHAS 30
#define MAX_COLUNAS 40

// FUNÇOES BACANAS QUE AINDA NÃO FAZEM NADA
void lerArquivo();
void criarArquivo();
void editarArquivo();
void importarArquivo();
void apagarArquivo();

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
