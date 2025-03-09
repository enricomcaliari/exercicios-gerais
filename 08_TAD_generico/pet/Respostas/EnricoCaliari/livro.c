#include "livro.h"
#include <stdlib.h>
#include <stdio.h>

struct Livro
{
    char *titulo;
    char *autor;
    char *genero;
    char *editora;
    int anoPublicacao;
};

// Aloca dinamicamente uma nova estrutura Livro e realiza a leitura dos dados
// de entrada associados ao livro. Retorna o ponteiro para o objeto Livro.
// Retorna: Ponteiro para o Livro recém-criado, com os dados carregados.
Livro *livro_construct()
{
    Livro *livro = malloc(sizeof(Livro));
    livro->titulo = malloc(MAXTAM_STRINGS * sizeof(char));
    livro->autor = malloc(MAXTAM_STRINGS * sizeof(char));
    livro->genero = malloc(MAXTAM_STRINGS * sizeof(char));
    livro->editora = malloc(MAXTAM_STRINGS * sizeof(char));

    // L 1984 George_Orwell Distopia Companhia_das_Letras 1949
    scanf("%s %s %s %s %d\n", livro->titulo, livro->autor, livro->genero, livro->editora, &livro->anoPublicacao);

    return livro;
}

// Imprime os dados do livro. Recebe um ponteiro genérico para o livro
// e exibe suas informações relevantes, como título, autor, etc.
// Parâmetros:
//  l - Ponteiro para o Livro a ser impresso.
void livro_print(void *l)
{
    Livro *livro = (Livro *)l;

    printf("LIVRO\n");
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Genero: %s\n", livro->genero);
    printf("Editora: %s\n", livro->editora);
    printf("Ano: %d\n", livro->anoPublicacao);
}

// Libera a memória alocada para o livro, desalocando a estrutura Livro
// e seus dados associados de forma adequada.
// Parâmetros:
//  l - Ponteiro para o Livro a ser destruído.
void livro_destroy(void *l) {
    Livro *livro = (Livro *)l;

    free(livro->titulo);
    free(livro->autor);
    free(livro->genero);
    free(livro->editora);
    free(livro);
    l = NULL;
}