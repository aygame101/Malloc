#include <stdio.h>
#include <stdlib.h>

int main() {
    int tab[10] = {3, -7, 1, 0, -4, 2, -9, 5, 8, -6}; // tableau d'entiers statique
    int nb_pos = 0, nb_neg = 0; // nombre d'éléments positifs et négatifs
    int *tab_pos = NULL, *tab_neg = NULL; // tableaux dynamiques pour les valeurs positives et négatives
    int i;

    for (i = 0; i < 10; i++) {
        if (tab[i] >= 0) {
            nb_pos++;
        } else {
            nb_neg++;
        }
    }

    tab_pos = (int*) malloc(nb_pos * sizeof(int)); // allocation du tableau dynamique pour les valeurs positives
    tab_neg = (int*) malloc(nb_neg * sizeof(int)); // allocation du tableau dynamique pour les valeurs négatives

    nb_pos = 0;
    nb_neg = 0;

    for (i = 0; i < 10; i++) {
        if (tab[i] >= 0) {
            tab_pos[nb_pos++] = tab[i];
        } else {
            tab_neg[nb_neg++] = tab[i];
        }
    }

    printf("Nombre d'éléments positifs : %d\n", nb_pos);
    for (i = 0; i < nb_pos; i++) {
        printf("%d ", tab_pos[i]);
    }
    printf("\n");

    printf("Nombre d'éléments négatifs : %d\n", nb_neg);
    for (i = 0; i < nb_neg; i++) {
        printf("%d ", tab_neg[i]);
    }
    printf("\n");

    free(tab_pos); // libération de la mémoire allouée pour le tableau dynamique des valeurs positives
    free(tab_neg); // libération de la mémoire allouée pour le tableau dynamique des valeurs négatives

    return 0;
}