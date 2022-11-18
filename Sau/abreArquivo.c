#include <stdio.h>
#include <stdlib.h>
#include "abreArquivo.h"

FILE *openFile(const char *file, const char *mode)
{
    FILE *arq = fopen(file, mode);
    if (arq == NULL)
    {
        printf("Arquivo nao encontrado\n");
        exit(1);
    }
    return arq;
}