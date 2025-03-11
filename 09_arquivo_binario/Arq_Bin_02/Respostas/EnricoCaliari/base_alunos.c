#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "base_alunos.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos
{
    tAluno **alunos;
    int qtdAlunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 *
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos *CriarBaseAlunos()
{
    tBaseAlunos *baseAlunos = (tBaseAlunos *)malloc(sizeof(tBaseAlunos));
    baseAlunos->alunos = (tAluno **)malloc(sizeof(tAluno *));
    baseAlunos->qtdAlunos = 1;
    return baseAlunos;
}

/**
 * @brief Função para destruir uma base de alunos.
 *
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos *baseAlunos)
{
    if (baseAlunos != NULL)
    {
        for (int i = 0; i < baseAlunos->qtdAlunos; i++)
        {
            DestruirAluno(baseAlunos->alunos[i]);
        }
        free(baseAlunos->alunos);
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 *
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos *baseAlunos, char *nomeArquivo)
{
    FILE *arquivo_binario = fopen(nomeArquivo, "rb");

    fread(&baseAlunos->qtdAlunos, sizeof(int), 1, arquivo_binario);

    baseAlunos->alunos = (tAluno **)realloc(baseAlunos->alunos, baseAlunos->qtdAlunos * sizeof(tAluno *));
    for (int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        baseAlunos->alunos[i] = LeAluno(arquivo_binario);
    }

    fclose(arquivo_binario);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 *
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos *baseAlunos)
{
    float coeficienteRendimentoMedio = 0;

    for (int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        coeficienteRendimentoMedio += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    coeficienteRendimentoMedio /= baseAlunos->qtdAlunos;

    return coeficienteRendimentoMedio;
}