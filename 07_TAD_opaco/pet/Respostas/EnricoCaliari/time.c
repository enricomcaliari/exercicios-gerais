#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct _Time
{
    char *nome;
    int vitorias;
    int empates;
    int derrotas;
    int golsMarcados;
    int golsSofridos;
};

/**
 * @brief Construtor do tipo time. Deve ler um nome pela entrada padrao.
 */
tTime *LeTime()
{
    tTime *time = malloc(sizeof(tTime));
    time->nome = malloc(MAX_TIME_NOME * sizeof(char));

    scanf("%[^\n]\n", time->nome);
    time->vitorias = 0;
    time->empates = 0;
    time->derrotas = 0;
    time->golsMarcados = 0;
    time->golsSofridos = 0;

    return time;
}

/**
 * @brief Retona o numero de vitorias do time.
 */
int ObtemVitorias(tTime *t)
{
    return t->vitorias;
}

/**
 * @brief Retona o numero de partidas.
 */
int ObtemPartidas(tTime *t)
{
    return t->vitorias + t->derrotas + t->empates;
}

/**
 * @brief Retona o numero de derrotas do time.
 */
int ObtemDerrotas(tTime *t)
{
    return t->derrotas;
}

/**
 * @brief Retona a string do nome do time.
 */
char *ObtemNomeTime(tTime *t)
{
    return t->nome;
}

/**
 * @brief Retona o saldo de gols da equipe.
 */
int ObtemSaldo(tTime *t)
{
    return t->golsMarcados - t->golsSofridos;
}

/**
 * @brief Aumenta o numero de vitorias em 1.
 */
void AtualizaVitorias(tTime *t)
{
    t->vitorias++;
}

/**
 * @brief Aumenta o numero de empates em 1.
 */
void AtualizaEmpates(tTime *t)
{
    t->empates++;
}

/**
 * @brief Aumenta o numero de derrotas em 1.
 */
void AtualizaDerrotas(tTime *t)
{
    t->derrotas++;
}

/**
 * @brief Aumenta a quantidade de gols marcados.
 */
void AtualizaGolsMarcados(tTime *t, int gols)
{
    t->golsMarcados += gols;
}

/**
 * @brief Aumenta a quantidade de gols sofridos.
 */
void AtualizaGolsSofridos(tTime *t, int gols)
{
    t->golsSofridos += gols;
}

/**
 * @brief Retorna a pontuacao do time.
 */
int ObtemPontos(tTime *t)
{
    return 3 * t->vitorias + t->empates;
}

/**
 * @brief Usa os criterios de classificacao para indicar qual time possui melhor colocacao. Retorna -1 para t1, 1 para t2.
 */
int DesempataTimes(tTime *t1, tTime *t2)
{
    int pontosT1 = ObtemPontos(t1);
    int pontosT2 = ObtemPontos(t2);

    if (pontosT2 > pontosT1)
    {
        return 1;
    }

    else if (pontosT2 < pontosT1)
    {
        return -1;
    }

    else if (t2->vitorias > t1->vitorias)
    {
        return 1;
    }

    else if (t2->vitorias < t1->vitorias)
    {
        return -1;
    }

    int saldoT1 = ObtemSaldo(t1);
    int saldoT2 = ObtemSaldo(t2);

    if (saldoT2 > saldoT1)
    {
        return 1;
    }

    else if (saldoT2 < saldoT1)
    {
        return -1;
    }

    return 0;
}

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
 */
void ImprimeTime(tTime *t)
{
    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", t->nome, ObtemPontos(t), t->vitorias, t->derrotas, t->empates, ObtemSaldo(t));
}

/**
 * @brief Libera a memoria alocada para time.
 */
void DesalocaTime(tTime *t)
{
    free(t->nome);
    free(t);
}
