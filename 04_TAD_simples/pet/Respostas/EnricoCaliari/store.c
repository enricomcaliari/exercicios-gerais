#include <stdio.h>
#include <string.h>
#include "store.h"

tStore abreLoja()
{
    tStore loja;
    loja.faturamento = 0;
    loja.nmProdutos = 0;
    loja.nmVendas = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        loja.produtos[i] = criaProduto("vazio", 0, 0, 0, 0);
    }
    return loja;
}

tStore adicionaProduto(tStore loja, tProduct produto)
{
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        if (!strcmp(loja.produtos[i].nome, "vazio"))
        {
            loja.produtos[i] = produto;
            loja.nmProdutos += loja.produtos[i].estoque;
            return loja;
        }
    }
}

int buscaProduto(tStore loja, int id)
{
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        if (ehMesmoId(loja.produtos[i], id))
        {
            return i;
        }
    }
    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd)
{
    int i = buscaProduto(loja, id);
    if (i != -1)
    {
        loja.produtos[i] = aumentaEstoqueProduto(loja.produtos[i], qtd);
        loja.nmProdutos += qtd;
    }
    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd)
{
    int i = buscaProduto(loja, id);
    if (i != -1)
    {
        loja.produtos[i] = vendeProduto(loja.produtos[i], qtd);
        loja.nmVendas += qtd;
        loja.nmProdutos -= qtd;
        loja.faturamento += qtd * obtemPrecoComDesconto(loja.produtos[i]);
    }
    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto)
{
    int i = buscaProduto(loja, id);
    if (i != -1)
    {
        loja.produtos[i] = atualizaDesconto(loja.produtos[i], desconto);
    }
    return loja;
}

void imprimeProdutosLoja(tStore loja)
{
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        if (strcmp(loja.produtos[i].nome, "vazio") != 0)
        {
            imprimeProduto(loja.produtos[i]);
        }
    }
    printf("\n");
}

void imprimeRelatorio(tStore loja)
{
    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", loja.nmProdutos);
    imprimeMaisVendido(loja);
    printf("\n");
}

int obtemEstoqueLoja(tStore loja)
{
    return loja.nmProdutos;
}

void imprimeMaisVendido(tStore loja)
{
    int mais_vendido = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        if (loja.produtos[i].vendas > mais_vendido)
        {
            mais_vendido = loja.produtos[i].vendas;
        }
    }

    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        if (mais_vendido == loja.produtos[i].vendas)
        {
            printf("PRODUTO MAIS VENDIDO:\n");
            printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", loja.produtos[i].nome, obtemPrecoComDesconto(loja.produtos[i]), loja.produtos[i].estoque, loja.produtos[i].vendas);
            break;
        }
    }
}