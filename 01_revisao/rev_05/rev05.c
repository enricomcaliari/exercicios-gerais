#include <stdio.h>

#define maxLinhas 50
#define maxColunas 50

typedef struct Posicao
{
  int x, y;
} Posicao;

typedef struct Mapa
{
  int mapa[maxLinhas][maxColunas];
  int linhas, colunas;
} Mapa;

typedef struct Jogo
{
  Posicao jogador;
  Posicao saida;
  Mapa mapa;
  char moveset[4];
  int direcao;
  int terminou;
} Jogo;

Mapa leMapa();
Posicao lePosicao();
Jogo leJogo();
Jogo moveJogador(Jogo jogo);
void printaPosicao(Jogo jogo);
Jogo atualizaDirecao(Jogo jogo);
Jogo realizaJogo(Jogo jogo);

void printaPosicao(Jogo jogo)
{
  printf("(%d,%d) ", jogo.jogador.x + 1, jogo.jogador.y + 1); // +1 para exibição 1-based
}

Mapa leMapa()
{
  Mapa mapa;
  scanf("%d %d", &mapa.linhas, &mapa.colunas);
  for (int i = 0; i < mapa.linhas; i++)
  {
    for (int j = 0; j < mapa.colunas; j++)
    {
      scanf("%d", &mapa.mapa[i][j]);
    }
  }
  return mapa;
}

Posicao lePosicao()
{
  Posicao posicao;
  scanf("%d %d", &posicao.x, &posicao.y);
  posicao.x--;
  posicao.y--; // Ajuste para índice 0-based
  return posicao;
}

Jogo leJogo()
{
  Jogo jogo;
  jogo.mapa = leMapa();
  jogo.jogador = lePosicao();
  jogo.saida = lePosicao();
  scanf(" %c%c%c%c", &jogo.moveset[0], &jogo.moveset[1], &jogo.moveset[2], &jogo.moveset[3]); // Espaço antes para ignorar newline
  jogo.terminou = 0;
  jogo.direcao = -1;
  return jogo;
}

Jogo moveJogador(Jogo jogo)
{
  // Verifica se o jogador já chegou ao destino
  if (jogo.jogador.x == jogo.saida.x && jogo.jogador.y == jogo.saida.y)
  {
    jogo.terminou = 1;
    printaPosicao(jogo);
    return jogo;
  }

  printaPosicao(jogo);
  jogo.mapa.mapa[jogo.jogador.x][jogo.jogador.y] = 1; // Marca como visitado

  if (jogo.direcao == 1)
  { // Cima
    jogo.jogador.x--;
  }
  else if (jogo.direcao == 2)
  { // Baixo
    jogo.jogador.x++;
  }
  else if (jogo.direcao == 3)
  { // Esquerda
    jogo.jogador.y--;
  }
  else if (jogo.direcao == 4)
  { // Direita
    jogo.jogador.y++;
  }
  else
  {
    jogo.terminou = 1;
  }

  return jogo;
}

Jogo atualizaDirecao(Jogo jogo)
{
  for (int i = 0; i < 4; i++)
  {
    int novo_x = jogo.jogador.x, novo_y = jogo.jogador.y;

    // Define nova posição de acordo com o move set
    if (jogo.moveset[i] == 'C' && novo_x > 0 && jogo.mapa.mapa[novo_x - 1][novo_y] == 0)
    {
      jogo.direcao = 1; // Cima
      return jogo;
    }
    else if (jogo.moveset[i] == 'B' && novo_x < jogo.mapa.linhas - 1 && jogo.mapa.mapa[novo_x + 1][novo_y] == 0)
    {
      jogo.direcao = 2; // Baixo
      return jogo;
    }
    else if (jogo.moveset[i] == 'E' && novo_y > 0 && jogo.mapa.mapa[novo_x][novo_y - 1] == 0)
    {
      jogo.direcao = 3; // Esquerda
      return jogo;
    }
    else if (jogo.moveset[i] == 'D' && novo_y < jogo.mapa.colunas - 1 && jogo.mapa.mapa[novo_x][novo_y + 1] == 0)
    {
      jogo.direcao = 4; // Direita
      return jogo;
    }
  }
  jogo.direcao = -1; // Sem movimentos válidos
  return jogo;
}

Jogo realizaJogo(Jogo jogo)
{
  while (!jogo.terminou)
  {
    jogo = atualizaDirecao(jogo);
    jogo = moveJogador(jogo);
  }
  return jogo;
}

int main()
{
  Jogo jogo = leJogo();
  jogo = realizaJogo(jogo);
  printf("\n");
  return 0;
}