#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int res = 0;
    int tab[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (int i = 0; i < 10; ++i) {
        res += tab[i];
    }
    
    printf("Le résultat est %d.\n", 2 * res);

    return EXIT_SUCCESS;
}
