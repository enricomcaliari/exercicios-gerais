#include "servidor.h"

int main()
{
  Servidor s = leRegistrosServidor();
  criaRelatorioServidor(s);
}