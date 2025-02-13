#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

Lesao *leLesao()
{
    Lesao *l = (Lesao *)calloc(1, sizeof(Lesao));
    l->diag = (char *)calloc(TAM_DIAG, sizeof(char));
    l->id = (char *)calloc(TAM_ID, sizeof(char));
    l->regiao = (char *)calloc(TAM_REG, sizeof(char));

    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diag);
    scanf("%[^\n]\n", l->regiao);
    scanf("%d\n", &l->malignidade);

    return l;
}

void liberaLesao(Lesao *l)
{
    if (l != NULL)
    {
        free(l->diag);
        free(l->id);
        free(l->regiao);
        free(l);
    }
}

char *getIdLesao(Lesao *l)
{
    return l->id;
}

int precisaCirurgiaLesao(Lesao *l)
{
    if (l->malignidade > 50)
    {
        return 1;
    }
    return 0;
}