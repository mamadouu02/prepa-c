#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, end;

    do
    {
        printf("Entrez une majuscule : ");
        ch = getc(stdin);

        do
        {
            end = getc(stdin);
        } while (end != '\n');
        
    } while (!isupper(ch));

    printf("Vous avez saisi : %c\n", ch);

    return EXIT_SUCCESS;
}
