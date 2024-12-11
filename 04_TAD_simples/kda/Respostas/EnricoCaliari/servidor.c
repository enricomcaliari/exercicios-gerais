#include <stdio.h>
#include "servidor.h"

Servidor leRegistrosServidor()
{
  Servidor s;
  s.nPartidas = 0;

  int idPartida;

  while (1)
  {
    scanf("%d\n", &idPartida);

    if (idPartida == -1)
    {
      return s;
    }

    s.partidas[s.nPartidas] = leRegistro(idPartida);
    s.nPartidas++;
  }
}

Jogador buscaDadosJogadorServidor(Servidor s, int idJog)
{
  Jogador jogador = inicializaJogador(idJog);
  int achouJogador = 0;

  for (int i = 0; i < s.nPartidas; i++)
  {
    for (int j = 0; j < MAX_JOGADOR_PARTIDA; j++)
    {
      if (s.partidas[i].jogadores[j].id == idJog)
      {
        achouJogador++;
        jogador = atualizaJogador(jogador, idJog, s.partidas[i].jogadores[j].kills, s.partidas[i].jogadores[j].deaths, s.partidas[i].jogadores[j].assists);
      }
    }
  }

  if (!achouJogador)
  {
    Jogador j = inicializaJogador(-1);
    return j;
  }
  else
    return jogador;
}

void criaRelatorioServidor(Servidor s)
{
  int nJogadores;
  scanf("%d\n", &nJogadores);

  int idSolicitada[nJogadores];

  int idJog;
  for (int i = 0; i < nJogadores; i++)
  {
    scanf("%d", &idSolicitada[i]);
  }

  for (int i = 0; i < nJogadores; i++)
  {
    Jogador jogador = buscaDadosJogadorServidor(s, idSolicitada[i]);
    if (jogador.id == -1)
    {
      printf("Jogador %d: -\n", idSolicitada[i]);
    }
    else
      printaJogador(jogador);
  }
}