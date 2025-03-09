#include "pintura.h"
#include <stdlib.h>
#include <stdio.h>

struct Pintura
{
    char *titulo;
    char *artista;
    char *movimento;
    char *material;
    int anoPintura;
};

// Aloca dinamicamente uma nova estrutura Pintura e realiza a leitura dos dados
// de entrada associados à pintura. Retorna o ponteiro para o objeto Pintura.
// Retorna: Ponteiro para a Pintura recém-criada, com dados carregados.
Pintura *pintura_construct()
{
    Pintura *pintura = malloc(sizeof(Pintura));
    pintura->titulo = malloc(MAXTAM_STRINGS * sizeof(char));
    pintura->artista = malloc(MAXTAM_STRINGS * sizeof(char));
    pintura->movimento = malloc(MAXTAM_STRINGS * sizeof(char));
    pintura->material = malloc(MAXTAM_STRINGS * sizeof(char));
    pintura->anoPintura = 0;

    // P Starry_Night Vincent_van_Gogh Pós-Impressionismo Óleo_sobre_Tela 1889
    scanf("%s %s %s %s %d\n", pintura->titulo, pintura->artista, pintura->movimento, pintura->material, &pintura->anoPintura);

    return pintura;
}

// Imprime os dados de uma pintura. Recebe um ponteiro genérico para a pintura,
// e utiliza a função de impressão para exibir as informações relevantes.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser impressa.
void pintura_print(void *p)
{
    Pintura *pintura = (Pintura *)p;

    /*
    PINTURA
    Titulo: Starry_Night
    Artista: Vincent_van_Gogh
    Movimento: Pós-Impressionismo
    Material: Óleo_sobre_Tela
    Ano: 1889
    */

    printf("PINTURA\n");
    printf("Titulo: %s\n", pintura->titulo);
    printf("Artista: %s\n", pintura->artista);
    printf("Movimento: %s\n", pintura->movimento);
    printf("Material: %s\n", pintura->material);
    printf("Ano: %d\n", pintura->anoPintura);
}

// Libera a memória alocada para a pintura, chamando a função de desalocação
// apropriada para os dados da estrutura Pintura.
// Parâmetros:
//  p - Ponteiro para a Pintura a ser destruída.
void pintura_destroy(void *p) {
    Pintura *pintura = (Pintura *)p;

    free(pintura->titulo);
    free(pintura->artista);
    free(pintura->movimento);
    free(pintura->material);
    free(pintura);
    p = NULL;
}