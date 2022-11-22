/**
 * @brief Fornece a relação de notas das disciplinas em que o aluno está inscrito.
 * 
 * @param {char *matr} Matrícula do usuário.
 * @returns {void} .
 * @interface Apresenta-se uma tabela de duas colunas, sendo a primeira coluna o nome da disciplina e a segunda coluna, a nota (com 2 casas decimais)
 * do aluno nela, caso a matrícula seja encontrada. Caso não encontre uma disciplina com nota, imprime "Nao ha notas para esse usuario".
 */

void consultaNotasAlun(char *matr);

/**
 * @brief Fornece a relação de notas das disciplinas em que o professor leciona.
 * 
 * @param {char *matr} Matrícula do usuário.
 * @returns {void} .
 * @interface Mostra todas as disciplinas que o professor lecionar; Prompt sobre quais disciplinas deseja-se saber as notas e apresenta-se 
 * uma tabela de duas colunas, sendo a primeira coluna a matrícula do aluno e a segunda coluna, a nota (com 2 casas decimais) do aluno nela,
 * caso a matrícula seja encontrada. Caso não encontre notas para a disciplina, imprime "Nao ha notas para essa disciplina".
 */

void consultaNotasProf(char *matr);
