#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote
{
    void *elemento;
    int soma;
    int numElem;
    Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *pac = (tPacote *)malloc(sizeof(tPacote));

    pac->soma = 0;
    pac->type = type;
    pac->numElem = numElem;
    if (type == INT)
    {
        pac->elemento = (int *)malloc(numElem * sizeof(int));
    }
    else
    {
        pac->elemento = (char *)malloc(numElem * sizeof(char));
    }

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{
    if (pac != NULL)
    {
        free(pac->elemento);
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{
    int type, numElem;
    scanf("%d %d\n", &type, &numElem);

    for (int i = 0; i < numElem; i++)
    {
        if (!type)
        {
            scanf("%[^\n]\n", (char *)pac->elemento + i);
        }
        else
        {
            scanf("%d\n", (int *)pac->elemento + i);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{
    for (int i = 0; i < pac->numElem; i++)
    {
        if (pac->type == CHAR)
        {
            printf("%s ", ((char *)pac->elemento)[i]);
        }
        else
        {
            printf("%d ", ((int *)pac->elemento)[i]);
        }
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    if (pac->type == INT)
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            pac->soma += ((int *)pac->elemento)[i];
        }
    }
    else
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            pac->soma += ((char *)pac->elemento)[i];
        }
    }
}