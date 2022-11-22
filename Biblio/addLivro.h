/**
 * @brief Adiciona livros ao cadastro da biblioteca.
 * 
 * @param {char *nomeArq} Nome do arquivo com os cadastros.
 * @param {int id} código único do livro.
 * @param {char *nomeLivro} Nome do Livro.
 * @param {char *editora} Editora.
 * @returns {int} 1: livro cadastrado com sucesso; 0: livro já existe na base.
 */

int addLivro(char *nomeArq, int id, char *nomeLivro, char *editora);
