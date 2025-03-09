#include "roteiro.h"
#include "midia.h"
#include <stdlib.h>
#include <stdio.h>

#define MIDIAS_TAM_INICIAL 10

struct Roteiro
{
    Midia **midias;
    int memSizeMidias;
    int countMidias;
};

// Aloca dinamicamente um novo objeto Roteiro e retorna o ponteiro para ele.
// Retorna: Ponteiro para o Roteiro recém-criado.
Roteiro *roteiro_construct()
{
    Roteiro *roteiro = malloc(sizeof(Roteiro));
    roteiro->midias = malloc(MIDIAS_TAM_INICIAL * sizeof(Midia *));
    roteiro->memSizeMidias = MIDIAS_TAM_INICIAL;
    roteiro->countMidias = 0;

    return roteiro;
}

// Aumenta o espaço de armazenamento de mídias no Roteiro, insere a nova mídia
// utilizando o construtor de mídia (midia_construct), e incrementa o contador de mídias.
// Parâmetros:
//  r       - Ponteiro para o Roteiro onde a mídia será inserida.
//  dado    - Ponteiro genérico contendo os dados da nova mídia a ser inserida.
//  print_fn - Função de impressão personalizada para a mídia.
//  free_fn  - Função de liberação personalizada para os recursos da mídia.
void roteiro_inserir_midia(Roteiro *r, void *dado, PrintFunction print_fn, FreeFunction free_fn)
{
    Midia *midia = midia_construct(dado, print_fn, free_fn);

    if (r->countMidias + 1 == r->memSizeMidias)
    {
        r->memSizeMidias *= 2;
        r->midias = realloc(r->midias, r->memSizeMidias * sizeof(Midia *));
    }

    r->midias[r->countMidias] = midia;
    r->countMidias++;
}

// Imprime todas as mídias presentes no Roteiro. Se não houver mídias,
// imprime a mensagem "SEM MIDIAS PARA IMPRIMIR".
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser impresso.
void roteiro_imprimir_midias(Roteiro *r)
{
    if (r->countMidias == 0) {
        printf("SEM MIDIAS PARA IMPRIMIR\n");
        return;
    }

    printf("IMPRIMINDO MIDIAS\n");

    for (int i = 0; i < r->countMidias; i++)
    {
        printf("MIDIA %d: ", i + 1);
        midia_print(r->midias[i]);
        printf("\n");
    }
}

// Libera a memória alocada para o Roteiro e suas mídias, desalocando
// adequadamente cada um dos elementos armazenados.
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser destruído.
void roteiro_destroy(Roteiro *r)
{
    for (int i = 0; i < r->countMidias; i++)
        midia_destroy(r->midias[i]);

    free(r->midias);
    free(r);
    r = NULL;
}