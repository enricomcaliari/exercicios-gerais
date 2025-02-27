#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

struct _Tabela
{
    tTime **times;
    int numTimes;
};

int qsort_ComparaTimes(const void *t1, const void *t2);

int qsort_ComparaTimes(const void *t1, const void *t2)
{
    tTime *time1 = *(tTime **)t1;
    tTime *time2 = *(tTime **)t2;

    return DesempataTimes(time1, time2);
}

/**
 * @brief Construtor do tipo tabela. Deve criar os times.
 * @param numTimes Numero de times a serem criados.
 */
tTabela *CriaTabela(int numTimes)
{
    tTabela *tabela = malloc(sizeof(tTabela));

    tabela->numTimes = numTimes;
    tabela->times = malloc(numTimes * sizeof(tTime *));

    for (int i = 0; i < numTimes; i++)
    {
        tabela->times[i] = LeTime();
    }

    return tabela;
}

/**
 * @brief Libera a memoria alocada para a tabela e seus times.
 */
void DesalocaTabela(tTabela *tabela)
{
    for (int i = 0; i < tabela->numTimes; i++)
    {
        DesalocaTime(tabela->times[i]);
    }
    free(tabela->times);
    free(tabela);
}

/**
 * @brief Ordena a tabela de acordo com os criterios definidos.
 */
void OrdenaTabela(tTabela *tabela)
{
    qsort(tabela->times, tabela->numTimes, sizeof(tTime *), qsort_ComparaTimes);
}

/**
 * @brief Dado um nome, retorna o time correspondente.
 */
tTime *ObtemTimeTabela(tTabela *tabela, char *time)
{
    for (int i = 0; i < tabela->numTimes; i++)
    {
        if (!strcmp(ObtemNomeTime(tabela->times[i]), time))
        {
            return tabela->times[i];
        }
    }
    return NULL;
}

/**
 * @brief Dado um nome, desaloca e remove o time correspondente da tabela.
 */
void RemoveTimeTabela(tTabela *tabela, char *time)
{
    tTime *timeAchado = NULL;

    if ((timeAchado = ObtemTimeTabela(tabela, time)) == NULL)
    {
        return;
    }

    DesalocaTime(timeAchado);

    for (int i = 0; i < tabela->numTimes; i++)
    {
        if (tabela->times[i] != timeAchado)
        {
            continue;
        }

        for (int j = i; j < tabela->numTimes - 1; j++)
        {
            tabela->times[j] = tabela->times[j + 1];
        }
    }

    tabela->numTimes--;
}

/**
 * @brief Imprime a tela de premiacao no final do campeonato.
 */
void ImprimePremiacao(tTabela *tabela, float valorPremio)
{
    if (tabela->numTimes == 0)
    {
        printf("Premio de R$%.2f acumulado para a proxima edicao\n", valorPremio);
        return;
    }

    tTime *primeiro = tabela->times[0];
    tTime *segundo = tabela->times[1];

    if (tabela->numTimes == 2)
    {
        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(primeiro), 0.6 * valorPremio);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(segundo), 0.4 * valorPremio);
        return;
    }

    tTime *terceiro = tabela->times[2];

    if (tabela->numTimes >= 3)
    {
        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(primeiro), 0.5 * valorPremio);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(segundo), 0.3 * valorPremio);
        printf("3º lugar - %s: R$%.2f\n", ObtemNomeTime(terceiro), 0.2 * valorPremio);
        return;
    }
}

/**
 * @brief Imprime todos os time da tabela.
 */
void ImprimeTabela(tTabela *tabela)
{
    printf("Classificação:\n");
    printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");

    for (int i = 0; i < tabela->numTimes; i++)
    {
        ImprimeTime(tabela->times[i]);
    }
    printf("\n");
}