#include <stdio.h>
#include <math.h>

typedef struct Circulo
{
  float x, y, raio;
} Circulo;

float distanciaPontos(float xi, float yi, float xf, float yf);
void acertouAlvo(float distancia, float raioT, float raioA);
void acertouAlvo(float distancia, float raioT, float raioA);

float distanciaPontos(float xi, float yi, float xf, float yf)
{
  float distancia = sqrt(pow((xf - xi), 2) + pow((yf - yi), 2));

  return distancia;
}

void acertouAlvo(float distancia, float raioT, float raioA)
{
  if (distancia >= raioA + raioT)
  {
    printf("ERROU\n");
  }
  else
    printf("ACERTOU\n");
}

int main()
{
  Circulo tiro, alvo;

  scanf("%f %f %f", &alvo.x, &alvo.y, &alvo.raio);
  scanf("%f %f %f", &tiro.x, &tiro.y, &tiro.raio);

  float distancia = distanciaPontos(tiro.x, alvo.x, tiro.y, alvo.y);
  acertouAlvo(distancia, alvo.raio, tiro.raio);

  return 0;
}