#include <stdio.h>
#include <string.h>
#include "abreArquivo.h"

#define ARQUSU "../Bases/livrosAlugadosUsu.txt"
#define ARQFUNC "../Bases/BaseLivros.txt"
#define TAMUSU 21
#define TAMLIV 21
#define TAMEDI 15
/* usuario da biblioteca pode ver com essa funcao todos os
livros que estao alugados por ele nesse momento
formatacao do txt :
matr, id, nome(livro), editora
matr eh a matricula de quem teria alugado tal livro
id eh a identificacao unica do livro
char d char char */

void checaLivrosAlugadosUsu(char *matr)
{
    char matrArq[TAMUSU], nomeLivro[TAMLIV], editora[TAMEDI];
    FILE *arq = openFile(ARQUSU, "r");
    int cmp, check, idLivro;
    check = 0;

    while (!feof(arq))
    {
        // pego todas as informacoes
        fscanf(arq, "%[^,], %d, %[^,], %[^,]\n", matrArq, &idLivro, nomeLivro, editora);
        // comparo matricula que peguei com a que usuario ja deu
        cmp = strcmp(matrArq, matr);
        // se encontrar printa nome do livro e editora
        if (cmp == 0)
        {
            check++;
            printf("1. %s\t%s", nomeLivro, editora);
        }
    }
    fclose(arq);
    if (check == 0)
        printf("Nao existem livros que estao alugados com a matricula %s\n", matr);

    return;
}

/* bibliotecario (funcionario ) ve todos os livros, escolhendo
se quer ver aqueles que estao alugados ou os que nao estao
formatacao do txt :
id(livro) nome(livro) editora 0/1(alugado ou nao) matr
id eh a identificacao unica do livro
0/1 para marcar se tal livro esta alugado ou nao
matr eh a matricula de quem teria alugado tal livro

*/

void checaLivrosFunc(void)
{
    // variaveis char auxiliares para ler o arquivo
    char matrArq[TAMUSU], nomeLivro[TAMLIV], editora[TAMEDI];
    FILE *arq = openFile(ARQFUNC, "r");
    int cmp, idLivro, opcao, check;
    // perguntar ao usuario
    while (opcao == -1)
    {
        printf("Escolha :\n");
        printf("1. Ver livros alugados\n");
        printf("2. Ver livros nao alugados\n");
        scanf("%d", &opcao);
        if (opcao != 1 && opcao != 2)
        {
            printf("Escolha invalida\nTente novamente\n");
            opcao = -1;
        }
    }
    if (opcao == 1) // livros alugados tem 0
    {
        opcao = 0;
        printf("\tLivros alugados\t\n");
    }
    else
    {
        opcao = 1; // livros nao alugados tem 1
        printf("\tLivros nao alugados\t\n");
    }

    // ler todo o arquivo e printar conforme encontrar o que
    // o usuario pediu
    while (!feof(arq))
    {
        fscanf(arq, "%d, %[^,], %[^,], %d\n", &idLivro, nomeLivro, editora, &check);
        if (check == 0) // livro esta alugado
        {
            if (opcao == 0) // se o livro esta alugado e o funcionario deseja ver livros alugados entao pego a matricula e printo
            {
                fscanf(arq, ", %[^,]", matrArq);
                printf("%d %s %s matr :%s", idLivro, nomeLivro, editora, matrArq);
            }
        }
        else // check == 1
        {
            if (opcao == 1) // se o livro nao esta alugado e o funcionario deseja ver livros que nao estao alugados
                printf("%d %s %s", idLivro, nomeLivro, editora);
        }
    }
    fclose(arq);

    return;
}
