#include <stdio.h>
#include <string.h>
#include "reserva.h"

#define IDADE_MINIMA 21

Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados, char turno)
{
    Reserva r;
    r.morador = morRes;
    r.area = aRes;
    r.data = dRes;
    r.qtdConvidados = qtdConvidados;
    r.turno = turno;
    return r;
}

void lerDadosSolicitacaoReserva(char *idArea, char *cpf, Data *dt, int *qtdConv, char *turno)
{
    Data dt2;

    scanf("%[^\n]\n", idArea);
    scanf("%[^\n]\n", cpf);

    dt2 = lerData();
    dt->dia = dt2.dia;
    dt->mes = dt2.mes;
    dt->ano = dt2.ano;

    scanf("%d\n", qtdConv);
    scanf("%c\n", turno);
}

int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes,
                               int qtdConvidados, char turno)
{
    int check = 1;

    if (calculaIdadeMorador(morRes, dRes) < IDADE_MINIMA || qtdConvidados > aRes.capacidade)
    {
        check = 0;
    }

    for (int i = 0; i < nRes; i++)
    {
        if (!strcmp(morRes.cpf, agendaReservas[i].morador.cpf) || (!strcmp(aRes.id, agendaReservas[i].area.id) && turno == agendaReservas[i].turno))
        {
            check = 0;
        }
    }

    return check;
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
    printf("Turno da reserva: %c\n", r.turno);
    printf("\nQuantidade de convidados: %d\n", r.qtdConvidados);
    printf("Taxa de ocupacao: %d%%\n", 100 * r.qtdConvidados / r.area.capacidade);
    printf("------------------------------\n");
}