#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

/**
 * @brief Structure de données décrivant un élément d'une liste.
 *
 */
struct cellule
{
    uint32_t val;           /**< La valeur d'une cellule est un entier */
    struct cellule* suiv;   /**< Pointeur vers la cellule suivant dans la liste */
};

/**
 * @brief Affiche sur la sortie standard les valeurs des cellules d'une liste.
 *
 * @param l la liste à afficher
 */
static void afficher(struct cellule* l)
{   
    while (l != NULL) {
        printf("%u -> ", l->val);
        l = l->suiv;
    }

    printf("NULL\n");
}

/**
 * @brief Insère une nouvelle cellule en tête d'une liste.
 *
 * @param pl l'adresse de la tête de la liste à étendre
 * @param v la valeur de la nouvelle cellule à créer et insérer
 */
static void inserer_tete(struct cellule** pl, uint32_t v)
{
    struct cellule *pc = malloc(sizeof(struct cellule));
    pc->val = v;
    pc->suiv = *pl;
    *pl = pc;
}

/**
 * @brief Insère une nouvelle cellule en dernière position d'une liste.
 *
 * @param pl l'adresse de la tête de la liste à étendre
 * @param v la valeur de la nouvelle cellule à créer et insérer
 */
static void inserer_queue(struct cellule** pl, uint32_t v)
{
    struct cellule *pc = malloc(sizeof(struct cellule));
    pc->val = v;
    pc->suiv = NULL;

    if (*pl == NULL) {
        *pl = pc;
    } else {
        struct cellule *pq = *pl;

        while (pq->suiv != NULL) {
            pq = pq->suiv;
        }
        
        pq->suiv = pc;
    }
}

/**
 * @brief Supprime la première occurrence d'une valeur dans une liste.
 *
 * @param pl l'adresse de la tête de la liste sur laquelle appliquer la suppression
 * @param v la valeur que l'on souhaite supprimer de la liste
 */
static void supprimer_premiere_occurrence(struct cellule** pl, uint32_t v)
{
    struct cellule *pp = NULL;
    struct cellule *pc = *pl;

    while (pc != NULL && pc->val != v) {
        pp = pc;
        pc = pc->suiv;
    }

    if (pc != NULL) {
        if (pp == NULL) {
            *pl = pc->suiv;
        } else {
            pp->suiv = pc->suiv;
        }
        free(pc);
    }
}

/**
 * @brief Point d'entrée du programme.
 *
 * @return int 0 (EXIT_SUCCESS) si tout s'est bien passé
 */
int main(void)
{
    struct cellule* liste = NULL;
    for (uint32_t i = 6; i < 10; i++) {
        inserer_queue(&liste, i);
        afficher(liste);
    }
    for (uint32_t i = 5; i > 0; i--) {
        inserer_tete(&liste, i);
        afficher(liste);
    }

    /*
        Initialisation du générateur de nombres aléatoires
        (nécessaire pour que rand() retourne des valeurs différentes à chaque
        exécution du programme).
    */
    srand(time(NULL));

    while (liste != NULL) {
        supprimer_premiere_occurrence(&liste, rand() % 10);
        afficher(liste);
    }
    return EXIT_SUCCESS;
}
