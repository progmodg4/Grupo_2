/**
 * @brief Menu da biblioteca para funcionários.
 * 
 * @returns {void}
 * @interface 1) Prompt ao usuário para escolher a ação desejada (Adicionar novo livro, Checar livros, Remover livro ou Sair); 
 *            2) Prompt para o usuário inserir informações específicas sobre a ação desejada;
 *            3) Resultado da ação.
 */

menuBilioFunc();


/**
 * @brief Menu da biblioteca para usuários comuns.
 * 
 * @param {char *matr}
 * @returns {void}
 * @interface 1) Prompt ao usuário para escolher a ação desejada (Consultar livros alugados, Alugar livro ou Sair); 
 *            2) Prompt para o usuário inserir informações específicas sobre a ação desejada;
 *            3) Resultado da ação.
 */

menuBiblioUsu(char* matr);
