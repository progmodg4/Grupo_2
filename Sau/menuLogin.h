/**
 * @brief Interface para login e cadastro de usuários.
 * 
 * @param {int tipo_usuario} Tipo do usuário; 1: usuário comum; qualquer outro valor: funcionário.
 * @param {int *check} Aponta para -1 (login falhou) por padrão; modifica-se para 0 caso o login seja feito com sucesso.
 * @returns {char*} Matrícula inserida pelo usuário.
 * @interface 1a tela: prompt para qual operação realizar; 2a tela : prompt para inserir matricula e senha.
 */

char* fazLogin(int tipo_usuario, int *check);
