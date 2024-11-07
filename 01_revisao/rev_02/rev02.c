#include <stdio.h>

int main()
{
  int nLinhas, j, k = 1;

  scanf("%d", &nLinhas);

  for (int i = 1; i <= nLinhas; i++)
  {
    for (j = 1; j <= i; j++)
    {
      printf("%d ", k);
      k++;
    }
    printf("\n");
  }

  return 0;
}