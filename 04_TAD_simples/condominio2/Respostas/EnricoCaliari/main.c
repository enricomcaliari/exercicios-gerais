#include <stdio.h>
#include <string.h>
#include "reserva.h"

int encontraIndiceArea(Area *areas, int nAreas, char *id)
{
    for (int i = 0; i < nAreas; i++)
    {
        if (!strcmp(areas[i].id, id))
        {
            return i;
        }
    }
    return -1;
}

int encontraIndiceMorador(Morador *moradores, int nMoradores, char *cpf)
{
    for (int i = 0; i < nMoradores; i++)
    {
        if (!strcmp(moradores[i].cpf, cpf))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int nAreas;
    scanf("%d\n", &nAreas);

    Area areas[nAreas];
    for (int i = 0; i < nAreas; i++)
    {
        areas[i] = lerArea();
    }

    int nMoradores;
    scanf("%d\n", &nMoradores);

    Morador moradores[nMoradores];
    for (int i = 0; i < nMoradores; i++)
    {
        moradores[i] = lerMorador();
    }

    int nReservas;
    scanf("%d\n", &nReservas);

    Reserva reservas[nReservas];
    char id[MAX_TAM_ID];
    char cpf[MAX_TAM_CPF];
    Data data;
    int qtdConvidados;
    char turno;

    for (int i = 0; i < nReservas; i++)
    {
        scanf("%[^\n]\n", id);
        scanf("%[^\n]\n", cpf);
        data = lerData();
        scanf("%d\n", &qtdConvidados);
        scanf("%c\n", &turno);

        if (encontraIndiceArea(areas, nAreas, id) != -1 && encontraIndiceMorador(moradores, nMoradores, cpf) != -1)
        {
            if (verificaSolicitacaoReserva(reservas, nReservas, moradores[encontraIndiceMorador(moradores, nMoradores, cpf)], areas[encontraIndiceArea(areas, nAreas, id)], data, qtdConvidados, turno))
            {
                reservas[i] = criaReserva(moradores[encontraIndiceMorador(moradores, nMoradores, cpf)], areas[encontraIndiceArea(areas, nAreas, id)], data, qtdConvidados, turno);
                imprimeReserva(reservas[i]);
            }
        }
    }

    return 0;
}