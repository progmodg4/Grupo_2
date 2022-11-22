/**
 * @brief Apresenta todos os livros alugados por um usuário comum na biblioteca.
 * 
 * @param {char *matr} Matrícula do usuário.
 * @returns {void}
 *
 * OBS: formatacao do txt:
 * matr, id, nome(livro), editora
 * char d char char 
 */

void checaLivrosAlugadosUsu(char *matr);


/**
 * @brief Apresenta todos livros na biblioteca (alugados ou não).
 * 
 * @returns {void}
 * @interface 1) Prompt ao usuário para escolher a que tipos de livros ele deseja ver (alugados ou os não alugados); 
 *            2) Apresenta-se o id único do livro, seu nome, sua editora e a matrícula do usuário que o alugou (caso ele esteja alugado).
 *
 * OBS: formatacao do txt :
 * id(livro) nome(livro) editora 0/1(alugado ou nao) matr
 */


void checaLivrosFunc(void);
