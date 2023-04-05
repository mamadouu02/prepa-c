#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

enum jours { LUNDI = 1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE };

int main(int argc, char **argv)
{
    /* Affiche un message d'erreur si l'utilisateur oublie l'argument
     * à passer en ligne de commandes. */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s nombre\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Convertit l'argument passé par l'utilisateur en entier. */
    int32_t nombre = atoi(argv[1]);

    switch (nombre)
    {
    case LUNDI:
    case MARDI:
    case MERCREDI:
    case JEUDI:
    case VENDREDI:
        printf("Le nombre entré correspond à un jour de semaine.\n");
        break;

    case SAMEDI:
    case DIMANCHE:
        printf("Le nombre entré correspond à un jour du week-end.\n");
        break;

    default:
        printf("Le nombre entré doit être compris entre 1 et 7!\n");
        break;
    }

    return EXIT_SUCCESS;
}
