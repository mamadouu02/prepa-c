#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void init_tab(uint32_t tab[], size_t length)
{
    for (uint32_t i = 0; i < length; ++i)
    {
        tab[i] = 2 * i + 1;
    }
}

uint32_t somme_tab(uint32_t tab[], size_t length)
{
    uint32_t res = 0;

    for (uint32_t i = 0; i < length; ++i)
    {
        res += tab[i];
    }

    return res;
}

int main(void)
{
    const size_t TAILLE_TAB = 5000;
    uint32_t tab[TAILLE_TAB];
    init_tab(tab, TAILLE_TAB);
    uint32_t res = somme_tab(tab, TAILLE_TAB);
    printf("Le résultat est %u.\n", res);

    return EXIT_SUCCESS;
}
