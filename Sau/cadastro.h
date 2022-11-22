/** 
 * @param {FILE *arq} Nome do arquivo com os cadastros.
 * @param {char *usuario} Matrícula inserida pelo usuário.
 * @param {char *senha} Senha inserida pelo usuário.
 * @returns {int} 1: para cadastro com sucesso; 2: se o par matrícula e senha ja esteja cadastrado; 0: caso já exista matrícula com outra senha.
 */

int cadastrar(char *nomeArq, char *usuario, char *senha);
