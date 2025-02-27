#include <stdio.h>
#include <stdlib.h>
#include "brasileirao.h"

struct _BRA
{
    tTabela *tabela;
    int numTimes;
    int numRodadas;
    int rodadaAtual;
    float valorPremio;
};

/**
 * @brief Construtor do campeonato. Le da entrada padrao numero de times, numero de rodadas e pontuacao.
 */
BRA *CriaCamp()
{
    BRA *br = malloc(sizeof(BRA));

    printf("Insira o num de times, rodadas e premio total:\n");
    scanf("%d %d %f\n", &br->numTimes, &br->numRodadas, &br->valorPremio);

    br->tabela = CriaTabela(br->numTimes);
    br->rodadaAtual = 0;

    return br;
}

/**
 * @brief Le da entrada padrao as partidas da rodada, computa os resultados e atualiza a tabela.
 */
void RealizaRodada(BRA *br)
{
    for (int i = 0; i < br->numTimes / 2; i++)
    {
        char nomeTime1[MAX_TIME_NOME];
        char nomeTime2[MAX_TIME_NOME];
        int gols1 = 0;
        int gols2 = 0;

        scanf("%s %d x %d %s\n", nomeTime1, &gols1, &gols2, nomeTime2);

        tTime *time1 = ObtemTimeTabela(br->tabela, nomeTime1);
        tTime *time2 = ObtemTimeTabela(br->tabela, nomeTime2);

        if (!time1 || !time2)
        {
            return;
        }

        AtualizaGolsMarcados(time1, gols1);
        AtualizaGolsMarcados(time2, gols2);
        AtualizaGolsSofridos(time1, gols2);
        AtualizaGolsSofridos(time2, gols1);

        if (gols1 > gols2)
        {
            AtualizaVitorias(time1);
            AtualizaDerrotas(time2);
        }
        else if (gols1 < gols2)
        {
            AtualizaDerrotas(time1);
            AtualizaVitorias(time2);
        }
        else
        {
            AtualizaEmpates(time1);
            AtualizaEmpates(time2);
        }
    }
    
    OrdenaTabela(br->tabela);
    ImprimeTabela(br->tabela);

    br->rodadaAtual++;
}

/**
 * @brief Imprime o menu e trata cada opcao.
 */
void RealizaCamp(BRA *br)
{
    char opcao = 0;

    while (br->rodadaAtual < br->numRodadas)
    {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");

        scanf("%c\n", &opcao);

        if (opcao == 'F')
        {
            break;
        }
        else if (opcao == 'C')
        {
            RealizaRodada(br);
        }
        else if (opcao == 'R')
        {
            RemoveTimesCamp(br);

            if (br->numTimes < 2)
            {
                break;
            }
            RealizaRodada(br);
        }
    }
}

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
 */
void RemoveTimesCamp(BRA *br)
{
    char nomeTime1[MAX_TIME_NOME];
    char nomeTime2[MAX_TIME_NOME];

    scanf("%s %s\n", nomeTime1, nomeTime2);

    RemoveTimeTabela(br->tabela, nomeTime1);
    RemoveTimeTabela(br->tabela, nomeTime2);

    printf("Times a serem retirados:\n");
    printf("Os times %s e %s se retiraram do campeonato\n", nomeTime1, nomeTime2);

    br->numTimes -= 2;
}

/**
 * @brief Libera a memoria do campeonato.
 */
void DesalocaCamp(BRA *br)
{
    DesalocaTabela(br->tabela);
    free(br);
}

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
 */
void FinalizaCamp(BRA *br)
{
    if (br->numTimes >= 2)
    {
        printf("Esta foi a tabela final:\n");
        ImprimeTabela(br->tabela);
    }
    ImprimePremiacao(br->tabela, br->valorPremio);
    DesalocaCamp(br);
    printf("Fim do campeonato\n");
}