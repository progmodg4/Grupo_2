#include <stdio.h>
#include "menuSau.h"
#include "sauHorarios.h"
#include "sauNotas.h"

void menuSau(int tipo_usuario, char* matr)
{
    int opcao;
    while(opcao != -1)
    {
        printf("Escolha uma das opcoes :\n");
        printf("1. Consultar notas\n");
        printf("2. Consultar horarios\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        // chama funcao de consulta de nota 
        // vendo qual tipo de usuario para ver o que esta
        // sendo procurado
        // para aluno procura mat
        // para prof vai ver qual a disciplina ele quer encontrar
        // entao procurar pela disciplina 
            if(tipo_usuario == 1)
                consultaNotasAlun(matr);
            else 
                consultaNotasProf(matr);
            
            break;
        case 2:
        // chama funcao de consulta horario
        // funcao vai ser a mesma para prof e aluno
        // mandando tipo de usuario 
            verHor(tipo_usuario, matr);
            break;
        case 3: // saida
            opcao = -1;
            break;
        default: // escolha diferente das existentes
            printf("Escolha invalida\nTente novamente\n");
            opcao = 0;
            break;
        }

    }

}
