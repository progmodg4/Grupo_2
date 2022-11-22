#include <stdlib.h>
#include <stdio.h>
#include "minunit.h"
#include "login.h"
#include "abreArquivo.h"

#define NOMEARQ "../Bases/BaseTesteLogin.txt"

int tests_run = 1;

static char *testesLogin(void){
    puts("Iniciando Testes Validos!!\n");
    FILE* arqTeste = openFile(NOMEARQ,"r");
    
    mu_assert("testar com usuário e senha que existem no .txt", 0==buscaArq(arqTeste,"testeUser", "testPass"));
    mu_assert("Testar com usuario que existe, mas com  senha errada", 1==buscaArq(arqTeste,"testeUser1","testePass1"));
    mu_assert("Testar com usuário que não existe", 1== buscaArq(arqTeste,"testeNaoEncontra","passNaoEncontra"));
    
    fclose(arqTeste);

    return 0;
}


static char *testes(void) {
    mu_run_test(testesLogin);

    return 0;

}

int main(void){
    char *saida;

    saida = testes();

    if(0!=saida) {
        puts(saida);
        return EXIT_FAILURE;
    }

    puts("TESTES EXECUTADOS COM SUCESSO");
    printf("Testes executados: %d\n", tests_run);

    return EXIT_SUCCESS;

    return 0;
}