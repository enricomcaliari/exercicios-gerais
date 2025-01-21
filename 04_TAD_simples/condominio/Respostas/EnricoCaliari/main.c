#include <stdio.h>
#include <string.h>
#include "reserva.h"

#define MAX_MORADORES 100
#define MAX_AREAS 10
#define MAX_RESERVAS 100

int encontraMorador(int nMoradores, Morador *morador, char *cpf)
{
    for (int i = 0; i < nMoradores; i++)
    {
        if (!strcmp(morador[i].cpf, cpf))
        {
            return i;
        }
    }

    return -1;
}

int encontraArea(int nArea, Area *area, char *id)
{
    for (int i = 0; i < nArea; i++)
    {
        if (!strcmp(area[i].id, id))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int nAreas, nMoradores, nReservas;

    scanf("%d\n", &nAreas);
    if (nAreas > MAX_AREAS)
    {
        return 0;
    }
    Area area[nAreas];
    for (int i = 0; i < nAreas; i++)
    {
        area[i] = lerArea();
    }

    scanf("%d\n", &nMoradores);
    if (nMoradores > MAX_MORADORES)
    {
        return 0;
    }
    Morador morador[nMoradores];
    for (int i = 0; i < nMoradores; i++)
    {
        morador[i] = lerMorador();
    }

    scanf("%d\n", &nReservas);
    if (nReservas > MAX_RESERVAS)
    {
        return 0;
    }
    Reserva reserva[nReservas];

    char id[MAX_TAM_ID];
    char cpf[MAX_TAM_CPF];
    Data data;
    int qtdConvidados;
    for (int i = 0; i < nReservas; i++)
    {
        scanf("%[^\n]\n", id);
        scanf("%[^\n]\n", cpf);
        data = lerData();
        scanf("%d\n", &qtdConvidados);

        if (encontraMorador(nMoradores, morador, cpf) == -1 || encontraArea(nAreas, area, id) == -1)
        {
            continue;
        }
        else if (verificaSolicitacaoReserva(reserva, nReservas, morador[encontraMorador(nMoradores, morador, cpf)], area[encontraArea(nAreas, area, id)], data, qtdConvidados))
        {
            reserva[i] = criaReserva(morador[encontraMorador(nMoradores, morador, cpf)], area[encontraArea(nAreas, area, id)], data, qtdConvidados);
            imprimeReserva(reserva[i]);
        }
    }

    return 0;
}