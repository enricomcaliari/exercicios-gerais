#include <stdio.h>
#include "data.h"

Data lerData()
{
    Data data;
    scanf("%d/%d/%d\n", &data.dia, &data.mes, &data.ano);
    return data;
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
    else
        return 0;
}

int calcularDiffAnosData(Data inicio, Data fim)
{
    int anos;

    anos = fim.ano - inicio.ano;

    if (fim.mes < inicio.mes)
    {
        anos -= 1;
    }
    else if (fim.dia < inicio.dia)
    {
        anos -= 1;
    }

    return anos;
}