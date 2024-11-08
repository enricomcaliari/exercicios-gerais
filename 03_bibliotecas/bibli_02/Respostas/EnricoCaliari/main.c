#include <stdio.h>
#include "matrix_utils.h"

void imprime_menu()
{
  printf("1 - Somar matrizes\n");
  printf("2 - Subtrair matrizes\n");
  printf("3 - Multiplicar matrizes\n");
  printf("4 - Multiplicacao de uma matriz por escalar\n");
  printf("5 - Transposta de uma matriz\n");
  printf("6 - Encerrar o programa\n");
  printf("Opcao escolhida:\n");
}

int main()
{
  int linha1, coluna1;
  scanf("%d %d", &linha1, &coluna1);

  int matriz1[linha1][coluna1];
  matrix_read(linha1, coluna1, matriz1);

  int linha2, coluna2;
  scanf("%d %d", &linha2, &coluna2);

  int matriz2[linha2][coluna2];
  matrix_read(linha2, coluna2, matriz2);

  int opcao;
  while (1)
  {
    imprime_menu();
    scanf("%d", &opcao);
    if (opcao == 1)
    {
      int resultado[linha1][coluna1];
      matrix_add(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
    }
    else if (opcao == 2)
    {
      int resultado[linha1][coluna1];
      matrix_sub(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
    }
    else if (opcao == 3)
    {
      int resultado[linha1][coluna2];
      matrix_multiply(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
    }
    else if (opcao == 4)
    {
      int escalar;
      scanf("%d", &escalar);
      int matriz;
      scanf("%d", &matriz);

      if (matriz == 1)
      {
        scalar_multiply(linha1, coluna1, matriz1, escalar);
        matrix_print(linha1, coluna1, matriz1);
      }
      else if (matriz == 2)
      {
        scalar_multiply(linha2, coluna2, matriz2, escalar);
        matrix_print(linha2, coluna2, matriz2);
      }
    }
    else if (opcao == 5)
    {
      int resultado1[coluna1][linha1];
      int resultado2[coluna2][linha2];
      transpose_matrix(linha1, coluna1, matriz1, resultado1);
      matrix_print(coluna1, linha1, resultado1);
      printf("\n");
      transpose_matrix(linha2, coluna2, matriz2, resultado2);
      matrix_print(coluna2, linha2, resultado2);
    }
    else if (opcao == 6)
    {
      break;
    }
    printf("\n");
  }

  return 0;
}