#include "musica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Musica
{
    char *titulo;
    char *artista;
    int countParticipantes;
    char *participantes;
    char *album;
    char *genero;
};

// Aloca dinamicamente uma nova estrutura Musica e realiza a leitura dos dados
// de entrada associados à música. Pode envolver múltiplos participantes na música.
// Retorna: Ponteiro para a Musica recém-criada, com os dados carregados.
Musica *musica_construct()
{
    Musica *musica = malloc(sizeof(Musica));
    musica->titulo = malloc(MAXTAM_STRINGS * sizeof(char));
    musica->artista = malloc(MAXTAM_STRINGS * sizeof(char));
    musica->album = malloc(MAXTAM_STRINGS * sizeof(char));
    musica->genero = malloc(MAXTAM_STRINGS * sizeof(char));
    musica->participantes = calloc(MAXTAM_STRINGS, sizeof(char));
    musica->countParticipantes = 0;

    // M Bohemian_Rhapsody Queen 3 Freddie_Mercury Brian_May Roger_Taylor A_Night_at_the_Opera Rock
    scanf("%s %s %d ", musica->titulo, musica->artista, &musica->countParticipantes);

    for (int i = 0; i < musica->countParticipantes; i++)
    {
        char participante[MAXTAM_STRINGS] = "";
        scanf("%s ", participante);
        strcat(musica->participantes, participante);

        if (i < musica->countParticipantes - 1)
            strcat(musica->participantes, ", ");
    }

    scanf("%s %s\n", musica->album, musica->genero);

    return musica;
}

// Imprime os dados da música. Recebe um ponteiro genérico para a música
// e exibe suas informações relevantes, como título, artistas, etc.
// Parâmetros:
//  m - Ponteiro para a Musica a ser impressa.
void musica_print(void *m)
{
    Musica *musica = (Musica *)m;

    /*
    MUSICA
    Queen - Bohemian_Rhapsody (feat. Freddie_Mercury, Brian_May, Roger_Taylor)
    Album: A_Night_at_the_Opera
    Genero: Rock
    */
    printf("MUSICA\n");
    printf("%s - %s", musica->artista, musica->titulo);

    if (musica->countParticipantes > 0)
        printf(" (feat. %s)", musica->participantes);

    printf("\n");

    printf("Album: %s\n", musica->album);
    printf("Genero: %s\n", musica->genero);
}

// Libera a memória alocada para a música, desalocando a estrutura Musica
// e seus dados associados de forma adequada.
// Parâmetros:
//  m - Ponteiro para a Musica a ser destruída.
void musica_destroy(void *m)
{
    Musica *musica = (Musica *)m;

    free(musica->titulo);
    free(musica->artista);
    free(musica->participantes);
    free(musica->album);
    free(musica->genero);

    free(musica);
    m = NULL;
}