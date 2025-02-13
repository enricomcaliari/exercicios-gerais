#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct _Time
{
    char nome[MAX_TIME_NOME];
    int partidas, pontos, vitorias, derrotas, empates, golsPro, golsContra, saldo;
};

tTime *LeTime()
{
    tTime *t = (tTime *)calloc(1, sizeof(tTime));
    scanf("%[^\n]\n", &t->nome);
    return t;
}

int ObtemVitorias(tTime *t)
{
    return t->vitorias;
}

int ObtemPartidas(tTime *t)
{
    return t->partidas;
}

int ObtemDerrotas(tTime *t)
{
    return t->derrotas;
}

char *ObtemNomeTime(tTime *t)
{
    return *t->nome;
}

int ObtemSaldo(tTime *t)
{
    return t->saldo;
}

void AtualizaVitorias(tTime *t)
{
    t->vitorias++;
}

void AtualizaEmpates(tTime *t)
{
    t->empates++;
}

void AtualizaDerrotas(tTime *t)
{
    t->derrotas++;
}

void AtualizaGolsMarcados(tTime *t, int gols)
{
    t->golsPro += gols;
}

void AtualizaGolsSofridos(tTime *t, int gols)
{
    t->golsContra += gols;
}

int ObtemPontos(tTime *t)
{
    t->pontos = t->vitorias * 3 + t->empates;
    return t->pontos;
}

int DesempataTimes(tTime *t1, tTime *t2)
{
    if (t1->pontos > t2->pontos)
    {
        return -1;
    }
    else if (t1->pontos == t2->pontos && t1->vitorias > t2->vitorias)
    {
        return -1;
    }
    else if (t1->vitorias == t2->vitorias && t1->golsPro > t2->golsPro)
    {
        return -1;
    }
    return 1;
}

void ImprimeTime(tTime *t)
{
    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", &t->nome, t->pontos, t->vitorias, t->derrotas, t->empates, t->saldo);
}

void DesalocaTime(tTime *t)
{
    free(t);
}