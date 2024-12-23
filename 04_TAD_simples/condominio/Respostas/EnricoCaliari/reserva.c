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
