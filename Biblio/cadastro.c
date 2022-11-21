#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "abreArquivo.h"
#define TAMUSU 21
#define TAMSE 15

// retorna 1 para cadastrado com sucesso
// retorna 2 se usuario e senha ja estao cadastrados
// retorna 0 caso ja exista usuario com outra senha
int cadastrar(char *nomeArq, char *usuario, char *senha)
{
    // primeiro busco para ver se ja nao existe
    int cmp1, cmp2; // pega retorno de strcmp
    FILE *arq;
    arq = openFile(nomeArq, "r");
    char usuarioArq[TAMUSU], senhaArq[TAMSE];
    while (!feof(arq))
    {
        if (fscanf(arq, "%[^,], %[^\n]\n", usuarioArq, senhaArq) != 2)
            break;
        cmp1 = strcmp(usuario, usuarioArq);
        // primeiro procuro usuario
        if (cmp1 == 0) // usuario ja existe
        {
            cmp2 = strcmp(senha, senhaArq);
            if (cmp2 == 0) // encontrou usuario e senha 
                return 2;
            else // encontrou usuario e senha errada 
                break;
        }
    }
    fclose(arq);
    // se nao retornou eh porque o usuario esta certo e
    // senha errada
    // retorna 0 porque nao foi cadastrado
    if (cmp1 == 0)
        return 0;
    // caso nao exista eu cadastro
    else
    {
        arq = openFile(nomeArq, "a");
        fprintf(arq, "%s, %s\n", usuario, senha);
        fclose(arq);
    }
    return 1;
}

