/**
 * @brief Remove livros do cadastro da biblioteca.
 * 
 * @param {char *nomeArq} Nome do arquivo com os cadastros.
 * @param {int idRemover} Código único do livro a ser removido.
 * @returns {int} 2: livro ja esta alugado ; 1: livro removido com sucesso; 0: livro não foi removido da base.
 */

int removeLivro(char *nomeArq, int idRemover);
