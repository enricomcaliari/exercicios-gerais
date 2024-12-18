#include "reserva.h"

Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados)
{
    Reserva reserva;
    reserva.morador = morRes;
    reserva.area = aRes;
    reserva.data = dRes;
    reserva.qtdConvidados = qtdConvidados;
    return reserva;
}

int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados)
{
}

void imprimeReserva(Reserva r)
{
    printf("--------- RESERVA -----------\n");
    printf("Morador:\n");
    imprimeMorador(r.morador);
    printf("\n");
    printf("Area reservada:\n");
    imprimeArea(r.area);
    printf("\n");
    printf("Quantidade de convidados: %d\n", r.qtdConvidados);
    printf("Taxa de ocupacao: %d%%\n", r.qtdConvidados / r.area.capacidade * 100);
}