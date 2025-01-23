#include <stdio.h>
#include "data.h"

Data lerData()
{
    Data d;
    scanf("%d/%d/%d\n", &d.dia, &d.mes, &d.ano);
    return d;
}

void imprimeData(Data d)
{
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

int comparaData(Data d1, Data d2)
{
    if (d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano)
    {
        return 1;
    }
    return 0;
}

int calcularDiffAnosData(Data inicio, Data fim)
{
    int diff = fim.ano - inicio.ano;

    if (fim.mes < inicio.mes)
    {
        diff--;
    }
    else if (fim.mes == inicio.mes && fim.dia < inicio.dia)
    {
        diff--;
    }
    return diff;
}