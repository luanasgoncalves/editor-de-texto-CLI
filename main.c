#include <stdio.h>
#include "interface.h"
#include "arquivos.h"


int main() 
{
	for(;;) {
	    switch(menu()) {
	        case 1: 
				lerArquivo(); break;
			case 2: 
				criarArquivo(); break;
			case 3:
				editarArquivo(); break;
			case 4:	
				importarArquivo(); break;	
			case 5:
			    excluirArquivo(); break;
			case 6:
			    encerrarPrograma();
		    default: 
		        printf(" Erro: valor inválido\n\n");
	    }
	}
	return 0;
}
