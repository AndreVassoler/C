#ifndef lista
#define lista

typedef struct No {
    char titulo[100];
    char autor[100];
    int avaliacao;
    int alugado;
    struct No* proximo;
} No;

float calcularPopularidade(No* livro);

void inserirLivro(No** head, char titulo[], char autor[], int avaliacao, int alugado);

void removeLivro(No** head, char titulo[]);

No* getMaisPopular(No* head);

void mostraLivro(No* head);

void freeList(No* head);

#endif
