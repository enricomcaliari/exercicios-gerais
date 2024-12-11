#include <stdio.h>
#include <string.h>
#include "product.h"

tProduct leProduto()
{
    tProduct produto;
    scanf("%99[^\n]", produto.nome);
    scanf("%d\n", &produto.id);
    scanf("%f\n", &produto.preco);
    scanf("%f\n", &produto.desconto);
    scanf("%d\n", &produto.estoque);
    produto.vendas = 0;
    return produto;
}

tProduct criaProduto(char *nome, float desconto, float preco, int estoque, int id)
{
    tProduct produto;
    strcpy(produto.nome, nome);
    produto.desconto = desconto;
    produto.preco = preco;
    produto.estoque = estoque;
    produto.id = id;
    return produto;
}

float obtemDesconto(tProduct produto)
{
    return produto.desconto;
}

float obtempreco(tProduct produto)
{
    return produto.preco;
}

float obtemPrecoComDesconto(tProduct produto)
{
    return produto.preco - (produto.preco * produto.desconto);
}

int obtemEstoque(tProduct produto)
{
    return produto.estoque;
}

int obtemVendas(tProduct produto)
{
    return produto.vendas;
}

int obtemId(tProduct produto)
{
    return produto.id;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd)
{
    if (qtd > 0)
    {
        produto.estoque += qtd;
    }
    return produto;
}

tProduct vendeProduto(tProduct produto, int qtd)
{
    if (produto.estoque >= qtd && produto.estoque > 0 && qtd > 0)
    {
        produto.estoque -= qtd;
        produto.vendas += qtd;
    }
    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto)
{
    if (desconto >= 0 && desconto <= 1)
    {
        produto.desconto = desconto;
    }
    return produto;
}

bool ehMesmoId(tProduct produto, int id)
{
    if (produto.id == id)
    {
        return true;
    }
    else
        return false;
}

void imprimeProduto(tProduct produto)
{
    printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", produto.nome, obtemPrecoComDesconto(produto), produto.estoque, produto.vendas);
}