/**
 * @brief Menu para consulta de notas e horários das disciplinas para 2 tipos de usuários: aluno (usuário comum) e professor (funcionário)
 * 
 * @param {int tipo_usuario} Tipo do usuário; 1: usuário comum; qualquer outro valor: funcionário.
 * @param {char *matr} Matrícula do usuário.
 * @returns {void} .
 * @interface 1a tela: prompt para qual operação realizar (consultar nota ou horários, ou sair); 2a tela: relação de notas (1) ou 
 * relação de horários (2), para cada tipo de usurário apresenta-se uma interface diferente em cada uma das opções (notas e horários)
 */
void menuSau(int tipo_usuario, char* matr);
