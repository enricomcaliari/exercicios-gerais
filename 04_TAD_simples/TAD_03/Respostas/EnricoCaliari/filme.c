#include <stdio.h>
#include <string.h>
#include "filme.h"

tFilme criarFilme(char *nome, int codigo, int valor, int quantidade)
{
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    return filme;
}

tFilme leFilme(int codigo)
{
    tFilme filme;
    scanf("%d,%[^,],%d,%d\n", &filme.codigo, filme.nome, &filme.valor, &filme.qtdEstoque);
    if (filme.codigo == codigo)
    {
        printf("Filme ja cadastrado no estoque\n");
    }
    return filme;
}

int obterCodigoFilme(tFilme filme)
{
    return filme.codigo;
}

void imprimirNomeFilme(tFilme filme)
{
    printf("%s\n", filme.nome);
}

int obterValorFilme(tFilme filme)
{
    return filme.valor;
}

int obterQtdEstoqueFilme(tFilme filme)
{
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme(tFilme filme)
{
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme(tFilme filme, int codigo)
{
    if (filme.codigo == codigo)
    {
        return 1;
    }
    return 0;
}

tFilme alugarFilme(tFilme filme)
{
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme(tFilme filme)
{
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes(tFilme filme1, tFilme filme2)
{
    if (!strcmp(filme1.nome, filme2.nome))
    {
        return 0;
    }
    else if (strcmp(filme1.nome, filme2.nome))
    {
        return 1;
    }
    else
        return -1;
}