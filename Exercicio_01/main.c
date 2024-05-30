#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    No* livraria = NULL; 

    inserirLivro(&livraria, "Livro A", "Autor 1", 10, 2);
    inserirLivro(&livraria, "Livro B", "Autor 2", 8, 1);
    inserirLivro(&livraria, "Livro C", "Autor 3", 12, 6);

    removeLivro(&livraria, "Livro B");

    No* maisPopular = getMaisPopular(livraria);
    if (maisPopular != NULL) {
        printf("Livro mais popular: %s\n", maisPopular->titulo);
    }

    printf("Todos os livros ordenados por popularidade:\n");
    mostraLivro(livraria);

    freeList(livraria);

    return 0;
}


/*
a) Qual é a complexidade do tempo da operação de inserção de um novo livro na lista ordenada por popularidade?
  A complexidade de tempo da operação de inserção de um novo livro em uma lista ordenada por popularidade depende da estrutura de dados que você está usando. Se você estiver usando uma lista simplesmente encadeada, a complexidade será O(n), onde 'n' é o número de livros na lista.


b) Qual é a complexidade do tempo da operação de remoção de um livro da lista?
  Se você estiver usando uma lista simplesmente encadeada, a complexidade será geralmente O(n), onde 'n' é o número de livros na lista. Isso ocorre porque, ao remover um livro, você pode precisar percorrer toda a lista para encontrar o livro a ser removido, a menos que tenha informações adicionais, como um índice ou uma referência direta para o livro a ser removido.

c) Como você implementaria a consulta do livro mais popular na lista de forma eficiente?
  Para implementar a consulta do livro mais popular de forma eficiente em uma lista de livros ordenada por popularidade, você pode manter uma referência direta para o livro mais popular na lista. Isso permitirá que você acesse o livro mais popular em O(1) sem percorrer toda a lista

d) Qual é a complexidade do tempo da operação de impressão de todos os livros na lista ordenada por popularidade em ordem decrescente?
  A complexidade de tempo da operação de impressão de todos os livros na lista ordenada por popularidade em ordem decrescente depende da estrutura de dados usada para armazenar os livros.
*/