#include <stdio.h>   // padrão entrada(input) e saída(output)
#include <stdlib.h>  // biblioteca padrão  - manipulação de arquivos, malloc/realloc;
#include <string.h>  //
#include <stdbool.h> //

/*

Funções principais
1. Abrir um arquivo para leitura;
2. Criar um arquivo para escrita;
3. Editar um arquivo;
4. Excluir um arquivo;
5. Importar um arquivo;
6. Encerrar um programa;

//alocação estática
int vetor[5][6]; -- erro;
int vetor[][] = { {1, 2, 3,7,8,9}, {4, 5, 6}, {}, {}, {} };
//alocação dinâmica
int **vetor = {{}, {}, {}, {}};

printf("* ---------------- MENU DE OPÇÕES ---------------- *\n");
-printf("1. Abrir um arquivo para leitura;\n");
-printf("2. Criar um arquivo para escrita;\n");
-printf("3. Editar um arquivo;\n");
-printf("4. Excluir um arquivo;\n");
-printf("5. Importar um arquivo;\n");
-printf("6. Encerra bool verdadeiro = false; um programa;\n");

*/

int main()
{

    char *opcoesMenu[] = {
        "1. Abrir um arquivo para leitura", "2. Criar um arquivo para escrita", "3. Editar um arquivo",
        "4. Excluir um arquivo", "5. Importar um arquivo", "6. Encerrar um programa"
    };
    printf("* ---------------- Bem-vindo ao Editor de Texto CLI! ---------------- *\n");
    printf("* ---------------- Seleciona aí, miserável ---------------- *\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\n", opcoesMenu[i]);
    }
    printf("\n > ");

}
