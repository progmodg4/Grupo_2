/**
 * @brief Registra o aluguel de livros da biblioteca.
 * 
 * @param {char *nomeArq} Nome do arquivo com os cadastros.
 * @param {int id} código único do livro.
 * @returns {int} 2: livro não encontrado; 1: livro disponível para o aluguel; 0: livro existe no cadastro da biblioteca mas está indisponível.
 */

int alugaLivro(char* nomeArq, int idLivro,char * matr);
