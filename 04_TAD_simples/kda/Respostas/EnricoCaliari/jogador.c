#include <stdio.h>
#include "jogador.h"

Jogador inicializaJogador(int id)
{
  Jogador jogador;

  jogador.id = id;
  jogador.kills = 0;
  jogador.deaths = 0;
  jogador.assists = 0;
  jogador.valorKDA = -1;

  return jogador;
}

Jogador leJogador(int id)
{
  Jogador jogador = inicializaJogador(id);

  scanf("%d %d %d\n", &jogador.kills, &jogador.deaths, &jogador.assists);
  jogador.valorKDA = calculaKDA(jogador);

  return jogador;
}

float calculaKDA(Jogador j)
{
  float k = j.kills;
  float d = j.deaths;
  float a = j.assists;

  if (d == 0)
  {
    int ka = k + a;
    j.valorKDA = ka;
    return ka;
  }
  else
  {
    float kda = (k + a) / d;
    j.valorKDA = kda;
    return kda;
  }
}

Jogador atualizaJogador(Jogador j, int id, int k, int d, int a)
{
  j.id = id;
  j.kills += k;
  j.deaths += d;
  j.assists += a;
  j.valorKDA = calculaKDA(j);

  return j;
}

int getKillsJogador(Jogador j)
{
  return j.kills;
}

int getDeathsJogador(Jogador j)
{
  return j.deaths;
}

int getAssistsJogador(Jogador j)
{
  return j.assists;
}

int getIdJogador(Jogador j)
{
  return j.id;
}

void printaJogador(Jogador j)
{
  printf("Jogador %d: %d/%d/%d (%.2f)\n", j.id, j.kills, j.deaths, j.assists, j.valorKDA);
}