#include <stdio.h>
#include <string.h>
#include "abreArquivo.h"

#define ARQUSU "../Bases/matDiscHorAlu.txt"
#define ARQFUNC "../Bases/matDiscHorProf.txt"
#define TAMMAT 21
#define TAMDISC 81
#define TAMHORA 6

// formato do arquivo 
// mat, disci, horario 
// char, char, char

// funcao recebe matricula
void verHor(int tipo_usuario, char* matr)
{
    FILE* arq; 
    char mat[TAMMAT], disc[TAMDISC], hora[TAMHORA];
    int cmp = -1;
    int vezes = 0;
    // unica diferenca eh o arquivo que vai ser aberto 
    if(tipo_usuario == 1)
        // abro arquivo estudante
        arq = openFile(ARQUSU, "r");
    else // abro arquivo professor
        arq = openFile(ARQFUNC, "r");

    while (!feof(arq))
    {
        // procuro a matricula
        fscanf(arq, "%[^,], %[^,], %[^\n]\n", mat, disc, hora);
        cmp = strcmp(matr, mat);
        // se matricula eh igual eu printo disciplina e horario 
        if(cmp == 0)
        {
            printf("%s %s", disc, hora);
            vezes++;
        }
    }
    // se vezes nao mudou o valor quer dizer que tal matricula 
    // nao aparece no arquivo
    if(vezes == 0)
        printf("Matricula %s nao ancontrada no arquivo\n", matr);
    fclose(arq);
    return; 

}
