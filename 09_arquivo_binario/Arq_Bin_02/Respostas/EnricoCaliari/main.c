#include <stdio.h>
#include "base_alunos.h"

#define TAM_MAX_DIRETORIO 50

int main()
{
    char diretorio[TAM_MAX_DIRETORIO];
    scanf("%s\n", diretorio);

    tBaseAlunos *baseAlunos = CriarBaseAlunos();
    LerBaseAlunos(baseAlunos, diretorio);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(baseAlunos));

    DestruirBaseAlunos(baseAlunos);

    return 0;
}