#include "midia.h"
#include <stdlib.h>

struct Midia
{
    void *dado;
    PrintFunction print_fn;
    FreeFunction free_fn;
};

// Aloca dinamicamente uma nova estrutura Midia, recebe os dados da mídia,
// a função de impressão (print_fn) e a função de desalocação (free_fn),
// e os insere na estrutura de forma adequada. Retorna o ponteiro para a Midia.
// Parâmetros:
//  dado    - Ponteiro genérico para os dados da mídia.
//  print_fn - Função responsável pela impressão dos dados da mídia.
//  free_fn  - Função responsável pela liberação de memória dos dados da mídia.
// Retorna: Ponteiro para a Midia recém-criada com os dados e funções associadas.
Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn)
{
    Midia *midia = malloc(sizeof(Midia));
    midia->dado = dado;
    midia->print_fn = print_fn;
    midia->free_fn = free_fn;

    return midia;
}

// Chama a função de impressão associada à mídia, exibindo seus dados.
// Parâmetros:
//  m - Ponteiro para a Midia a ser impressa.
void midia_print(Midia *m)
{
    m->print_fn(m->dado);
}

// Chama a função de desalocação associada à mídia, liberando os dados alocados.
// Parâmetros:
//  m - Ponteiro para a Midia a ser destruída.
void midia_destroy(Midia *m)
{
    m->free_fn(m->dado);
    free(m);
    m = NULL;
}