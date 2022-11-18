#include <stdio.h>
#include <string.h>
#include "menuLogin.h"
#include "menuSau.h"
// primeiro menu vai servir para os dois tipos e usuario 

#define TAMUSU 21

int main(void)
{
    int retorno, tipo_usuario = -1;
    int check = -1;
    FILE* arq;
    char matr[TAMUSU]; 
    while(tipo_usuario == -1)
    {
        printf("Esolha o tipo da sua conta :\n");
        printf("1. Estudante\n");
        printf("2. Professor\n");
        scanf("%d", &tipo_usuario);
        if(tipo_usuario != 1 && tipo_usuario != 2)
        {
            printf("Escolha invalida\n");
            tipo_usuario = -1;
        }
    }

    // chama menuLogin
    // pergunto a matricula e senha dentro da funcao 
    // pego de volta para usar aqui
    strcpy(matr,fazLogin(tipo_usuario, &check));
    printf("Matr : %s\n", matr);
    // login bem sucedido
    // chama menu sau com tipo de usuario
    // tudo vai ser feito dentro do modulo menusau
    // menusau chama as outras funcoes 
    if(check == 0)
        menuSau(tipo_usuario, matr);
    // check sendo diferente de 0 quer dizer que 
    // nao quis entrar na plataforma
    return 0;
}


// para sair do while colocar valor qualquer na variavel
// tipo usuario e assim vai terminar o programa 