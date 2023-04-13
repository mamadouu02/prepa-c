#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "tableau.h"

void affiche(int32_t tab[], uint32_t taille)
{
    printf("[");

    for (uint32_t i = 0; i < taille; ++i) {
        printf("%u%s", tab[i], (i == taille - 1) ? "" : ", ");
    }

    printf("]\n");
}

void init_interactive(int32_t tab[], uint32_t taille)
{
    char tampon[11];

    for (uint32_t i = 0; i < taille; ++i) {
        printf("Entrez une valeur entière pour tab[%u] : ", i);
        fgets(tampon, 11, stdin);
        tab[i] = atoi(tampon);
    }
}

void init_aleatoire(int32_t tab[], uint32_t taille)
{
    for (uint32_t i = 0; i < taille; ++i) {
        tab[i] = rand();
    }
}

void tri_insertion(int32_t tab[], uint32_t taille)
{
    for (uint32_t i = 1; i < taille; ++i) {
        int32_t elem = tab[i];
        uint32_t j = i;
        
        while (j > 0 && tab[j-1] > elem) {
            tab[j] = tab[j-1];
            --j;
        }

        tab[j] = elem;
    }
}
