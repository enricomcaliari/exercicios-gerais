#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Data *leData()
{
    Data *d = (Data *)calloc(1, sizeof(Data));
    scanf("%d/%d/%d\n", &d->dia, &d->mes, &d->ano);
    return d;
}

Data *criaData(int dia, int mes, int ano)
{
    Data *d = (Data *)calloc(1, sizeof(Data));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

void liberaData(Data *d)
{
    if (d != NULL)
    {
        free(d);
    }
}

int calculaDiffAnosData(Data *d, Data *atual)
{
    int diff = atual->ano - d->ano;
    if (atual->mes < d->mes || (atual->mes == d->mes && atual->dia < d->dia))
    {
        diff--;
    }
    return diff;
}

void imprimeData(Data *d)
{
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}