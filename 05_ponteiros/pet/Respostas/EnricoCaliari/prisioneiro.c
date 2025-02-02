#include "prisioneiro.h"

tPrisioneiro criaPrisioneiro(char *nome, int pena)
{
    tPrisioneiro prisioneiro;
    strcpy(prisioneiro.nome, nome);
    prisioneiro.pena = pena;
    return prisioneiro;
}

void passaTempoPrisioneiro(tPrisioneiro *prisioneiro)
{
    prisioneiro->pena--;
}

void fogePrisioneiro(tPrisioneiro *prisioneiro)
{
    printf("Detento %s fugiu!\n", prisioneiro->nome);
}

int acabouPenaPrisioneiro(tPrisioneiro *prisioneiro)
{
    if (!prisioneiro->pena)
    {
        return 1;
    }
    return 0;
}

int prisionerioExiste(tPrisioneiro *prisioneiro)
{
    if (prisioneiro != NULL)
    {
        return 1;
    }
    return 0;
}

void liberaPrisioneiroCumpriuPena(tPrisioneiro *prisioneiro)
{
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
}

void liberaPrisioneiroFimPrograma(tPrisioneiro *prisioneiro)
{
    printf("Prisioneiros liberados para a finalizacao do programa !!!\n");
}