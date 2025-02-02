#ifndef PRISAO_H
#define PRISAO_H

#include "cela.h"
#include "prisioneiro.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAXTAM_NOME 100

typedef struct
{
    char nome[MAXTAM_NOME];
    int dia;
    int nCelas;
    int capacidadeCelas;
    tCela celas[MAXTAM_CELAS];
}tPrisao;


tPrisao criaPrisao(char* nome, int nCelas, int capacidadeCelas);

void executaPrisao(tPrisao* prisao);

void imprimeDiaEMenuPrisao(tPrisao* prisao);

void inserePrisioneiroPrisao(tPrisao* prisao);

void passaDiaPrisao(tPrisao* prisao);

void registraFugaCelaPrisao(tPrisao* prisao);

void finalizaPrograma(tPrisao* prisao);

int obtemNumeroPrisioneirosPrisao(tPrisao* prisao);

void rebeliaoGeralPrisao(tPrisao* prisao);
#endif