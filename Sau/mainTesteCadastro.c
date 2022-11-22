#include <stdlib.h>
#include <stdio.h>
#include "minunit.h"
#include "cadastro.h"
#include "abreArquivo.h"

#define NOMEARQ "../Bases/BaseTesteCadastro.txt"

int tests_run = 1;

static char *testesCadastro(void){
    puts("Iniciando Testes Validos!!\n");
    
    mu_assert("Testar usuário e senha que não existem no .txt", 1==cadastrar(NOMEARQ,"testeUser", "testPass"));
    mu_assert("Testar usuário e senha que já existem", 2==cadastrar(NOMEARQ,"testeUser1","testePass1"));
    mu_assert("Testar usuário que existe no txt e uma senha errada", 0==cadastrar(NOMEARQ,"testeNaoEncontra","passNaoEncontra"));
    
    return 0;
}


static char *testes(void) {
    mu_run_test(testesCadastro);

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