#include "conta.h"
#include <stdio.h>
#include <stdlib.h>

Conta *CriaConta(Usuario *usuario, int nConta)
{
    Conta *conta = malloc(sizeof(Conta));
    conta->usuario = usuario;
    conta->nConta = nConta;
    conta->saldo = 0;
    conta->movimentacoes = malloc(100 * sizeof(float));
    conta->qtdMovimentacoes = 0;

    return conta;
}

Conta *BuscaConta(Conta **contas, int qtdContas, int nConta)
{
    for (int i = 0; i < qtdContas; i++)
    {
        if (contas[i]->nConta == nConta)
        {
            return contas[i];
        }
    }
    return NULL;
}

Usuario *RecuperaUsuario(Conta *conta)
{
    return conta->usuario;
}

int RecuperaNConta(Conta *conta)
{
    return conta->nConta;
}

int RecuperaQtdMovimentacoes(Conta *conta)
{
    return conta->qtdMovimentacoes;
}

float RecuperaSaldo(Conta *conta)
{
    return conta->saldo;
}

float Saque(Conta *conta, float valor)
{
    if (conta->saldo < valor)
    {
        return 0;
    }
    conta->saldo -= valor;
    conta->movimentacoes[conta->qtdMovimentacoes] = -valor;
    conta->qtdMovimentacoes++;

    return valor;
}

float Transferencia(Conta *contaOri, Conta *contaDes, float valor)
{
    if (valor == 0)
    {
        return 0;
    }
    Saque(contaOri, valor);
    Deposito(contaDes, valor);

    return valor;
}

float *RecuperaMovimentacoes(Conta *conta)
{
    return conta->movimentacoes;
}

void Deposito(Conta *conta, float valor)
{
    conta->saldo += valor;
    conta->movimentacoes[conta->qtdMovimentacoes] = valor;
    conta->qtdMovimentacoes++;
}

void DestroiConta(Conta *conta)
{
    free(conta->movimentacoes);
    free(conta);
}