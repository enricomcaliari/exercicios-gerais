#include <stdio.h>
#include "data.h"

void InicializaDataParam(int dia, int mes, int ano, tData *data)
{
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData(tData *data)
{
    int dia, mes, ano;

    scanf("%d %d %d\n", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);

    if (data->mes > 12)
    {
        data->mes = 12;
    }

    if (InformaQtdDiasNoMes(data) == 28)
    {
        if (data->dia > 28)
        {
            data->dia = 28;
        }
    }
    else if (InformaQtdDiasNoMes(data) == 29)
    {
        if (data->dia > 29)
        {
            data->dia = 29;
        }
    }
    else if (InformaQtdDiasNoMes(data) == 30)
    {
        if (data->dia > 30)
        {
            data->dia = 30;
        }
    }
    else
    {
        if (data->dia > 31)
        {
            data->dia = 31;
        }
    }
}

void ImprimeData(tData *data)
{
    if (data->dia < 10 && data->mes < 10)
    {
        printf("'0%d/0%d/%d'", data->dia, data->mes, data->ano);
    }
    else if (data->dia < 10)
    {
        printf("'0%d/%d/%d'", data->dia, data->mes, data->ano);
    }
    else if (data->mes < 10)
    {
        printf("'%d/0%d/%d'", data->dia, data->mes, data->ano);
    }
    else
    {
        printf("'%d/%d/%d'", data->dia, data->mes, data->ano);
    }
}

int EhBissexto(tData *data)
{
    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes(tData *data)
{
    if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
    {
        return 30;
    }
    else if (data->mes == 2)
    {
        if (EhBissexto(data))
        {
            return 29;
        }
        return 28;
    }
    else
    {
        return 31;
    }
}

void AvancaParaDiaSeguinte(tData *data)
{
    if (InformaQtdDiasNoMes(data) == 30)
    {
        if (data->dia == 30)
        {
            data->dia = 1;
            data->mes++;
        }
        else
        {
            data->dia++;
        }
    }
    else if (InformaQtdDiasNoMes(data) == 29)
    {
        if (data->dia == 29)
        {
            data->dia = 1;
            data->mes++;
        }
        else
        {
            data->dia++;
        }
    }
    else if (InformaQtdDiasNoMes(data) == 28)
    {
        if (data->dia == 28)
        {
            data->dia = 1;
            data->mes++;
        }
        else
        {
            data->dia++;
        }
    }
    else
    {
        if (data->dia == 31)
        {
            if (data->mes == 12)
            {
                data->dia = 1;
                data->mes = 1;
                data->ano++;
            }
            else
            {
                data->dia = 1;
                data->mes++;
            }
        }
        else
        {
            data->dia++;
        }
    }
}

int EhIgual(tData *data1, tData *data2)
{
    if (data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano)
    {
        return 1;
    }
    return 0;
}