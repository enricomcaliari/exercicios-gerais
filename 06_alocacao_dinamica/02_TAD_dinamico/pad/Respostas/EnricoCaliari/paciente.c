#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

Paciente *lePaciente()
{
    Paciente *p = (Paciente *)calloc(1, sizeof(Paciente));

    p->nome = (char *)calloc(TAM_NOME, sizeof(char));
    scanf("%[^\n]\n", p->nome);

    p->dataNasc = leData();

    p->cartaoSus = (char *)calloc(TAM_SUS, sizeof(char));
    scanf("%[^\n]\n", p->cartaoSus);

    scanf("%c\n", &p->genero);

    p->qtdLesoesAlocadas = 2;

    p->lesoes = (Lesao **)calloc(p->qtdLesoesAlocadas, sizeof(Lesao));

    return p;
}

void liberaPaciente(Paciente *p)
{
    if (p != NULL)
    {
        free(p->cartaoSus);
        liberaData(p->dataNasc);
        free(p->nome);
        for (int i = 0; i < p->qtdLesoes; i++)
        {
            liberaLesao(p->lesoes[i]);
        }
        free(p->lesoes);
        free(p);
    }
}

void adicionaLesaoPaciente(Paciente *p, Lesao *l)
{
    if (p->qtdLesoes == p->qtdLesoesAlocadas)
    {
        p->qtdLesoesAlocadas += 2;
        p->lesoes = (Lesao **)realloc(p->lesoes, p->qtdLesoesAlocadas * sizeof(Lesao));
    }

    p->lesoes[p->qtdLesoes] = l;
    p->qtdLesoes++;
}

int calculaIdadePaciente(Paciente *p, Data *ref)
{
    return calculaDiffAnosData(p->dataNasc, ref);
}

int getQtdCirurgiasPaciente(Paciente *p)
{
    int qtd = 0;

    for (int i = 0; i < p->qtdLesoes; i++)
    {
        qtd += precisaCirurgiaLesao(p->lesoes[i]);
    }

    return qtd;
}

char *getCartaoSusPaciente(Paciente *p)
{
    return p->cartaoSus;
}

Data *getDataNascPaciente(Paciente *p)
{
    return p->dataNasc;
}

int getQtdLesoesPaciente(Paciente *p)
{
    return p->qtdLesoes;
}

void imprimeIdLesoesPaciente(Paciente *p)
{
    if (p->qtdLesoes > 0)
    {
        printf(" - %s - ", p->nome);
        for (int i = 0; i < p->qtdLesoes; i++)
        {
            printf("%s ", getIdLesao(p->lesoes[i]));
        }
        printf("\n");
    }
}