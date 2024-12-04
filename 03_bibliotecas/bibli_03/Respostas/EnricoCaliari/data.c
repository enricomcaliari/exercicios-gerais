#include <stdio.h>
#include "data.h"

int verificaBissexto(int ano)
{
  if (ano % 4 == 0)
  {
    if (ano % 100 != 0)
    {
      return 1;
    }
    else
    {
      if (ano % 400 == 0)
      {
        return 1;
      }
      else
        return 0;
    }
  }
  return 0;
}

int numeroDiasMes(int mes, int ano)
{
  if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
  {
    return 30;
  }
  else if (mes == 2)
  {
    if (verificaBissexto(ano))
    {
      return 29;
    }
    else
      return 28;
  }
  return 31;
}

int verificaDataValida(int dia, int mes, int ano)
{
  if (ano < 0)
  {
    return 0;
  }
  else if (mes < 1 || mes > 12)
  {
    return 0;
  }
  else if (dia < 1 || dia > 31)
  {
    return 0;
  }
  else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
  {
    return 0;
  }
  else if (mes == 2)
  {
    if (verificaBissexto(ano))
    {
      if (dia > 29)
      {
        return 0;
      }
    }
    else if (dia > 28)
    {
      return 0;
    }
  }
  return 1;
}

void imprimeMesExtenso(int mes)
{
  switch (mes)
  {
  case 1:
    printf("Janeiro");
    break;
  case 2:
    printf("Fevereiro");
    break;
  case 3:
    printf("Marco");
    break;
  case 4:
    printf("Abril");
    break;
  case 5:
    printf("Maio");
    break;
  case 6:
    printf("Junho");
    break;
  case 7:
    printf("Julho");
    break;
  case 8:
    printf("Agosto");
    break;
  case 9:
    printf("Setembro");
    break;
  case 10:
    printf("Outubro");
    break;
  case 11:
    printf("Novembro");
    break;
  case 12:
    printf("Dezembro");
    break;

  default:
    break;
  }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
  if (dia < 10)
  {
    printf("0%d de ", dia);
  }
  else
  {
    printf("%d de ", dia);
  }
  imprimeMesExtenso(mes);
  printf(" de %d\n", ano);
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
  if (ano1 > ano2)
  {
    return 1;
  }
  else if (ano1 < ano2)
  {
    return -1;
  }

  if (mes1 > mes2)
  {
    return 1;
  }
  else if (mes1 < mes2)
  {
    return -1;
  }

  if (dia1 > dia2)
  {
    return 1;
  }
  else if (dia1 < dia2)
  {
    return -1;
  }

  return 0;
}

int calculaDiasAteMes(int mes, int ano)
{
  int dias = 0;
  for (int i = 1; i < mes; i++)
  {
    dias += numeroDiasMes(i, ano);
  }
  return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
  int comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

  if (comparacao == 0)
  {
    return 0; // Datas iguais
  }

  int totalDias1 = 0, totalDias2 = 0;

  // Calcula os dias totais da data 1
  for (int i = 1; i < ano1; i++)
  {
    totalDias1 += verificaBissexto(i) ? 366 : 365;
  }
  totalDias1 += calculaDiasAteMes(mes1, ano1) + dia1;

  // Calcula os dias totais da data 2
  for (int i = 1; i < ano2; i++)
  {
    totalDias2 += verificaBissexto(i) ? 366 : 365;
  }
  totalDias2 += calculaDiasAteMes(mes2, ano2) + dia2;

  // Retorna a diferença de dias dependendo da ordem das datas
  if (comparacao == 1)
  {
    return totalDias1 - totalDias2;
  }
  else
  {
    return totalDias2 - totalDias1;
  }
}