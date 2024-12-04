#include <stdio.h>
#include "registro.h"

Registro leRegistro(int idPartida)
{
  Registro registro;
  registro.idPartida = idPartida;

  int idJog;

  for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
  {
    scanf("%d: ", &idJog);
    registro.jogadores[i] = leJogador(idJog);
  }

  return registro;
}

Jogador buscaJogadorRegistro(Registro r, int idJog)
{
  for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
  {
    if (r.jogadores[i].id == idJog)
    {
      return r.jogadores[i];
    }
  }

  Jogador jogador = inicializaJogador(-1);

  return jogador;
}