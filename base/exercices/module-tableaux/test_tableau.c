#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "tableau.h"

int main(void)
{
    uint32_t taille = 5;
    int32_t tab[taille];

    printf("\nInitialisation interactive d'un tableau de taille %u\n", taille);
    init_interactive(tab, taille);

    printf("\nAffichage du tableau\n");
    affiche(tab, taille);

    tri_insertion(tab, taille);

    printf("\nAffichage du tableau trié\n");
    affiche(tab, taille);

    printf("\nInitialisation aléatoire d'un tableau de taille %u\n", taille);
    srand(time(NULL));
    init_aleatoire(tab, taille);

    printf("\nAffichage du tableau\n");
    affiche(tab, taille);

    tri_insertion(tab, taille);

    printf("\nAffichage du tableau trié\n");
    affiche(tab, taille);

    printf("\n");

    return EXIT_SUCCESS;
}
