#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

Conta *CriaConta(Usuario *usuario, int nConta)
{
    Conta *conta = (Conta *)calloc(1, sizeof(Conta));
    conta->usuario = CriaUsuario(usuario->nome, usuario->cpf);
    conta->nConta = nConta;
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
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        return valor;
    }
    return 0;
}

float Transferencia(Conta *contaOri, Conta *contaDes, float valor)
{
    if (valor <= contaOri->saldo)
    {
        contaOri->saldo -= valor;
        contaDes->saldo += valor;
        return valor;
    }
    return 0;
}

float *RecuperaMovimentacoes(Conta *conta)
{
    return conta->movimentacoes;
}

void Deposito(Conta *conta, float valor)
{
    conta->saldo += valor;
}

void DestroiConta(Conta *conta)
{
    if (conta != NULL)
    {
        DestroiUsuario(conta->usuario);
        free(conta);
    }
}