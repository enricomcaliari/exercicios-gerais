#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic
{
    void *elemento;
    int numElem;
    Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem)
{
    tGeneric *gen = (tGeneric *)malloc(sizeof(tGeneric));
    gen->type = type;
    gen->numElem = numElem;

    switch (type)
    {
    case INT:
        gen->elemento = malloc(numElem * sizeof(int));
        break;
    case FLOAT:
        gen->elemento = malloc(numElem * sizeof(float));
        break;
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{
    if (gen != NULL)
    {
        free(gen->elemento);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
    switch (gen->type)
    {
    case INT:
        for (int i = 0; i < gen->numElem; i++)
        {
            scanf("%d\n", (int *)gen->elemento + i);
        }
        break;

    case FLOAT:
        for (int i = 0; i < gen->numElem; i++)
        {
            scanf("%f\n", (float *)gen->elemento + i);
        }
        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{
    printf("\nDigite o vetor:\n");
    for (int i = 0; i < gen->numElem; i++)
    {
        if (gen->type == INT)
        {
            printf("%d ", ((int *)gen->elemento)[i]);
        }
        else
        {
            printf("%.2f ", ((float *)gen->elemento)[i]);
        }
    }
    printf("\n");
}