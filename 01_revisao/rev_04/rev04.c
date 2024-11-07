#include <stdio.h>

void decimalParaOctal(int decimal)
{
  int octal[100], i = 0;

  while (decimal != 0)
  {
    octal[i] = decimal % 8;
    decimal /= 8;
    i++;
  }

  for (int j = i - 1; j >= 0; j--)
  {
    printf("%d", octal[j]);
  }
  printf("\n");
}

int main()
{
  int decimal;

  scanf("%d", &decimal);

  decimalParaOctal(decimal);

  return 0;
}