#include <stdio.h>
#include <string.h>
#include "morador.h"

Morador lerMorador()
{
    Morador m;
    scanf("%[^\n]\n", m.nome);
    scanf("%[^\n]\n", m.cpf);
    m.dataNasc = lerData();
    scanf("%[^\n]\n", m.idResidencia);
    return m;
}

void imprimeMorador(Morador m)
{
    printf("Nome: %s\n", m.nome);
    printf("CPF: %s\n", m.cpf);
    printf("Data de Nascimento: %d/%d/%d\n", m.dataNasc.dia, m.dataNasc.mes, m.dataNasc.ano);
    printf("Residência: %s\n", m.idResidencia);
}

int comparaMorador(Morador m1, Morador m2)
{
    if (!strcmp(m1.cpf, m2.cpf))
    {
        return 1;
    }
    else
        return 0;
}

int verificaCPFMorador(Morador m1, char *cpf)
{
    if (!strcmp(m1.cpf, cpf))
    {
        return 1;
    }
    else
        return 0;
}

int calculaIdadeMorador(Morador m, Data dataRef)
{
    return calcularDiffAnosData(m.dataNasc, dataRef);
}