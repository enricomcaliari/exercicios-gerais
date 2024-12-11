#include <stdio.h>
#include "store.h"

void imprimeMenu()
{
  printf("Menu:\n");
  printf("C - Cadastrar Produto\n");
  printf("E - Estocar Produto\n");
  printf("V - Vender Produto\n");
  printf("D - Atualizar desconto de Produto\n");
  printf("I - Imprimir Produtos\n");
  printf("R - Imprimir Relatorio de Vendas\n");
  printf("F - Finalizar programa\n");
}

tStore cadastraProdutoMain(tStore loja)
{
  tProduct produto = leProduto();
  loja = adicionaProduto(loja, produto);
  return loja;
}

tStore estocaProdutoMain(tStore loja)
{
  int id, qtd;
  scanf("%d\n", &id);
  scanf("%d\n", &qtd);
  loja = aumentaEstoqueLoja(loja, id, qtd);
  return loja;
}

tStore vendeProdutoMain(tStore loja)
{
  int id, qtd;
  scanf("%d\n", &id);
  scanf("%d\n", &qtd);
  loja = vendeProdutoLoja(loja, id, qtd);
  return loja;
}

tStore atualizaDescontoMain(tStore loja)
{
  int id;
  float desconto;
  scanf("%d\n", &id);
  scanf("%f\n", &desconto);
  loja = atualizaDescontoLoja(loja, id, desconto);
  return loja;
}

int main()
{
  tStore loja = abreLoja();
  char menu;

  imprimeMenu();
  while (1)
  {
    scanf("%c\n", &menu);
    if (menu == 'C' || menu == 'c')
    {
      printf("Nome do Produto: ID: Preco: Desconto: Estoque: \n");
      loja = cadastraProdutoMain(loja);
    }
    else if (menu == 'E' || menu == 'e')
    {
      printf("Digite o id do Produto: Digite o numero de unidades: ");
      loja = estocaProdutoMain(loja);
    }
    else if (menu == 'V' || menu == 'v')
    {
      printf("Digite o id do Produto: Digite o numero de unidades: ");
      loja = vendeProdutoMain(loja);
    }
    else if (menu == 'D' || menu == 'd')
    {
      printf("Digite o id do Produto: Digite o novo desconto: ");
      loja = atualizaDescontoMain(loja);
    }
    else if (menu == 'I' || menu == 'i')
    {
      imprimeProdutosLoja(loja);
    }
    else if (menu == 'R' || menu == 'r')
    {
      imprimeRelatorio(loja);
    }
    else
    {
      break;
    }
    imprimeMenu();
  }
  return 0;
}