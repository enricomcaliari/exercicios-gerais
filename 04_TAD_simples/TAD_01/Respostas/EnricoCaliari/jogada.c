#include <stdio.h>
#include "jogada.h"

tJogada LeJogada()
{
    tJogada jogada;
    printf("Digite uma posicao (x e y):\n");
    if (scanf("%d %d\n", &jogada.x, &jogada.y))
    {
        jogada.sucesso = 1;
    }
    else
        jogada.sucesso = 0;

    return jogada;
}

int ObtemJogadaX(tJogada jogada)
{
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada)
{
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada)
{
    if (jogada.sucesso)
    {
        return 1;
    }
    else
        return 0;
}