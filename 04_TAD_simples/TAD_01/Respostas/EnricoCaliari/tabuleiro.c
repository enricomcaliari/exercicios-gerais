#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    if (peca == PECA_1)
    {
        tabuleiro.posicoes[y][x] = 'X';
    }
    else if (peca == PECA_2)
    {
        tabuleiro.posicoes[y][x] = '0';
    }

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro.posicoes[i][j] == '-')
            {
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    if (peca == PECA_1)
    {
        if (tabuleiro.posicoes[y][x] == 'X')
        {
            return 1;
        }
    }
    else if (peca == PECA_2)
    {
        if (tabuleiro.posicoes[y][x] == '0')
        {
            return 1;
        }
    }

    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    if (tabuleiro.posicoes[y][x] == '-')
    {
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if ((x >= 0 && x <= 2) && (y >= 0 && y <= 2))
    {
        return 1;
    }
    return 0;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("    ");
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}