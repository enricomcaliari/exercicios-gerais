#include <stdio.h>
#include "registro.h"

/*
Função que recebe o número de um log e o caminho da pasta de logs e retorna um Registro de partida
lido do arquivo binário correspondente ao log.

@param logNum: Número do log
@param pastaLogs: Caminho da pasta de logs (já com a barra no final)
*/
Registro leRegistro(int logNum, char *pastaLogs)
{
    char diretorio[50];
    sprintf(diretorio, "%slog_%d.bin", pastaLogs, logNum);

    Registro r;

    FILE *arquivo_binario = fopen(diretorio, "rb");

    fread(&r.idPartida, sizeof(int), 1, arquivo_binario);
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {
        r.jogadores[i] = leJogador(arquivo_binario);
    }

    fclose(arquivo_binario);

    return r;
}

/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog)
{
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {
        if (r.jogadores[i].id == idJog)
        {
            return r.jogadores[i];
        }
    }
    return inicializaJogador(-1);
}