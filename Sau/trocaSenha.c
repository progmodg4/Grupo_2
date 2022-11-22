#include <stdio.h>
#include <string.h>
#include "trocaSenha.h"
#include "abreArquivo.h"

#define TAMUSU 21
#define TAMSE 15
#define ARQAUX "../cadastroAux.txt"

// vai copiando para o arquivo auxiliar ate 
// encontrar a matricula procurada
// quando encontrar coloca a nova senha naquela linha 
// continua a copia 
 
// primeiro leio arq de todos os cadastros
// e depois escrevo nele

void trocaSenha(char *nomeArq, char *usuario, char *senha_nova)
{
    FILE *arq, *arq_aux;
    int cmp;
    char usuarioArq[TAMUSU], senhaArq[TAMSE];
    arq = openFile(nomeArq, "r");
    arq_aux = openFile(ARQAUX, "w");
    while (!feof(arq))
    {
        if (fscanf(arq, "%[^,], %[^\n]\n", usuarioArq, senhaArq) != 2)
            break;
        cmp = strcmp(usuario, usuarioArq);
        if (cmp == 0) // encontrei a matricula
            strcpy(senhaArq, senha_nova);
        // coloco matricula nova
        fprintf(arq_aux, "%s, %s\n", usuarioArq, senhaArq);
    }
    // acabou o arq e tudo foi para o arqaux
    // agora faco o trabalho contrario
    fclose(arq);
    fclose(arq_aux);
    arq = openFile(nomeArq, "w");
    arq_aux = openFile(ARQAUX, "r");
    while (!feof(arq))
    {
        if (fscanf(arq_aux, "%[^,], %[^\n]\n", usuarioArq, senhaArq) != 2)
            break;
        fprintf(arq, "%s, %s\n", usuarioArq, senhaArq);
    }
    fclose(arq);
    fclose(arq_aux);
    return;
}
