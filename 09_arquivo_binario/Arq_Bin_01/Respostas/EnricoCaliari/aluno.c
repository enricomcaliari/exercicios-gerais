#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_TAM_STRING 100

struct aluno
{
    char *nome;
    char *dtNasc;
    char *cursoUfes;
    char *periodoIngresso;
    int percConclusao;
    float CRA;
};

Aluno **CriaVetorAlunos(int numeroAlunos)
{
    Aluno **vetorAlunos = (Aluno **)malloc(numeroAlunos * sizeof(Aluno));
    return vetorAlunos;
}

Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char *periodoIngresso, int percConclusao, float CRA)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->nome = (char *)malloc(MAX_TAM_STRING * sizeof(char));
    aluno->dtNasc = (char *)malloc(MAX_TAM_STRING * sizeof(char));
    aluno->cursoUfes = (char *)malloc(MAX_TAM_STRING * sizeof(char));
    aluno->periodoIngresso = (char *)malloc(MAX_TAM_STRING * sizeof(char));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dtNasc, dtNasc);
    strcpy(aluno->cursoUfes, cursoUfes);
    strcpy(aluno->periodoIngresso, periodoIngresso);
    aluno->percConclusao = percConclusao;
    aluno->CRA = CRA;

    return aluno;
}

void LeAlunos(Aluno **vetorAlunos, int numeroAlunos)
{
    for (int i = 0; i < numeroAlunos; i++)
    {
        scanf("%[^\n]\n", vetorAlunos[i]->nome);
        scanf("%[^\n]\n", vetorAlunos[i]->dtNasc);
        scanf("%[^\n]\n", vetorAlunos[i]->cursoUfes);
        scanf("%[^\n]\n", vetorAlunos[i]->periodoIngresso);
        scanf("%d\n", vetorAlunos[i]->percConclusao);
        scanf("%f\n", vetorAlunos[i]->CRA);
    }
}

void LiberaAlunos(Aluno **alunos, int numeroAlunos)
{
    if (alunos != NULL)
    {
        for (int i = 0; i < numeroAlunos; i++)
        {
            free(alunos[i]->nome);
            free(alunos[i]->dtNasc);
            free(alunos[i]->cursoUfes);
            free(alunos[i]->periodoIngresso);
            free(alunos[i]);
        }
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
}

void ImprimeAlunos(Aluno **alunos, int numeroAlunos)
{
}