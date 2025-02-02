#include "cela.h"

tCela criaCela(int capacidade)
{
    tCela cela;
    cela.capacidade = capacidade;
    cela.nPresidiarios = 0;
    return cela;
}

int possuiVagaCela(tCela *cela)
{
    if (cela->nPresidiarios < cela->capacidade)
    {
        return 1;
    }
    return 0;
}

int obtemNumeroPrisioneirosCela(tCela *cela)
{
    return cela->nPresidiarios;
}

void inserePrisioneiroCela(tCela *cela, tPrisioneiro prisioneiro)
{
    if (possuiVagaCela(cela))
    {
        for (int i = 0; i < cela->nPresidiarios; i++)
        {
            if (!prisionerioExiste(&cela->prisioneiros[i]))
            {
                cela->prisioneiros[i] = prisioneiro;
                cela->nPresidiarios++;
            }
        }
    }
}

tPrisioneiro obtemPrisioneiroCela(tCela *cela, int i)
{
    return cela->prisioneiros[i];
}

void fogePrisioneirosCela(tCela *cela)
{
    for (int i = 0; i < cela->nPresidiarios; i++)
    {
        fogePrisioneiro(&cela->prisioneiros[i]);
    }
}

void passaDiaCela(tCela *cela)
{
    for (int i = 0; i < cela->nPresidiarios; i++)
    {
        passaTempoPrisioneiro(&cela->prisioneiros[i]);
    }
}