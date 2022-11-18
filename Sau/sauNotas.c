#include <stdio.h>
#include <string.h>
#include "sauNotas.h"
#include "abreArquivo.h"

// txt no formato 
// mat(aluno) disciplina nota 
#define ARQNOTA "matDiscNotAlu.txt"
#define ARQDISC "matDiscHorProf.txt"
#define TAMUSU 21
#define TAMDISC 81
#define TAMHOR 6
#define NUMDISC 5
// duas funcoes
// uma para aluno porque vai procurar por matricula

// outra para professor porque vai mostrar disciplinas que ele da
// ele escolhe uma e faz a procura por tal disciplina 
// mostrando todas as matriculas e notas dos alunos 

// funcao recebe matricula
void consultaNotasAlun(char* matr)
{
    char mat[TAMUSU], disc[TAMDISC];
    float nota;
    int cmp; 
    FILE* arq = openFile(ARQNOTA, "r");
    // preciso de temporarios para guardar as outras informacoes
    // presentes no arquivo
    // procura no arquivo a matricula do aluno
    while (!feof(arq))
    {
        // procuro a matricula
        fscanf(arq, "%[^,], %[^,], %f\n", mat, disc, nota);
        cmp = strcmp(matr, mat);
        // se matricula eh igual eu printo disciplina e nota
        if (cmp == 0)
            printf("%s %.2f", disc, nota);
    }
    printf("Nao ha notas para esse usuario\n");
    fclose(arq);
    return;
}



void consultaNotasProf(char* matr)
{
    // procurar pela matricula do professor quais materias
    // ele leciona 
    // perguntar dentre as materias que ele leciona qual 
    // delas ele quer ver as notas
    FILE* arq = openFile(ARQDISC, "r");
    char mat[TAMUSU], disc[TAMDISC], hora[TAMHOR];
    char vetorDisc[NUMDISC][TAMDISC];
    int cmp, i, j, opcao, check;
    float nota;
    i = 0;
    check = 0;
    while(!feof(arq))
    {
        fscanf(arq, "%[^,], %[^,], %[^\n]\n", mat, disc, hora);
        cmp = strcmp(matr, mat);
        if(cmp == 0) // achei matricula do professot
        {
            strcpy(vetorDisc[i], disc); // copio disc para o vetor
            i++;
        }
    }
    // quando sai do while tenho todas as disciplinas que tal prof
    // leciona 
    fclose(arq);
    // se nao existem disciplinas no vetor
    if(i==0)
    {
        printf("Nao ha notas para esse disciplina\n");
        return;
    }
    // mostro todas as disciplinas
    for(j = 0; j<i; j++)
        printf("%d. %s", j+1, vetorDisc[j]); // mostrei indice do vetor + 1
    check = 0;
    while(check != -1)
    {
        printf("Deseja ver a nota de qual disciplina : ");
        scanf("%d", &opcao);
        if(opcao>= 1 && opcao < i)
            check = -1;
        else 
        {
            printf("Opcao invalida\n");
            check = 0;
        }   
    }
    opcao--; // para pegar o indice certo do vetor
    arq = openFile(ARQNOTA, "r"); // procuro no arquivo de notas as matriculas que tem nota em tal materia
    while(!feof(arq))
    {
        fscanf(arq, "%[^,], %[^,], %f\n", mat, disc, nota);
        cmp = strcmp(disc, vetorDisc[opcao]);
        if (cmp == 0) // achei disciplina procurada
        {
            printf("%-20s %.2f",mat, nota);
        }
    }
    fclose(arq);
    return;
}

// preciso de um vetor para guardar todas as disciplinas 
// que tal prof da aula
// depois tem que comparar com o arquivo de notas 
// cada posicao do vetor que tiver tal disciplina
// restricao :
// nao podem existir 2 professores que lecionam
// a mesma materia
// restricao:
// um professor nao pode dar aula em mais de 5 disciplinas 
