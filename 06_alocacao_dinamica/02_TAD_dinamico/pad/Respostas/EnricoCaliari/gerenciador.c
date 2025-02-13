#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciador.h"

Gerenciador *criaGerenciador()
{
    Gerenciador *g = (Gerenciador *)calloc(1, sizeof(Gerenciador));
    g->tamBancoAlocado = 2;
    g->bancoPacientes = (Paciente **)calloc(g->tamBancoAlocado, sizeof(Paciente));
    return g;
}

void adicionaPacienteBancoGerenciador(Gerenciador *g, Paciente *p)
{
    if (g->tamBanco == g->tamBancoAlocado)
    {
        g->tamBancoAlocado += 2;
        g->bancoPacientes = (Paciente **)realloc(g->bancoPacientes, g->tamBancoAlocado * sizeof(Paciente));
    }
    g->bancoPacientes[g->tamBanco] = p;
    g->tamBanco++;
}

Paciente *getPacientePeloSUSBancoGerenciador(Gerenciador *g, char *sus)
{
    for (int i = 0; i < g->tamBanco; i++)
    {
        if (!strcmp(g->bancoPacientes[i]->cartaoSus, sus))
        {
            return g->bancoPacientes[i];
        }
    }
    return NULL;
}

void preencheBancoPacientesGerenciador(Gerenciador *ger)
{
    char menu;
    while (1)
    {
        scanf("%c\n", &menu);

        if (menu == 'P')
        {
            Paciente *p = lePaciente();
            adicionaPacienteBancoGerenciador(ger, p);
        }
        else if (menu == 'L')
        {
            char sus[TAM_SUS];
            scanf("%[^\n]\n", sus);
            Lesao *l = leLesao();
            if (getPacientePeloSUSBancoGerenciador(ger, sus) != NULL)
            {
                adicionaLesaoPaciente(getPacientePeloSUSBancoGerenciador(ger, sus), l);
            }
            else
                liberaLesao(l);
        }
        else
            break;
    }
}

void liberaGerenciador(Gerenciador *g)
{
    if (g != NULL)
    {
        for (int i = 0; i < g->tamBanco; i++)
        {
            liberaPaciente(g->bancoPacientes[i]);
        }
        free(g->bancoPacientes);
        free(g);
    }
}

int calculaMediaIdadePacientesBancoGerenciador(Gerenciador *g)
{
    int soma = 0;
    Data *d = criaData(DIA_BASE, MES_BASE, ANO_BASE);

    for (int i = 0; i < g->tamBanco; i++)
    {
        soma += calculaIdadePaciente(g->bancoPacientes[i], d);
    }
    
    liberaData(d);

    if (g->tamBanco == 0)
    {
        return 0;
    }
    return soma /= g->tamBanco;
}

int calculaQtdLesoesPacientesBancoGerenciador(Gerenciador *g)
{
    int qtd = 0;
    for (int i = 0; i < g->tamBanco; i++)
    {
        qtd += g->bancoPacientes[i]->qtdLesoes;
    }
    return qtd;
}

int calculaQtdCirurgiaPacientesBancoGerenciador(Gerenciador *g)
{
    int qtd = 0;
    for (int i = 0; i < g->tamBanco; i++)
    {
        qtd += getQtdCirurgiasPaciente(g->bancoPacientes[i]);
    }
    return qtd;
}

void imprimePacientesBancoGerenciador(Gerenciador *g)
{
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < g->tamBanco; i++)
    {
        if (getQtdLesoesPaciente(g->bancoPacientes[i]) > 0)
        {
            imprimeIdLesoesPaciente(g->bancoPacientes[i]);
        }
    }
}

void imprimeRelatorioGerenciador(Gerenciador *g)
{
    printf("TOTAL PACIENTES: %d\n", g->tamBanco);
    printf("MEDIA IDADE (ANOS): %d\n", calculaMediaIdadePacientesBancoGerenciador(g));
    printf("TOTAL LESOES: %d\n", calculaQtdLesoesPacientesBancoGerenciador(g));
    printf("TOTAL CIRURGIAS: %d\n", calculaQtdCirurgiaPacientesBancoGerenciador(g));
    imprimePacientesBancoGerenciador(g);
}