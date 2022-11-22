/**
 * @brief Fornece a relação de disciplinas e seus horários em que o aluno ou professor está inscrito.
 * 
 * @param {int tipo_usuario} Tipo do usuário; 1: usuário comum; qualquer outro valor: professor.
 * @param {char *matr} Matrícula do usuário.
 * @returns {void} .
 * @interface Apresenta-se uma tabela de duas colunas, sendo a primeira coluna o nome da disciplina e a segunda coluna, o horário dela, caso
 * a matrícula seja encontrada. 
 * 
 * Obs: formato do arquivo 
 * mat, disci, horario 
 * char, char, char
 */

void verHor(int tipo_usuario, char* matr);
