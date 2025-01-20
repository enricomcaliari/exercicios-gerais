#include <stdio.h>
#include "reserva.h"

#define MAIORIDADE 18

Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados)
{
    Reserva r;
    r.morador = morRes;
    r.area = aRes;
    r.data = dRes;
    r.qtdConvidados = qtdConvidados;
    return r;
}

int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados)
{
    int check = 1;

    for (int i = 0; i < nRes; i++)
    {
        if (comparaData(agendaReservas[i].data, dRes))
        {
            if (comparaMorador(agendaReservas[i].morador, morRes) || comparaArea(agendaReservas[i].area, aRes))
            {
                check = 0;
            }
        }
    }

    if (calcularDiffAnosData(morRes.dataNasc, dRes) >= MAIORIDADE && qtdConvidados <= aRes.capacidade && check)
    {
        return 1;
    }
    return 0;
}

void imprimeReserva(Reserva r)
{
    printf("--------- RESERVA -----------\n");
    printf("Morador:\n");
    imprimeMorador(r.morador);
    printf("\nArea reservada:\n");
    imprimeArea(r.area);
    printf("Data da reserva: ");
    imprimeData(r.data);
    printf("\nQuantidade de convidados: %d\n", r.qtdConvidados);
    printf("Taxa de ocupação: %d%%\n", 100 * r.qtdConvidados / r.area.capacidade);
    printf("------------------------------\n");
}