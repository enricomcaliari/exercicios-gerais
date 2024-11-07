#include <stdio.h>

typedef struct Livro
{
  int id;
} Livro;

int main()
{
  int n, copias = 1, check = 0;
  scanf("%d", &n);

  Livro livro[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d ", &livro[i].id);
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (livro[j].id > livro[j + 1].id)
      {
        int temp = livro[j].id;
        livro[j].id = livro[j + 1].id;
        livro[j + 1].id = temp;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        continue;
      }
      if (livro[i].id == livro[j].id)
      {
        copias++;
      }
    }
    if (copias == 1)
    {
      printf("%d ", livro[i].id);
    }
    else
    {
      check++;
    }
    copias = 1;
  }

  if (check == n)
  {
    printf("NENHUM\n");
  }
  else
    printf("\n");

  return 0;
}