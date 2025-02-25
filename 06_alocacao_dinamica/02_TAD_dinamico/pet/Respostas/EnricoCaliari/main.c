#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL_CONTAS 10

void AdicionaConta(Conta **contas, int *qtdContas, int *qtdContasMem, Conta *conta);

void ImprimeRelatorioConta(Conta *conta);

void ImprimeExtratoConta(Conta *conta, int limit);

void AdicionaConta(Conta **contas, int *qtdContas, int *qtdContasMem, Conta *conta)
{
    if (*qtdContas + 1 == *qtdContasMem)
    {
        *qtdContasMem *= 2;
        contas = realloc(contas, *qtdContasMem * sizeof(Conta *));
    }

    contas[*qtdContas] = conta;
    (*qtdContas)++;
}

void ImprimeRelatorioConta(Conta *conta)
{
    Usuario *usuario = RecuperaUsuario(conta);
    printf("Conta: %d\n", RecuperaNConta(conta));
    printf("Saldo: R$ %.2f\n", RecuperaSaldo(conta));
    printf("Nome: %s\n", RecuperaNomeUsuario(usuario));
    printf("CPF: %d\n\n", RecuperaCpfUsuario(usuario));
}


void ImprimeExtratoConta(Conta *conta, int limit)
{
    ImprimeRelatorioConta(conta);

    float *movimentacoes = RecuperaMovimentacoes(conta);
    int qtdMovimentacoes = RecuperaQtdMovimentacoes(conta);

    if (limit > qtdMovimentacoes)
    {
        limit = qtdMovimentacoes;
    }

    printf("Ultimas %d transações\n", limit);

    for (int i = qtdMovimentacoes - 1; i >= qtdMovimentacoes - limit; i--)
    {
        printf("%.2f\n", movimentacoes[i]);
    }

    printf("\n");
}

int main()
{
    Conta **contas = malloc(TAM_INICIAL_CONTAS * sizeof(Conta *));
    int qtdContas = 0;
    int qtdContasMem = TAM_INICIAL_CONTAS;
    int option = 0;

    while (1)
    {
        scanf("%d\n", &option);

        if (option == 0)
        {
            break;
        }

        if (option == 1)
        {
            int nConta;
            float valor;
            scanf("%d %f\n", &nConta, &valor);

            Conta *conta = BuscaConta(contas, qtdContas, nConta);

            if (!conta)
            {
                continue;
            }

            Saque(conta, valor);

            continue;
        }

        if (option == 2)
        {
            int nConta;
            float valor;
            scanf("%d %f\n", &nConta, &valor);

            Conta *conta = BuscaConta(contas, qtdContas, nConta);

            if (!conta)
            {
                continue;
            }

            Deposito(conta, valor);

            continue;
        }

        if (option == 3)
        {
            int nContaOrigem;
            int nContaDestino;
            float valor;
            scanf("%d %d %f\n", &nContaOrigem, &nContaDestino, &valor);

            Conta *contaOrigem = BuscaConta(contas, qtdContas, nContaOrigem);
            Conta *contaDestino = BuscaConta(contas, qtdContas, nContaDestino);

            if (!contaOrigem || !contaDestino)
            {
                continue;
            }

            Transferencia(contaOrigem, contaDestino, valor);

            continue;
        }

        if (option == 4)
        {
            char nome[100];
            int cpf;
            int nConta;
            scanf("%s %d %d\n", nome, &cpf, &nConta);

            Usuario *usuario = CriaUsuario(nome, cpf);
            Conta *conta = CriaConta(usuario, nConta);

            AdicionaConta(contas, &qtdContas, &qtdContasMem, conta);
        }

        if (option == 5)
        {
            printf("===| Imprimindo Relatorio |===\n");

            for (int i = 0; i < qtdContas; i++)
            {
                ImprimeRelatorioConta(contas[i]);
            }
        }

        if (option == 6)
        {
            int nConta;
            int limit;

            scanf("%d %d\n", &nConta, &limit);

            Conta *conta = BuscaConta(contas, qtdContas, nConta);

            printf("===| Imprimindo Extrato |===\n");

            ImprimeExtratoConta(conta, limit);
        }
    }

    for (int i = 0; i < qtdContas; i++)
    {
        DestroiUsuario(RecuperaUsuario(contas[i]));
        DestroiConta(contas[i]);
    }

    free(contas);

    return 0;
}