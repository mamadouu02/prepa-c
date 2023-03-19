#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void afficher_papous(bool est_papa, bool a_poux)
{
    printf("y'a des papous ");
    
    if (!est_papa)
    {
        printf("pas ");
    }

    printf("papa ");

    if (!a_poux)
    {
        printf("pas ");
    }

    printf("à poux\n");
}

int main(void)
{
    printf("Chez les papous...\n");
    afficher_papous(true, true);
    afficher_papous(true, false);
    afficher_papous(false, true);
    afficher_papous(false, false);

    return EXIT_SUCCESS;
}
