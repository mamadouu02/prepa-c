#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool est_palindrome(const char *mot)
{
    size_t length = strlen(mot);

    if (length > 1)
    {
        size_t i = 0, j = length - 1;

        for (i = 0; i < length/2; ++i, --j)
        {
            if (mot[i] != mot[j])
            {
                return false;
            }
        }
    }

    return true;
}

/*
    Ce prototype de fonction main permet de récupérer les arguments
    passés au programme sur la ligne de commande (ici, le mot sur
    lequel travailler).
*/
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s mot\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (est_palindrome(argv[1])) {
        printf("%s est bien un palindrome!\n", argv[1]);
    } else {
        printf("%s n'est pas un palindrome...\n", argv[1]);
    }

    return EXIT_SUCCESS;
}
