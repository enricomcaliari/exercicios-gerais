#include <stdio.h>
#include <string.h>
#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}

tCandidato LeCandidato()
{
    tCandidato candidato;

    scanf("%[^,], %[^,], %c, %d\n", candidato.nome, candidato.partido, &candidato.cargo, &candidato.id);
    candidato.votos = 0;

    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    if (candidato.id == id)
    {
        return 1;
    }
    return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    if (candidato1.id == candidato2.id)
    {
        return 1;
    }
    return 0;
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    float percentualVotos = (float) 100 * candidato.votos / totalVotos;
    return percentualVotos;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}