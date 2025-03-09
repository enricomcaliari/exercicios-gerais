#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define TAM_MAX_NOME 100
#define TAM_MAX_DATA 11
#define TAM_MAX_CURSO 50

struct Aluno
{
    char *nome;
    char *dataNascimento;
    char *curso;
    int periodo;
    float coeficienteRendimento;
};

/**
 * @brief Função para criar um novo aluno.
 *
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno *CriarAluno(char *nome, char *dataNascimento, char *curso, int periodo, float coeficienteRendimento)
{
    tAluno *aluno = (tAluno *)malloc(sizeof(tAluno));
    aluno->nome = (char *)malloc(TAM_MAX_NOME * sizeof(char));
    aluno->dataNascimento = (char *)malloc(TAM_MAX_DATA * sizeof(char));
    aluno->curso = (char *)malloc(TAM_MAX_CURSO * sizeof(char));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);
    aluno->periodo = periodo;
    aluno->coeficienteRendimento = coeficienteRendimento;

    return aluno;
}

/**
 * @brief Função para destruir um aluno.
 *
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno *aluno)
{
    if (aluno != NULL)
    {
        free(aluno->nome);
        free(aluno->dataNascimento);
        free(aluno->curso);
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 *
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    tAluno *aluno = CriarAluno("vazio", "vazio", "vazio", 0, 0);
    
    fread(aluno->nome, sizeof(char), TAM_MAX_NOME, arquivo_binario);
    fread(aluno->dataNascimento, sizeof(char), TAM_MAX_DATA, arquivo_binario);
    fread(aluno->curso, sizeof(char), TAM_MAX_CURSO, arquivo_binario);

    int periodo;
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    aluno->periodo = periodo;

    float coeficienteRendimento;
    fread(&coeficienteRendimento, sizeof(float), 1, arquivo_binario);
    aluno->coeficienteRendimento = coeficienteRendimento;

    return aluno;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 *
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno *aluno)
{
    return aluno->coeficienteRendimento;
}