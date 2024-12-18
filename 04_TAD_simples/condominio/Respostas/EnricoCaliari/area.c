#include <stdio.h>
#include <string.h>
#include "area.h"

Area lerArea()
{
    Area a;
    scanf("%[^\n]\n", a.nome);
    scanf("%[^\n]\n", a.id);
    scanf("%d\n", &a.capacidade);
    return a;
}

void imprimeArea(Area a)
{
    printf("Nome: %s\nId: %s\nCapacidade: %d convidado(s)\n", a.nome, a.id, a.capacidade);
}

int comparaArea(Area a1, Area a2)
{
    if (!strcmp(a1.id, a2.id))
    {
        return 1;
    }
    else
        return 0;
}

int verificaIdArea(Area a, char *id)
{
    if (!strcmp(a.id, id))
    {
        return 1;
    }
    else
        return 0;
}

int getCapacidadeArea(Area a)
{
    return a.capacidade;
}